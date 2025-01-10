#!/bin/bash

set -x

# Configuration
DEVICE_IP="192.168.1.89"
DEVICE_USER="comma"
BRANCH_NAME="Chubbs"
DEVELOPMENT_BRANCH="Chubbs"
COMPILE_BRANCH="compile"

# Confirmation function
confirm() {
    read -p "$1 (y/n): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        echo "Operation cancelled by user"
        exit 1
    fi
}

function device_operations() {
    echo "Performing device operations==="
    confirm "Ready to begin device operations?"
    echo "Removing old SSH keys..."
    ssh-keygen -R $DEVICE_IP

    echo "Connecting to device at $DEVICE_IP..."
    COMMIT_HASH=$(ssh $DEVICE_USER@$DEVICE_IP << 'ENDSSH'
        set -x  # Enable command tracing
        echo "Changing to openpilot directory..."
        cd /data/openpilot

        echo "Adding files..."
        git add -A .
        git add -f .

        echo "Processing deleted files..."
        for file in $DELETED_FILES; do
            git add -f "$file" || echo "Could not add deleted file: $file"
        done

        echo "Adding untracked files..."
        git add -f $(git ls-files --others --exclude-standard)
        # Add deleted files
        git add -f $(git ls-files --deleted)

        echo "Current git status:"
        git status

        echo "Committing changes..."
        git commit -m "Compile ChubbsPilot with prebuilts"
        git rev-parse HEAD
ENDSSH
    )
    echo "=== Device operations completed ==="
    echo "Device commit hash: $COMMIT_HASH"

    scp $DEVICE_USER@$DEVICE_IP:/data/openpilot/deleted_files.txt .
    echo "Deleted files have been logged to deleted_files.txt"
    return $COMMIT_HASH
}

function workspace_operations() {
    set -x  # Enable command tracing
    local device_commit=$1
    echo "=== Starting workspace operations ==="


    if ! git remote | grep -q "device"; then
        git remote add device ssh://$DEVICE_USER@$DEVICE_IP:/data/openpilot
    fi

    # Fetch everything from device
    git fetch device $DEVELOPMENT_BRANCH --force

    confirm "Cherry-pick to compile branch?"
    git checkout $COMPILE_BRANCH
    git cherry-pick --no-commit --strategy=recursive -X theirs $device_commit
    git add -A
    git add -f .

    echo "Cherry-pick complete but not committed. Please manually merge with HEAD commit."
    echo "Once you're done merging, press any key to continue with the commit..."
    read -n 1 -s

    git commit --amend --no-edit
    AMENDED_HASH=$(git rev-parse HEAD)

    confirm "Cherry-pick to Development branch?"
    git checkout $DEVELOPMENT_BRANCH
    git cherry-pick --strategy=recursive -X theirs $AMENDED_HASH
    git push -f origin $DEVELOPMENT_BRANCH

    read -p "Reset ChubbsPilot branch to match Development? (y/n): " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        git checkout $BRANCH_NAME
        git reset --hard $DEVELOPMENT_BRANCH
        git push -f origin $BRANCH_NAME
        echo "ChubbsPilot branch has been reset to match Development"
    else
        echo "Skipping ChubbsPilot branch reset"
        echo "Sync process completed with Development branch update only"
        return 0
    fi
}

# Main execution
set -x  # Enable command tracing
echo "Starting automated sync process..."
confirm "Begin sync process?"
DEVICE_COMMIT=$(device_operations)
workspace_operations $DEVICE_COMMIT
echo "Sync process completed."
