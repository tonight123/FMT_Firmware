/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.545
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug 10 21:48:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

const Control_Out_Bus Controller_rtZControl_Out_Bus = {
  0U,                                  /* timestamp */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  /* actuator_cmd */
} ;                                    /* Control_Out_Bus ground */

/* Exported block parameters */
struct_Ae52N6uY2eO0jd5TMQiCYB CONTROL_PARAM = {
  0.9F,
  0.09F,
  0.01F,
  0.5F,
  0.2F,
  0.1F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.3F,
  0.3F,
  -0.2F,
  0.2F,
  3.0F,
  3.0F,
  0.52359879F,
  0.05F,
  0.05F,
  0.2F,
  0.1F,
  0.1F,
  0.1F,
  0.0005F,
  0.0005F,
  0.0005F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S12>/Saturation'
                                        *   '<S12>/Saturation1'
                                        *   '<S36>/kd'
                                        *   '<S36>/Saturation'
                                        *   '<S37>/ki'
                                        *   '<S37>/Discrete-Time Integrator'
                                        *   '<S38>/kp'
                                        *   '<S46>/kd'
                                        *   '<S46>/Saturation'
                                        *   '<S47>/ki'
                                        *   '<S47>/Discrete-Time Integrator'
                                        *   '<S48>/kp'
                                        *   '<S19>/gain1'
                                        *   '<S19>/gain2'
                                        *   '<S19>/gain3'
                                        *   '<S19>/Saturation'
                                        *   '<S20>/gain1'
                                        *   '<S20>/gain2'
                                        *   '<S20>/gain3'
                                        *   '<S20>/Discrete-Time Integrator'
                                        *   '<S21>/gain1'
                                        *   '<S21>/gain2'
                                        *   '<S21>/gain3'
                                        *   '<S29>/Gain'
                                        *   '<S29>/Gain1'
                                        *   '<S29>/Gain2'
                                        */

struct_4XfCoaAMTej5uH3d8u88xB CONTROL_EXPORT = {
  4U
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S4>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  real32_T rtb_TrigoFcn1;
  real32_T rtb_Gain;
  real32_T rtb_k_pt;
  real32_T rtb_M_z[9];
  real32_T rtb_TrigoFcn;
  real32_T rtb_Saturation_m;
  real32_T rtb_Cos1;
  real32_T rtb_Cos;
  real32_T rtb_Multiply4;
  real32_T rtb_Multiply3;
  uint32_T rtb_Switch;
  int32_T i;
  real32_T rtb_M_z_0[3];
  real32_T rtb_Atan_idx_0;
  real32_T rtb_Atan_idx_1;
  real32_T rtb_k_pt_i_idx_0;
  real32_T rtb_k_pt_i_idx_1;
  real32_T tmp;
  uint16_T u0;
  real32_T u0_0;
  real32_T u0_1;

  /* Gain: '<S44>/Gain' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S44>/Sum1'
   */
  rtb_Gain = -(Controller_U.FMS_Out.w_cmd - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE <=
          CONTROL_PARAM.VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S49>/k_pt' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
   *  Sum: '<S49>/Sum5'
   */
  rtb_k_pt = (rtb_Gain - Controller_DW.DiscreteTimeIntegrator1_DSTATE) * 10.0F;

  /* Trigonometry: '<S35>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_TrigoFcn1 = arm_cos_f32(Controller_U.INS_Out.psi);

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_TrigoFcn1;

  /* Trigonometry: '<S35>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_TrigoFcn = arm_sin_f32(Controller_U.INS_Out.psi);

  /* Gain: '<S35>/Gain' */
  rtb_M_z[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_TrigoFcn1;

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S35>/ConcatBufferAtVecConcentate1In3' */
  rtb_M_z[6] = Controller_ConstB.VecConcentate3[0];
  rtb_M_z[7] = Controller_ConstB.VecConcentate3[1];
  rtb_M_z[8] = Controller_ConstB.VecConcentate3[2];

  /* Product: '<S34>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S34>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_M_z_0[i] = rtb_M_z[i + 3] * Controller_U.INS_Out.ve + rtb_M_z[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S34>/Multiply' */

  /* Sum: '<S32>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_TrigoFcn1 = Controller_U.FMS_Out.u_cmd - rtb_M_z_0[0];
  rtb_TrigoFcn = Controller_U.FMS_Out.v_cmd - rtb_M_z_0[1];

  /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_k != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[1] = 0.0F;
  }

  /* Gain: '<S39>/k_pt' incorporates:
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator1'
   *  Sum: '<S39>/Sum5'
   */
  rtb_k_pt_i_idx_0 = (rtb_TrigoFcn1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[0]) * 10.0F;
  rtb_k_pt_i_idx_1 = (rtb_TrigoFcn -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[1]) * 10.0F;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S15>/Multiply'
   *  Product: '<S15>/Multiply1'
   *  Product: '<S15>/Multiply5'
   *  RelationalOperator: '<S23>/Compare'
   *  Saturate: '<S12>/Saturation'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   *  Sum: '<S26>/Sum'
   *  Trigonometry: '<S15>/Sin1'
   */
  if (Controller_U.FMS_Out.mode == 5) {
    rtb_Atan_idx_0 = Controller_U.FMS_Out.p_cmd;
    rtb_Atan_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_Saturation_m = Controller_U.FMS_Out.r_cmd;
  } else {
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
    } else {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     *  Saturate: '<S12>/Saturation'
     *  Trigonometry: '<S31>/Atan'
     */
    if (Controller_U.FMS_Out.mode >= 3) {
      rtb_Atan_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_Atan_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      /* Product: '<S36>/Multiply' incorporates:
       *  Constant: '<S36>/kd'
       */
      u0_0 = CONTROL_PARAM.VEL_XY_D * rtb_k_pt_i_idx_0;
      rtb_Cos = CONTROL_PARAM.VEL_XY_D * rtb_k_pt_i_idx_1;

      /* Saturate: '<S36>/Saturation' */
      if (rtb_Cos > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_Cos = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_Cos < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_Cos = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Trigonometry: '<S31>/Atan' incorporates:
       *  Constant: '<S31>/Constant'
       *  Constant: '<S38>/kp'
       *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
       *  Gain: '<S31>/mass'
       *  Product: '<S31>/Divide'
       *  Product: '<S38>/Multiply'
       *  Sum: '<S33>/Add'
       */
      rtb_Atan_idx_1 = atanf(((CONTROL_PARAM.VEL_XY_P * rtb_TrigoFcn +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1]) + rtb_Cos) * 1.4F /
        9.806F);

      /* Saturate: '<S9>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }

      rtb_Atan_idx_0 = rtb_Atan_idx_1;

      /* Saturate: '<S36>/Saturation' incorporates:
       *  Trigonometry: '<S31>/Atan'
       */
      if (u0_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
        u0_0 = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (u0_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
          u0_0 = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Trigonometry: '<S31>/Atan' incorporates:
       *  Constant: '<S31>/Constant'
       *  Constant: '<S38>/kp'
       *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
       *  Gain: '<S31>/Gain1'
       *  Gain: '<S31>/mass'
       *  Product: '<S31>/Divide'
       *  Product: '<S38>/Multiply'
       *  Sum: '<S33>/Add'
       */
      rtb_Atan_idx_1 = atanf(-((CONTROL_PARAM.VEL_XY_P * rtb_TrigoFcn1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) + u0_0) * 1.4F /
        9.806F);

      /* Saturate: '<S9>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S25>/Switch' */
    rtb_Atan_idx_0 -= Controller_U.INS_Out.phi;

    /* Saturate: '<S12>/Saturation1' incorporates:
     *  Gain: '<S29>/Gain'
     *  Gain: '<S29>/Gain1'
     *  Gain: '<S29>/Gain2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S26>/Sum'
     *  Trigonometry: '<S29>/Tanh'
     */
    u0_0 = tanhf(CONTROL_PARAM.ROLL_P * rtb_Atan_idx_0) *
      CONTROL_PARAM.P_Q_CMD_LIM;
    rtb_Atan_idx_1 = tanhf((rtb_Atan_idx_1 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.PITCH_P) * CONTROL_PARAM.P_Q_CMD_LIM;
    if (rtb_Atan_idx_1 > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Atan_idx_1 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_Atan_idx_1 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_Atan_idx_1 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    /* Trigonometry: '<S15>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S15>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S15>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply4 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Product: '<S15>/Multiply3' */
    rtb_Multiply3 = rtb_Multiply4 * rtb_Cos1 * rtb_Saturation_m;

    /* Product: '<S15>/Multiply4' */
    rtb_Multiply4 *= rtb_Atan_idx_1;

    /* Saturate: '<S12>/Saturation1' */
    if (u0_0 > CONTROL_PARAM.P_Q_CMD_LIM) {
      u0_0 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (u0_0 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        u0_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    rtb_Atan_idx_0 = u0_0 - arm_sin_f32(Controller_U.INS_Out.theta) *
      rtb_Saturation_m;
    rtb_Atan_idx_1 = rtb_Cos * rtb_Atan_idx_1 + rtb_Multiply3;
    rtb_Saturation_m = rtb_Cos * rtb_Cos1 * rtb_Saturation_m - rtb_Multiply4;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = rtb_Atan_idx_0 - Controller_U.INS_Out.p;
  rtb_Multiply4 = rtb_Atan_idx_1 - Controller_U.INS_Out.q;
  rtb_Multiply3 = rtb_Saturation_m - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant_n[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant_n[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant_n[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_c != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2] = 0.0F;
  }

  /* Gain: '<S22>/k_pt' incorporates:
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator1'
   *  Sum: '<S22>/Sum5'
   */
  rtb_Atan_idx_0 = (rtb_Cos1 - Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0])
    * 50.0F;
  rtb_Atan_idx_1 = (rtb_Multiply4 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1]) * 50.0F;
  rtb_Saturation_m = (rtb_Multiply3 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2]) * 50.0F;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.state == 2) {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S41>/Constant1'
     *  Constant: '<S42>/Constant'
     *  Gain: '<S41>/Gain1'
     *  RelationalOperator: '<S42>/Compare'
     *  Sum: '<S41>/Sum1'
     */
    if (Controller_U.FMS_Out.mode >= 4) {
      rtb_Switch = Controller_U.FMS_Out.throttle_cmd;
    } else {
      /* Product: '<S46>/Multiply' incorporates:
       *  Constant: '<S46>/kd'
       */
      u0_0 = CONTROL_PARAM.VEL_Z_D * rtb_k_pt;

      /* Saturate: '<S46>/Saturation' */
      if (u0_0 > CONTROL_PARAM.VEL_Z_D_MAX) {
        u0_0 = CONTROL_PARAM.VEL_Z_D_MAX;
      } else {
        if (u0_0 < CONTROL_PARAM.VEL_Z_D_MIN) {
          u0_0 = CONTROL_PARAM.VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S46>/Saturation' */

      /* Sum: '<S45>/Add' incorporates:
       *  Constant: '<S48>/kp'
       *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
       *  Product: '<S48>/Multiply'
       */
      u0_0 += CONTROL_PARAM.VEL_Z_P * rtb_Gain +
        Controller_DW.DiscreteTimeIntegrator_DSTATE;

      /* Saturate: '<S6>/Saturation2' */
      if (u0_0 > 1.0F) {
        u0_0 = 1.0F;
      } else {
        if (u0_0 < -1.0F) {
          u0_0 = -1.0F;
        }
      }

      /* End of Saturate: '<S6>/Saturation2' */

      /* Saturate: '<S41>/Saturation' incorporates:
       *  Constant: '<S41>/hover_throttle'
       *  Sum: '<S41>/Sum'
       */
      if (u0_0 + 0.5F > 1.0F) {
        u0_0 = 1.0F;
      } else if (u0_0 + 0.5F < 0.0F) {
        u0_0 = 0.0F;
      } else {
        u0_0 += 0.5F;
      }

      /* End of Saturate: '<S41>/Saturation' */
      rtb_Switch = (uint32_T)fmodf(floorf(1000.0F * u0_0), 4.2949673E+9F) +
        1000U;
    }

    /* End of Switch: '<S40>/Switch' */

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Constant: '<S19>/gain1'
     *  Product: '<S19>/Multiply'
     */
    u0_0 = CONTROL_PARAM.ROLL_RATE_D * rtb_Atan_idx_0;
    if (u0_0 > CONTROL_PARAM.RATE_D_MAX) {
      u0_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (u0_0 < CONTROL_PARAM.RATE_D_MIN) {
        u0_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain1'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S17>/Add'
     */
    u0_0 += CONTROL_PARAM.ROLL_RATE_P * rtb_Cos1 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0];
    if (u0_0 > 1.0F) {
      u0_0 = 1.0F;
    } else {
      if (u0_0 < -1.0F) {
        u0_0 = -1.0F;
      }
    }

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Constant: '<S19>/gain2'
     *  Product: '<S19>/Multiply'
     */
    rtb_Cos = CONTROL_PARAM.PITCH_RATE_D * rtb_Atan_idx_1;
    if (rtb_Cos > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Cos = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Cos < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Cos = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain2'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S17>/Add'
     */
    rtb_Cos += CONTROL_PARAM.PITCH_RATE_P * rtb_Multiply4 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1];
    if (rtb_Cos > 1.0F) {
      rtb_Cos = 1.0F;
    } else {
      if (rtb_Cos < -1.0F) {
        rtb_Cos = -1.0F;
      }
    }

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Constant: '<S19>/gain3'
     *  Product: '<S19>/Multiply'
     */
    u0_1 = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_m;
    if (u0_1 > CONTROL_PARAM.RATE_D_MAX) {
      u0_1 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (u0_1 < CONTROL_PARAM.RATE_D_MIN) {
        u0_1 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain3'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S17>/Add'
     */
    u0_1 += CONTROL_PARAM.YAW_RATE_P * rtb_Multiply3 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2];
    if (u0_1 > 1.0F) {
      u0_1 = 1.0F;
    } else {
      if (u0_1 < -1.0F) {
        u0_1 = -1.0F;
      }
    }

    for (i = 0; i < 4; i++) {
      /* Saturate: '<S6>/Saturation' incorporates:
       *  Constant: '<S6>/X_Frame_Effective_Matrix'
       *  Gain: '<S6>/Gain'
       *  Product: '<S6>/Multiply'
       *  Sum: '<S6>/Add'
       */
      tmp = fmodf(floorf(1000.0F *
                         (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 8]
                          * u0_1 +
                          (Controller_ConstP.X_Frame_Effective_Matrix_Value[i +
                           4] * rtb_Cos +
                           Controller_ConstP.X_Frame_Effective_Matrix_Value[i] *
                           u0_0))), 65536.0F);
      u0 = (uint16_T)((uint32_T)(tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-tmp : (int32_T)(uint16_T)tmp) + (uint16_T)rtb_Switch);
      if (u0 > 2000) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 2000U;
      } else if (u0 < 1100) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 1100U;
      } else {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = u0;
      }

      /* End of Saturate: '<S6>/Saturation' */
    }

    /* Reshape: '<S6>/Reshape' */
    for (i = 0; i < 12; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Constant: '<S6>/Constant'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
    }
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S47>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S47>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.004F * rtb_k_pt;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S37>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S37>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_TrigoFcn1 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[0] += 0.004F * rtb_k_pt_i_idx_0;

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S37>/ki'
   *  Product: '<S37>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_TrigoFcn * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_d[1] += 0.004F * rtb_k_pt_i_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Cos1 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0] += 0.004F * rtb_Atan_idx_0;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain2'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += CONTROL_PARAM.PITCH_RATE_I
    * rtb_Multiply4 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1] += 0.004F * rtb_Atan_idx_1;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain3'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += CONTROL_PARAM.YAW_RATE_I *
    rtb_Multiply3 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2] += 0.004F * rtb_Saturation_m;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_c = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
    Controller_ConstB.Constant_n[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
    Controller_ConstB.Constant_n[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
    Controller_ConstB.Constant_n[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_c = 0;
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
