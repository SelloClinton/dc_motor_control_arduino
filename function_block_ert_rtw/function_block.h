/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: function_block.h
 *
 * Code generated for Simulink model 'function_block'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sat Aug 17 12:15:26 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_function_block_h_
#define RTW_HEADER_function_block_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef function_block_COMMON_INCLUDES_
# define function_block_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* function_block_COMMON_INCLUDES_ */

#include "function_block_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S2>/Digital Input' */
  codertarget_arduinobase_blo_b_T obj_j;/* '<S3>/Digital Output' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_function_block_T;

/* Parameters (default storage) */
struct P_function_block_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S2>/Digital Input'
                                        */
  real_T DigitalInput_Protocol;        /* Expression: 0
                                        * Referenced by: '<S2>/Digital Input'
                                        */
  real_T DigitalOutput_Protocol;       /* Expression: 0
                                        * Referenced by: '<S3>/Digital Output'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_function_block_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint8_T rtmDbBufReadBuf1;
    uint8_T rtmDbBufWriteBuf1;
    boolean_T rtmDbBufLastBufWr1;
    uint32_T rtmDbBufClockTick1[2];
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_function_block_T function_block_P;

/* Block states (default storage) */
extern DW_function_block_T function_block_DW;

/* Model entry point functions */
extern void function_block_initialize(void);
extern void function_block_step(void);
extern void function_block_terminate(void);

/* Real-time Model object */
extern RT_MODEL_function_block_T *const function_block_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'function_block'
 * '<S1>'   : 'function_block/Function-Call Subsystem'
 * '<S2>'   : 'function_block/Function-Call Subsystem/Digital Input'
 * '<S3>'   : 'function_block/Function-Call Subsystem/Digital Output'
 * '<S4>'   : 'function_block/Function-Call Subsystem/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_function_block_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
