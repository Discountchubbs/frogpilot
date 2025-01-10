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
void err_fun(double *nom_x, double *delta_x, double *out_2942978262161439799) {
   out_2942978262161439799[0] = delta_x[0] + nom_x[0];
   out_2942978262161439799[1] = delta_x[1] + nom_x[1];
   out_2942978262161439799[2] = delta_x[2] + nom_x[2];
   out_2942978262161439799[3] = delta_x[3] + nom_x[3];
   out_2942978262161439799[4] = delta_x[4] + nom_x[4];
   out_2942978262161439799[5] = delta_x[5] + nom_x[5];
   out_2942978262161439799[6] = delta_x[6] + nom_x[6];
   out_2942978262161439799[7] = delta_x[7] + nom_x[7];
   out_2942978262161439799[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7821311029239530165) {
   out_7821311029239530165[0] = -nom_x[0] + true_x[0];
   out_7821311029239530165[1] = -nom_x[1] + true_x[1];
   out_7821311029239530165[2] = -nom_x[2] + true_x[2];
   out_7821311029239530165[3] = -nom_x[3] + true_x[3];
   out_7821311029239530165[4] = -nom_x[4] + true_x[4];
   out_7821311029239530165[5] = -nom_x[5] + true_x[5];
   out_7821311029239530165[6] = -nom_x[6] + true_x[6];
   out_7821311029239530165[7] = -nom_x[7] + true_x[7];
   out_7821311029239530165[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5963371045109878546) {
   out_5963371045109878546[0] = 1.0;
   out_5963371045109878546[1] = 0;
   out_5963371045109878546[2] = 0;
   out_5963371045109878546[3] = 0;
   out_5963371045109878546[4] = 0;
   out_5963371045109878546[5] = 0;
   out_5963371045109878546[6] = 0;
   out_5963371045109878546[7] = 0;
   out_5963371045109878546[8] = 0;
   out_5963371045109878546[9] = 0;
   out_5963371045109878546[10] = 1.0;
   out_5963371045109878546[11] = 0;
   out_5963371045109878546[12] = 0;
   out_5963371045109878546[13] = 0;
   out_5963371045109878546[14] = 0;
   out_5963371045109878546[15] = 0;
   out_5963371045109878546[16] = 0;
   out_5963371045109878546[17] = 0;
   out_5963371045109878546[18] = 0;
   out_5963371045109878546[19] = 0;
   out_5963371045109878546[20] = 1.0;
   out_5963371045109878546[21] = 0;
   out_5963371045109878546[22] = 0;
   out_5963371045109878546[23] = 0;
   out_5963371045109878546[24] = 0;
   out_5963371045109878546[25] = 0;
   out_5963371045109878546[26] = 0;
   out_5963371045109878546[27] = 0;
   out_5963371045109878546[28] = 0;
   out_5963371045109878546[29] = 0;
   out_5963371045109878546[30] = 1.0;
   out_5963371045109878546[31] = 0;
   out_5963371045109878546[32] = 0;
   out_5963371045109878546[33] = 0;
   out_5963371045109878546[34] = 0;
   out_5963371045109878546[35] = 0;
   out_5963371045109878546[36] = 0;
   out_5963371045109878546[37] = 0;
   out_5963371045109878546[38] = 0;
   out_5963371045109878546[39] = 0;
   out_5963371045109878546[40] = 1.0;
   out_5963371045109878546[41] = 0;
   out_5963371045109878546[42] = 0;
   out_5963371045109878546[43] = 0;
   out_5963371045109878546[44] = 0;
   out_5963371045109878546[45] = 0;
   out_5963371045109878546[46] = 0;
   out_5963371045109878546[47] = 0;
   out_5963371045109878546[48] = 0;
   out_5963371045109878546[49] = 0;
   out_5963371045109878546[50] = 1.0;
   out_5963371045109878546[51] = 0;
   out_5963371045109878546[52] = 0;
   out_5963371045109878546[53] = 0;
   out_5963371045109878546[54] = 0;
   out_5963371045109878546[55] = 0;
   out_5963371045109878546[56] = 0;
   out_5963371045109878546[57] = 0;
   out_5963371045109878546[58] = 0;
   out_5963371045109878546[59] = 0;
   out_5963371045109878546[60] = 1.0;
   out_5963371045109878546[61] = 0;
   out_5963371045109878546[62] = 0;
   out_5963371045109878546[63] = 0;
   out_5963371045109878546[64] = 0;
   out_5963371045109878546[65] = 0;
   out_5963371045109878546[66] = 0;
   out_5963371045109878546[67] = 0;
   out_5963371045109878546[68] = 0;
   out_5963371045109878546[69] = 0;
   out_5963371045109878546[70] = 1.0;
   out_5963371045109878546[71] = 0;
   out_5963371045109878546[72] = 0;
   out_5963371045109878546[73] = 0;
   out_5963371045109878546[74] = 0;
   out_5963371045109878546[75] = 0;
   out_5963371045109878546[76] = 0;
   out_5963371045109878546[77] = 0;
   out_5963371045109878546[78] = 0;
   out_5963371045109878546[79] = 0;
   out_5963371045109878546[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4591040400138422943) {
   out_4591040400138422943[0] = state[0];
   out_4591040400138422943[1] = state[1];
   out_4591040400138422943[2] = state[2];
   out_4591040400138422943[3] = state[3];
   out_4591040400138422943[4] = state[4];
   out_4591040400138422943[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4591040400138422943[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4591040400138422943[7] = state[7];
   out_4591040400138422943[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4482564090024373644) {
   out_4482564090024373644[0] = 1;
   out_4482564090024373644[1] = 0;
   out_4482564090024373644[2] = 0;
   out_4482564090024373644[3] = 0;
   out_4482564090024373644[4] = 0;
   out_4482564090024373644[5] = 0;
   out_4482564090024373644[6] = 0;
   out_4482564090024373644[7] = 0;
   out_4482564090024373644[8] = 0;
   out_4482564090024373644[9] = 0;
   out_4482564090024373644[10] = 1;
   out_4482564090024373644[11] = 0;
   out_4482564090024373644[12] = 0;
   out_4482564090024373644[13] = 0;
   out_4482564090024373644[14] = 0;
   out_4482564090024373644[15] = 0;
   out_4482564090024373644[16] = 0;
   out_4482564090024373644[17] = 0;
   out_4482564090024373644[18] = 0;
   out_4482564090024373644[19] = 0;
   out_4482564090024373644[20] = 1;
   out_4482564090024373644[21] = 0;
   out_4482564090024373644[22] = 0;
   out_4482564090024373644[23] = 0;
   out_4482564090024373644[24] = 0;
   out_4482564090024373644[25] = 0;
   out_4482564090024373644[26] = 0;
   out_4482564090024373644[27] = 0;
   out_4482564090024373644[28] = 0;
   out_4482564090024373644[29] = 0;
   out_4482564090024373644[30] = 1;
   out_4482564090024373644[31] = 0;
   out_4482564090024373644[32] = 0;
   out_4482564090024373644[33] = 0;
   out_4482564090024373644[34] = 0;
   out_4482564090024373644[35] = 0;
   out_4482564090024373644[36] = 0;
   out_4482564090024373644[37] = 0;
   out_4482564090024373644[38] = 0;
   out_4482564090024373644[39] = 0;
   out_4482564090024373644[40] = 1;
   out_4482564090024373644[41] = 0;
   out_4482564090024373644[42] = 0;
   out_4482564090024373644[43] = 0;
   out_4482564090024373644[44] = 0;
   out_4482564090024373644[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4482564090024373644[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4482564090024373644[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4482564090024373644[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4482564090024373644[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4482564090024373644[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4482564090024373644[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4482564090024373644[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4482564090024373644[53] = -9.8000000000000007*dt;
   out_4482564090024373644[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4482564090024373644[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4482564090024373644[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4482564090024373644[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4482564090024373644[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4482564090024373644[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4482564090024373644[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4482564090024373644[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4482564090024373644[62] = 0;
   out_4482564090024373644[63] = 0;
   out_4482564090024373644[64] = 0;
   out_4482564090024373644[65] = 0;
   out_4482564090024373644[66] = 0;
   out_4482564090024373644[67] = 0;
   out_4482564090024373644[68] = 0;
   out_4482564090024373644[69] = 0;
   out_4482564090024373644[70] = 1;
   out_4482564090024373644[71] = 0;
   out_4482564090024373644[72] = 0;
   out_4482564090024373644[73] = 0;
   out_4482564090024373644[74] = 0;
   out_4482564090024373644[75] = 0;
   out_4482564090024373644[76] = 0;
   out_4482564090024373644[77] = 0;
   out_4482564090024373644[78] = 0;
   out_4482564090024373644[79] = 0;
   out_4482564090024373644[80] = 1;
}
void h_25(double *state, double *unused, double *out_4607435000116305352) {
   out_4607435000116305352[0] = state[6];
}
void H_25(double *state, double *unused, double *out_192331079046689633) {
   out_192331079046689633[0] = 0;
   out_192331079046689633[1] = 0;
   out_192331079046689633[2] = 0;
   out_192331079046689633[3] = 0;
   out_192331079046689633[4] = 0;
   out_192331079046689633[5] = 0;
   out_192331079046689633[6] = 1;
   out_192331079046689633[7] = 0;
   out_192331079046689633[8] = 0;
}
void h_24(double *state, double *unused, double *out_8304259634700004229) {
   out_8304259634700004229[0] = state[4];
   out_8304259634700004229[1] = state[5];
}
void H_24(double *state, double *unused, double *out_9026347808593666758) {
   out_9026347808593666758[0] = 0;
   out_9026347808593666758[1] = 0;
   out_9026347808593666758[2] = 0;
   out_9026347808593666758[3] = 0;
   out_9026347808593666758[4] = 1;
   out_9026347808593666758[5] = 0;
   out_9026347808593666758[6] = 0;
   out_9026347808593666758[7] = 0;
   out_9026347808593666758[8] = 0;
   out_9026347808593666758[9] = 0;
   out_9026347808593666758[10] = 0;
   out_9026347808593666758[11] = 0;
   out_9026347808593666758[12] = 0;
   out_9026347808593666758[13] = 0;
   out_9026347808593666758[14] = 1;
   out_9026347808593666758[15] = 0;
   out_9026347808593666758[16] = 0;
   out_9026347808593666758[17] = 0;
}
void h_30(double *state, double *unused, double *out_2853123764132582973) {
   out_2853123764132582973[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4335365251080918565) {
   out_4335365251080918565[0] = 0;
   out_4335365251080918565[1] = 0;
   out_4335365251080918565[2] = 0;
   out_4335365251080918565[3] = 0;
   out_4335365251080918565[4] = 1;
   out_4335365251080918565[5] = 0;
   out_4335365251080918565[6] = 0;
   out_4335365251080918565[7] = 0;
   out_4335365251080918565[8] = 0;
}
void h_26(double *state, double *unused, double *out_1909613911230920538) {
   out_1909613911230920538[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3549172239827366591) {
   out_3549172239827366591[0] = 0;
   out_3549172239827366591[1] = 0;
   out_3549172239827366591[2] = 0;
   out_3549172239827366591[3] = 0;
   out_3549172239827366591[4] = 0;
   out_3549172239827366591[5] = 0;
   out_3549172239827366591[6] = 0;
   out_3549172239827366591[7] = 1;
   out_3549172239827366591[8] = 0;
}
void h_27(double *state, double *unused, double *out_2003029679307607701) {
   out_2003029679307607701[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2111771179896975348) {
   out_2111771179896975348[0] = 0;
   out_2111771179896975348[1] = 0;
   out_2111771179896975348[2] = 0;
   out_2111771179896975348[3] = 1;
   out_2111771179896975348[4] = 0;
   out_2111771179896975348[5] = 0;
   out_2111771179896975348[6] = 0;
   out_2111771179896975348[7] = 0;
   out_2111771179896975348[8] = 0;
}
void h_29(double *state, double *unused, double *out_8158476875148267830) {
   out_8158476875148267830[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3825133906766526381) {
   out_3825133906766526381[0] = 0;
   out_3825133906766526381[1] = 1;
   out_3825133906766526381[2] = 0;
   out_3825133906766526381[3] = 0;
   out_3825133906766526381[4] = 0;
   out_3825133906766526381[5] = 0;
   out_3825133906766526381[6] = 0;
   out_3825133906766526381[7] = 0;
   out_3825133906766526381[8] = 0;
}
void h_28(double *state, double *unused, double *out_7004702946968453346) {
   out_7004702946968453346[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1861503635201200130) {
   out_1861503635201200130[0] = 1;
   out_1861503635201200130[1] = 0;
   out_1861503635201200130[2] = 0;
   out_1861503635201200130[3] = 0;
   out_1861503635201200130[4] = 0;
   out_1861503635201200130[5] = 0;
   out_1861503635201200130[6] = 0;
   out_1861503635201200130[7] = 0;
   out_1861503635201200130[8] = 0;
}
void h_31(double *state, double *unused, double *out_6636093116607260294) {
   out_6636093116607260294[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4175380342060718067) {
   out_4175380342060718067[0] = 0;
   out_4175380342060718067[1] = 0;
   out_4175380342060718067[2] = 0;
   out_4175380342060718067[3] = 0;
   out_4175380342060718067[4] = 0;
   out_4175380342060718067[5] = 0;
   out_4175380342060718067[6] = 0;
   out_4175380342060718067[7] = 0;
   out_4175380342060718067[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_2942978262161439799) {
  err_fun(nom_x, delta_x, out_2942978262161439799);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7821311029239530165) {
  inv_err_fun(nom_x, true_x, out_7821311029239530165);
}
void car_H_mod_fun(double *state, double *out_5963371045109878546) {
  H_mod_fun(state, out_5963371045109878546);
}
void car_f_fun(double *state, double dt, double *out_4591040400138422943) {
  f_fun(state,  dt, out_4591040400138422943);
}
void car_F_fun(double *state, double dt, double *out_4482564090024373644) {
  F_fun(state,  dt, out_4482564090024373644);
}
void car_h_25(double *state, double *unused, double *out_4607435000116305352) {
  h_25(state, unused, out_4607435000116305352);
}
void car_H_25(double *state, double *unused, double *out_192331079046689633) {
  H_25(state, unused, out_192331079046689633);
}
void car_h_24(double *state, double *unused, double *out_8304259634700004229) {
  h_24(state, unused, out_8304259634700004229);
}
void car_H_24(double *state, double *unused, double *out_9026347808593666758) {
  H_24(state, unused, out_9026347808593666758);
}
void car_h_30(double *state, double *unused, double *out_2853123764132582973) {
  h_30(state, unused, out_2853123764132582973);
}
void car_H_30(double *state, double *unused, double *out_4335365251080918565) {
  H_30(state, unused, out_4335365251080918565);
}
void car_h_26(double *state, double *unused, double *out_1909613911230920538) {
  h_26(state, unused, out_1909613911230920538);
}
void car_H_26(double *state, double *unused, double *out_3549172239827366591) {
  H_26(state, unused, out_3549172239827366591);
}
void car_h_27(double *state, double *unused, double *out_2003029679307607701) {
  h_27(state, unused, out_2003029679307607701);
}
void car_H_27(double *state, double *unused, double *out_2111771179896975348) {
  H_27(state, unused, out_2111771179896975348);
}
void car_h_29(double *state, double *unused, double *out_8158476875148267830) {
  h_29(state, unused, out_8158476875148267830);
}
void car_H_29(double *state, double *unused, double *out_3825133906766526381) {
  H_29(state, unused, out_3825133906766526381);
}
void car_h_28(double *state, double *unused, double *out_7004702946968453346) {
  h_28(state, unused, out_7004702946968453346);
}
void car_H_28(double *state, double *unused, double *out_1861503635201200130) {
  H_28(state, unused, out_1861503635201200130);
}
void car_h_31(double *state, double *unused, double *out_6636093116607260294) {
  h_31(state, unused, out_6636093116607260294);
}
void car_H_31(double *state, double *unused, double *out_4175380342060718067) {
  H_31(state, unused, out_4175380342060718067);
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
