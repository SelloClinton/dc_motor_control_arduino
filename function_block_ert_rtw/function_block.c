/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: function_block.c
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

#include "function_block.h"
#include "function_block_private.h"
#include "function_block_dt.h"

/* Block states (default storage) */
DW_function_block_T function_block_DW;

/* Real-time model */
RT_MODEL_function_block_T function_block_M_;
RT_MODEL_function_block_T *const function_block_M = &function_block_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCod_m(codertarget_arduinobase_blo_b_T *obj);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(function_block_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      boolean_T rtb_DigitalInput_p;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (function_block_M->Timing.rtmDbBufWriteBuf1) {
       case 0:
        function_block_M->Timing.rtmDbBufReadBuf1 = 1;
        break;

       case 1:
        function_block_M->Timing.rtmDbBufReadBuf1 = 0;
        break;

       default:
        function_block_M->Timing.rtmDbBufReadBuf1 =
          function_block_M->Timing.rtmDbBufLastBufWr1;
        break;
      }

      function_block_M->Timing.clockTick1 =
        function_block_M->Timing.rtmDbBufClockTick1
        [function_block_M->Timing.rtmDbBufReadBuf1];
      function_block_M->Timing.rtmDbBufReadBuf1 = 0xFF;

      /* MATLABSystem: '<S2>/Digital Input' */
      if (function_block_DW.obj.SampleTime !=
          function_block_P.DigitalInput_SampleTime) {
        function_block_DW.obj.SampleTime =
          function_block_P.DigitalInput_SampleTime;
      }

      if (function_block_DW.obj.Protocol !=
          function_block_P.DigitalInput_Protocol) {
        function_block_DW.obj.Protocol = function_block_P.DigitalInput_Protocol;
      }

      rtb_DigitalInput_p = readDigitalPin(3);

      /* MATLABSystem: '<S3>/Digital Output' incorporates:
       *  DataTypeConversion: '<S3>/Data Type Conversion'
       *  MATLABSystem: '<S2>/Digital Input'
       */
      if (function_block_DW.obj_j.Protocol !=
          function_block_P.DigitalOutput_Protocol) {
        function_block_DW.obj_j.Protocol =
          function_block_P.DigitalOutput_Protocol;
      }

      writeDigitalPin(13, (uint8_T)rtb_DigitalInput_p);

      /* End of MATLABSystem: '<S3>/Digital Output' */
      function_block_DW.FunctionCallSubsystem_SubsysRan = 4;
    }

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCod_m(codertarget_arduinobase_blo_b_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void function_block_step(void)
{
  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [1.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)function_block_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(function_block_M)!=-1) &&
        !((rtmGetTFinal(function_block_M)-function_block_M->Timing.taskTime0) >
          function_block_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(function_block_M, "Simulation finished");
    }

    if (rtmGetStopRequested(function_block_M)) {
      rtmSetErrorStatus(function_block_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  function_block_M->Timing.taskTime0 =
    (++function_block_M->Timing.clockTick0) * function_block_M->Timing.stepSize0;
  switch (function_block_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    function_block_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    function_block_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    function_block_M->Timing.rtmDbBufWriteBuf1 =
      !function_block_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  function_block_M->Timing.rtmDbBufClockTick1
    [function_block_M->Timing.rtmDbBufWriteBuf1] =
    function_block_M->Timing.clockTick0;
  function_block_M->Timing.rtmDbBufLastBufWr1 =
    function_block_M->Timing.rtmDbBufWriteBuf1;
  function_block_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void function_block_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)function_block_M, 0,
                sizeof(RT_MODEL_function_block_T));
  rtmSetTFinal(function_block_M, -1);
  function_block_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  function_block_M->Sizes.checksums[0] = (4006559081U);
  function_block_M->Sizes.checksums[1] = (3813541953U);
  function_block_M->Sizes.checksums[2] = (2583402690U);
  function_block_M->Sizes.checksums[3] = (1583792487U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    function_block_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &function_block_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[2] = (sysRanDType *)
      &function_block_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[3] = (sysRanDType *)
      &function_block_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)
      &function_block_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(function_block_M->extModeInfo,
      &function_block_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(function_block_M->extModeInfo,
                        function_block_M->Sizes.checksums);
    rteiSetTPtr(function_block_M->extModeInfo, rtmGetTPtr(function_block_M));
  }

  /* states (dwork) */
  (void) memset((void *)&function_block_DW, 0,
                sizeof(DW_function_block_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    function_block_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  function_block_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  function_block_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  function_block_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* Start for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Start for function-call system: '<Root>/Function-Call Subsystem' */

  /* Start for MATLABSystem: '<S2>/Digital Input' */
  function_block_DW.obj.matlabCodegenIsDeleted = true;
  function_block_DW.obj.isInitialized = 0L;
  function_block_DW.obj.matlabCodegenIsDeleted = false;
  function_block_DW.obj.SampleTime = function_block_P.DigitalInput_SampleTime;
  function_block_DW.obj.Protocol = function_block_P.DigitalInput_Protocol;
  function_block_DW.obj.isSetupComplete = false;
  function_block_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, false);
  function_block_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Digital Output' */
  function_block_DW.obj_j.matlabCodegenIsDeleted = true;
  function_block_DW.obj_j.isInitialized = 0L;
  function_block_DW.obj_j.matlabCodegenIsDeleted = false;
  function_block_DW.obj_j.Protocol = function_block_P.DigitalOutput_Protocol;
  function_block_DW.obj_j.isSetupComplete = false;
  function_block_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(13, true);
  function_block_DW.obj_j.isSetupComplete = true;
  pinMode(2, INPUT_PULLUP);

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

  /* End of Start for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/* Model terminate function */
void function_block_terminate(void)
{
  /* Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S2>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&function_block_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/Digital Output' */
  matlabCodegenHandle_matlabCod_m(&function_block_DW.obj_j);

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
