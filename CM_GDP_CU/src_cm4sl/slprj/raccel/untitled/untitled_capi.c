#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "untitled_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "untitled.h"
#include "untitled_capi.h"
#include "untitled_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"untitled/Integrator" ) , TARGET_STRING ( "Velocity (m/s)" ) , 0 , 0 , 0 , 0
, 0 } , { 1 , 0 , TARGET_STRING ( "untitled/Divide1" ) , TARGET_STRING (
"Acceleration (mps2)" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"untitled/Product1" ) , TARGET_STRING ( "Force (N)" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 3 , 0 , TARGET_STRING ( "untitled/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 4 , 0 , TARGET_STRING ( "untitled/Switch" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Data Type Conversion" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 2 } , { 6 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 7 , 0 , TARGET_STRING (
"untitled/Drive Cycle Source/Signal Routing/UnitConversion" ) , TARGET_STRING
( "Reference Speed" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/Digital Clock" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 9 , 0 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/Add1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/Switch" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"untitled/PID Controller/D Gain/Internal Parameters/Derivative Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"untitled/PID Controller/Filter/Cont. Filter/Filter" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"untitled/PID Controller/Filter/Cont. Filter/SumD" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"untitled/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"untitled/PID Controller/Integrator/Continuous/Integrator" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"untitled/PID Controller/N Gain/Internal Parameters/Filter Coefficient" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"untitled/PID Controller/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"untitled/PID Controller/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 20 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 21 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 23 , TARGET_STRING ( "untitled/PID Controller" )
, TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"untitled/PID Controller" ) , TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 25 ,
TARGET_STRING ( "untitled/PID Controller" ) , TARGET_STRING ( "D" ) , 0 , 0 ,
0 } , { 26 , TARGET_STRING ( "untitled/PID Controller" ) , TARGET_STRING (
"N" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING ( "untitled/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 28 ,
TARGET_STRING ( "untitled/PID Controller" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"untitled/Turn off the SW1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
30 , TARGET_STRING ( "untitled/Vehicle Mass" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 31 , TARGET_STRING ( "untitled/Wheel Effective Radius (m)" )
, TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"untitled/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 }
, { 33 , TARGET_STRING ( "untitled/Switch" ) , TARGET_STRING ( "Threshold" )
, 0 , 0 , 0 } , { 34 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Compare To Zero/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/repeat" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/tFinal" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/1-D Lookup Table" ) ,
TARGET_STRING ( "Table" ) , 0 , 1 , 0 } , { 39 , TARGET_STRING (
"untitled/Drive Cycle Source/Timing Mode/Continuous/1-D Lookup Table" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 1 , 0 } , { 40 ,
TARGET_STRING ( "untitled/Drive Cycle Source/Timing Mode/Continuous/Switch" )
, TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/1\\ib2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"untitled/PWM Generator (DC-DC)/Sawtooth Generator/Model/Hit  Crossing" ) ,
TARGET_STRING ( "HitCrossingOffset" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . phs4dw3rf1 , & rtB . a4iojocihb ,
& rtB . nney2i4pyw , & rtB . eb0e205xih , & rtB . lhavmgatqv , & rtB .
hpveyrr4sr , & rtB . ojnp3e5evq , & rtB . krat4dda10 , & rtB . msrl1jyfvp , &
rtB . jakzot2e02 , & rtB . ndehh3qpqw , & rtB . oucjjpfycu , & rtB .
axg2quzprb , & rtB . kz3ubmsynm , & rtB . fdzcfoagnz , & rtB . kbllboipo4 , &
rtB . lcwett1dl0 , & rtB . dnqjm5ob1g , & rtB . hdb5byq0en , & rtB .
j40km4a2al , & rtB . posjxokjpl , & rtB . mwt0rbffiu , & rtB . dr25zlggpf , &
rtP . PIDController_P , & rtP . PIDController_I , & rtP . PIDController_D , &
rtP . PIDController_N , & rtP . PIDController_InitialConditionForIntegrator ,
& rtP . PIDController_InitialConditionForFilter , & rtP . TurnofftheSW1_Value
, & rtP . VehicleMass_Value , & rtP . WheelEffectiveRadiusm_Value , & rtP .
Integrator_IC , & rtP . Switch_Threshold_avb0kjxnjb , & rtP . Constant_Value
, & rtP . repeat_Value , & rtP . tFinal_Value , & rtP .
HitCrossing_Offset_a2t4evac2m , & rtP . uDLookupTable_tableData [ 0 ] , & rtP
. uDLookupTable_bp01Data [ 0 ] , & rtP . Switch_Threshold , & rtP .
Constant2_Value , & rtP . Constant4_Value , & rtP . uib2_Gain , & rtP .
HitCrossing_Offset , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) }
;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 2474 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , 0.5 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
4 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 2 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 3 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 23 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 22 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2992278952U , 3842139681U , 2160823228U , 1665553614U } , ( NULL ) , 0 ,
0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo *
untitled_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void untitled_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void untitled_host_InitializeDataMapInfo ( untitled_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
