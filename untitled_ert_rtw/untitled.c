/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sat Aug 17 01:11:25 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(untitled_DW.FunctionCallSubsystem_SubsysRan);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      real_T rtb_PulseGenerator;
      uint8_T rtb_PulseGenerator_p;

      /* Asynchronous task (with no priority assigned)
       * reads absolute time */
      switch (untitled_M->Timing.rtmDbBufWriteBuf1) {
       case 0:
        untitled_M->Timing.rtmDbBufReadBuf1 = 1;
        break;

       case 1:
        untitled_M->Timing.rtmDbBufReadBuf1 = 0;
        break;

       default:
        untitled_M->Timing.rtmDbBufReadBuf1 =
          untitled_M->Timing.rtmDbBufLastBufWr1;
        break;
      }

      untitled_M->Timing.clockTick1 = untitled_M->
        Timing.rtmDbBufClockTick1[untitled_M->Timing.rtmDbBufReadBuf1];
      untitled_M->Timing.rtmDbBufReadBuf1 = 0xFF;

      /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
      rtb_PulseGenerator = (untitled_DW.clockTickCounter <
                            untitled_P.PulseGenerator_Duty) &&
        (untitled_DW.clockTickCounter >= 0L) ? untitled_P.PulseGenerator_Amp :
        0.0;
      if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator_Period - 1.0)
      {
        untitled_DW.clockTickCounter = 0L;
      } else {
        untitled_DW.clockTickCounter++;
      }

      /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

      /* MATLABSystem: '<S2>/Digital Output' */
      if (untitled_DW.obj.Protocol != untitled_P.DigitalOutput_Protocol) {
        untitled_DW.obj.Protocol = untitled_P.DigitalOutput_Protocol;
      }

      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      if (rtb_PulseGenerator < 256.0) {
        if (rtb_PulseGenerator >= 0.0) {
          rtb_PulseGenerator_p = (uint8_T)rtb_PulseGenerator;
        } else {
          rtb_PulseGenerator_p = 0U;
        }
      } else {
        rtb_PulseGenerator_p = MAX_uint8_T;
      }

      /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

      /* MATLABSystem: '<S2>/Digital Output' */
      writeDigitalPin(12, rtb_PulseGenerator_p);
      untitled_DW.FunctionCallSubsystem_SubsysRan = 4;
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

/* Model step function */
void untitled_step(void)
{
  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
  switch (untitled_M->Timing.rtmDbBufReadBuf1) {
   case 0:
    untitled_M->Timing.rtmDbBufWriteBuf1 = 1;
    break;

   case 1:
    untitled_M->Timing.rtmDbBufWriteBuf1 = 0;
    break;

   default:
    untitled_M->Timing.rtmDbBufWriteBuf1 =
      !untitled_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  untitled_M->Timing.rtmDbBufClockTick1[untitled_M->Timing.rtmDbBufWriteBuf1] =
    untitled_M->Timing.clockTick0;
  untitled_M->Timing.rtmDbBufLastBufWr1 = untitled_M->Timing.rtmDbBufWriteBuf1;
  untitled_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1778878098U);
  untitled_M->Sizes.checksums[1] = (4165629009U);
  untitled_M->Sizes.checksums[2] = (4076947886U);
  untitled_M->Sizes.checksums[3] = (3576767642U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&untitled_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[2] = (sysRanDType *)&untitled_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  untitled_M->Timing.rtmDbBufReadBuf1 = 0xFF;
  untitled_M->Timing.rtmDbBufWriteBuf1 = 0xFF;
  untitled_M->Timing.rtmDbBufLastBufWr1 = 0;

  /* Start for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Start for function-call system: '<Root>/Function-Call Subsystem' */

  /* Start for MATLABSystem: '<S2>/Digital Output' */
  untitled_DW.obj.matlabCodegenIsDeleted = true;
  untitled_DW.obj.isInitialized = 0L;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.Protocol = untitled_P.DigitalOutput_Protocol;
  untitled_DW.obj.isSetupComplete = false;
  untitled_DW.obj.isInitialized = 1L;
  digitalIOSetup(12, true);
  untitled_DW.obj.isSetupComplete = true;

  /* Attach callback function */
  attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, CHANGE);

  /* End of Start for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

  /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* Asynchronous task (with no priority assigned)
   * reads absolute time */
  switch (untitled_M->Timing.rtmDbBufWriteBuf1) {
   case 0:
    untitled_M->Timing.rtmDbBufReadBuf1 = 1;
    break;

   case 1:
    untitled_M->Timing.rtmDbBufReadBuf1 = 0;
    break;

   default:
    untitled_M->Timing.rtmDbBufReadBuf1 = untitled_M->Timing.rtmDbBufLastBufWr1;
    break;
  }

  untitled_M->Timing.clockTick1 = untitled_M->
    Timing.rtmDbBufClockTick1[untitled_M->Timing.rtmDbBufReadBuf1];
  untitled_M->Timing.rtmDbBufReadBuf1 = 0xFF;

  /* InitializeConditions for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  untitled_DW.clockTickCounter = 0L;

  /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S2>/Digital Output' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);

  /* End of Terminate for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
