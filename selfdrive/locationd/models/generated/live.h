#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8353050709366375372);
void live_err_fun(double *nom_x, double *delta_x, double *out_3524010424271379488);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_9156970974497279680);
void live_H_mod_fun(double *state, double *out_5655419639632425896);
void live_f_fun(double *state, double dt, double *out_3783964803714660621);
void live_F_fun(double *state, double dt, double *out_266640275894821832);
void live_h_4(double *state, double *unused, double *out_5249318892942921089);
void live_H_4(double *state, double *unused, double *out_7017186613873811411);
void live_h_9(double *state, double *unused, double *out_2084132629847414432);
void live_H_9(double *state, double *unused, double *out_4128325061593732069);
void live_h_10(double *state, double *unused, double *out_4638880908110628108);
void live_H_10(double *state, double *unused, double *out_53982469377547821);
void live_h_12(double *state, double *unused, double *out_4072170863061210879);
void live_H_12(double *state, double *unused, double *out_6396087588826217744);
void live_h_35(double *state, double *unused, double *out_3901988497461409070);
void live_H_35(double *state, double *unused, double *out_3650524556501204035);
void live_h_32(double *state, double *unused, double *out_474102628617699552);
void live_H_32(double *state, double *unused, double *out_6537005979349658531);
void live_h_13(double *state, double *unused, double *out_2171259417435830038);
void live_H_13(double *state, double *unused, double *out_520792213179781524);
void live_h_14(double *state, double *unused, double *out_2084132629847414432);
void live_H_14(double *state, double *unused, double *out_4128325061593732069);
void live_h_33(double *state, double *unused, double *out_787119254569029086);
void live_H_33(double *state, double *unused, double *out_499967551862346431);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}