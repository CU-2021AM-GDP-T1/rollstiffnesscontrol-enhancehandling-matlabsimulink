#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include <math.h>
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , & stopRequested ) ; }
rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes
( SimStruct * S , const char * inportFileName , int * matFileFormat ) {
return rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; real_T look1_pbinlcapw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) { real_T frac ; real_T y ; real_T yL_0d0 ; uint32_T bpIdx
; uint32_T found ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] )
{ bpIdx = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx =
prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found
== 0U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( ( bpIdx
+ iLeft ) - 1U ) >> 1U ; } else if ( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ;
} else { iLeft = bpIdx + 1U ; bpIdx = ( ( bpIdx + iRght ) + 1U ) >> 1U ; } }
frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; }
else { bpIdx = maxIndex ; frac = 0.0 ; } prevIndex [ 0U ] = bpIdx ; if (
bpIdx == maxIndex ) { y = table [ bpIdx ] ; } else { yL_0d0 = table [ bpIdx ]
; y = ( table [ bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } return y ; } void
MdlInitialize ( void ) { rtX . kliqtpn32m = rtP . Integrator_IC ; rtX .
gajpcm3ihl = rtP . PIDController_InitialConditionForIntegrator ; rtX .
c123eqimxb = rtP . PIDController_InitialConditionForFilter ; } void MdlStart
( void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T bb5n4erdio ;
boolean_T apz3h405iw ; ZCEventType zcEvent ; if ( ssIsSampleHit ( rtS , 1 , 0
) ) { apz3h405iw = ( rtB . lhavmgatqv != rtP . Constant_Value ) ; rtB .
posjxokjpl = rtP . Constant4_Value ; rtB . j40km4a2al = rtP . Constant2_Value
; } rtB . mwt0rbffiu = muDoubleScalarRem ( ssGetT ( rtS ) + rtB . posjxokjpl
, rtB . j40km4a2al ) * rtP . uib2_Gain ; rtB . ojnp3e5evq = ( ( 2.0 * rtB .
mwt0rbffiu - 1.0 ) + 1.0 ) * 0.5 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . lmarfarffp = ( rtB . lhavmgatqv >= rtB
. ojnp3e5evq ) ; } rtB . hpveyrr4sr = ( apz3h405iw && rtDW . lmarfarffp ) ;
zcEvent = rt_ZCFcn ( ANY_ZERO_CROSSING , & rtPrevZCX . a1cjbdru2w , ( rtB .
mwt0rbffiu - rtP . HitCrossing_Offset ) ) ; if ( rtDW . elksuwtwly == 0 ) {
if ( zcEvent != NO_ZCEVENT ) { rtB . dr25zlggpf = ! rtB . dr25zlggpf ; rtDW .
elksuwtwly = 1 ; } else if ( rtB . dr25zlggpf ) { rtB . dr25zlggpf = ( ( ! (
rtB . mwt0rbffiu != rtP . HitCrossing_Offset ) ) && rtB . dr25zlggpf ) ; }
else { rtB . dr25zlggpf = ( ( rtB . mwt0rbffiu == rtP . HitCrossing_Offset )
|| rtB . dr25zlggpf ) ; } } else { rtB . dr25zlggpf = ( ( ! ( rtB .
mwt0rbffiu != rtP . HitCrossing_Offset ) ) && rtB . dr25zlggpf ) ; rtDW .
elksuwtwly = 0 ; } } rtB . phs4dw3rf1 = rtX . kliqtpn32m ; bb5n4erdio =
ssGetT ( rtS ) ; if ( rtP . repeat_Value > rtP . Switch_Threshold ) { rtB .
ndehh3qpqw = muDoubleScalarMod ( bb5n4erdio , rtP . tFinal_Value ) ; } else {
rtB . ndehh3qpqw = bb5n4erdio ; } rtB . krat4dda10 = look1_pbinlcapw ( rtB .
ndehh3qpqw , rtP . uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , &
rtDW . aevkk301sc , 2473U ) ; rtB . eb0e205xih = rtB . krat4dda10 - rtB .
phs4dw3rf1 ; rtB . dnqjm5ob1g = rtP . PIDController_P * rtB . eb0e205xih ;
rtB . kbllboipo4 = rtX . gajpcm3ihl ; rtB . oucjjpfycu = rtP .
PIDController_D * rtB . eb0e205xih ; rtB . axg2quzprb = rtX . c123eqimxb ;
rtB . kz3ubmsynm = rtB . oucjjpfycu - rtB . axg2quzprb ; rtB . lcwett1dl0 =
rtP . PIDController_N * rtB . kz3ubmsynm ; rtB . hdb5byq0en = ( rtB .
dnqjm5ob1g + rtB . kbllboipo4 ) + rtB . lcwett1dl0 ; rtB . nney2i4pyw = rtB .
hdb5byq0en * rtP . WheelEffectiveRadiusm_Value ; rtB . a4iojocihb = rtB .
nney2i4pyw / rtP . VehicleMass_Value ; if ( ssIsSampleHit ( rtS , 3 , 0 ) ) {
rtB . msrl1jyfvp = ssGetTaskTime ( rtS , 3 ) ; } rtB . jakzot2e02 =
bb5n4erdio - rtB . msrl1jyfvp ; rtB . fdzcfoagnz = rtP . PIDController_I *
rtB . eb0e205xih ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T
tid ) { if ( 0.0 > rtP . Switch_Threshold_avb0kjxnjb ) { rtB . lhavmgatqv = (
rtNaN ) ; } else { rtB . lhavmgatqv = rtP . TurnofftheSW1_Value ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID4 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> kliqtpn32m = rtB . a4iojocihb ; _rtXdot ->
gajpcm3ihl = rtB . fdzcfoagnz ; _rtXdot -> c123eqimxb = rtB . lcwett1dl0 ; }
void MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV *
_rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV
-> gfnxkzcnwz = rtB . lhavmgatqv - rtB . ojnp3e5evq ; _rtZCSV -> oqjbl5z3xp =
rtB . mwt0rbffiu - rtP . HitCrossing_Offset ; if ( rtDW . elksuwtwly == 0 ) {
_rtZCSV -> pcay3eo0fg = ( ( rtB . mwt0rbffiu - rtP . HitCrossing_Offset ) * (
real_T ) rtB . dr25zlggpf != 0.0 ) ; } else { _rtZCSV -> pcay3eo0fg = ssGetT
( rtS ) - ssGetTimeOfLastOutput ( rtS ) ; } _rtZCSV -> nli1himvou = rtB .
jakzot2e02 - rtP . HitCrossing_Offset_a2t4evac2m ; } void MdlTerminate ( void
) { } static void mr_untitled_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_untitled_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_untitled_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_untitled_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_untitled_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_untitled_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_untitled_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_untitled_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_untitled_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix
( 1 , 1 , 3 , ssDWFieldNames ) ; mr_untitled_cacheDataAsMxArray ( ssDW , 0 ,
0 , ( const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 3 ] = { "rtDW.aevkk301sc" , "rtDW.elksuwtwly" ,
"rtDW.lmarfarffp" , } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 3
, rtdwDataFieldNames ) ; mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 0 ,
( const void * ) & ( rtDW . aevkk301sc ) , sizeof ( rtDW . aevkk301sc ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. elksuwtwly ) , sizeof ( rtDW . elksuwtwly ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. lmarfarffp ) , sizeof ( rtDW . lmarfarffp ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } mr_untitled_cacheDataAsMxArray ( ssDW , 0 , 2 , (
const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; }
void mr_untitled_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . aevkk301sc
) , rtdwData , 0 , 0 , sizeof ( rtDW . aevkk301sc ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . elksuwtwly ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . elksuwtwly ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . lmarfarffp ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . lmarfarffp ) ) ; }
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0 ,
2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_untitled_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 2 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 2 ] = { "Scope" , "Scope" , } ; static const char *
blockPath [ 2 ] = { "untitled/Scope" , "untitled/Scope1" , } ; static const
int reason [ 2 ] = { 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 2 ; ++ (
subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 ,
subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ]
] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 3 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 4 ) ; ssSetNumBlocks ( rtS , 44 ) ;
ssSetNumBlockIO ( rtS , 23 ) ; ssSetNumBlockParams ( rtS , 4968 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.0001 ) ;
ssSetSampleTime ( rtS , 3 , 0.5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2992278952U ) ; ssSetChecksumVal ( rtS , 1 ,
3842139681U ) ; ssSetChecksumVal ( rtS , 2 , 2160823228U ) ; ssSetChecksumVal
( rtS , 3 , 1665553614U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 15 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
untitled_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "untitled" ) ; ssSetPath
( rtS , "untitled" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 200.0
) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "untitled/Integrator" ,
"untitled/PID Controller/Integrator/Continuous/Integrator" ,
"untitled/PID Controller/Filter/Cont. Filter/Filter" } ; static const char_T
* rt_LoggedStateNames [ ] = { "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . kliqtpn32m ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . gajpcm3ihl ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . c123eqimxb ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ;
static real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 3 ] = { 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 3 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 3 ] ; static uint8_T zcAttributes [ 4 ] = {
( ZC_EVENT_ALL ) , ( 0x80 | ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL_DN ) } ; { int i ; for ( i = 0 ; i < 3 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.0001
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 4 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . a1cjbdru2w = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 2992278952U ) ; ssSetChecksumVal ( rtS , 1 , 3842139681U ) ;
ssSetChecksumVal ( rtS , 2 , 2160823228U ) ; ssSetChecksumVal ( rtS , 3 ,
1665553614U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_untitled_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_untitled_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_untitled_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 4 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID4 ( tid ) ; }
