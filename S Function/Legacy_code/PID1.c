/**
 * PID1.c
 *
 *    ABSTRACT:
 *      The purpose of this sfunction is to call a simple legacy
 *      function during simulation:
 *
 *         double y1 = pid(double u1, double p1, double p2, double p3)
 *
 *    Simulink version           : 9.2 (R2018b) 24-May-2018
 *    C source code generated on : 30-Nov-2018 15:33:21
 *
 * THIS S-FUNCTION IS GENERATED BY THE LEGACY CODE TOOL AND MAY NOT WORK IF MODIFIED
 */

/**
     %%%-MATLAB_Construction_Commands_Start
     def = legacy_code('initialize');
     def.SFunctionName = 'PID1';
     def.OutputFcnSpec = 'double y1 = pid(double u1, double p1, double p2, double p3)';
     def.HeaderFiles = {'PIDC.h'};
     def.SourceFiles = {'PIDC.cpp'};
     legacy_code('sfcn_cmex_generate', def);
     legacy_code('compile', def);
     %%%-MATLAB_Construction_Commands_End
 */

/* Must specify the S_FUNCTION_NAME as the name of the S-function */
#define S_FUNCTION_NAME  PID1
#define S_FUNCTION_LEVEL 2

/**
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"

/* Specific header file(s) required by the legacy code function */
#include "PIDC.h"

#define EDIT_OK(S, P_IDX) \
       (!((ssGetSimMode(S)==SS_SIMMODE_SIZES_CALL_ONLY) && mxIsEmpty(ssGetSFcnParam(S, P_IDX))))


#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlCheckParameters ===========================================
 * Abstract:
 *   mdlCheckParameters verifies new parameter settings whenever parameter
 *   change or are re-evaluated during a simulation. When a simulation is
 *   running, changes to S-function parameters can occur at any time during
 *   the simulation loop.
 */
static void mdlCheckParameters(SimStruct *S)
{
    /* Check the parameter 1 */
    if (EDIT_OK(S, 0)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 0, "P1", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 2 */
    if (EDIT_OK(S, 1)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 1, "P2", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

    /* Check the parameter 3 */
    if (EDIT_OK(S, 2)) {
        int_T dimsArray[2] = {1, 1};

        /* Check the parameter attributes */
        ssCheckSFcnParamValueAttribs(S, 2, "P3", DYNAMICALLY_TYPED, 2, dimsArray, 0);
    } /* if */

}
#endif

#define MDL_PROCESS_PARAMETERS
#if defined(MDL_PROCESS_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlProcessParameters =========================================
 * Abstract:
 *   Update run-time parameters.
 */
static void mdlProcessParameters(SimStruct *S)
{
    ssUpdateAllTunableParamsAsRunTimeParams(S);
}
#endif

/* Function: mdlInitializeSizes ===========================================
 * Abstract:
 *   The sizes information is used by Simulink to determine the S-function
 *   block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{
    /* Number of expected parameters */
    ssSetNumSFcnParams(S, 3);

    #if defined(MATLAB_MEX_FILE) 
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        /**
         * If the number of expected input parameters is not equal
         * to the number of parameters entered in the dialog box return.
         * Simulink will generate an error indicating that there is a
         * parameter mismatch.
         */
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) return;
    } else {
        /* Return if number of expected != number of actual parameters */
        return;
    } /* if */
    #endif 

    /* Set the parameter's tunability */
    ssSetSFcnParamTunable(S, 0, 1);
    ssSetSFcnParamTunable(S, 1, 1);
    ssSetSFcnParamTunable(S, 2, 1);

    /* Set the number of work vectors */
    if (!ssSetNumDWork(S, 0)) return;
    ssSetNumPWork(S, 0);

    /* Set the number of input ports */
    if (!ssSetNumInputPorts(S, 1)) return;

    /* Configure the input port 1 */
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    {
        int_T u1Width = 1;
        ssSetInputPortWidth(S, 0, u1Width);
    }
    ssSetInputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortAcceptExprInRTW(S, 0, 1);
    ssSetInputPortOverWritable(S, 0, 1);
    ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetInputPortRequiredContiguous(S, 0, 1);

    /* Set the number of output ports */
    if (!ssSetNumOutputPorts(S, 1)) return;

    /* Configure the output port 1 */
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
    {
        int_T y1Width = 1;
        ssSetOutputPortWidth(S, 0, y1Width);
    }
    ssSetOutputPortComplexSignal(S, 0, COMPLEX_NO);
    ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
    ssSetOutputPortOutputExprInRTW(S, 0, 1);

    /* Register reserved identifiers to avoid name conflict */
    if (ssRTWGenIsCodeGen(S) || ssGetSimMode(S)==SS_SIMMODE_EXTERNAL) {

        /* Register reserved identifier for  */
        ssRegMdlInfo(S, "pid", MDL_INFO_ID_RESERVED, 0, 0, ssGetPath(S));
    } /* if */

    /* This S-function can be used in referenced model simulating in normal mode */
    ssSetModelReferenceNormalModeSupport(S, MDL_START_AND_MDL_PROCESS_PARAMS_OK);

    /* Set the number of sample time */
    ssSetNumSampleTimes(S, 1);

    /* Set the compliance with the SimState feature */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetArrayLayoutForCodeGen(S, SS_ALL);

    /* Set the Simulink version this S-Function has been generated in */
    ssSetSimulinkVersionGeneratedIn(S, "9.2");

    /**
     * All options have the form SS_OPTION_<name> and are documented in
     * matlabroot/simulink/include/simstruc.h. The options should be
     * bitwise or'd together as in
     *    ssSetOptions(S, (SS_OPTION_name1 | SS_OPTION_name2))
     */
    ssSetOptions(S,
        SS_OPTION_USE_TLC_WITH_ACCELERATOR |
        SS_OPTION_CAN_BE_CALLED_CONDITIONALLY |
        SS_OPTION_EXCEPTION_FREE_CODE |
        SS_OPTION_WORKS_WITH_CODE_REUSE |
        SS_OPTION_SFUNCTION_INLINED_FOR_RTW |
        SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
    );
}

/* Function: mdlInitializeSampleTimes =====================================
 * Abstract:
 *   This function is used to specify the sample time(s) for your
 *   S-function. You must register the same number of sample times as
 *   specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);

    #if defined(ssSetModelReferenceSampleTimeDefaultInheritance)
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    #endif
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)
/* Function: mdlSetWorkWidths =============================================
 * Abstract:
 *   The optional method, mdlSetWorkWidths is called after input port
 *   width, output port width, and sample times of the S-function have
 *   been determined to set any state and work vector sizes which are
 *   a function of the input, output, and/or sample times. 
 *   Run-time parameters are registered in this method using methods 
 *   ssSetNumRunTimeParams, ssSetRunTimeParamInfo, and related methods.
 */
static void mdlSetWorkWidths(SimStruct *S)
{
    /* Set number of run-time parameters */
    if (!ssSetNumRunTimeParams(S, 3)) return;

    /* Register the run-time parameter 1 */
    ssRegDlgParamAsRunTimeParam(S, 0, 0, "p1", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 2 */
    ssRegDlgParamAsRunTimeParam(S, 1, 1, "p2", ssGetDataTypeId(S, "double"));

    /* Register the run-time parameter 3 */
    ssRegDlgParamAsRunTimeParam(S, 2, 2, "p3", ssGetDataTypeId(S, "double"));
}
#endif

/* Function: mdlOutputs ===================================================
 * Abstract:
 *   In this function, you compute the outputs of your S-function
 *   block. Generally outputs are placed in the output vector(s),
 *   ssGetOutputPortSignal.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{

    /* Get access to Parameter/Input/Output/DWork data */
    real_T* y1 = (real_T*) ssGetOutputPortSignal(S, 0);
    real_T* u1 = (real_T*) ssGetInputPortSignal(S, 0);
    real_T* p1 = (real_T*) ssGetRunTimeParamInfo(S, 0)->data;
    real_T* p2 = (real_T*) ssGetRunTimeParamInfo(S, 1)->data;
    real_T* p3 = (real_T*) ssGetRunTimeParamInfo(S, 2)->data;


    /* Call the legacy code function */
    *y1 = pid(*u1, *p1, *p2, *p3);
}

/* Function: mdlTerminate =================================================
 * Abstract:
 *   In this function, you should perform any actions that are necessary
 *   at the termination of a simulation.
 */
static void mdlTerminate(SimStruct *S)
{
}

/* Required S-function trailer */
#ifdef    MATLAB_MEX_FILE
# include "simulink.c"
#else
# include "cg_sfun.h"
#endif

