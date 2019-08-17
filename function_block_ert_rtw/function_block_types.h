/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: function_block_types.h
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

#ifndef RTW_HEADER_function_block_types_h_
#define RTW_HEADER_function_block_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  real_T Protocol;
} codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_codertarget_arduinobase_blo_b_T
#define typedef_codertarget_arduinobase_blo_b_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
} codertarget_arduinobase_blo_b_T;

#endif                               /*typedef_codertarget_arduinobase_blo_b_T*/

/* Parameters (default storage) */
typedef struct P_function_block_T_ P_function_block_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_function_block_T RT_MODEL_function_block_T;

#endif                                 /* RTW_HEADER_function_block_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
