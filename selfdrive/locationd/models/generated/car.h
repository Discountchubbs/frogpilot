#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2942978262161439799);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7821311029239530165);
void car_H_mod_fun(double *state, double *out_5963371045109878546);
void car_f_fun(double *state, double dt, double *out_4591040400138422943);
void car_F_fun(double *state, double dt, double *out_4482564090024373644);
void car_h_25(double *state, double *unused, double *out_4607435000116305352);
void car_H_25(double *state, double *unused, double *out_192331079046689633);
void car_h_24(double *state, double *unused, double *out_8304259634700004229);
void car_H_24(double *state, double *unused, double *out_9026347808593666758);
void car_h_30(double *state, double *unused, double *out_2853123764132582973);
void car_H_30(double *state, double *unused, double *out_4335365251080918565);
void car_h_26(double *state, double *unused, double *out_1909613911230920538);
void car_H_26(double *state, double *unused, double *out_3549172239827366591);
void car_h_27(double *state, double *unused, double *out_2003029679307607701);
void car_H_27(double *state, double *unused, double *out_2111771179896975348);
void car_h_29(double *state, double *unused, double *out_8158476875148267830);
void car_H_29(double *state, double *unused, double *out_3825133906766526381);
void car_h_28(double *state, double *unused, double *out_7004702946968453346);
void car_H_28(double *state, double *unused, double *out_1861503635201200130);
void car_h_31(double *state, double *unused, double *out_6636093116607260294);
void car_H_31(double *state, double *unused, double *out_4175380342060718067);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}