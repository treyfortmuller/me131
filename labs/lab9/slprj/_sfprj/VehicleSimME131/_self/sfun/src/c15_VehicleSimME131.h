#ifndef __c15_VehicleSimME131_h__
#define __c15_VehicleSimME131_h__

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_c15_emxArray_real_T
#define typedef_c15_emxArray_real_T

typedef struct emxArray_real_T c15_emxArray_real_T;

#endif                                 /*typedef_c15_emxArray_real_T*/

#ifndef typedef_c15_cell_wrap_0
#define typedef_c15_cell_wrap_0

typedef struct {
  c15_emxArray_real_T *f1;
} c15_cell_wrap_0;

#endif                                 /*typedef_c15_cell_wrap_0*/

#ifndef typedef_c15_emxArray_cell_wrap_0
#define typedef_c15_emxArray_cell_wrap_0

typedef struct {
  c15_cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c15_emxArray_cell_wrap_0;

#endif                                 /*typedef_c15_emxArray_cell_wrap_0*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_c15_emxArray_int32_T
#define typedef_c15_emxArray_int32_T

typedef struct emxArray_int32_T c15_emxArray_int32_T;

#endif                                 /*typedef_c15_emxArray_int32_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_c15_emxArray_boolean_T
#define typedef_c15_emxArray_boolean_T

typedef struct emxArray_boolean_T c15_emxArray_boolean_T;

#endif                                 /*typedef_c15_emxArray_boolean_T*/

#ifndef typedef_c15_cell_wrap_1
#define typedef_c15_cell_wrap_1

typedef struct {
  uint8_T f1[256000];
} c15_cell_wrap_1;

#endif                                 /*typedef_c15_cell_wrap_1*/

#ifndef typedef_c15_images_internal_coder_BoundaryFinder
#define typedef_c15_images_internal_coder_BoundaryFinder

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  real_T conn;
  int32_T numRows;
  int32_T numCols;
  real_T paddedLabelMatrix[258084];
  int32_T neighborOffsets[8];
  int32_T validationOffsets[8];
  int32_T nextDirectionLut[8];
  int32_T nextSearchDirectionLut[8];
  int32_T nextSearchDir;
  real_T startMarker;
  real_T boundaryMarker;
} c15_images_internal_coder_BoundaryFinder;

#endif                                 /*typedef_c15_images_internal_coder_BoundaryFinder*/

#ifndef typedef_c15_images_internal_coder_strel_StructuringElementHelper
#define typedef_c15_images_internal_coder_strel_StructuringElementHelper

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  boolean_T Neighborhood[9];
  real_T Dimensionality;
} c15_images_internal_coder_strel_StructuringElementHelper;

#endif                                 /*typedef_c15_images_internal_coder_strel_StructuringElementHelper*/

#ifndef typedef_SFc15_VehicleSimME131InstanceStruct
#define typedef_SFc15_VehicleSimME131InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_VehicleSimME131;
  c15_images_internal_coder_BoundaryFinder c15_finder;
  c15_images_internal_coder_BoundaryFinder c15_b_finder;
  real_T c15_dv0[258084];
  real_T c15_L[256000];
  real_T c15_labelMatrix[256000];
  real_T c15_dv1[258084];
  real_T c15_b_labelMatrix[256000];
  uint8_T c15_lanes[256000];
  uint8_T c15_varargin_1[256000];
  c15_cell_wrap_1 c15_args[1];
  c15_cell_wrap_1 c15_r0;
  boolean_T c15_BWcomplement[256000];
  boolean_T c15_b_BWcomplement[256000];
  boolean_T c15_BWholes[256000];
  boolean_T c15_paddedIm[258084];
  boolean_T c15_B[258084];
  boolean_T c15_borderlessIm[256000];
  uint8_T c15_u[256000];
  void *c15_fEmlrtCtx;
  uint8_T (*c15_b_lanes)[256000];
  real_T *c15_curvature;
} SFc15_VehicleSimME131InstanceStruct;

#endif                                 /*typedef_SFc15_VehicleSimME131InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_VehicleSimME131_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c15_VehicleSimME131_get_check_sum(mxArray *plhs[]);
extern void c15_VehicleSimME131_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
