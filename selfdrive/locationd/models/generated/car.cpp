#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4657099386715777158) {
   out_4657099386715777158[0] = delta_x[0] + nom_x[0];
   out_4657099386715777158[1] = delta_x[1] + nom_x[1];
   out_4657099386715777158[2] = delta_x[2] + nom_x[2];
   out_4657099386715777158[3] = delta_x[3] + nom_x[3];
   out_4657099386715777158[4] = delta_x[4] + nom_x[4];
   out_4657099386715777158[5] = delta_x[5] + nom_x[5];
   out_4657099386715777158[6] = delta_x[6] + nom_x[6];
   out_4657099386715777158[7] = delta_x[7] + nom_x[7];
   out_4657099386715777158[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4201029058516827396) {
   out_4201029058516827396[0] = -nom_x[0] + true_x[0];
   out_4201029058516827396[1] = -nom_x[1] + true_x[1];
   out_4201029058516827396[2] = -nom_x[2] + true_x[2];
   out_4201029058516827396[3] = -nom_x[3] + true_x[3];
   out_4201029058516827396[4] = -nom_x[4] + true_x[4];
   out_4201029058516827396[5] = -nom_x[5] + true_x[5];
   out_4201029058516827396[6] = -nom_x[6] + true_x[6];
   out_4201029058516827396[7] = -nom_x[7] + true_x[7];
   out_4201029058516827396[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5371876564602563323) {
   out_5371876564602563323[0] = 1.0;
   out_5371876564602563323[1] = 0;
   out_5371876564602563323[2] = 0;
   out_5371876564602563323[3] = 0;
   out_5371876564602563323[4] = 0;
   out_5371876564602563323[5] = 0;
   out_5371876564602563323[6] = 0;
   out_5371876564602563323[7] = 0;
   out_5371876564602563323[8] = 0;
   out_5371876564602563323[9] = 0;
   out_5371876564602563323[10] = 1.0;
   out_5371876564602563323[11] = 0;
   out_5371876564602563323[12] = 0;
   out_5371876564602563323[13] = 0;
   out_5371876564602563323[14] = 0;
   out_5371876564602563323[15] = 0;
   out_5371876564602563323[16] = 0;
   out_5371876564602563323[17] = 0;
   out_5371876564602563323[18] = 0;
   out_5371876564602563323[19] = 0;
   out_5371876564602563323[20] = 1.0;
   out_5371876564602563323[21] = 0;
   out_5371876564602563323[22] = 0;
   out_5371876564602563323[23] = 0;
   out_5371876564602563323[24] = 0;
   out_5371876564602563323[25] = 0;
   out_5371876564602563323[26] = 0;
   out_5371876564602563323[27] = 0;
   out_5371876564602563323[28] = 0;
   out_5371876564602563323[29] = 0;
   out_5371876564602563323[30] = 1.0;
   out_5371876564602563323[31] = 0;
   out_5371876564602563323[32] = 0;
   out_5371876564602563323[33] = 0;
   out_5371876564602563323[34] = 0;
   out_5371876564602563323[35] = 0;
   out_5371876564602563323[36] = 0;
   out_5371876564602563323[37] = 0;
   out_5371876564602563323[38] = 0;
   out_5371876564602563323[39] = 0;
   out_5371876564602563323[40] = 1.0;
   out_5371876564602563323[41] = 0;
   out_5371876564602563323[42] = 0;
   out_5371876564602563323[43] = 0;
   out_5371876564602563323[44] = 0;
   out_5371876564602563323[45] = 0;
   out_5371876564602563323[46] = 0;
   out_5371876564602563323[47] = 0;
   out_5371876564602563323[48] = 0;
   out_5371876564602563323[49] = 0;
   out_5371876564602563323[50] = 1.0;
   out_5371876564602563323[51] = 0;
   out_5371876564602563323[52] = 0;
   out_5371876564602563323[53] = 0;
   out_5371876564602563323[54] = 0;
   out_5371876564602563323[55] = 0;
   out_5371876564602563323[56] = 0;
   out_5371876564602563323[57] = 0;
   out_5371876564602563323[58] = 0;
   out_5371876564602563323[59] = 0;
   out_5371876564602563323[60] = 1.0;
   out_5371876564602563323[61] = 0;
   out_5371876564602563323[62] = 0;
   out_5371876564602563323[63] = 0;
   out_5371876564602563323[64] = 0;
   out_5371876564602563323[65] = 0;
   out_5371876564602563323[66] = 0;
   out_5371876564602563323[67] = 0;
   out_5371876564602563323[68] = 0;
   out_5371876564602563323[69] = 0;
   out_5371876564602563323[70] = 1.0;
   out_5371876564602563323[71] = 0;
   out_5371876564602563323[72] = 0;
   out_5371876564602563323[73] = 0;
   out_5371876564602563323[74] = 0;
   out_5371876564602563323[75] = 0;
   out_5371876564602563323[76] = 0;
   out_5371876564602563323[77] = 0;
   out_5371876564602563323[78] = 0;
   out_5371876564602563323[79] = 0;
   out_5371876564602563323[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2063473534760059585) {
   out_2063473534760059585[0] = state[0];
   out_2063473534760059585[1] = state[1];
   out_2063473534760059585[2] = state[2];
   out_2063473534760059585[3] = state[3];
   out_2063473534760059585[4] = state[4];
   out_2063473534760059585[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2063473534760059585[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2063473534760059585[7] = state[7];
   out_2063473534760059585[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3446551190387353375) {
   out_3446551190387353375[0] = 1;
   out_3446551190387353375[1] = 0;
   out_3446551190387353375[2] = 0;
   out_3446551190387353375[3] = 0;
   out_3446551190387353375[4] = 0;
   out_3446551190387353375[5] = 0;
   out_3446551190387353375[6] = 0;
   out_3446551190387353375[7] = 0;
   out_3446551190387353375[8] = 0;
   out_3446551190387353375[9] = 0;
   out_3446551190387353375[10] = 1;
   out_3446551190387353375[11] = 0;
   out_3446551190387353375[12] = 0;
   out_3446551190387353375[13] = 0;
   out_3446551190387353375[14] = 0;
   out_3446551190387353375[15] = 0;
   out_3446551190387353375[16] = 0;
   out_3446551190387353375[17] = 0;
   out_3446551190387353375[18] = 0;
   out_3446551190387353375[19] = 0;
   out_3446551190387353375[20] = 1;
   out_3446551190387353375[21] = 0;
   out_3446551190387353375[22] = 0;
   out_3446551190387353375[23] = 0;
   out_3446551190387353375[24] = 0;
   out_3446551190387353375[25] = 0;
   out_3446551190387353375[26] = 0;
   out_3446551190387353375[27] = 0;
   out_3446551190387353375[28] = 0;
   out_3446551190387353375[29] = 0;
   out_3446551190387353375[30] = 1;
   out_3446551190387353375[31] = 0;
   out_3446551190387353375[32] = 0;
   out_3446551190387353375[33] = 0;
   out_3446551190387353375[34] = 0;
   out_3446551190387353375[35] = 0;
   out_3446551190387353375[36] = 0;
   out_3446551190387353375[37] = 0;
   out_3446551190387353375[38] = 0;
   out_3446551190387353375[39] = 0;
   out_3446551190387353375[40] = 1;
   out_3446551190387353375[41] = 0;
   out_3446551190387353375[42] = 0;
   out_3446551190387353375[43] = 0;
   out_3446551190387353375[44] = 0;
   out_3446551190387353375[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3446551190387353375[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3446551190387353375[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3446551190387353375[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3446551190387353375[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3446551190387353375[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3446551190387353375[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3446551190387353375[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3446551190387353375[53] = -9.8000000000000007*dt;
   out_3446551190387353375[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3446551190387353375[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3446551190387353375[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3446551190387353375[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3446551190387353375[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3446551190387353375[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3446551190387353375[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3446551190387353375[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3446551190387353375[62] = 0;
   out_3446551190387353375[63] = 0;
   out_3446551190387353375[64] = 0;
   out_3446551190387353375[65] = 0;
   out_3446551190387353375[66] = 0;
   out_3446551190387353375[67] = 0;
   out_3446551190387353375[68] = 0;
   out_3446551190387353375[69] = 0;
   out_3446551190387353375[70] = 1;
   out_3446551190387353375[71] = 0;
   out_3446551190387353375[72] = 0;
   out_3446551190387353375[73] = 0;
   out_3446551190387353375[74] = 0;
   out_3446551190387353375[75] = 0;
   out_3446551190387353375[76] = 0;
   out_3446551190387353375[77] = 0;
   out_3446551190387353375[78] = 0;
   out_3446551190387353375[79] = 0;
   out_3446551190387353375[80] = 1;
}
void h_25(double *state, double *unused, double *out_786968565585552838) {
   out_786968565585552838[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4853345651662414123) {
   out_4853345651662414123[0] = 0;
   out_4853345651662414123[1] = 0;
   out_4853345651662414123[2] = 0;
   out_4853345651662414123[3] = 0;
   out_4853345651662414123[4] = 0;
   out_4853345651662414123[5] = 0;
   out_4853345651662414123[6] = 1;
   out_4853345651662414123[7] = 0;
   out_4853345651662414123[8] = 0;
}
void h_24(double *state, double *unused, double *out_7350088187030941283) {
   out_7350088187030941283[0] = state[4];
   out_7350088187030941283[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7025995250667913689) {
   out_7025995250667913689[0] = 0;
   out_7025995250667913689[1] = 0;
   out_7025995250667913689[2] = 0;
   out_7025995250667913689[3] = 0;
   out_7025995250667913689[4] = 1;
   out_7025995250667913689[5] = 0;
   out_7025995250667913689[6] = 0;
   out_7025995250667913689[7] = 0;
   out_7025995250667913689[8] = 0;
   out_7025995250667913689[9] = 0;
   out_7025995250667913689[10] = 0;
   out_7025995250667913689[11] = 0;
   out_7025995250667913689[12] = 0;
   out_7025995250667913689[13] = 0;
   out_7025995250667913689[14] = 1;
   out_7025995250667913689[15] = 0;
   out_7025995250667913689[16] = 0;
   out_7025995250667913689[17] = 0;
}
void h_30(double *state, double *unused, double *out_38683540202290018) {
   out_38683540202290018[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4982684598805654193) {
   out_4982684598805654193[0] = 0;
   out_4982684598805654193[1] = 0;
   out_4982684598805654193[2] = 0;
   out_4982684598805654193[3] = 0;
   out_4982684598805654193[4] = 1;
   out_4982684598805654193[5] = 0;
   out_4982684598805654193[6] = 0;
   out_4982684598805654193[7] = 0;
   out_4982684598805654193[8] = 0;
}
void h_26(double *state, double *unused, double *out_5040356807863135663) {
   out_5040356807863135663[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8594848970536470347) {
   out_8594848970536470347[0] = 0;
   out_8594848970536470347[1] = 0;
   out_8594848970536470347[2] = 0;
   out_8594848970536470347[3] = 0;
   out_8594848970536470347[4] = 0;
   out_8594848970536470347[5] = 0;
   out_8594848970536470347[6] = 0;
   out_8594848970536470347[7] = 1;
   out_8594848970536470347[8] = 0;
}
void h_27(double *state, double *unused, double *out_5788641833246398483) {
   out_5788641833246398483[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7157447910606079104) {
   out_7157447910606079104[0] = 0;
   out_7157447910606079104[1] = 0;
   out_7157447910606079104[2] = 0;
   out_7157447910606079104[3] = 1;
   out_7157447910606079104[4] = 0;
   out_7157447910606079104[5] = 0;
   out_7157447910606079104[6] = 0;
   out_7157447910606079104[7] = 0;
   out_7157447910606079104[8] = 0;
}
void h_29(double *state, double *unused, double *out_982193393103952453) {
   out_982193393103952453[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4472453254491262009) {
   out_4472453254491262009[0] = 0;
   out_4472453254491262009[1] = 1;
   out_4472453254491262009[2] = 0;
   out_4472453254491262009[3] = 0;
   out_4472453254491262009[4] = 0;
   out_4472453254491262009[5] = 0;
   out_4472453254491262009[6] = 0;
   out_4472453254491262009[7] = 0;
   out_4472453254491262009[8] = 0;
}
void h_28(double *state, double *unused, double *out_7656428972802307488) {
   out_7656428972802307488[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6907180365910303886) {
   out_6907180365910303886[0] = 1;
   out_6907180365910303886[1] = 0;
   out_6907180365910303886[2] = 0;
   out_6907180365910303886[3] = 0;
   out_6907180365910303886[4] = 0;
   out_6907180365910303886[5] = 0;
   out_6907180365910303886[6] = 0;
   out_6907180365910303886[7] = 0;
   out_6907180365910303886[8] = 0;
}
void h_31(double *state, double *unused, double *out_8550233822406225279) {
   out_8550233822406225279[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4822699689785453695) {
   out_4822699689785453695[0] = 0;
   out_4822699689785453695[1] = 0;
   out_4822699689785453695[2] = 0;
   out_4822699689785453695[3] = 0;
   out_4822699689785453695[4] = 0;
   out_4822699689785453695[5] = 0;
   out_4822699689785453695[6] = 0;
   out_4822699689785453695[7] = 0;
   out_4822699689785453695[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4657099386715777158) {
  err_fun(nom_x, delta_x, out_4657099386715777158);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4201029058516827396) {
  inv_err_fun(nom_x, true_x, out_4201029058516827396);
}
void car_H_mod_fun(double *state, double *out_5371876564602563323) {
  H_mod_fun(state, out_5371876564602563323);
}
void car_f_fun(double *state, double dt, double *out_2063473534760059585) {
  f_fun(state,  dt, out_2063473534760059585);
}
void car_F_fun(double *state, double dt, double *out_3446551190387353375) {
  F_fun(state,  dt, out_3446551190387353375);
}
void car_h_25(double *state, double *unused, double *out_786968565585552838) {
  h_25(state, unused, out_786968565585552838);
}
void car_H_25(double *state, double *unused, double *out_4853345651662414123) {
  H_25(state, unused, out_4853345651662414123);
}
void car_h_24(double *state, double *unused, double *out_7350088187030941283) {
  h_24(state, unused, out_7350088187030941283);
}
void car_H_24(double *state, double *unused, double *out_7025995250667913689) {
  H_24(state, unused, out_7025995250667913689);
}
void car_h_30(double *state, double *unused, double *out_38683540202290018) {
  h_30(state, unused, out_38683540202290018);
}
void car_H_30(double *state, double *unused, double *out_4982684598805654193) {
  H_30(state, unused, out_4982684598805654193);
}
void car_h_26(double *state, double *unused, double *out_5040356807863135663) {
  h_26(state, unused, out_5040356807863135663);
}
void car_H_26(double *state, double *unused, double *out_8594848970536470347) {
  H_26(state, unused, out_8594848970536470347);
}
void car_h_27(double *state, double *unused, double *out_5788641833246398483) {
  h_27(state, unused, out_5788641833246398483);
}
void car_H_27(double *state, double *unused, double *out_7157447910606079104) {
  H_27(state, unused, out_7157447910606079104);
}
void car_h_29(double *state, double *unused, double *out_982193393103952453) {
  h_29(state, unused, out_982193393103952453);
}
void car_H_29(double *state, double *unused, double *out_4472453254491262009) {
  H_29(state, unused, out_4472453254491262009);
}
void car_h_28(double *state, double *unused, double *out_7656428972802307488) {
  h_28(state, unused, out_7656428972802307488);
}
void car_H_28(double *state, double *unused, double *out_6907180365910303886) {
  H_28(state, unused, out_6907180365910303886);
}
void car_h_31(double *state, double *unused, double *out_8550233822406225279) {
  h_31(state, unused, out_8550233822406225279);
}
void car_H_31(double *state, double *unused, double *out_4822699689785453695) {
  H_31(state, unused, out_4822699689785453695);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
