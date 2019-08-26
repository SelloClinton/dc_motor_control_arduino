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
<<<<<<< HEAD
 * C/C++ source code generated on : Fri Aug 23 15:47:56 2019
=======
 * C/C++ source code generated on : Fri Aug 23 23:39:26 2019
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void untitled_step(void)
{
  /* MATLABSystem: '<S1>/Digital Input' */
  if (untitled_DW.obj.SampleTime != untitled_P.DigitalInput_SampleTime) {
    untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
  }

  if (untitled_DW.obj.Protocol != untitled_P.DigitalInput_Protocol) {
    untitled_DW.obj.Protocol = untitled_P.DigitalInput_Protocol;
  }

<<<<<<< HEAD
  untitled_B.DigitalInput = readDigitalPin(2);
=======
  untitled_B.DigitalInput = readDigitalPin(8);
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02

  /* End of MATLABSystem: '<S1>/Digital Input' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

<<<<<<< HEAD
  {                                    /* Sample time: [0.001s, 0.0s] */
=======
  {                                    /* Sample time: [0.1s, 0.0s] */
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
<<<<<<< HEAD
  {                                    /* Sample time: [0.001s, 0.0s] */
=======
  {                                    /* Sample time: [0.1s, 0.0s] */
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02
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
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
<<<<<<< HEAD
  untitled_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (961826623U);
  untitled_M->Sizes.checksums[1] = (1566994674U);
  untitled_M->Sizes.checksums[2] = (35952765U);
  untitled_M->Sizes.checksums[3] = (397500069U);
=======
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (667418574U);
  untitled_M->Sizes.checksums[1] = (69652169U);
  untitled_M->Sizes.checksums[2] = (2937512211U);
  untitled_M->Sizes.checksums[3] = (2481937756U);
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

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

  /* Start for MATLABSystem: '<S1>/Digital Input' */
  untitled_DW.obj.matlabCodegenIsDeleted = true;
  untitled_DW.obj.isInitialized = 0L;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.DigitalInput_SampleTime;
  untitled_DW.obj.Protocol = untitled_P.DigitalInput_Protocol;
  untitled_DW.obj.isSetupComplete = false;
  untitled_DW.obj.isInitialized = 1L;
<<<<<<< HEAD
  digitalIOSetup(2, false);
=======
  digitalIOSetup(8, false);
>>>>>>> 6906ceb8d7f075b065c49c225d695a7e53900e02
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Input' */
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
