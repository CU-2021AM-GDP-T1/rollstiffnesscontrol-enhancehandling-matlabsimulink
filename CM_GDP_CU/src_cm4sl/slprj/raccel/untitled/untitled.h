#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "untitled_types.h"
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME untitled
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (23) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T posjxokjpl ; real_T j40km4a2al ; real_T mwt0rbffiu ;
real_T ojnp3e5evq ; real_T hpveyrr4sr ; real_T phs4dw3rf1 ; real_T ndehh3qpqw
; real_T krat4dda10 ; real_T eb0e205xih ; real_T dnqjm5ob1g ; real_T
kbllboipo4 ; real_T oucjjpfycu ; real_T axg2quzprb ; real_T kz3ubmsynm ;
real_T lcwett1dl0 ; real_T hdb5byq0en ; real_T nney2i4pyw ; real_T a4iojocihb
; real_T msrl1jyfvp ; real_T jakzot2e02 ; real_T fdzcfoagnz ; real_T
lhavmgatqv ; boolean_T dr25zlggpf ; } B ; typedef struct { struct { void *
LoggedData ; } oysaf5b551 ; struct { void * LoggedData ; } dproym02o0 ;
uint32_T aevkk301sc ; int_T elksuwtwly ; boolean_T lmarfarffp ; } DW ;
typedef struct { real_T kliqtpn32m ; real_T gajpcm3ihl ; real_T c123eqimxb ;
} X ; typedef struct { real_T kliqtpn32m ; real_T gajpcm3ihl ; real_T
c123eqimxb ; } XDot ; typedef struct { boolean_T kliqtpn32m ; boolean_T
gajpcm3ihl ; boolean_T c123eqimxb ; } XDis ; typedef struct { real_T
kliqtpn32m ; real_T gajpcm3ihl ; real_T c123eqimxb ; } CStateAbsTol ; typedef
struct { real_T kliqtpn32m ; real_T gajpcm3ihl ; real_T c123eqimxb ; }
CXPtMin ; typedef struct { real_T kliqtpn32m ; real_T gajpcm3ihl ; real_T
c123eqimxb ; } CXPtMax ; typedef struct { real_T gfnxkzcnwz ; real_T
oqjbl5z3xp ; real_T pcay3eo0fg ; real_T nli1himvou ; } ZCV ; typedef struct {
ZCSigState a1cjbdru2w ; } PrevZCX ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T PIDController_D ; real_T
PIDController_I ; real_T PIDController_InitialConditionForFilter ; real_T
PIDController_InitialConditionForIntegrator ; real_T PIDController_N ; real_T
PIDController_P ; real_T Constant_Value ; real_T Constant4_Value ; real_T
Constant2_Value ; real_T uib2_Gain ; real_T HitCrossing_Offset ; real_T
Integrator_IC ; real_T Switch_Threshold ; real_T uDLookupTable_tableData [
2474 ] ; real_T uDLookupTable_bp01Data [ 2474 ] ; real_T
HitCrossing_Offset_a2t4evac2m ; real_T TurnofftheSW1_Value ; real_T
Switch_Threshold_avb0kjxnjb ; real_T repeat_Value ; real_T tFinal_Value ;
real_T VehicleMass_Value ; real_T WheelEffectiveRadiusm_Value ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_untitled_GetDWork ( ) ; extern void mr_untitled_SetDWork ( const mxArray *
ssDW ) ; extern mxArray * mr_untitled_GetSimStateDisallowedBlocks ( ) ;
extern const rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
