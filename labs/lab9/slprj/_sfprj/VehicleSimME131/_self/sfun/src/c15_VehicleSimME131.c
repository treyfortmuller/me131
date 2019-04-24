/* Include files */

#include "VehicleSimME131_sfun.h"
#include "c15_VehicleSimME131.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "VehicleSimME131_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c15_debug_family_names[9] = { "edges", "x", "k", "right",
  "left", "nargin", "nargout", "lanes", "curvature" };

static emlrtRTEInfo c15_emlrtRTEI = { 152,/* lineNo */
  9,                                   /* colNo */
  "bwboundaries",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\bwboundaries.m"/* pName */
};

static emlrtRTEInfo c15_b_emlrtRTEI = { 277,/* lineNo */
  9,                                   /* colNo */
  "bwboundaries",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\bwboundaries.m"/* pName */
};

static emlrtRTEInfo c15_c_emlrtRTEI = { 280,/* lineNo */
  9,                                   /* colNo */
  "bwboundaries",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\bwboundaries.m"/* pName */
};

static emlrtRTEInfo c15_d_emlrtRTEI = { 17,/* lineNo */
  13,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_e_emlrtRTEI = { 8,/* lineNo */
  13,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_f_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_g_emlrtRTEI = { 19,/* lineNo */
  17,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_h_emlrtRTEI = { 12,/* lineNo */
  21,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_i_emlrtRTEI = { 9,/* lineNo */
  17,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_j_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_k_emlrtRTEI = { 9,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_l_emlrtRTEI = { 10,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_m_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_n_emlrtRTEI = { 23,/* lineNo */
  19,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_o_emlrtRTEI = { 23,/* lineNo */
  30,                                  /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_p_emlrtRTEI = { 20,/* lineNo */
  5,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_q_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_r_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_s_emlrtRTEI = { 3,/* lineNo */
  1,                                   /* colNo */
  "MATLAB Function14",                 /* fName */
  "#VehicleSimME131:158"               /* pName */
};

static emlrtRTEInfo c15_t_emlrtRTEI = { 142,/* lineNo */
  2,                                   /* colNo */
  "bwboundaries",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\bwboundaries.m"/* pName */
};

static emlrtRTEInfo c15_u_emlrtRTEI = { 145,/* lineNo */
  6,                                   /* colNo */
  "bwboundaries",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\bwboundaries.m"/* pName */
};

static emlrtRTEInfo c15_v_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_w_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pName */
};

static emlrtRTEInfo c15_x_emlrtRTEI = { 38,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_y_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_ab_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_bb_emlrtRTEI = { 1,/* lineNo */
  31,                                  /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pName */
};

static emlrtRTEInfo c15_cb_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_db_emlrtRTEI = { 44,/* lineNo */
  1,                                   /* colNo */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\eml\\bwlabel.m"/* pName */
};

static emlrtRTEInfo c15_eb_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_fb_emlrtRTEI = { 51,/* lineNo */
  57,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_gb_emlrtRTEI = { 51,/* lineNo */
  64,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_hb_emlrtRTEI = { 114,/* lineNo */
  55,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pName */
};

static emlrtRTEInfo c15_ib_emlrtRTEI = { 46,/* lineNo */
  22,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_jb_emlrtRTEI = { 59,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_kb_emlrtRTEI = { 76,/* lineNo */
  40,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_lb_emlrtRTEI = { 183,/* lineNo */
  24,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_mb_emlrtRTEI = { 77,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_nb_emlrtRTEI = { 380,/* lineNo */
  30,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_ob_emlrtRTEI = { 151,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_pb_emlrtRTEI = { 151,/* lineNo */
  30,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_qb_emlrtRTEI = { 76,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_rb_emlrtRTEI = { 112,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c15_sb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "flip",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2018a\\toolbox\\eml\\lib\\matlab\\elmat\\flip.m"/* pName */
};

static const char_T c15_cv0[33] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w',
  'b', 'o', 'u', 'n', 'd', 'a', 'r', 'i', 'e', 's', ':', 'b', 'a', 'd', 'S', 'c',
  'a', 'l', 'a', 'r', 'C', 'o', 'n', 'n' };

/* Function Declarations */
static void initialize_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void initialize_params_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance);
static void enable_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void disable_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void c15_update_debugger_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance);
static void set_sim_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance, const mxArray *c15_st);
static void finalize_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void sf_gateway_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void mdl_start_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void initSimStructsc15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid,
  c15_emxArray_cell_wrap_0 *c15_inData);
static void c15_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_cell_wrap_0 *c15_y);
static void c15_b_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_real_T *c15_y);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, c15_emxArray_cell_wrap_0
  *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_c_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_x, const char_T *c15_identifier);
static real_T c15_d_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c15_inData_data[], int32_T c15_inData_size[1]);
static void c15_e_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y_data[], int32_T c15_y_size[1]);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, real_T c15_outData_data[],
  int32_T c15_outData_size[1]);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid,
  c15_emxArray_real_T *c15_inData);
static void c15_f_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_real_T *c15_y);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, c15_emxArray_real_T
  *c15_outData);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_bwlabel(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], real_T c15_b_L[256000]);
static void c15_check_forloop_overflow_error(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, boolean_T c15_overflow);
static void c15_padarray(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  real_T c15_b_varargin_1[256000], real_T c15_b[258084]);
static void c15_BoundaryFinder_findBoundaries
  (SFc15_VehicleSimME131InstanceStruct *chartInstance,
   c15_images_internal_coder_BoundaryFinder *c15_obj, c15_emxArray_cell_wrap_0
   *c15_b_B);
static void c15_error(SFc15_VehicleSimME131InstanceStruct *chartInstance);
static void c15_imclearborder(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], boolean_T c15_outputImage[256000]);
static void c15_b_padarray(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b[258084]);
static void c15_b_bwlabel(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], real_T c15_b_L[256000]);
static c15_images_internal_coder_BoundaryFinder
  *c15_BoundaryFinder_BoundaryFinder(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_images_internal_coder_BoundaryFinder *c15_obj, real_T
  c15_c_labelMatrix[256000]);
static void c15_flip(SFc15_VehicleSimME131InstanceStruct *chartInstance,
                     c15_emxArray_real_T *c15_x, c15_emxArray_real_T *c15_b_x);
static real_T c15_mean(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  real_T c15_x_data[], int32_T c15_x_size[1]);
static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_g_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_h_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_VehicleSimME131, const
  char_T *c15_identifier);
static uint8_T c15_i_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_BoundaryFinder_BoundaryFinder
  (SFc15_VehicleSimME131InstanceStruct *chartInstance,
   c15_images_internal_coder_BoundaryFinder **c15_obj, real_T c15_c_labelMatrix
   [256000]);
static void c15_b_flip(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  c15_emxArray_real_T *c15_x);
static void c15_emxFree_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray);
static void c15_emxFreeStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_pStruct);
static void c15_emxTrim_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 *c15_emxArray, int32_T c15_fromIndex,
  int32_T c15_toIndex);
static void c15_emxInitStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_pStruct, const emlrtRTEInfo
  *c15_srcLocation);
static void c15_emxInit_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray, int32_T c15_numDimensions,
  const emlrtRTEInfo *c15_srcLocation);
static void c15_emxExpand_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 *c15_emxArray, int32_T c15_fromIndex,
  int32_T c15_toIndex, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxEnsureCapacity_cell_wrap_0
  (SFc15_VehicleSimME131InstanceStruct *chartInstance, c15_emxArray_cell_wrap_0 *
   c15_emxArray, int32_T c15_oldNumel, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxEnsureCapacity_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T *c15_emxArray, int32_T c15_oldNumel, const
  emlrtRTEInfo *c15_srcLocation);
static void c15_emxEnsureCapacity_real_T1(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T *c15_emxArray, int32_T c15_oldNumel, const
  emlrtRTEInfo *c15_srcLocation);
static void c15_emxInit_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxInit_real_T1(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray, int32_T c15_numDimensions,
  const emlrtRTEInfo *c15_srcLocation);
static void c15_emxFree_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 **c15_pEmxArray);
static void c15_emxCopyStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_dst, const c15_cell_wrap_0 *c15_src,
  const emlrtRTEInfo *c15_srcLocation);
static void c15_emxCopy_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_dst, c15_emxArray_real_T * const
  *c15_src, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxEnsureCapacity_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T *c15_emxArray, int32_T c15_oldNumel,
  const emlrtRTEInfo *c15_srcLocation);
static void c15_emxInit_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxFree_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T **c15_pEmxArray);
static void c15_emxEnsureCapacity_boolean_T(SFc15_VehicleSimME131InstanceStruct *
  chartInstance, c15_emxArray_boolean_T *c15_emxArray, int32_T c15_oldNumel,
  const emlrtRTEInfo *c15_srcLocation);
static void c15_emxInit_boolean_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_boolean_T **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation);
static void c15_emxFree_boolean_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_boolean_T **c15_pEmxArray);
static int32_T c15_div_s32(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  int32_T c15_numerator, int32_T c15_denominator, uint32_T c15_ssid_src_loc,
  int32_T c15_offset_src_loc, int32_T c15_length_src_loc);
static void init_dsm_address_info(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc15_VehicleSimME131InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  emlrtLicenseCheckR2012b(chartInstance->c15_fEmlrtCtx, "Image_Toolbox", 2);
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc15_VehicleSimME131(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c15_is_active_c15_VehicleSimME131 = 0U;
}

static void initialize_params_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c15_update_debugger_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  const mxArray *c15_b_y = NULL;
  uint8_T c15_b_hoistedGlobal;
  const mxArray *c15_c_y = NULL;
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellmatrix(2, 1), false);
  c15_hoistedGlobal = *chartInstance->c15_curvature;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = chartInstance->c15_is_active_c15_VehicleSimME131;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y, false);
  return c15_st;
}

static void set_sim_state_c15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_b_u;
  chartInstance->c15_doneDoubleBufferReInit = true;
  c15_b_u = sf_mex_dup(c15_st);
  *chartInstance->c15_curvature = c15_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c15_b_u, 0)), "curvature");
  chartInstance->c15_is_active_c15_VehicleSimME131 = c15_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_b_u, 1)),
     "is_active_c15_VehicleSimME131");
  sf_mex_destroy(&c15_b_u);
  c15_update_debugger_state_c15_VehicleSimME131(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  c15_emxArray_cell_wrap_0 *c15_edges;
  c15_emxArray_real_T *c15_left;
  int32_T c15_i0;
  int32_T c15_i1;
  uint32_T c15_debug_family_var_map[9];
  real_T c15_x;
  real_T c15_k;
  real_T c15_right_data[100];
  int32_T c15_right_size[1];
  real_T c15_nargin = 1.0;
  real_T c15_nargout = 1.0;
  real_T c15_b_curvature;
  int32_T c15_i2;
  int32_T c15_i3;
  int32_T c15_i4;
  int32_T c15_i5;
  int32_T c15_i6;
  c15_images_internal_coder_BoundaryFinder *c15_obj;
  c15_images_internal_coder_BoundaryFinder *c15_b_obj;
  c15_images_internal_coder_BoundaryFinder *c15_this;
  int32_T c15_i7;
  c15_emxArray_cell_wrap_0 *c15_objs;
  boolean_T c15_b_u;
  const mxArray *c15_y = NULL;
  const mxArray *c15_b_y = NULL;
  int32_T c15_i8;
  c15_emxArray_cell_wrap_0 *c15_holes;
  c15_emxArray_cell_wrap_0 *c15_r1;
  real_T c15_N;
  real_T c15_M;
  int32_T c15_b_N[2];
  int32_T c15_i9;
  int32_T c15_i10;
  int32_T c15_i11;
  int32_T c15_b_k;
  real_T c15_c_k;
  int32_T c15_i12;
  int32_T c15_i13;
  int32_T c15_d_k;
  int32_T c15_i14;
  int32_T c15_i15;
  int32_T c15_i16;
  real_T c15_b_x;
  int32_T c15_i17;
  int32_T c15_b_edges;
  int32_T c15_c_edges;
  int32_T c15_i18;
  int32_T c15_d_edges;
  int32_T c15_e_edges;
  c15_emxArray_real_T *c15_r2;
  int32_T c15_f_edges;
  c15_emxArray_real_T *c15_r3;
  int32_T c15_g_edges;
  int32_T c15_loop_ub;
  int32_T c15_h_edges;
  int32_T c15_i19;
  int32_T c15_i_edges;
  int32_T c15_j_edges;
  int32_T c15_i20;
  int32_T c15_i21;
  int32_T c15_k_edges;
  int32_T c15_b_loop_ub;
  int32_T c15_i22;
  int32_T c15_i23;
  int32_T c15_i24;
  int32_T c15_i25;
  int32_T c15_i26;
  int32_T c15_c_loop_ub;
  int32_T c15_d_loop_ub;
  int32_T c15_i27;
  int32_T c15_i28;
  int32_T c15_i29;
  int32_T c15_i30;
  int32_T c15_i31;
  int32_T c15_i32;
  real_T c15_c_y;
  real_T c15_b_left[100];
  int32_T c15_e_k;
  int32_T c15_i33;
  real_T c15_A;
  int32_T c15_xoffset;
  real_T c15_c_x;
  int32_T c15_ix;
  real_T c15_d_x;
  int32_T c15_i34;
  real_T c15_d0;
  int32_T c15_i35;
  int32_T c15_e_loop_ub;
  int32_T c15_i36;
  int32_T c15_i37;
  int32_T c15_i38;
  int32_T c15_i39;
  int32_T c15_i40;
  int32_T c15_i41;
  int32_T c15_i42;
  int32_T c15_i43;
  int32_T c15_i44;
  int32_T c15_f_loop_ub;
  int32_T c15_g_loop_ub;
  int32_T c15_h_loop_ub;
  int32_T c15_i45;
  int32_T c15_i46;
  int32_T c15_i47;
  int32_T c15_i48;
  int32_T c15_i49;
  int32_T c15_i50;
  int32_T c15_i51;
  int32_T c15_i52;
  int32_T c15_i_loop_ub;
  int32_T c15_j_loop_ub;
  int32_T c15_i53;
  int32_T c15_i54;
  int32_T c15_i55;
  int32_T c15_matrixSize;
  int32_T c15_i56;
  int32_T c15_size1;
  boolean_T c15_b;
  int32_T c15_k_loop_ub;
  int32_T c15_i57;
  boolean_T c15_c;
  int32_T c15_left_size[1];
  int32_T c15_l_loop_ub;
  boolean_T c15_b_c;
  int32_T c15_b_matrixSize;
  int32_T c15_i58;
  int32_T c15_b_size1;
  const mxArray *c15_d_y = NULL;
  static char_T c15_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  int32_T c15_c_left;
  boolean_T c15_b_b;
  int32_T c15_b_right_size[1];
  real_T c15_left_data[100];
  const mxArray *c15_e_y = NULL;
  int32_T c15_i59;
  int32_T c15_m_loop_ub;
  int32_T c15_i60;
  boolean_T c15_c_c;
  int32_T c15_i61;
  boolean_T c15_d_c;
  real_T c15_b_right_data[100];
  int32_T c15_i62;
  const mxArray *c15_f_y = NULL;
  static char_T c15_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  int32_T c15_d_left;
  const mxArray *c15_g_y = NULL;
  int32_T c15_i63;
  int32_T c15_i64;
  int32_T c15_i65;
  c15_emxInit_cell_wrap_0(chartInstance, &c15_edges, 1, &c15_s_emlrtRTEI);
  c15_emxInit_real_T1(chartInstance, &c15_left, 1, &c15_l_emlrtRTEI);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i0 = 0; c15_i0 < 256000; c15_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c15_b_lanes)[c15_i0], 0U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i1 = 0; c15_i1 < 256000; c15_i1++) {
    chartInstance->c15_lanes[c15_i1] = (*chartInstance->c15_b_lanes)[c15_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c15_edges->data, (const int32_T *)
    c15_edges->size, NULL, 0, 0, (void *)c15_sf_marshallOut, (void *)
    c15_sf_marshallIn, (void *)c15_edges, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_x, 1U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_k, 2U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE((void *)&c15_right_data, (const
    int32_T *)&c15_right_size, NULL, 0, 3, (void *)c15_c_sf_marshallOut, (void *)
    c15_c_sf_marshallIn, (void *)&c15_right_data, false);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_EMX_IMPORTABLE(c15_left->data, (const int32_T *)
    c15_left->size, NULL, 0, 4, (void *)c15_d_sf_marshallOut, (void *)
    c15_d_sf_marshallIn, (void *)c15_left, true);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 5U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 6U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c15_lanes, 7U, c15_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_curvature, 8U,
    c15_b_sf_marshallOut, c15_b_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 3);
  for (c15_i2 = 0; c15_i2 < 256000; c15_i2++) {
    chartInstance->c15_varargin_1[c15_i2] = chartInstance->c15_lanes[c15_i2];
  }

  for (c15_i3 = 0; c15_i3 < 256000; c15_i3++) {
    chartInstance->c15_r0.f1[c15_i3] = chartInstance->c15_varargin_1[c15_i3];
  }

  chartInstance->c15_args[0] = chartInstance->c15_r0;
  for (c15_i4 = 0; c15_i4 < 256000; c15_i4++) {
    chartInstance->c15_varargin_1[c15_i4] = chartInstance->c15_args[0].f1[c15_i4];
  }

  for (c15_i5 = 0; c15_i5 < 256000; c15_i5++) {
    chartInstance->c15_BWcomplement[c15_i5] = ((real_T)
      chartInstance->c15_varargin_1[c15_i5] != 0.0);
  }

  for (c15_i6 = 0; c15_i6 < 256000; c15_i6++) {
    chartInstance->c15_b_BWcomplement[c15_i6] = chartInstance->
      c15_BWcomplement[c15_i6];
  }

  c15_bwlabel(chartInstance, chartInstance->c15_b_BWcomplement,
              chartInstance->c15_L);
  c15_obj = &chartInstance->c15_finder;
  c15_b_obj = c15_obj;
  c15_this = c15_b_obj;
  c15_b_obj = c15_this;
  c15_b_obj->matlabCodegenIsDeleted = false;
  c15_padarray(chartInstance, chartInstance->c15_L, chartInstance->c15_dv0);
  for (c15_i7 = 0; c15_i7 < 258084; c15_i7++) {
    c15_b_obj->paddedLabelMatrix[c15_i7] = chartInstance->c15_dv0[c15_i7];
  }

  c15_emxInit_cell_wrap_0(chartInstance, &c15_objs, 1, &c15_t_emlrtRTEI);
  c15_b_obj->numRows = 402;
  c15_b_obj->numCols = 642;
  c15_b_u = true;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 11, 0U, 0U, 0U, 0), false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "assert", 0U, 2U, 14, c15_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_b_y));
  c15_b_obj->conn = 8.0;
  c15_BoundaryFinder_findBoundaries(chartInstance, &chartInstance->c15_finder,
    c15_objs);
  for (c15_i8 = 0; c15_i8 < 256000; c15_i8++) {
    chartInstance->c15_BWcomplement[c15_i8] = !chartInstance->
      c15_BWcomplement[c15_i8];
  }

  c15_emxInit_cell_wrap_0(chartInstance, &c15_holes, 1, &c15_u_emlrtRTEI);
  c15_emxInit_cell_wrap_0(chartInstance, &c15_r1, 1, (emlrtRTEInfo *)NULL);
  c15_imclearborder(chartInstance, chartInstance->c15_BWcomplement,
                    chartInstance->c15_BWholes);
  c15_b_bwlabel(chartInstance, chartInstance->c15_BWholes, chartInstance->c15_L);
  c15_BoundaryFinder_BoundaryFinder(chartInstance, &chartInstance->c15_b_finder,
    chartInstance->c15_L);
  c15_BoundaryFinder_findBoundaries(chartInstance, &chartInstance->c15_b_finder,
    c15_holes);
  c15_N = (real_T)c15_objs->size[0];
  c15_M = (real_T)c15_holes->size[0];
  c15_b_N[0] = (int32_T)sf_integer_check(chartInstance->S, 1U, 51U, 19U, c15_N +
    c15_M);
  c15_b_N[1] = 1;
  c15_i9 = c15_r1->size[0];
  c15_r1->size[0] = c15_b_N[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_r1, c15_i9,
    &c15_emlrtRTEI);
  c15_i10 = c15_edges->size[0];
  c15_edges->size[0] = c15_r1->size[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_edges, c15_i10,
    &c15_emlrtRTEI);
  c15_i11 = (int32_T)c15_N - 1;
  c15_b_k = 0;
  c15_emxFree_cell_wrap_0(chartInstance, &c15_r1);
  while (c15_b_k <= c15_i11) {
    c15_c_k = 1.0 + (real_T)c15_b_k;
    c15_i13 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_edges->size[0] - 1);
    c15_i14 = c15_edges->data[c15_i13].f1->size[0] * c15_edges->data[c15_i13].
      f1->size[1];
    c15_edges->data[c15_i13].f1->size[0] = c15_objs->
      data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_objs->size[0] - 1)].f1->size[0];
    c15_i15 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_edges->size[0] - 1);
    c15_edges->data[c15_i15].f1->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_edges->data[c15_i15].f1,
      c15_i14, &c15_b_emlrtRTEI);
    c15_b_edges = c15_edges->size[0];
    c15_c_edges = c15_edges->size[0];
    c15_d_edges = c15_edges->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 51, 19, MAX_uint32_T,
       (int32_T)c15_c_k - 1, 0, c15_c_edges - 1)].f1->size[0];
    c15_e_edges = c15_edges->size[0];
    c15_f_edges = c15_edges->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 51, 19, MAX_uint32_T,
       (int32_T)c15_c_k - 1, 0, c15_e_edges - 1)].f1->size[1];
    c15_loop_ub = c15_objs->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 43, 27, MAX_uint32_T,
       (int32_T)c15_c_k - 1, 0, c15_objs->size[0] - 1)].f1->size[0] *
      c15_objs->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 43, 27, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_objs->size[0] - 1)].f1->size[1] - 1;
    for (c15_i19 = 0; c15_i19 <= c15_loop_ub; c15_i19++) {
      c15_edges->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
        c15_b_edges - 1)].f1->data[c15_i19] = c15_objs->
        data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
        c15_objs->size[0] - 1)].f1->data[c15_i19];
    }

    c15_b_k++;
  }

  c15_emxFree_cell_wrap_0(chartInstance, &c15_objs);
  c15_i12 = (int32_T)c15_M - 1;
  for (c15_d_k = 0; c15_d_k <= c15_i12; c15_d_k++) {
    c15_c_k = 1.0 + (real_T)c15_d_k;
    c15_i16 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 51U, 19U, c15_c_k + c15_N) - 1, 0, c15_edges->size
      [0] - 1);
    c15_i17 = c15_edges->data[c15_i16].f1->size[0] * c15_edges->data[c15_i16].
      f1->size[1];
    c15_edges->data[c15_i16].f1->size[0] = c15_holes->
      data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_holes->size[0] - 1)].f1->size[0];
    c15_i18 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)sf_integer_check
      (chartInstance->S, 1U, 51U, 19U, c15_c_k + c15_N) - 1, 0, c15_edges->size
      [0] - 1);
    c15_edges->data[c15_i18].f1->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_edges->data[c15_i18].f1,
      c15_i17, &c15_c_emlrtRTEI);
    c15_g_edges = c15_edges->size[0];
    c15_h_edges = c15_edges->size[0];
    c15_i_edges = c15_edges->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 51, 19, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 51U, 19U, c15_c_k + c15_N)
       - 1, 0, c15_h_edges - 1)].f1->size[0];
    c15_j_edges = c15_edges->size[0];
    c15_k_edges = c15_edges->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 51, 19, MAX_uint32_T,
       (int32_T)sf_integer_check(chartInstance->S, 1U, 51U, 19U, c15_c_k + c15_N)
       - 1, 0, c15_j_edges - 1)].f1->size[1];
    c15_b_loop_ub = c15_holes->data[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 43, 27, MAX_uint32_T,
       (int32_T)c15_c_k - 1, 0, c15_holes->size[0] - 1)].f1->size[0] *
      c15_holes->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
      chartInstance->S, 1U, 43, 27, MAX_uint32_T, (int32_T)c15_c_k - 1, 0,
      c15_holes->size[0] - 1)].f1->size[1] - 1;
    for (c15_i22 = 0; c15_i22 <= c15_b_loop_ub; c15_i22++) {
      c15_edges->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
        chartInstance->S, 1U, 51, 19, MAX_uint32_T, (int32_T)sf_integer_check
        (chartInstance->S, 1U, 51U, 19U, c15_c_k + c15_N) - 1, 0, c15_g_edges -
        1)].f1->data[c15_i22] = c15_holes->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 51, 19, MAX_uint32_T,
         (int32_T)c15_c_k - 1, 0, c15_holes->size[0] - 1)].f1->data[c15_i22];
    }
  }

  c15_emxFree_cell_wrap_0(chartInstance, &c15_holes);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 5);
  c15_b_x = (real_T)c15_edges->size[0];
  c15_x = c15_b_x;
  c15_k = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_emxInit_real_T(chartInstance, &c15_r2, 2, (emlrtRTEInfo *)NULL);
  c15_emxInit_real_T1(chartInstance, &c15_r3, 1, (emlrtRTEInfo *)NULL);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c15_x, 1.0, -1, 0U, c15_x
        == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
    sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
      123, 1, MAX_uint32_T, 0, 0, c15_edges->size[0] - 1);
    c15_i21 = c15_r2->size[0] * c15_r2->size[1];
    c15_r2->size[0] = c15_edges->data[0].f1->size[0];
    c15_r2->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_r2, c15_i21,
      &c15_e_emlrtRTEI);
    c15_i24 = c15_r2->size[0];
    c15_i26 = c15_r2->size[1];
    c15_d_loop_ub = c15_edges->data[0].f1->size[0] * c15_edges->data[0].f1->
      size[1] - 1;
    for (c15_i28 = 0; c15_i28 <= c15_d_loop_ub; c15_i28++) {
      c15_r2->data[c15_i28] = c15_edges->data[0].f1->data[c15_i28];
    }

    c15_i30 = c15_r2->size[0];
    for (c15_i31 = 0; c15_i31 < 100; c15_i31++) {
      c15_b_left[c15_i31] = c15_r2->data[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 128, 5, MAX_uint32_T,
         c15_i31 + 1, 1, c15_i30) + c15_r2->size[0]) - 1];
    }

    c15_c_y = c15_b_left[0];
    for (c15_e_k = 0; c15_e_k < 99; c15_e_k++) {
      c15_xoffset = c15_e_k;
      c15_ix = c15_xoffset;
      c15_c_y += c15_b_left[c15_ix + 1];
    }

    c15_A = c15_c_y;
    c15_c_x = c15_A;
    c15_d_x = c15_c_x;
    c15_d0 = c15_d_x / 100.0;
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c15_d0, 300.0, -1, 4U,
          c15_d0 > 300.0))) {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
      sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
        1U, 166, 1, MAX_uint32_T, 0, 0, c15_edges->size[0] - 1);
      c15_i38 = c15_r2->size[0] * c15_r2->size[1];
      c15_r2->size[0] = c15_edges->data[0].f1->size[0];
      c15_r2->size[1] = 2;
      c15_emxEnsureCapacity_real_T(chartInstance, c15_r2, c15_i38,
        &c15_i_emlrtRTEI);
      c15_i42 = c15_r2->size[0];
      c15_i44 = c15_r2->size[1];
      c15_h_loop_ub = c15_edges->data[0].f1->size[0] * c15_edges->data[0]
        .f1->size[1] - 1;
      for (c15_i47 = 0; c15_i47 <= c15_h_loop_ub; c15_i47++) {
        c15_r2->data[c15_i47] = c15_edges->data[0].f1->data[c15_i47];
      }

      c15_i49 = c15_r2->size[0];
      c15_right_size[0] = 100;
      for (c15_i52 = 0; c15_i52 < 100; c15_i52++) {
        c15_right_data[c15_i52] = c15_r2->data[(sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 171, 7,
           MAX_uint32_T, (int32_T)(401.0 + (real_T)c15_i52), 1, c15_i49) +
          c15_r2->size[0]) - 1];
      }

      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 10);
      c15_i55 = c15_left->size[0];
      c15_left->size[0] = 1;
      c15_emxEnsureCapacity_real_T1(chartInstance, c15_left, c15_i55,
        &c15_l_emlrtRTEI);
      c15_left->data[0] = 600.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
      sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S,
        1U, 238, 1, MAX_uint32_T, 1, 0, c15_edges->size[0] - 1);
      c15_i37 = c15_r2->size[0] * c15_r2->size[1];
      c15_r2->size[0] = c15_edges->data[1].f1->size[0];
      c15_r2->size[1] = 2;
      c15_emxEnsureCapacity_real_T(chartInstance, c15_r2, c15_i37,
        &c15_h_emlrtRTEI);
      c15_i41 = c15_r2->size[0];
      c15_i43 = c15_r2->size[1];
      c15_g_loop_ub = c15_edges->data[1].f1->size[0] * c15_edges->data[1]
        .f1->size[1] - 1;
      for (c15_i46 = 0; c15_i46 <= c15_g_loop_ub; c15_i46++) {
        c15_r2->data[c15_i46] = c15_edges->data[1].f1->data[c15_i46];
      }

      c15_i48 = c15_r2->size[0];
      c15_i51 = c15_r3->size[0];
      c15_r3->size[0] = c15_i48;
      c15_emxEnsureCapacity_real_T1(chartInstance, c15_r3, c15_i51,
        (emlrtRTEInfo *)NULL);
      c15_j_loop_ub = c15_i48 - 1;
      for (c15_i54 = 0; c15_i54 <= c15_j_loop_ub; c15_i54++) {
        c15_r3->data[c15_i54] = c15_r2->data[c15_i54 + c15_r2->size[0]];
      }

      c15_b_flip(chartInstance, c15_r3);
      c15_i56 = c15_left->size[0];
      c15_left->size[0] = c15_r3->size[0];
      c15_emxEnsureCapacity_real_T1(chartInstance, c15_left, c15_i56,
        &c15_m_emlrtRTEI);
      c15_k_loop_ub = c15_r3->size[0] - 1;
      for (c15_i57 = 0; c15_i57 <= c15_k_loop_ub; c15_i57++) {
        c15_left->data[c15_i57] = c15_r3->data[c15_i57];
      }

      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
      c15_b_matrixSize = c15_left->size[0];
      c15_b_size1 = c15_b_matrixSize;
      if (c15_b_size1 != 1) {
        c15_b_b = false;
      } else {
        c15_b_b = true;
      }

      if (c15_b_b) {
        c15_c_c = true;
      } else {
        c15_c_c = false;
      }

      c15_d_c = c15_c_c;
      if (!c15_d_c) {
      } else {
        c15_f_y = NULL;
        sf_mex_assign(&c15_f_y, sf_mex_create("y", c15_cv2, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        c15_g_y = NULL;
        sf_mex_assign(&c15_g_y, sf_mex_create("y", c15_cv2, 10, 0U, 1U, 0U, 2, 1,
          30), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                          c15_f_y, 14, sf_mex_call_debug
                          (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                           sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 1U, 14, c15_g_y)));
      }

      c15_d_left = c15_left->size[0];
      for (c15_i63 = 0; c15_i63 < 100; c15_i63++) {
        c15_b_left[c15_i63] = c15_left->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 270, 5,
           MAX_uint32_T, c15_i63 + 1, 1, c15_d_left) - 1];
      }

      c15_i64 = c15_left->size[0];
      c15_left->size[0] = 100;
      c15_emxEnsureCapacity_real_T1(chartInstance, c15_left, c15_i64,
        &c15_q_emlrtRTEI);
      for (c15_i65 = 0; c15_i65 < 100; c15_i65++) {
        c15_left->data[c15_i65] = c15_b_left[c15_i65];
      }

      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
      c15_right_size[0] = 1;
      c15_right_data[0] = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
    sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
      328, 1, MAX_uint32_T, 0, 0, c15_edges->size[0] - 1);
    c15_i20 = c15_r2->size[0] * c15_r2->size[1];
    c15_r2->size[0] = c15_edges->data[0].f1->size[0];
    c15_r2->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_r2, c15_i20,
      &c15_d_emlrtRTEI);
    c15_i23 = c15_r2->size[0];
    c15_i25 = c15_r2->size[1];
    c15_c_loop_ub = c15_edges->data[0].f1->size[0] * c15_edges->data[0].f1->
      size[1] - 1;
    for (c15_i27 = 0; c15_i27 <= c15_c_loop_ub; c15_i27++) {
      c15_r2->data[c15_i27] = c15_edges->data[0].f1->data[c15_i27];
    }

    c15_i29 = c15_r2->size[0];
    c15_right_size[0] = 100;
    for (c15_i32 = 0; c15_i32 < 100; c15_i32++) {
      c15_right_data[c15_i32] = c15_r2->data[(sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 333, 7, MAX_uint32_T,
         (int32_T)(401.0 + (real_T)c15_i32), 1, c15_i29) + c15_r2->size[0]) - 1];
    }

    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
    sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct, chartInstance->S, 1U,
      372, 1, MAX_uint32_T, 1, 0, c15_edges->size[0] - 1);
    c15_i33 = c15_r2->size[0] * c15_r2->size[1];
    c15_r2->size[0] = c15_edges->data[1].f1->size[0];
    c15_r2->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_r2, c15_i33,
      &c15_g_emlrtRTEI);
    c15_i34 = c15_r2->size[0];
    c15_i35 = c15_r2->size[1];
    c15_e_loop_ub = c15_edges->data[1].f1->size[0] * c15_edges->data[1].f1->
      size[1] - 1;
    for (c15_i36 = 0; c15_i36 <= c15_e_loop_ub; c15_i36++) {
      c15_r2->data[c15_i36] = c15_edges->data[1].f1->data[c15_i36];
    }

    c15_i39 = c15_r2->size[0];
    c15_i40 = c15_r3->size[0];
    c15_r3->size[0] = c15_i39;
    c15_emxEnsureCapacity_real_T1(chartInstance, c15_r3, c15_i40, (emlrtRTEInfo *)
      NULL);
    c15_f_loop_ub = c15_i39 - 1;
    for (c15_i45 = 0; c15_i45 <= c15_f_loop_ub; c15_i45++) {
      c15_r3->data[c15_i45] = c15_r2->data[c15_i45 + c15_r2->size[0]];
    }

    c15_b_flip(chartInstance, c15_r3);
    c15_i50 = c15_left->size[0];
    c15_left->size[0] = c15_r3->size[0];
    c15_emxEnsureCapacity_real_T1(chartInstance, c15_left, c15_i50,
      &c15_j_emlrtRTEI);
    c15_i_loop_ub = c15_r3->size[0] - 1;
    for (c15_i53 = 0; c15_i53 <= c15_i_loop_ub; c15_i53++) {
      c15_left->data[c15_i53] = c15_r3->data[c15_i53];
    }

    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 20);
    c15_matrixSize = c15_left->size[0];
    c15_size1 = c15_matrixSize;
    if (c15_size1 != 1) {
      c15_b = false;
    } else {
      c15_b = true;
    }

    if (c15_b) {
      c15_c = true;
    } else {
      c15_c = false;
    }

    c15_b_c = c15_c;
    if (!c15_b_c) {
    } else {
      c15_d_y = NULL;
      sf_mex_assign(&c15_d_y, sf_mex_create("y", c15_cv1, 10, 0U, 1U, 0U, 2, 1,
        30), false);
      c15_e_y = NULL;
      sf_mex_assign(&c15_e_y, sf_mex_create("y", c15_cv1, 10, 0U, 1U, 0U, 2, 1,
        30), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14,
                        c15_d_y, 14, sf_mex_call_debug
                        (sfGlobalDebugInstanceStruct, "getString", 1U, 1U, 14,
                         sf_mex_call_debug(sfGlobalDebugInstanceStruct,
        "message", 1U, 1U, 14, c15_e_y)));
    }

    c15_c_left = c15_left->size[0];
    for (c15_i59 = 0; c15_i59 < 100; c15_i59++) {
      c15_b_left[c15_i59] = c15_left->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 400, 5, MAX_uint32_T,
         c15_i59 + 1, 1, c15_c_left) - 1];
    }

    c15_i61 = c15_left->size[0];
    c15_left->size[0] = 100;
    c15_emxEnsureCapacity_real_T1(chartInstance, c15_left, c15_i61,
      &c15_p_emlrtRTEI);
    for (c15_i62 = 0; c15_i62 < 100; c15_i62++) {
      c15_left->data[c15_i62] = c15_b_left[c15_i62];
    }
  }

  c15_emxFree_real_T(chartInstance, &c15_r3);
  c15_emxFree_real_T(chartInstance, &c15_r2);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 23);
  c15_left_size[0] = c15_left->size[0];
  c15_l_loop_ub = c15_left->size[0] - 1;
  for (c15_i58 = 0; c15_i58 <= c15_l_loop_ub; c15_i58++) {
    c15_left_data[c15_i58] = c15_left->data[c15_i58];
  }

  c15_b_right_size[0] = c15_right_size[0];
  c15_m_loop_ub = c15_right_size[0] - 1;
  for (c15_i60 = 0; c15_i60 <= c15_m_loop_ub; c15_i60++) {
    c15_b_right_data[c15_i60] = c15_right_data[c15_i60];
  }

  c15_b_curvature = (c15_mean(chartInstance, c15_left_data, c15_left_size) +
                     c15_mean(chartInstance, c15_b_right_data, c15_b_right_size))
    - 640.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c15_curvature = c15_b_curvature;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_DATA_RANGE_CHECK(*chartInstance->c15_curvature, 1U);
  c15_emxFree_real_T(chartInstance, &c15_left);
  c15_emxFree_cell_wrap_0(chartInstance, &c15_edges);
}

static void mdl_start_c15_VehicleSimME131(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc15_VehicleSimME131
  (SFc15_VehicleSimME131InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber, uint32_T c15_instanceNumber)
{
  (void)(c15_machineNumber);
  (void)(c15_chartNumber);
  (void)(c15_instanceNumber);
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid,
  c15_emxArray_cell_wrap_0 *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  c15_emxArray_cell_wrap_0 *c15_b_u;
  int32_T c15_i66;
  int32_T c15_loop_ub;
  int32_T c15_i67;
  const mxArray *c15_y = NULL;
  int32_T c15_c_u[1];
  int32_T c15_i68;
  int32_T c15_n;
  c15_emxArray_real_T *c15_d_u;
  int32_T c15_b_n[1];
  int32_T c15_i69;
  int32_T c15_c_n[1];
  int32_T c15_d_n[1];
  int32_T c15_e_n[1];
  int32_T c15_e_u;
  int32_T c15_f_u;
  int32_T c15_b_loop_ub;
  int32_T c15_i70;
  const mxArray *c15_b_y = NULL;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_emxInit_cell_wrap_0(chartInstance, &c15_b_u, 1, (emlrtRTEInfo *)NULL);
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_i66 = c15_b_u->size[0];
  c15_b_u->size[0] = c15_inData->size[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_b_u, c15_i66,
    (emlrtRTEInfo *)NULL);
  c15_loop_ub = c15_inData->size[0] - 1;
  for (c15_i67 = 0; c15_i67 <= c15_loop_ub; c15_i67++) {
    c15_emxCopyStruct_cell_wrap_0(chartInstance, &c15_b_u->data[c15_i67],
      &c15_inData->data[c15_i67], (emlrtRTEInfo *)NULL);
  }

  c15_y = NULL;
  c15_c_u[0] = c15_b_u->size[0];
  sf_mex_assign(&c15_y, sf_mex_createcellarray(1, c15_c_u), false);
  c15_i68 = 0;
  c15_n = c15_b_u->size[0];
  c15_emxInit_real_T(chartInstance, &c15_d_u, 2, (emlrtRTEInfo *)NULL);
  while (c15_i68 < c15_n) {
    c15_b_n[0] = c15_n;
    c15_i69 = c15_d_u->size[0] * c15_d_u->size[1];
    c15_d_u->size[0] = c15_b_u->data[c15_i68].f1->size[0];
    c15_d_u->size[1] = 2;
    c15_emxEnsureCapacity_real_T(chartInstance, c15_d_u, c15_i69, (emlrtRTEInfo *)
      NULL);
    c15_c_n[0] = c15_n;
    c15_d_n[0] = c15_n;
    c15_e_n[0] = c15_n;
    c15_e_u = c15_d_u->size[0];
    c15_f_u = c15_d_u->size[1];
    c15_b_loop_ub = c15_b_u->data[c15_i68].f1->size[0] * c15_b_u->data[c15_i68].
      f1->size[1] - 1;
    for (c15_i70 = 0; c15_i70 <= c15_b_loop_ub; c15_i70++) {
      c15_d_u->data[c15_i70] = c15_b_u->data[c15_i68].f1->data[c15_i70];
    }

    c15_b_y = NULL;
    sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_d_u->data, 0, 0U, 1U, 0U, 2,
      c15_d_u->size[0], c15_d_u->size[1]), false);
    sf_mex_setcell(c15_y, c15_i68, c15_b_y);
    c15_i68++;
  }

  c15_emxFree_real_T(chartInstance, &c15_d_u);
  c15_emxFree_cell_wrap_0(chartInstance, &c15_b_u);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_cell_wrap_0 *c15_y)
{
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_iv0[1];
  boolean_T c15_bv0[1];
  int32_T c15_iv1[1];
  int32_T c15_i71;
  int32_T c15_n;
  int32_T c15_i72;
  char_T c15_str[11];
  int32_T c15_b_n[1];
  c15_thisId.fParent = c15_parentId;
  c15_thisId.bParentIsCell = true;
  c15_iv0[0] = -1;
  c15_bv0[0] = true;
  sf_mex_check_cell_vs(c15_parentId, c15_b_u, 1U, c15_iv0, c15_bv0, c15_iv1);
  c15_i71 = c15_y->size[0];
  c15_y->size[0] = c15_iv1[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_y, c15_i71, (emlrtRTEInfo
    *)NULL);
  c15_n = c15_y->size[0];
  for (c15_i72 = 0; c15_i72 < c15_n; c15_i72++) {
    sprintf(&c15_str[0], "%d", c15_i72 + 1);
    c15_thisId.fIdentifier = &c15_str[0];
    c15_b_n[0] = c15_n;
    c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_b_u,
      c15_i72)), &c15_thisId, c15_y->data[c15_i72].f1);
  }

  sf_mex_destroy(&c15_b_u);
}

static void c15_b_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_real_T *c15_y)
{
  c15_emxArray_real_T *c15_r4;
  int32_T c15_i73;
  int32_T c15_i74;
  uint32_T c15_uv0[2];
  static uint32_T c15_uv1[2] = { MAX_uint32_T, 2U };

  int32_T c15_i75;
  boolean_T c15_bv1[2];
  static boolean_T c15_bv2[2] = { true, false };

  int32_T c15_i76;
  int32_T c15_b_y;
  int32_T c15_c_y;
  int32_T c15_loop_ub;
  int32_T c15_i77;
  c15_emxInit_real_T(chartInstance, &c15_r4, 2, (emlrtRTEInfo *)NULL);
  for (c15_i73 = 0; c15_i73 < 2; c15_i73++) {
    c15_uv0[c15_i73] = c15_uv1[c15_i73];
  }

  c15_i74 = c15_r4->size[0] * c15_r4->size[1];
  c15_r4->size[0] = sf_mex_get_dimension(c15_b_u, 0);
  c15_r4->size[1] = sf_mex_get_dimension(c15_b_u, 1);
  c15_emxEnsureCapacity_real_T(chartInstance, c15_r4, c15_i74, (emlrtRTEInfo *)
    NULL);
  for (c15_i75 = 0; c15_i75 < 2; c15_i75++) {
    c15_bv1[c15_i75] = c15_bv2[c15_i75];
  }

  sf_mex_import_vs(c15_parentId, sf_mex_dup(c15_b_u), c15_r4->data, 1, 0, 0U, 1,
                   0U, 2, c15_bv1, c15_uv0, c15_r4->size);
  c15_i76 = c15_y->size[0] * c15_y->size[1];
  c15_y->size[0] = c15_r4->size[0];
  c15_y->size[1] = 2;
  c15_emxEnsureCapacity_real_T(chartInstance, c15_y, c15_i76, (emlrtRTEInfo *)
    NULL);
  c15_b_y = c15_y->size[0];
  c15_c_y = c15_y->size[1];
  c15_loop_ub = c15_r4->size[0] * c15_r4->size[1] - 1;
  for (c15_i77 = 0; c15_i77 <= c15_loop_ub; c15_i77++) {
    c15_y->data[c15_i77] = c15_r4->data[c15_i77];
  }

  sf_mex_destroy(&c15_b_u);
  c15_emxFree_real_T(chartInstance, &c15_r4);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, c15_emxArray_cell_wrap_0
  *c15_outData)
{
  c15_emxArray_cell_wrap_0 *c15_y;
  const mxArray *c15_edges;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_i78;
  int32_T c15_loop_ub;
  int32_T c15_i79;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_emxInit_cell_wrap_0(chartInstance, &c15_y, 1, (emlrtRTEInfo *)NULL);
  c15_edges = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_edges), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_edges);
  c15_i78 = c15_outData->size[0];
  c15_outData->size[0] = c15_y->size[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_outData, c15_i78,
    (emlrtRTEInfo *)NULL);
  c15_loop_ub = c15_y->size[0] - 1;
  for (c15_i79 = 0; c15_i79 <= c15_loop_ub; c15_i79++) {
    c15_emxCopyStruct_cell_wrap_0(chartInstance, &c15_outData->data[c15_i79],
      &c15_y->data[c15_i79], (emlrtRTEInfo *)NULL);
  }

  c15_emxFree_cell_wrap_0(chartInstance, &c15_y);
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  real_T c15_b_u;
  const mxArray *c15_y = NULL;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_b_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static real_T c15_c_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_x, const char_T *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_x), &c15_thisId);
  sf_mex_destroy(&c15_x);
  return c15_y;
}

static real_T c15_d_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d1;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_d1, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d1;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_x;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_x = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_x), &c15_thisId);
  sf_mex_destroy(&c15_x);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, real_T
  c15_inData_data[], int32_T c15_inData_size[1])
{
  const mxArray *c15_mxArrayOutData;
  int32_T c15_u_size[1];
  int32_T c15_loop_ub;
  int32_T c15_i80;
  const mxArray *c15_y = NULL;
  real_T c15_u_data[100];
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_u_size[0] = c15_inData_size[0];
  c15_loop_ub = c15_inData_size[0] - 1;
  for (c15_i80 = 0; c15_i80 <= c15_loop_ub; c15_i80++) {
    c15_u_data[c15_i80] = c15_inData_data[c15_i80];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", (void *)&c15_u_data, 0, 0U, 1U, 0U, 1,
    c15_u_size[0]), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static void c15_e_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y_data[], int32_T c15_y_size[1])
{
  uint32_T c15_uv2[1];
  int32_T c15_tmp_size[1];
  boolean_T c15_bv3[1];
  real_T c15_tmp_data[100];
  int32_T c15_loop_ub;
  int32_T c15_i81;
  (void)chartInstance;
  c15_uv2[0] = 100U;
  c15_tmp_size[0] = sf_mex_get_dimension(c15_b_u, 0);
  c15_bv3[0] = true;
  sf_mex_import_vs(c15_parentId, sf_mex_dup(c15_b_u), (void *)&c15_tmp_data, 1,
                   0, 0U, 1, 0U, 1, c15_bv3, c15_uv2, c15_tmp_size);
  c15_y_size[0] = c15_tmp_size[0];
  c15_loop_ub = c15_tmp_size[0] - 1;
  for (c15_i81 = 0; c15_i81 <= c15_loop_ub; c15_i81++) {
    c15_y_data[c15_i81] = c15_tmp_data[c15_i81];
  }

  sf_mex_destroy(&c15_b_u);
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, real_T c15_outData_data[],
  int32_T c15_outData_size[1])
{
  const mxArray *c15_right;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y_data[100];
  int32_T c15_y_size[1];
  int32_T c15_loop_ub;
  int32_T c15_i82;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_right = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_right), &c15_thisId,
    c15_y_data, c15_y_size);
  sf_mex_destroy(&c15_right);
  c15_outData_size[0] = c15_y_size[0];
  c15_loop_ub = c15_y_size[0] - 1;
  for (c15_i82 = 0; c15_i82 <= c15_loop_ub; c15_i82++) {
    c15_outData_data[c15_i82] = c15_y_data[c15_i82];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid,
  c15_emxArray_real_T *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  c15_emxArray_real_T *c15_b_u;
  int32_T c15_i83;
  int32_T c15_loop_ub;
  int32_T c15_i84;
  const mxArray *c15_y = NULL;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_emxInit_real_T1(chartInstance, &c15_b_u, 1, (emlrtRTEInfo *)NULL);
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_i83 = c15_b_u->size[0];
  c15_b_u->size[0] = c15_inData->size[0];
  c15_emxEnsureCapacity_real_T1(chartInstance, c15_b_u, c15_i83, (emlrtRTEInfo *)
    NULL);
  c15_loop_ub = c15_inData->size[0] - 1;
  for (c15_i84 = 0; c15_i84 <= c15_loop_ub; c15_i84++) {
    c15_b_u->data[c15_i84] = c15_inData->data[c15_i84];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_b_u->data, 0, 0U, 1U, 0U, 1,
    c15_b_u->size[0]), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  c15_emxFree_real_T(chartInstance, &c15_b_u);
  return c15_mxArrayOutData;
}

static void c15_f_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId,
  c15_emxArray_real_T *c15_y)
{
  c15_emxArray_real_T *c15_r5;
  uint32_T c15_uv3[1];
  int32_T c15_i85;
  boolean_T c15_bv4[1];
  int32_T c15_i86;
  int32_T c15_loop_ub;
  int32_T c15_i87;
  c15_emxInit_real_T1(chartInstance, &c15_r5, 1, (emlrtRTEInfo *)NULL);
  c15_uv3[0] = MAX_uint32_T;
  c15_i85 = c15_r5->size[0];
  c15_r5->size[0] = sf_mex_get_dimension(c15_b_u, 0);
  c15_emxEnsureCapacity_real_T1(chartInstance, c15_r5, c15_i85, (emlrtRTEInfo *)
    NULL);
  c15_bv4[0] = true;
  sf_mex_import_vs(c15_parentId, sf_mex_dup(c15_b_u), c15_r5->data, 1, 0, 0U, 1,
                   0U, 1, c15_bv4, c15_uv3, c15_r5->size);
  c15_i86 = c15_y->size[0];
  c15_y->size[0] = c15_r5->size[0];
  c15_emxEnsureCapacity_real_T1(chartInstance, c15_y, c15_i86, (emlrtRTEInfo *)
    NULL);
  c15_loop_ub = c15_r5->size[0] - 1;
  for (c15_i87 = 0; c15_i87 <= c15_loop_ub; c15_i87++) {
    c15_y->data[c15_i87] = c15_r5->data[c15_i87];
  }

  sf_mex_destroy(&c15_b_u);
  c15_emxFree_real_T(chartInstance, &c15_r5);
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, c15_emxArray_real_T
  *c15_outData)
{
  c15_emxArray_real_T *c15_y;
  const mxArray *c15_left;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_i88;
  int32_T c15_loop_ub;
  int32_T c15_i89;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_emxInit_real_T1(chartInstance, &c15_y, 1, (emlrtRTEInfo *)NULL);
  c15_left = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_left), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_left);
  c15_i88 = c15_outData->size[0];
  c15_outData->size[0] = c15_y->size[0];
  c15_emxEnsureCapacity_real_T1(chartInstance, c15_outData, c15_i88,
    (emlrtRTEInfo *)NULL);
  c15_loop_ub = c15_y->size[0] - 1;
  for (c15_i89 = 0; c15_i89 <= c15_loop_ub; c15_i89++) {
    c15_outData->data[c15_i89] = c15_y->data[c15_i89];
  }

  c15_emxFree_real_T(chartInstance, &c15_y);
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  int32_T c15_i90;
  int32_T c15_i91;
  const mxArray *c15_y = NULL;
  int32_T c15_i92;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_i90 = 0;
  for (c15_i91 = 0; c15_i91 < 640; c15_i91++) {
    for (c15_i92 = 0; c15_i92 < 400; c15_i92++) {
      chartInstance->c15_u[c15_i92 + c15_i90] = (*(uint8_T (*)[256000])
        c15_inData)[c15_i92 + c15_i90];
    }

    c15_i90 += 400;
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", chartInstance->c15_u, 3, 0U, 1U, 0U,
    2, 400, 640), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

const mxArray *sf_c15_VehicleSimME131_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c15_nameCaptureInfo;
}

static void c15_bwlabel(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], real_T c15_b_L[256000])
{
  int32_T c15_numRuns;
  int32_T c15_col;
  c15_emxArray_int32_T *c15_startRow;
  real_T c15_b_col;
  c15_emxArray_int32_T *c15_endRow;
  c15_emxArray_int32_T *c15_startCol;
  c15_emxArray_int32_T *c15_labelForEachRun;
  int32_T c15_k;
  int32_T c15_i93;
  int32_T c15_i94;
  real_T c15_b_k;
  int32_T c15_i95;
  int32_T c15_i96;
  int32_T c15_i97;
  int32_T c15_i98;
  int32_T c15_runCounter;
  int32_T c15_i99;
  int32_T c15_c_col;
  int32_T c15_i100;
  real_T c15_d_col;
  int32_T c15_row;
  c15_emxArray_int32_T *c15_labelsRenumbered;
  int32_T c15_i101;
  int32_T c15_loop_ub;
  int32_T c15_i102;
  int32_T c15_i103;
  real_T c15_numComponents;
  int32_T c15_c_k;
  int32_T c15_i104;
  int32_T c15_currentColumn;
  int32_T c15_nextLabel;
  int32_T c15_firstRunOnPreviousColumn;
  int32_T c15_b;
  int32_T c15_lastRunOnPreviousColumn;
  int32_T c15_b_b;
  int32_T c15_firstRunOnThisColumn;
  boolean_T c15_overflow;
  int32_T c15_d_k;
  int32_T c15_p;
  int32_T c15_i105;
  int32_T c15_i106;
  int32_T c15_idx;
  int32_T c15_e_k;
  int32_T c15_b_p;
  int32_T c15_node;
  int32_T c15_root_k;
  int32_T c15_b_node;
  int32_T c15_root_p;
  int32_T c15_b_root_k;
  int32_T c15_b_root_p;
  int32_T c15_f_k;
  int32_T c15_c_p;
  c15_numRuns = 0;
  for (c15_col = 0; c15_col < 640; c15_col++) {
    c15_b_col = 1.0 + (real_T)c15_col;
    if (c15_b_varargin_1[400 * ((int32_T)c15_b_col - 1)]) {
      c15_numRuns++;
    }

    for (c15_k = 0; c15_k < 399; c15_k++) {
      c15_b_k = 2.0 + (real_T)c15_k;
      if (c15_b_varargin_1[((int32_T)c15_b_k + 400 * ((int32_T)c15_b_col - 1)) -
          1] && (!c15_b_varargin_1[((int32_T)(c15_b_k - 1.0) + 400 * ((int32_T)
             c15_b_col - 1)) - 1])) {
        c15_numRuns++;
      }
    }
  }

  c15_emxInit_int32_T(chartInstance, &c15_startRow, 1, &c15_eb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_endRow, 1, &c15_fb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_startCol, 1, &c15_gb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_labelForEachRun, 1, &c15_hb_emlrtRTEI);
  if (c15_numRuns == 0) {
    c15_i94 = c15_startRow->size[0];
    c15_startRow->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startRow, c15_i94,
      &c15_v_emlrtRTEI);
    c15_i96 = c15_endRow->size[0];
    c15_endRow->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_endRow, c15_i96,
      &c15_x_emlrtRTEI);
    c15_i98 = c15_startCol->size[0];
    c15_startCol->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startCol, c15_i98,
      &c15_y_emlrtRTEI);
    c15_i99 = c15_labelForEachRun->size[0];
    c15_labelForEachRun->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelForEachRun, c15_i99,
      &c15_ab_emlrtRTEI);
    c15_numRuns = 0;
  } else {
    c15_i93 = c15_startRow->size[0];
    c15_startRow->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
      c15_numRuns);
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startRow, c15_i93,
      &c15_w_emlrtRTEI);
    c15_i95 = c15_endRow->size[0];
    c15_endRow->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_endRow, c15_i95,
      &c15_w_emlrtRTEI);
    c15_i97 = c15_startCol->size[0];
    c15_startCol->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startCol, c15_i97,
      &c15_w_emlrtRTEI);
    c15_runCounter = 1;
    for (c15_c_col = 0; c15_c_col < 640; c15_c_col++) {
      c15_d_col = 1.0 + (real_T)c15_c_col;
      c15_row = 1;
      while (c15_row <= 400) {
        while ((c15_row <= 400) && (!c15_b_varargin_1[(c15_row + 400 * ((int32_T)
                  c15_d_col - 1)) - 1])) {
          c15_row++;
        }

        if ((c15_row <= 400) && c15_b_varargin_1[(c15_row + 400 * ((int32_T)
              c15_d_col - 1)) - 1]) {
          c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_runCounter, 1, c15_startCol->size[0]) - 1] =
            (int32_T)c15_d_col;
          c15_startRow->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_runCounter, 1, c15_startRow->size[0]) - 1] =
            c15_row;
          while ((c15_row <= 400) && c15_b_varargin_1[(c15_row + 400 * ((int32_T)
                   c15_d_col - 1)) - 1]) {
            c15_row++;
          }

          c15_endRow->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_runCounter, 1,
            c15_endRow->size[0]) - 1] = c15_row - 1;
          c15_runCounter++;
        }
      }
    }

    c15_i100 = c15_labelForEachRun->size[0];
    c15_labelForEachRun->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelForEachRun, c15_i100,
      &c15_cb_emlrtRTEI);
    c15_loop_ub = c15_numRuns - 1;
    for (c15_i103 = 0; c15_i103 <= c15_loop_ub; c15_i103++) {
      c15_labelForEachRun->data[c15_i103] = 0;
    }

    c15_c_k = 1;
    c15_currentColumn = 2;
    c15_nextLabel = 1;
    c15_firstRunOnPreviousColumn = -1;
    c15_lastRunOnPreviousColumn = 0;
    c15_firstRunOnThisColumn = 1;
    while (c15_c_k <= c15_numRuns) {
      if (c15_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_startCol->size[0]) - 1] == c15_currentColumn) {
        c15_firstRunOnPreviousColumn = c15_firstRunOnThisColumn;
        c15_firstRunOnThisColumn = c15_c_k;
        c15_lastRunOnPreviousColumn = c15_c_k;
        c15_currentColumn = c15_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_startCol->size[0]) - 1] + 1;
      } else {
        if (c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_c_k, 1, c15_startCol->size[0]) - 1] >
            c15_currentColumn) {
          c15_firstRunOnPreviousColumn = -1;
          c15_lastRunOnPreviousColumn = 0;
          c15_firstRunOnThisColumn = c15_c_k;
          c15_currentColumn = c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_c_k, 1, c15_startCol->size[0]) - 1] + 1;
        }
      }

      if (c15_firstRunOnPreviousColumn >= 0) {
        for (c15_p = c15_firstRunOnPreviousColumn; c15_p <
             c15_lastRunOnPreviousColumn; c15_p++) {
          if ((c15_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_c_k, 1, c15_endRow->size[0]) - 1] >=
               c15_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_p, 1, c15_startRow->size[0]) - 1] - 1) &&
              (c15_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_c_k, 1, c15_startRow->size[0]) - 1] <=
               c15_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_p, 1, c15_endRow->size[0]) - 1] + 1)) {
            if (c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] ==
                0) {
              c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] =
                c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_p, 1, c15_labelForEachRun->size[0]) - 1];
              c15_nextLabel++;
            } else {
              if (c15_labelForEachRun->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1]
                  != c15_labelForEachRun->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c15_p, 1, c15_labelForEachRun->size[0]) - 1]) {
                c15_e_k = c15_c_k;
                c15_b_p = c15_p;
                c15_node = c15_e_k;
                c15_root_k = c15_node;
                while (c15_root_k != c15_labelForEachRun->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c15_root_k, 1, c15_labelForEachRun->size[0])
                       - 1]) {
                  c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_root_k, 1, c15_labelForEachRun->size[0])
                    - 1] = c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_labelForEachRun->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_k, 1,
                      c15_labelForEachRun->size[0]) - 1], 1,
                     c15_labelForEachRun->size[0]) - 1];
                  c15_root_k = c15_labelForEachRun->
                    data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_k, 1,
                    c15_labelForEachRun->size[0]) - 1];
                }

                c15_b_node = c15_b_p;
                c15_root_p = c15_b_node;
                while (c15_root_p != c15_labelForEachRun->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c15_root_p, 1, c15_labelForEachRun->size[0])
                       - 1]) {
                  c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_root_p, 1, c15_labelForEachRun->size[0])
                    - 1] = c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_labelForEachRun->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_p, 1,
                      c15_labelForEachRun->size[0]) - 1], 1,
                     c15_labelForEachRun->size[0]) - 1];
                  c15_root_p = c15_labelForEachRun->
                    data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_p, 1,
                    c15_labelForEachRun->size[0]) - 1];
                }

                if (c15_root_k != c15_root_p) {
                  c15_b_root_k = c15_root_k;
                  c15_b_root_p = c15_root_p;
                  c15_f_k = c15_e_k;
                  c15_c_p = c15_b_p;
                  if (c15_b_root_p < c15_b_root_k) {
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_b_root_k, 1, c15_labelForEachRun->size
                       [0]) - 1] = c15_b_root_p;
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_f_k, 1, c15_labelForEachRun->size[0]) -
                      1] = c15_b_root_p;
                  } else {
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_b_root_p, 1, c15_labelForEachRun->size
                       [0]) - 1] = c15_b_root_k;
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_c_p, 1, c15_labelForEachRun->size[0]) -
                      1] = c15_b_root_k;
                  }
                }
              }
            }
          }
        }
      }

      if (c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] == 0) {
        c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] = c15_nextLabel;
        c15_nextLabel++;
      }

      c15_c_k++;
    }
  }

  if (c15_numRuns == 0) {
    for (c15_i101 = 0; c15_i101 < 256000; c15_i101++) {
      c15_b_L[c15_i101] = 0.0;
    }
  } else {
    c15_emxInit_int32_T(chartInstance, &c15_labelsRenumbered, 1,
                        &c15_db_emlrtRTEI);
    c15_i102 = c15_labelsRenumbered->size[0];
    c15_labelsRenumbered->size[0] = c15_labelForEachRun->size[0];
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelsRenumbered, c15_i102,
      &c15_bb_emlrtRTEI);
    c15_numComponents = 0.0;
    for (c15_i104 = 0; c15_i104 < 256000; c15_i104++) {
      c15_b_L[c15_i104] = 0.0;
    }

    c15_b = c15_numRuns;
    c15_b_b = c15_b;
    if (1 > c15_b_b) {
      c15_overflow = false;
    } else {
      c15_overflow = (c15_b_b > 2147483646);
    }

    if (c15_overflow) {
      c15_check_forloop_overflow_error(chartInstance, true);
    }

    for (c15_d_k = 1; c15_d_k <= c15_numRuns; c15_d_k++) {
      if (c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelForEachRun->size[0]) - 1] == c15_d_k) {
        c15_numComponents++;
        c15_labelsRenumbered->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1] = (int32_T)
          c15_numComponents;
      }

      c15_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1] =
        c15_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_labelForEachRun->data[sf_eml_array_bounds_check
         (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
          c15_d_k, 1, c15_labelForEachRun->size[0]) - 1], 1,
         c15_labelsRenumbered->size[0]) - 1];
      c15_i105 = c15_startRow->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_startRow->size[0]) - 1];
      c15_i106 = c15_endRow->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_endRow->size[0]) - 1];
      for (c15_idx = c15_i105; c15_idx <= c15_i106; c15_idx++) {
        c15_b_L[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_idx, 1, 400) +
                 400 * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                   chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_startCol->
                   data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_d_k, 1,
                    c15_startCol->size[0]) - 1], 1, 640) - 1)) - 1] = (real_T)
          c15_labelsRenumbered->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1];
      }
    }

    c15_emxFree_int32_T(chartInstance, &c15_labelsRenumbered);
  }

  c15_emxFree_int32_T(chartInstance, &c15_labelForEachRun);
  c15_emxFree_int32_T(chartInstance, &c15_startCol);
  c15_emxFree_int32_T(chartInstance, &c15_endRow);
  c15_emxFree_int32_T(chartInstance, &c15_startRow);
}

static void c15_check_forloop_overflow_error(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, boolean_T c15_overflow)
{
  const mxArray *c15_y = NULL;
  static char_T c15_cv3[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *c15_b_y = NULL;
  const mxArray *c15_c_y = NULL;
  static char_T c15_cv4[5] = { 'i', 'n', 't', '3', '2' };

  (void)chartInstance;
  (void)c15_overflow;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_cv3, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_cv4, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c15_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 2U,
    14, c15_b_y, 14, c15_c_y)));
}

static void c15_padarray(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  real_T c15_b_varargin_1[256000], real_T c15_b[258084])
{
  int32_T c15_i;
  int32_T c15_b_i;
  real_T c15_c_i;
  int32_T c15_j;
  int32_T c15_b_j;
  real_T c15_c_j;
  real_T c15_a;
  int32_T c15_c;
  int32_T c15_d_j;
  real_T c15_b_a;
  int32_T c15_b_c;
  int32_T c15_d_i;
  real_T c15_c_a;
  int32_T c15_c_c;
  real_T c15_d_a;
  int32_T c15_d_c;
  for (c15_i = 0; c15_i < 402; c15_i++) {
    c15_c_i = 1.0 + (real_T)c15_i;
    c15_b[(int32_T)c15_c_i - 1] = 0.0;
  }

  for (c15_b_i = 0; c15_b_i < 402; c15_b_i++) {
    c15_c_i = 1.0 + (real_T)c15_b_i;
    c15_b[(int32_T)c15_c_i + 257681] = 0.0;
  }

  for (c15_j = 0; c15_j < 640; c15_j++) {
    c15_c_j = 1.0 + (real_T)c15_j;
    c15_a = c15_c_j;
    c15_c = (int32_T)c15_a;
    c15_b[402 * c15_c] = 0.0;
  }

  for (c15_b_j = 0; c15_b_j < 640; c15_b_j++) {
    c15_c_j = 1.0 + (real_T)c15_b_j;
    c15_b_a = c15_c_j;
    c15_b_c = (int32_T)c15_b_a;
    c15_b[401 + 402 * c15_b_c] = 0.0;
  }

  for (c15_d_j = 0; c15_d_j < 640; c15_d_j++) {
    c15_c_j = 1.0 + (real_T)c15_d_j;
    for (c15_d_i = 0; c15_d_i < 400; c15_d_i++) {
      c15_c_i = 1.0 + (real_T)c15_d_i;
      c15_c_a = c15_c_i;
      c15_c_c = (int32_T)c15_c_a;
      c15_d_a = c15_c_j;
      c15_d_c = (int32_T)c15_d_a;
      c15_b[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_c_c + 1, 1, 402) +
             402 * c15_d_c) - 1] = c15_b_varargin_1[((int32_T)c15_c_i + 400 *
        ((int32_T)c15_c_j - 1)) - 1];
    }
  }
}

static void c15_BoundaryFinder_findBoundaries
  (SFc15_VehicleSimME131InstanceStruct *chartInstance,
   c15_images_internal_coder_BoundaryFinder *c15_obj, c15_emxArray_cell_wrap_0
   *c15_b_B)
{
  int32_T c15_M;
  int32_T c15_N;
  c15_images_internal_coder_BoundaryFinder *c15_b_obj;
  int32_T c15_b_M;
  int32_T c15_b_N;
  real_T c15_numRegions;
  int32_T c15_numElements;
  int32_T c15_b;
  int32_T c15_b_b;
  boolean_T c15_overflow;
  int32_T c15_k;
  c15_emxArray_boolean_T *c15_regionHasBeenTraced;
  real_T c15_label;
  c15_emxArray_cell_wrap_0 *c15_r6;
  int32_T c15_b_numRegions[2];
  int32_T c15_i107;
  int32_T c15_i108;
  int32_T c15_i109;
  int32_T c15_loop_ub;
  int32_T c15_i110;
  c15_images_internal_coder_BoundaryFinder *c15_c_obj;
  int32_T c15_c_M;
  int32_T c15_i111;
  int32_T c15_i112;
  int32_T c15_i113;
  static int32_T c15_ndl4c[8] = { 1, 2, 3, 0, 0, 0, 0, 0 };

  int32_T c15_i114;
  static int32_T c15_ndl8c[8] = { 1, 2, 3, 4, 5, 6, 7, 0 };

  static int32_T c15_nsdl4c[8] = { 3, 0, 1, 2, 0, 0, 0, 0 };

  static int32_T c15_nsdl8c[8] = { 7, 7, 1, 1, 3, 3, 5, 5 };

  c15_images_internal_coder_BoundaryFinder *c15_d_obj;
  int32_T c15_i115;
  int32_T c15_c;
  c15_emxArray_real_T *c15_boundary;
  c15_emxArray_int32_T *c15_scratch;
  c15_emxArray_int32_T *c15_b_scratch;
  c15_emxArray_int32_T *c15_r7;
  int32_T c15_i116;
  int32_T c15_r;
  int32_T c15_linearIdx;
  int32_T c15_b_label;
  real_T c15_previousLabel;
  c15_images_internal_coder_BoundaryFinder *c15_e_obj;
  int32_T c15_idx;
  int32_T c15_i117;
  int32_T c15_i118;
  int32_T c15_iv2[200];
  int32_T c15_scratchLength;
  boolean_T c15_isDone;
  int32_T c15_numPixels;
  int32_T c15_currentPixel;
  int32_T c15_nextSearchDir;
  int32_T c15_initDepartureDir;
  c15_images_internal_coder_BoundaryFinder *c15_f_obj;
  int32_T c15_direction;
  int32_T c15_b_numPixels;
  boolean_T c15_foundNextPixel;
  int32_T c15_i119;
  real_T c15_d2;
  int32_T c15_i120;
  int32_T c15_b_k;
  int32_T c15_c_b;
  int32_T c15_d_b;
  int32_T c15_a;
  boolean_T c15_b_overflow;
  int32_T c15_e_b;
  int32_T c15_neighbor;
  real_T c15_d3;
  real_T c15_x;
  int32_T c15_c_k;
  real_T c15_b_x;
  boolean_T c15_f_b;
  int32_T c15_i121;
  int32_T c15_b_a;
  int32_T c15_i122;
  int32_T c15_g_b;
  int32_T c15_col;
  int32_T c15_i123;
  int32_T c15_row;
  int32_T c15_c_B;
  int32_T c15_d_B;
  int32_T c15_e_B;
  int32_T c15_f_B;
  int32_T c15_scratchLengthIn;
  int32_T c15_g_B;
  int32_T c15_h_b;
  int32_T c15_b_loop_ub;
  int32_T c15_b_scratchLength;
  int32_T c15_i124;
  int32_T c15_i125;
  int32_T c15_c_loop_ub;
  int32_T c15_i126;
  int32_T c15_i127;
  int32_T c15_i_b;
  int32_T c15_j_b;
  boolean_T c15_c_overflow;
  int32_T c15_d_k;
  int32_T c15_i128;
  int32_T c15_d_loop_ub;
  int32_T c15_i129;
  boolean_T guard1 = false;
  boolean_T exitg1;
  c15_M = c15_obj->numRows;
  c15_N = c15_obj->numCols - 1;
  c15_b_obj = c15_obj;
  c15_b_M = c15_b_obj->numRows;
  c15_b_N = c15_b_obj->numCols;
  c15_numRegions = 0.0;
  c15_numElements = c15_b_M * c15_b_N;
  c15_b = c15_numElements;
  c15_b_b = c15_b;
  if (1 > c15_b_b) {
    c15_overflow = false;
  } else {
    c15_overflow = (c15_b_b > 2147483646);
  }

  if (c15_overflow) {
    c15_check_forloop_overflow_error(chartInstance, true);
  }

  for (c15_k = 1; c15_k <= c15_numElements; c15_k++) {
    c15_label = c15_b_obj->paddedLabelMatrix[sf_eml_array_bounds_check
      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
       c15_k, 1, 258084) - 1];
    if (c15_label > c15_numRegions) {
      c15_numRegions = c15_label;
    }
  }

  c15_emxInit_boolean_T(chartInstance, &c15_regionHasBeenTraced, 1,
                        &c15_jb_emlrtRTEI);
  c15_emxInit_cell_wrap_0(chartInstance, &c15_r6, 1, &c15_ib_emlrtRTEI);
  c15_b_numRegions[0] = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
    c15_numRegions);
  c15_b_numRegions[1] = 1;
  c15_i107 = c15_r6->size[0];
  c15_r6->size[0] = c15_b_numRegions[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_r6, c15_i107,
    &c15_ib_emlrtRTEI);
  c15_i108 = c15_b_B->size[0];
  c15_b_B->size[0] = c15_r6->size[0];
  c15_emxEnsureCapacity_cell_wrap_0(chartInstance, c15_b_B, c15_i108,
    &c15_ib_emlrtRTEI);
  c15_i109 = c15_regionHasBeenTraced->size[0];
  c15_regionHasBeenTraced->size[0] = (int32_T)sf_integer_check(chartInstance->S,
    1U, 0U, 0U, c15_numRegions);
  c15_emxEnsureCapacity_boolean_T(chartInstance, c15_regionHasBeenTraced,
    c15_i109, &c15_jb_emlrtRTEI);
  c15_loop_ub = (int32_T)sf_integer_check(chartInstance->S, 1U, 0U, 0U,
    c15_numRegions) - 1;
  c15_emxFree_cell_wrap_0(chartInstance, &c15_r6);
  for (c15_i110 = 0; c15_i110 <= c15_loop_ub; c15_i110++) {
    c15_regionHasBeenTraced->data[c15_i110] = false;
  }

  if (c15_numRegions > 0.0) {
    c15_c_obj = c15_obj;
    c15_c_obj->startMarker = -2.0;
    c15_c_obj->boundaryMarker = -3.0;
    c15_c_M = c15_c_obj->numRows;
    if (c15_c_obj->conn == 8.0) {
      c15_c_obj->neighborOffsets[0] = -1;
      c15_c_obj->neighborOffsets[1] = c15_c_M - 1;
      c15_c_obj->neighborOffsets[2] = c15_c_M;
      c15_c_obj->neighborOffsets[3] = c15_c_M + 1;
      c15_c_obj->neighborOffsets[4] = 1;
      c15_c_obj->neighborOffsets[5] = 1 - c15_c_M;
      c15_c_obj->neighborOffsets[6] = -c15_c_M;
      c15_c_obj->neighborOffsets[7] = -c15_c_M - 1;
      c15_c_obj->validationOffsets[0] = -1;
      c15_c_obj->validationOffsets[1] = c15_c_M;
      c15_c_obj->validationOffsets[2] = 1;
      c15_c_obj->validationOffsets[3] = -c15_c_M;
      c15_c_obj->validationOffsets[4] = 0;
      c15_c_obj->validationOffsets[5] = 0;
      c15_c_obj->validationOffsets[6] = 0;
      c15_c_obj->validationOffsets[7] = 0;
    } else {
      c15_c_obj->neighborOffsets[0] = -1;
      c15_c_obj->neighborOffsets[1] = c15_c_M;
      c15_c_obj->neighborOffsets[2] = 1;
      c15_c_obj->neighborOffsets[3] = -c15_c_M;
      c15_c_obj->neighborOffsets[4] = 0;
      c15_c_obj->neighborOffsets[5] = 0;
      c15_c_obj->neighborOffsets[6] = 0;
      c15_c_obj->neighborOffsets[7] = 0;
      c15_c_obj->validationOffsets[0] = -1;
      c15_c_obj->validationOffsets[1] = c15_c_M - 1;
      c15_c_obj->validationOffsets[2] = c15_c_M;
      c15_c_obj->validationOffsets[3] = c15_c_M + 1;
      c15_c_obj->validationOffsets[4] = 1;
      c15_c_obj->validationOffsets[5] = 1 - c15_c_M;
      c15_c_obj->validationOffsets[6] = -c15_c_M;
      c15_c_obj->validationOffsets[7] = -c15_c_M - 1;
    }

    if (c15_c_obj->conn == 8.0) {
      for (c15_i112 = 0; c15_i112 < 8; c15_i112++) {
        c15_c_obj->nextDirectionLut[c15_i112] = c15_ndl8c[c15_i112];
      }

      for (c15_i114 = 0; c15_i114 < 8; c15_i114++) {
        c15_c_obj->nextSearchDirectionLut[c15_i114] = c15_nsdl8c[c15_i114];
      }
    } else {
      for (c15_i111 = 0; c15_i111 < 8; c15_i111++) {
        c15_c_obj->nextDirectionLut[c15_i111] = c15_ndl4c[c15_i111];
      }

      for (c15_i113 = 0; c15_i113 < 8; c15_i113++) {
        c15_c_obj->nextSearchDirectionLut[c15_i113] = c15_nsdl4c[c15_i113];
      }
    }

    c15_d_obj = c15_obj;
    c15_d_obj->nextSearchDir = 1;
    c15_i115 = c15_N;
    c15_c = 1;
    c15_emxInit_real_T(chartInstance, &c15_boundary, 2, &c15_qb_emlrtRTEI);
    c15_emxInit_int32_T(chartInstance, &c15_scratch, 1, &c15_rb_emlrtRTEI);
    c15_emxInit_int32_T(chartInstance, &c15_b_scratch, 1, &c15_ib_emlrtRTEI);
    c15_emxInit_int32_T(chartInstance, &c15_r7, 1, &c15_nb_emlrtRTEI);
    while (c15_c + 1 <= c15_i115) {
      c15_i116 = c15_M;
      for (c15_r = 2; c15_r < c15_i116; c15_r++) {
        c15_linearIdx = c15_M * c15_c + c15_r;
        c15_b_label = (int32_T)c15_obj->
          paddedLabelMatrix[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_linearIdx, 1, 258084) - 1];
        c15_previousLabel = c15_obj->paddedLabelMatrix[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_linearIdx - 1, 1, 258084) - 1];
        if ((c15_b_label > 0) && (c15_previousLabel == 0.0) &&
            (!c15_regionHasBeenTraced->data[sf_eml_array_bounds_check
             (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
              MAX_uint32_T, c15_b_label, 1, c15_regionHasBeenTraced->size[0]) -
             1])) {
          c15_e_obj = c15_obj;
          c15_idx = c15_linearIdx;
          for (c15_i117 = 0; c15_i117 < 200; c15_i117++) {
            c15_iv2[c15_i117] = 0;
          }

          c15_i118 = c15_scratch->size[0];
          c15_scratch->size[0] = 200;
          c15_emxEnsureCapacity_int32_T(chartInstance, c15_scratch, c15_i118,
            &c15_kb_emlrtRTEI);
          c15_scratchLength = 200;
          c15_scratch->data[0] = c15_idx;
          c15_e_obj->paddedLabelMatrix[c15_idx - 1] = c15_e_obj->startMarker;
          c15_isDone = false;
          c15_numPixels = 2;
          c15_currentPixel = c15_idx;
          c15_nextSearchDir = c15_e_obj->nextSearchDir;
          c15_initDepartureDir = -1;
          while (!c15_isDone) {
            c15_direction = c15_nextSearchDir;
            c15_foundNextPixel = false;
            c15_d2 = c15_e_obj->conn;
            c15_i120 = (int32_T)c15_d2;
            _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c15_d2, mxDOUBLE_CLASS,
              c15_i120);
            c15_b_k = 0;
            guard1 = false;
            exitg1 = false;
            while ((!exitg1) && (c15_b_k <= c15_i120 - 1)) {
              c15_a = c15_currentPixel;
              c15_e_b = c15_e_obj->neighborOffsets[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_direction + 1, 1, 8) - 1];
              c15_neighbor = c15_a + c15_e_b;
              c15_d3 = c15_e_obj->paddedLabelMatrix[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_neighbor, 1, 258084) - 1];
              c15_x = c15_d3;
              c15_b_x = c15_x;
              c15_f_b = muDoubleScalarIsNaN(c15_b_x);
              if (c15_f_b) {
                c15_error(chartInstance);
              }

              if (c15_d3 != 0.0) {
                if ((c15_e_obj->paddedLabelMatrix[c15_currentPixel - 1] ==
                     c15_e_obj->startMarker) && (c15_initDepartureDir == -1)) {
                  c15_initDepartureDir = c15_direction;
                  guard1 = true;
                } else if ((c15_e_obj->paddedLabelMatrix[c15_currentPixel - 1] ==
                            c15_e_obj->startMarker) && (c15_initDepartureDir ==
                            c15_direction)) {
                  c15_isDone = true;
                  c15_foundNextPixel = true;
                } else {
                  guard1 = true;
                }

                exitg1 = true;
              } else {
                c15_direction = c15_e_obj->
                  nextDirectionLut[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c15_direction + 1, 1, 8) - 1];
                c15_b_k++;
                guard1 = false;
              }
            }

            if (guard1) {
              c15_nextSearchDir = c15_e_obj->
                nextSearchDirectionLut[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_direction + 1, 1, 8) - 1];
              c15_foundNextPixel = true;
              if (c15_scratchLength <= c15_numPixels) {
                c15_scratchLengthIn = c15_scratchLength;
                c15_h_b = c15_scratchLengthIn;
                c15_b_scratchLength = c15_h_b << 1;
                c15_i125 = c15_r7->size[0];
                c15_r7->size[0] = c15_b_scratchLength;
                c15_emxEnsureCapacity_int32_T(chartInstance, c15_r7, c15_i125,
                  &c15_nb_emlrtRTEI);
                c15_c_loop_ub = c15_b_scratchLength - 1;
                for (c15_i126 = 0; c15_i126 <= c15_c_loop_ub; c15_i126++) {
                  c15_r7->data[c15_i126] = 0;
                }

                c15_i127 = c15_b_scratch->size[0];
                c15_b_scratch->size[0] = c15_r7->size[0];
                c15_emxEnsureCapacity_int32_T(chartInstance, c15_b_scratch,
                  c15_i127, &c15_ob_emlrtRTEI);
                c15_i_b = c15_scratchLengthIn;
                c15_j_b = c15_i_b;
                if (1 > c15_j_b) {
                  c15_c_overflow = false;
                } else {
                  c15_c_overflow = (c15_j_b > 2147483646);
                }

                if (c15_c_overflow) {
                  c15_check_forloop_overflow_error(chartInstance, true);
                }

                for (c15_d_k = 1; c15_d_k <= c15_scratchLengthIn; c15_d_k++) {
                  c15_b_scratch->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_d_k, 1, c15_b_scratch->size[0]) - 1] =
                    c15_scratch->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_d_k, 1, c15_scratch->size[0]) - 1];
                }

                c15_i128 = c15_scratch->size[0];
                c15_scratch->size[0] = c15_b_scratch->size[0];
                c15_emxEnsureCapacity_int32_T(chartInstance, c15_scratch,
                  c15_i128, &c15_pb_emlrtRTEI);
                c15_d_loop_ub = c15_b_scratch->size[0] - 1;
                for (c15_i129 = 0; c15_i129 <= c15_d_loop_ub; c15_i129++) {
                  c15_scratch->data[c15_i129] = c15_b_scratch->data[c15_i129];
                }

                c15_scratchLength = c15_b_scratchLength;
              }

              c15_scratch->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_numPixels, 1, c15_scratch->size[0]) - 1] =
                c15_neighbor;
              c15_numPixels++;
              if (c15_numPixels - 1 == MAX_int32_T) {
                c15_isDone = true;
              } else {
                if (c15_e_obj->paddedLabelMatrix[c15_neighbor - 1] !=
                    c15_e_obj->startMarker) {
                  c15_e_obj->paddedLabelMatrix[c15_neighbor - 1] =
                    c15_e_obj->boundaryMarker;
                }

                c15_currentPixel = c15_neighbor;
              }
            }

            if (!c15_foundNextPixel) {
              c15_numPixels = 3;
              c15_scratch->data[1] = c15_scratch->data[0];
              c15_isDone = true;
            }
          }

          c15_f_obj = c15_e_obj;
          c15_b_numPixels = c15_numPixels - 1;
          c15_i119 = c15_boundary->size[0] * c15_boundary->size[1];
          c15_boundary->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
            c15_b_numPixels);
          c15_boundary->size[1] = 2;
          c15_emxEnsureCapacity_real_T(chartInstance, c15_boundary, c15_i119,
            &c15_lb_emlrtRTEI);
          c15_c_b = c15_b_numPixels;
          c15_d_b = c15_c_b;
          if (1 > c15_d_b) {
            c15_b_overflow = false;
          } else {
            c15_b_overflow = (c15_d_b > 2147483646);
          }

          if (c15_b_overflow) {
            c15_check_forloop_overflow_error(chartInstance, true);
          }

          for (c15_c_k = 1; c15_c_k <= c15_b_numPixels; c15_c_k++) {
            c15_b_a = c15_scratch->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, c15_c_k, 1, c15_scratch->size[0]) - 1];
            c15_g_b = c15_f_obj->numRows;
            c15_col = c15_div_s32(chartInstance, c15_b_a, c15_g_b, 1U, 0, 0);
            c15_row = c15_scratch->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, c15_c_k, 1, c15_scratch->size[0]) - 1] - c15_col *
              c15_f_obj->numRows;
            c15_boundary->data[sf_eml_array_bounds_check
              (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
               MAX_uint32_T, c15_c_k, 1, c15_boundary->size[0]) - 1] = (real_T)
              (c15_row - 1);
            c15_boundary->data[(sf_eml_array_bounds_check
                                (sfGlobalDebugInstanceStruct, chartInstance->S,
                                 1U, 0, 0, MAX_uint32_T, c15_c_k, 1,
                                 c15_boundary->size[0]) + c15_boundary->size[0])
              - 1] = (real_T)c15_col;
          }

          c15_i121 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_b_label - 1, 0,
            c15_b_B->size[0] - 1);
          c15_i122 = c15_b_B->data[c15_i121].f1->size[0] * c15_b_B->
            data[c15_i121].f1->size[1];
          c15_b_B->data[c15_i121].f1->size[0] = c15_boundary->size[0];
          c15_i123 = sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_b_label - 1, 0,
            c15_b_B->size[0] - 1);
          c15_b_B->data[c15_i123].f1->size[1] = 2;
          c15_emxEnsureCapacity_real_T(chartInstance, c15_b_B->data[c15_i123].f1,
            c15_i122, &c15_mb_emlrtRTEI);
          c15_c_B = c15_b_B->size[0];
          c15_d_B = c15_b_B->size[0];
          c15_e_B = c15_b_B->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_b_label - 1, 0, c15_d_B - 1)].f1->size[0];
          c15_f_B = c15_b_B->size[0];
          c15_g_B = c15_b_B->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_b_label - 1, 0, c15_f_B - 1)].f1->size[1];
          c15_b_loop_ub = c15_boundary->size[0] * c15_boundary->size[1] - 1;
          for (c15_i124 = 0; c15_i124 <= c15_b_loop_ub; c15_i124++) {
            c15_b_B->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
              chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_b_label - 1, 0,
              c15_c_B - 1)].f1->data[c15_i124] = c15_boundary->data[c15_i124];
          }

          c15_regionHasBeenTraced->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_b_label, 1, c15_regionHasBeenTraced->size[0]) - 1]
            = true;
        }
      }

      c15_c++;
    }

    c15_emxFree_int32_T(chartInstance, &c15_r7);
    c15_emxFree_int32_T(chartInstance, &c15_b_scratch);
    c15_emxFree_int32_T(chartInstance, &c15_scratch);
    c15_emxFree_real_T(chartInstance, &c15_boundary);
  }

  c15_emxFree_boolean_T(chartInstance, &c15_regionHasBeenTraced);
}

static void c15_error(SFc15_VehicleSimME131InstanceStruct *chartInstance)
{
  const mxArray *c15_y = NULL;
  static char_T c15_cv5[19] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'l',
    'o', 'g', 'i', 'c', 'a', 'l', 'n', 'a', 'n' };

  const mxArray *c15_b_y = NULL;
  (void)chartInstance;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_cv5, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_cv5, 10, 0U, 1U, 0U, 2, 1, 19),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 2U, 14, c15_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "getString",
    1U, 1U, 14, sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U, 1U,
    14, c15_b_y)));
}

static void c15_imclearborder(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], boolean_T c15_outputImage[256000])
{
  int32_T c15_i130;
  c15_images_internal_coder_strel_StructuringElementHelper *c15_iobj_0;
  c15_images_internal_coder_strel_StructuringElementHelper c15_se;
  c15_images_internal_coder_strel_StructuringElementHelper *c15_obj;
  c15_images_internal_coder_strel_StructuringElementHelper *c15_b_se;
  c15_images_internal_coder_strel_StructuringElementHelper *c15_this;
  int32_T c15_i131;
  static boolean_T c15_nhood[9] = { false, true, false, true, true, true, false,
    true, false };

  int32_T c15_i132;
  int32_T c15_i133;
  real_T c15_asizeT[2];
  real_T c15_nsizeT[2];
  int32_T c15_i134;
  int32_T c15_i135;
  int32_T c15_i136;
  int32_T c15_i;
  int32_T c15_i137;
  int32_T c15_i138;
  int32_T c15_i139;
  int32_T c15_i140;
  for (c15_i130 = 0; c15_i130 < 256000; c15_i130++) {
    c15_outputImage[c15_i130] = c15_b_varargin_1[c15_i130];
  }

  c15_b_padarray(chartInstance, chartInstance->c15_paddedIm);
  c15_iobj_0 = &c15_se;
  c15_obj = c15_iobj_0;
  c15_b_se = c15_obj;
  c15_this = c15_b_se;
  c15_b_se = c15_this;
  c15_b_se->matlabCodegenIsDeleted = false;
  for (c15_i131 = 0; c15_i131 < 9; c15_i131++) {
    c15_b_se->Neighborhood[c15_i131] = c15_nhood[c15_i131];
  }

  c15_b_se->Dimensionality = 2.0;
  for (c15_i132 = 0; c15_i132 < 2; c15_i132++) {
    c15_asizeT[c15_i132] = 402.0 + 240.0 * (real_T)c15_i132;
  }

  for (c15_i133 = 0; c15_i133 < 2; c15_i133++) {
    c15_nsizeT[c15_i133] = 3.0;
  }

  erode_binary_twod_tbb(chartInstance->c15_paddedIm, c15_asizeT, 2.0, c15_nhood,
                        c15_nsizeT, 2.0, chartInstance->c15_B);
  c15_i134 = 0;
  c15_i135 = 0;
  for (c15_i136 = 0; c15_i136 < 640; c15_i136++) {
    for (c15_i137 = 0; c15_i137 < 400; c15_i137++) {
      chartInstance->c15_borderlessIm[c15_i137 + c15_i134] =
        chartInstance->c15_B[(c15_i137 + c15_i135) + 403];
    }

    c15_i134 += 400;
    c15_i135 += 402;
  }

  for (c15_i = 0; c15_i < 256000; c15_i++) {
    if (chartInstance->c15_borderlessIm[c15_i]) {
      c15_outputImage[c15_i] = false;
    }
  }

  for (c15_i138 = 0; c15_i138 < 2; c15_i138++) {
    c15_asizeT[c15_i138] = 400.0 + 240.0 * (real_T)c15_i138;
  }

  ippreconstruct_uint8(c15_outputImage, c15_b_varargin_1, c15_asizeT, 1.0);
  for (c15_i139 = 0; c15_i139 < 256000; c15_i139++) {
    c15_outputImage[c15_i139] = !c15_outputImage[c15_i139];
  }

  for (c15_i140 = 0; c15_i140 < 256000; c15_i140++) {
    c15_outputImage[c15_i140] = (c15_b_varargin_1[c15_i140] &&
      c15_outputImage[c15_i140]);
  }
}

static void c15_b_padarray(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b[258084])
{
  int32_T c15_i;
  int32_T c15_b_i;
  real_T c15_c_i;
  int32_T c15_j;
  int32_T c15_b_j;
  real_T c15_c_j;
  real_T c15_a;
  int32_T c15_c;
  int32_T c15_d_j;
  real_T c15_b_a;
  int32_T c15_b_c;
  int32_T c15_d_i;
  real_T c15_c_a;
  int32_T c15_c_c;
  real_T c15_d_a;
  int32_T c15_d_c;
  (void)chartInstance;
  for (c15_i = 0; c15_i < 402; c15_i++) {
    c15_c_i = 1.0 + (real_T)c15_i;
    c15_b[(int32_T)c15_c_i - 1] = false;
  }

  for (c15_b_i = 0; c15_b_i < 402; c15_b_i++) {
    c15_c_i = 1.0 + (real_T)c15_b_i;
    c15_b[(int32_T)c15_c_i + 257681] = false;
  }

  for (c15_j = 0; c15_j < 640; c15_j++) {
    c15_c_j = 1.0 + (real_T)c15_j;
    c15_a = c15_c_j;
    c15_c = (int32_T)c15_a;
    c15_b[402 * c15_c] = false;
  }

  for (c15_b_j = 0; c15_b_j < 640; c15_b_j++) {
    c15_c_j = 1.0 + (real_T)c15_b_j;
    c15_b_a = c15_c_j;
    c15_b_c = (int32_T)c15_b_a;
    c15_b[401 + 402 * c15_b_c] = false;
  }

  for (c15_d_j = 0; c15_d_j < 640; c15_d_j++) {
    c15_c_j = 1.0 + (real_T)c15_d_j;
    for (c15_d_i = 0; c15_d_i < 400; c15_d_i++) {
      c15_c_i = 1.0 + (real_T)c15_d_i;
      c15_c_a = c15_c_i;
      c15_c_c = (int32_T)c15_c_a;
      c15_d_a = c15_c_j;
      c15_d_c = (int32_T)c15_d_a;
      c15_b[c15_c_c + 402 * c15_d_c] = true;
    }
  }
}

static void c15_b_bwlabel(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  boolean_T c15_b_varargin_1[256000], real_T c15_b_L[256000])
{
  int32_T c15_numRuns;
  int32_T c15_col;
  c15_emxArray_int32_T *c15_startRow;
  real_T c15_b_col;
  c15_emxArray_int32_T *c15_endRow;
  c15_emxArray_int32_T *c15_startCol;
  c15_emxArray_int32_T *c15_labelForEachRun;
  int32_T c15_k;
  int32_T c15_i141;
  int32_T c15_i142;
  real_T c15_b_k;
  int32_T c15_i143;
  int32_T c15_i144;
  int32_T c15_i145;
  int32_T c15_i146;
  int32_T c15_runCounter;
  int32_T c15_i147;
  int32_T c15_c_col;
  int32_T c15_i148;
  real_T c15_d_col;
  int32_T c15_row;
  c15_emxArray_int32_T *c15_labelsRenumbered;
  int32_T c15_i149;
  int32_T c15_loop_ub;
  int32_T c15_i150;
  int32_T c15_i151;
  real_T c15_numComponents;
  int32_T c15_c_k;
  int32_T c15_i152;
  int32_T c15_currentColumn;
  int32_T c15_nextLabel;
  int32_T c15_firstRunOnPreviousColumn;
  int32_T c15_b;
  int32_T c15_lastRunOnPreviousColumn;
  int32_T c15_b_b;
  int32_T c15_firstRunOnThisColumn;
  boolean_T c15_overflow;
  int32_T c15_d_k;
  int32_T c15_p;
  int32_T c15_i153;
  int32_T c15_i154;
  int32_T c15_idx;
  int32_T c15_e_k;
  int32_T c15_b_p;
  int32_T c15_node;
  int32_T c15_root_k;
  int32_T c15_b_node;
  int32_T c15_root_p;
  int32_T c15_b_root_k;
  int32_T c15_b_root_p;
  int32_T c15_f_k;
  int32_T c15_c_p;
  c15_numRuns = 0;
  for (c15_col = 0; c15_col < 640; c15_col++) {
    c15_b_col = 1.0 + (real_T)c15_col;
    if (c15_b_varargin_1[400 * ((int32_T)c15_b_col - 1)]) {
      c15_numRuns++;
    }

    for (c15_k = 0; c15_k < 399; c15_k++) {
      c15_b_k = 2.0 + (real_T)c15_k;
      if (c15_b_varargin_1[((int32_T)c15_b_k + 400 * ((int32_T)c15_b_col - 1)) -
          1] && (!c15_b_varargin_1[((int32_T)(c15_b_k - 1.0) + 400 * ((int32_T)
             c15_b_col - 1)) - 1])) {
        c15_numRuns++;
      }
    }
  }

  c15_emxInit_int32_T(chartInstance, &c15_startRow, 1, &c15_eb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_endRow, 1, &c15_fb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_startCol, 1, &c15_gb_emlrtRTEI);
  c15_emxInit_int32_T(chartInstance, &c15_labelForEachRun, 1, &c15_hb_emlrtRTEI);
  if (c15_numRuns == 0) {
    c15_i142 = c15_startRow->size[0];
    c15_startRow->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startRow, c15_i142,
      &c15_v_emlrtRTEI);
    c15_i144 = c15_endRow->size[0];
    c15_endRow->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_endRow, c15_i144,
      &c15_x_emlrtRTEI);
    c15_i146 = c15_startCol->size[0];
    c15_startCol->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startCol, c15_i146,
      &c15_y_emlrtRTEI);
    c15_i147 = c15_labelForEachRun->size[0];
    c15_labelForEachRun->size[0] = 0;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelForEachRun, c15_i147,
      &c15_ab_emlrtRTEI);
    c15_numRuns = 0;
  } else {
    c15_i141 = c15_startRow->size[0];
    c15_startRow->size[0] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)
      c15_numRuns);
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startRow, c15_i141,
      &c15_w_emlrtRTEI);
    c15_i143 = c15_endRow->size[0];
    c15_endRow->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_endRow, c15_i143,
      &c15_w_emlrtRTEI);
    c15_i145 = c15_startCol->size[0];
    c15_startCol->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_startCol, c15_i145,
      &c15_w_emlrtRTEI);
    c15_runCounter = 1;
    for (c15_c_col = 0; c15_c_col < 640; c15_c_col++) {
      c15_d_col = 1.0 + (real_T)c15_c_col;
      c15_row = 1;
      while (c15_row <= 400) {
        while ((c15_row <= 400) && (!c15_b_varargin_1[(c15_row + 400 * ((int32_T)
                  c15_d_col - 1)) - 1])) {
          c15_row++;
        }

        if ((c15_row <= 400) && c15_b_varargin_1[(c15_row + 400 * ((int32_T)
              c15_d_col - 1)) - 1]) {
          c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_runCounter, 1, c15_startCol->size[0]) - 1] =
            (int32_T)c15_d_col;
          c15_startRow->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_runCounter, 1, c15_startRow->size[0]) - 1] =
            c15_row;
          while ((c15_row <= 400) && c15_b_varargin_1[(c15_row + 400 * ((int32_T)
                   c15_d_col - 1)) - 1]) {
            c15_row++;
          }

          c15_endRow->data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
            chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_runCounter, 1,
            c15_endRow->size[0]) - 1] = c15_row - 1;
          c15_runCounter++;
        }
      }
    }

    c15_i148 = c15_labelForEachRun->size[0];
    c15_labelForEachRun->size[0] = c15_numRuns;
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelForEachRun, c15_i148,
      &c15_cb_emlrtRTEI);
    c15_loop_ub = c15_numRuns - 1;
    for (c15_i151 = 0; c15_i151 <= c15_loop_ub; c15_i151++) {
      c15_labelForEachRun->data[c15_i151] = 0;
    }

    c15_c_k = 1;
    c15_currentColumn = 2;
    c15_nextLabel = 1;
    c15_firstRunOnPreviousColumn = -1;
    c15_lastRunOnPreviousColumn = 0;
    c15_firstRunOnThisColumn = 1;
    while (c15_c_k <= c15_numRuns) {
      if (c15_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_startCol->size[0]) - 1] == c15_currentColumn) {
        c15_firstRunOnPreviousColumn = c15_firstRunOnThisColumn;
        c15_firstRunOnThisColumn = c15_c_k;
        c15_lastRunOnPreviousColumn = c15_c_k;
        c15_currentColumn = c15_startCol->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_startCol->size[0]) - 1] + 1;
      } else {
        if (c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_c_k, 1, c15_startCol->size[0]) - 1] >
            c15_currentColumn) {
          c15_firstRunOnPreviousColumn = -1;
          c15_lastRunOnPreviousColumn = 0;
          c15_firstRunOnThisColumn = c15_c_k;
          c15_currentColumn = c15_startCol->data[sf_eml_array_bounds_check
            (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
             MAX_uint32_T, c15_c_k, 1, c15_startCol->size[0]) - 1] + 1;
        }
      }

      if (c15_firstRunOnPreviousColumn >= 0) {
        for (c15_p = c15_firstRunOnPreviousColumn; c15_p <
             c15_lastRunOnPreviousColumn; c15_p++) {
          if ((c15_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_c_k, 1, c15_endRow->size[0]) - 1] >=
               c15_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_p, 1, c15_startRow->size[0]) - 1]) &&
              (c15_startRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_c_k, 1, c15_startRow->size[0]) - 1] <=
               c15_endRow->data[sf_eml_array_bounds_check
               (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                MAX_uint32_T, c15_p, 1, c15_endRow->size[0]) - 1])) {
            if (c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] ==
                0) {
              c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] =
                c15_labelForEachRun->data[sf_eml_array_bounds_check
                (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                 MAX_uint32_T, c15_p, 1, c15_labelForEachRun->size[0]) - 1];
              c15_nextLabel++;
            } else {
              if (c15_labelForEachRun->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c15_c_k, 1, c15_labelForEachRun->size[0]) - 1]
                  != c15_labelForEachRun->data[sf_eml_array_bounds_check
                  (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                   MAX_uint32_T, c15_p, 1, c15_labelForEachRun->size[0]) - 1]) {
                c15_e_k = c15_c_k;
                c15_b_p = c15_p;
                c15_node = c15_e_k;
                c15_root_k = c15_node;
                while (c15_root_k != c15_labelForEachRun->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c15_root_k, 1, c15_labelForEachRun->size[0])
                       - 1]) {
                  c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_root_k, 1, c15_labelForEachRun->size[0])
                    - 1] = c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_labelForEachRun->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_k, 1,
                      c15_labelForEachRun->size[0]) - 1], 1,
                     c15_labelForEachRun->size[0]) - 1];
                  c15_root_k = c15_labelForEachRun->
                    data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_k, 1,
                    c15_labelForEachRun->size[0]) - 1];
                }

                c15_b_node = c15_b_p;
                c15_root_p = c15_b_node;
                while (c15_root_p != c15_labelForEachRun->
                       data[sf_eml_array_bounds_check
                       (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                        MAX_uint32_T, c15_root_p, 1, c15_labelForEachRun->size[0])
                       - 1]) {
                  c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_root_p, 1, c15_labelForEachRun->size[0])
                    - 1] = c15_labelForEachRun->data[sf_eml_array_bounds_check
                    (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                     MAX_uint32_T, c15_labelForEachRun->
                     data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                      chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_p, 1,
                      c15_labelForEachRun->size[0]) - 1], 1,
                     c15_labelForEachRun->size[0]) - 1];
                  c15_root_p = c15_labelForEachRun->
                    data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_root_p, 1,
                    c15_labelForEachRun->size[0]) - 1];
                }

                if (c15_root_k != c15_root_p) {
                  c15_b_root_k = c15_root_k;
                  c15_b_root_p = c15_root_p;
                  c15_f_k = c15_e_k;
                  c15_c_p = c15_b_p;
                  if (c15_b_root_p < c15_b_root_k) {
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_b_root_k, 1, c15_labelForEachRun->size
                       [0]) - 1] = c15_b_root_p;
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_f_k, 1, c15_labelForEachRun->size[0]) -
                      1] = c15_b_root_p;
                  } else {
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_b_root_p, 1, c15_labelForEachRun->size
                       [0]) - 1] = c15_b_root_k;
                    c15_labelForEachRun->data[sf_eml_array_bounds_check
                      (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0,
                       MAX_uint32_T, c15_c_p, 1, c15_labelForEachRun->size[0]) -
                      1] = c15_b_root_k;
                  }
                }
              }
            }
          }
        }
      }

      if (c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] == 0) {
        c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_c_k, 1, c15_labelForEachRun->size[0]) - 1] = c15_nextLabel;
        c15_nextLabel++;
      }

      c15_c_k++;
    }
  }

  if (c15_numRuns == 0) {
    for (c15_i149 = 0; c15_i149 < 256000; c15_i149++) {
      c15_b_L[c15_i149] = 0.0;
    }
  } else {
    c15_emxInit_int32_T(chartInstance, &c15_labelsRenumbered, 1,
                        &c15_db_emlrtRTEI);
    c15_i150 = c15_labelsRenumbered->size[0];
    c15_labelsRenumbered->size[0] = c15_labelForEachRun->size[0];
    c15_emxEnsureCapacity_int32_T(chartInstance, c15_labelsRenumbered, c15_i150,
      &c15_bb_emlrtRTEI);
    c15_numComponents = 0.0;
    for (c15_i152 = 0; c15_i152 < 256000; c15_i152++) {
      c15_b_L[c15_i152] = 0.0;
    }

    c15_b = c15_numRuns;
    c15_b_b = c15_b;
    if (1 > c15_b_b) {
      c15_overflow = false;
    } else {
      c15_overflow = (c15_b_b > 2147483646);
    }

    if (c15_overflow) {
      c15_check_forloop_overflow_error(chartInstance, true);
    }

    for (c15_d_k = 1; c15_d_k <= c15_numRuns; c15_d_k++) {
      if (c15_labelForEachRun->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelForEachRun->size[0]) - 1] == c15_d_k) {
        c15_numComponents++;
        c15_labelsRenumbered->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1] = (int32_T)
          c15_numComponents;
      }

      c15_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1] =
        c15_labelsRenumbered->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_labelForEachRun->data[sf_eml_array_bounds_check
         (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
          c15_d_k, 1, c15_labelForEachRun->size[0]) - 1], 1,
         c15_labelsRenumbered->size[0]) - 1];
      c15_i153 = c15_startRow->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_startRow->size[0]) - 1];
      c15_i154 = c15_endRow->data[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
         c15_d_k, 1, c15_endRow->size[0]) - 1];
      for (c15_idx = c15_i153; c15_idx <= c15_i154; c15_idx++) {
        c15_b_L[(sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                  chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_idx, 1, 400) +
                 400 * (sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                   chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_startCol->
                   data[sf_eml_array_bounds_check(sfGlobalDebugInstanceStruct,
                    chartInstance->S, 1U, 0, 0, MAX_uint32_T, c15_d_k, 1,
                    c15_startCol->size[0]) - 1], 1, 640) - 1)) - 1] = (real_T)
          c15_labelsRenumbered->data[sf_eml_array_bounds_check
          (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 0, 0, MAX_uint32_T,
           c15_d_k, 1, c15_labelsRenumbered->size[0]) - 1];
      }
    }

    c15_emxFree_int32_T(chartInstance, &c15_labelsRenumbered);
  }

  c15_emxFree_int32_T(chartInstance, &c15_labelForEachRun);
  c15_emxFree_int32_T(chartInstance, &c15_startCol);
  c15_emxFree_int32_T(chartInstance, &c15_endRow);
  c15_emxFree_int32_T(chartInstance, &c15_startRow);
}

static c15_images_internal_coder_BoundaryFinder
  *c15_BoundaryFinder_BoundaryFinder(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_images_internal_coder_BoundaryFinder *c15_obj, real_T
  c15_c_labelMatrix[256000])
{
  c15_images_internal_coder_BoundaryFinder *c15_b_obj;
  int32_T c15_i155;
  c15_b_obj = c15_obj;
  for (c15_i155 = 0; c15_i155 < 256000; c15_i155++) {
    chartInstance->c15_labelMatrix[c15_i155] = c15_c_labelMatrix[c15_i155];
  }

  c15_b_BoundaryFinder_BoundaryFinder(chartInstance, &c15_b_obj,
    chartInstance->c15_labelMatrix);
  return c15_b_obj;
}

static void c15_flip(SFc15_VehicleSimME131InstanceStruct *chartInstance,
                     c15_emxArray_real_T *c15_x, c15_emxArray_real_T *c15_b_x)
{
  int32_T c15_i156;
  int32_T c15_loop_ub;
  int32_T c15_i157;
  c15_i156 = c15_b_x->size[0];
  c15_b_x->size[0] = c15_x->size[0];
  c15_emxEnsureCapacity_real_T1(chartInstance, c15_b_x, c15_i156,
    &c15_sb_emlrtRTEI);
  c15_loop_ub = c15_x->size[0] - 1;
  for (c15_i157 = 0; c15_i157 <= c15_loop_ub; c15_i157++) {
    c15_b_x->data[c15_i157] = c15_x->data[c15_i157];
  }

  c15_b_flip(chartInstance, c15_b_x);
}

static real_T c15_mean(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  real_T c15_x_data[], int32_T c15_x_size[1])
{
  int32_T c15_vlen;
  int32_T c15_b_vlen;
  real_T c15_b_y;
  int32_T c15_k;
  real_T c15_A;
  int32_T c15_xoffset;
  real_T c15_b_B;
  int32_T c15_ix;
  real_T c15_x;
  real_T c15_c_y;
  real_T c15_b_x;
  real_T c15_d_y;
  (void)chartInstance;
  c15_vlen = c15_x_size[0];
  c15_b_vlen = c15_vlen;
  c15_b_y = c15_x_data[0];
  for (c15_k = 1; c15_k < c15_b_vlen; c15_k++) {
    c15_xoffset = c15_k;
    c15_ix = c15_xoffset;
    c15_b_y += c15_x_data[c15_ix];
  }

  c15_A = c15_b_y;
  c15_b_B = (real_T)c15_x_size[0];
  c15_x = c15_A;
  c15_c_y = c15_b_B;
  c15_b_x = c15_x;
  c15_d_y = c15_c_y;
  return c15_b_x / c15_d_y;
}

static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData;
  int32_T c15_b_u;
  const mxArray *c15_y = NULL;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_mxArrayOutData = NULL;
  c15_b_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, false);
  return c15_mxArrayOutData;
}

static int32_T c15_g_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i158;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_i158, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i158;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_h_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_VehicleSimME131, const
  char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = (const char *)c15_identifier;
  c15_thisId.fParent = NULL;
  c15_thisId.bParentIsCell = false;
  c15_y = c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_VehicleSimME131), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_VehicleSimME131);
  return c15_y;
}

static uint8_T c15_i_emlrt_marshallIn(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, const mxArray *c15_b_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  (void)chartInstance;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_b_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_b_u);
  return c15_y;
}

static void c15_b_BoundaryFinder_BoundaryFinder
  (SFc15_VehicleSimME131InstanceStruct *chartInstance,
   c15_images_internal_coder_BoundaryFinder **c15_obj, real_T c15_c_labelMatrix
   [256000])
{
  c15_images_internal_coder_BoundaryFinder *c15_this;
  int32_T c15_i159;
  int32_T c15_i160;
  boolean_T c15_b_u;
  const mxArray *c15_y = NULL;
  const mxArray *c15_b_y = NULL;
  c15_this = *c15_obj;
  *c15_obj = c15_this;
  (*c15_obj)->matlabCodegenIsDeleted = false;
  for (c15_i159 = 0; c15_i159 < 256000; c15_i159++) {
    chartInstance->c15_b_labelMatrix[c15_i159] = c15_c_labelMatrix[c15_i159];
  }

  c15_padarray(chartInstance, chartInstance->c15_b_labelMatrix,
               chartInstance->c15_dv1);
  for (c15_i160 = 0; c15_i160 < 258084; c15_i160++) {
    (*c15_obj)->paddedLabelMatrix[c15_i160] = chartInstance->c15_dv1[c15_i160];
  }

  (*c15_obj)->numRows = 402;
  (*c15_obj)->numCols = 642;
  c15_b_u = true;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_b_u, 11, 0U, 0U, 0U, 0), false);
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_cv0, 10, 0U, 1U, 0U, 2, 1, 33),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "assert", 0U, 2U, 14, c15_y, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c15_b_y));
  (*c15_obj)->conn = 4.0;
}

static void c15_b_flip(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  c15_emxArray_real_T *c15_x)
{
  int32_T c15_dim;
  real_T c15_d4;
  int32_T c15_b_dim;
  int32_T c15_vstride;
  int32_T c15_i161;
  int32_T c15_b;
  int32_T c15_b_b;
  boolean_T c15_overflow;
  int32_T c15_k;
  real_T c15_d5;
  real_T c15_d6;
  int32_T c15_n;
  int32_T c15_nd2;
  int32_T c15_i162;
  int32_T c15_i;
  int32_T c15_offset;
  int32_T c15_c_b;
  int32_T c15_d_b;
  boolean_T c15_b_overflow;
  int32_T c15_b_k;
  real_T c15_tmp;
  c15_dim = 2;
  if ((real_T)c15_x->size[0] != 1.0) {
    c15_dim = 1;
  }

  if (!(c15_x->size[0] == 0)) {
    if (c15_dim <= 1) {
      c15_d4 = (real_T)c15_x->size[0];
    } else {
      c15_d4 = 1.0;
    }

    if (c15_d4 > 1.0) {
      c15_b_dim = c15_dim - 1;
      c15_vstride = 1;
      c15_i161 = c15_b_dim;
      c15_b = c15_i161;
      c15_b_b = c15_b;
      if (1 > c15_b_b) {
        c15_overflow = false;
      } else {
        c15_overflow = (c15_b_b > 2147483646);
      }

      if (c15_overflow) {
        c15_check_forloop_overflow_error(chartInstance, true);
      }

      c15_k = 1;
      while (c15_k <= c15_i161) {
        c15_d5 = (real_T)c15_x->size[0];
        c15_vstride *= (int32_T)c15_d5;
        c15_k = 2;
      }

      if (c15_dim <= 1) {
        c15_d6 = (real_T)c15_x->size[0];
      } else {
        c15_d6 = 1.0;
      }

      c15_n = (int32_T)c15_d6;
      c15_nd2 = c15_n >> 1;
      c15_i162 = c15_vstride;
      for (c15_i = 0; c15_i < c15_i162; c15_i++) {
        c15_offset = c15_i;
        c15_c_b = c15_nd2;
        c15_d_b = c15_c_b;
        if (1 > c15_d_b) {
          c15_b_overflow = false;
        } else {
          c15_b_overflow = (c15_d_b > 2147483646);
        }

        if (c15_b_overflow) {
          c15_check_forloop_overflow_error(chartInstance, true);
        }

        for (c15_b_k = 1; c15_b_k <= c15_nd2; c15_b_k++) {
          c15_tmp = c15_x->data[c15_offset + (c15_b_k - 1) * c15_vstride];
          c15_x->data[c15_offset + (c15_b_k - 1) * c15_vstride] = c15_x->
            data[c15_offset + (c15_n - c15_b_k) * c15_vstride];
          c15_x->data[c15_offset + (c15_n - c15_b_k) * c15_vstride] = c15_tmp;
        }
      }
    }
  }
}

static void c15_emxFree_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray)
{
  if (*c15_pEmxArray != (c15_emxArray_real_T *)NULL) {
    if (((*c15_pEmxArray)->data != (real_T *)NULL) && (*c15_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)*c15_pEmxArray);
    *c15_pEmxArray = (c15_emxArray_real_T *)NULL;
  }
}

static void c15_emxFreeStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_pStruct)
{
  c15_emxFree_real_T(chartInstance, &c15_pStruct->f1);
}

static void c15_emxTrim_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 *c15_emxArray, int32_T c15_fromIndex,
  int32_T c15_toIndex)
{
  int32_T c15_i;
  for (c15_i = c15_fromIndex; c15_i < c15_toIndex; c15_i++) {
    c15_emxFreeStruct_cell_wrap_0(chartInstance, &c15_emxArray->data[c15_i]);
  }
}

static void c15_emxInitStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_pStruct, const emlrtRTEInfo
  *c15_srcLocation)
{
  c15_emxInit_real_T(chartInstance, &c15_pStruct->f1, 2, c15_srcLocation);
}

static void c15_emxInit_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray, int32_T c15_numDimensions,
  const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxArray_real_T *c15_emxArray;
  int32_T c15_i;
  *c15_pEmxArray = (c15_emxArray_real_T *)emlrtMallocMex(sizeof
    (c15_emxArray_real_T));
  if ((void *)*c15_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray = *c15_pEmxArray;
  c15_emxArray->data = (real_T *)NULL;
  c15_emxArray->numDimensions = c15_numDimensions;
  c15_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c15_numDimensions);
  if ((void *)c15_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray->allocatedSize = 0;
  c15_emxArray->canFreeData = true;
  for (c15_i = 0; c15_i < c15_numDimensions; c15_i++) {
    c15_emxArray->size[c15_i] = 0;
  }
}

static void c15_emxExpand_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 *c15_emxArray, int32_T c15_fromIndex,
  int32_T c15_toIndex, const emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_i;
  for (c15_i = c15_fromIndex; c15_i < c15_toIndex; c15_i++) {
    c15_emxInitStruct_cell_wrap_0(chartInstance, &c15_emxArray->data[c15_i],
      c15_srcLocation);
  }
}

static void c15_emxEnsureCapacity_cell_wrap_0
  (SFc15_VehicleSimME131InstanceStruct *chartInstance, c15_emxArray_cell_wrap_0 *
   c15_emxArray, int32_T c15_oldNumel, const emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_newNumel;
  int32_T c15_i;
  int32_T c15_newCapacity;
  void *c15_newData;
  if (c15_oldNumel < 0) {
    c15_oldNumel = 0;
  }

  c15_newNumel = 1;
  for (c15_i = 0; c15_i < c15_emxArray->numDimensions; c15_i++) {
    c15_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c15_newNumel, (uint32_T)
      c15_emxArray->size[c15_i], c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  if (c15_newNumel > c15_emxArray->allocatedSize) {
    c15_newCapacity = c15_emxArray->allocatedSize;
    if (c15_newCapacity < 16) {
      c15_newCapacity = 16;
    }

    while (c15_newCapacity < c15_newNumel) {
      if (c15_newCapacity > 1073741823) {
        c15_newCapacity = MAX_int32_T;
      } else {
        c15_newCapacity <<= 1;
      }
    }

    c15_newData = emlrtCallocMex((uint32_T)c15_newCapacity, sizeof
      (c15_cell_wrap_0));
    if (c15_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c15_srcLocation,
        chartInstance->c15_fEmlrtCtx);
    }

    if (c15_emxArray->data != NULL) {
      memcpy(c15_newData, (void *)c15_emxArray->data, sizeof(c15_cell_wrap_0) *
             (uint32_T)c15_oldNumel);
      if (c15_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)
                          c15_emxArray->data);
      }
    }

    c15_emxArray->data = (c15_cell_wrap_0 *)c15_newData;
    c15_emxArray->allocatedSize = c15_newCapacity;
    c15_emxArray->canFreeData = true;
  }

  if (c15_oldNumel > c15_newNumel) {
    c15_emxTrim_cell_wrap_0(chartInstance, c15_emxArray, c15_newNumel,
      c15_oldNumel);
  } else {
    if (c15_oldNumel < c15_newNumel) {
      c15_emxExpand_cell_wrap_0(chartInstance, c15_emxArray, c15_oldNumel,
        c15_newNumel, c15_srcLocation);
    }
  }
}

static void c15_emxEnsureCapacity_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T *c15_emxArray, int32_T c15_oldNumel, const
  emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_newNumel;
  int32_T c15_i;
  int32_T c15_newCapacity;
  void *c15_newData;
  if (c15_oldNumel < 0) {
    c15_oldNumel = 0;
  }

  c15_newNumel = 1;
  for (c15_i = 0; c15_i < c15_emxArray->numDimensions; c15_i++) {
    c15_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c15_newNumel, (uint32_T)
      c15_emxArray->size[c15_i], c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  if (c15_newNumel > c15_emxArray->allocatedSize) {
    c15_newCapacity = c15_emxArray->allocatedSize;
    if (c15_newCapacity < 16) {
      c15_newCapacity = 16;
    }

    while (c15_newCapacity < c15_newNumel) {
      if (c15_newCapacity > 1073741823) {
        c15_newCapacity = MAX_int32_T;
      } else {
        c15_newCapacity <<= 1;
      }
    }

    c15_newData = emlrtCallocMex((uint32_T)c15_newCapacity, sizeof(real_T));
    if (c15_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c15_srcLocation,
        chartInstance->c15_fEmlrtCtx);
    }

    if (c15_emxArray->data != NULL) {
      memcpy(c15_newData, (void *)c15_emxArray->data, sizeof(real_T) * (uint32_T)
             c15_oldNumel);
      if (c15_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)
                          c15_emxArray->data);
      }
    }

    c15_emxArray->data = (real_T *)c15_newData;
    c15_emxArray->allocatedSize = c15_newCapacity;
    c15_emxArray->canFreeData = true;
  }
}

static void c15_emxEnsureCapacity_real_T1(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T *c15_emxArray, int32_T c15_oldNumel, const
  emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_newNumel;
  int32_T c15_i;
  int32_T c15_newCapacity;
  void *c15_newData;
  if (c15_oldNumel < 0) {
    c15_oldNumel = 0;
  }

  c15_newNumel = 1;
  for (c15_i = 0; c15_i < c15_emxArray->numDimensions; c15_i++) {
    c15_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c15_newNumel, (uint32_T)
      c15_emxArray->size[c15_i], c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  if (c15_newNumel > c15_emxArray->allocatedSize) {
    c15_newCapacity = c15_emxArray->allocatedSize;
    if (c15_newCapacity < 16) {
      c15_newCapacity = 16;
    }

    while (c15_newCapacity < c15_newNumel) {
      if (c15_newCapacity > 1073741823) {
        c15_newCapacity = MAX_int32_T;
      } else {
        c15_newCapacity <<= 1;
      }
    }

    c15_newData = emlrtCallocMex((uint32_T)c15_newCapacity, sizeof(real_T));
    if (c15_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c15_srcLocation,
        chartInstance->c15_fEmlrtCtx);
    }

    if (c15_emxArray->data != NULL) {
      memcpy(c15_newData, (void *)c15_emxArray->data, sizeof(real_T) * (uint32_T)
             c15_oldNumel);
      if (c15_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)
                          c15_emxArray->data);
      }
    }

    c15_emxArray->data = (real_T *)c15_newData;
    c15_emxArray->allocatedSize = c15_newCapacity;
    c15_emxArray->canFreeData = true;
  }
}

static void c15_emxInit_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxArray_cell_wrap_0 *c15_emxArray;
  int32_T c15_i;
  *c15_pEmxArray = (c15_emxArray_cell_wrap_0 *)emlrtMallocMex(sizeof
    (c15_emxArray_cell_wrap_0));
  if ((void *)*c15_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray = *c15_pEmxArray;
  c15_emxArray->data = (c15_cell_wrap_0 *)NULL;
  c15_emxArray->numDimensions = c15_numDimensions;
  c15_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c15_numDimensions);
  if ((void *)c15_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray->allocatedSize = 0;
  c15_emxArray->canFreeData = true;
  for (c15_i = 0; c15_i < c15_numDimensions; c15_i++) {
    c15_emxArray->size[c15_i] = 0;
  }
}

static void c15_emxInit_real_T1(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_pEmxArray, int32_T c15_numDimensions,
  const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxArray_real_T *c15_emxArray;
  int32_T c15_i;
  *c15_pEmxArray = (c15_emxArray_real_T *)emlrtMallocMex(sizeof
    (c15_emxArray_real_T));
  if ((void *)*c15_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray = *c15_pEmxArray;
  c15_emxArray->data = (real_T *)NULL;
  c15_emxArray->numDimensions = c15_numDimensions;
  c15_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c15_numDimensions);
  if ((void *)c15_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray->allocatedSize = 0;
  c15_emxArray->canFreeData = true;
  for (c15_i = 0; c15_i < c15_numDimensions; c15_i++) {
    c15_emxArray->size[c15_i] = 0;
  }
}

static void c15_emxFree_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_cell_wrap_0 **c15_pEmxArray)
{
  int32_T c15_numEl;
  int32_T c15_i;
  int32_T c15_b_i;
  if (*c15_pEmxArray != (c15_emxArray_cell_wrap_0 *)NULL) {
    if ((*c15_pEmxArray)->data != (c15_cell_wrap_0 *)NULL) {
      c15_numEl = 1;
      for (c15_i = 0; c15_i < (*c15_pEmxArray)->numDimensions; c15_i++) {
        c15_numEl *= (*c15_pEmxArray)->size[c15_i];
      }

      for (c15_b_i = 0; c15_b_i < c15_numEl; c15_b_i++) {
        c15_emxFreeStruct_cell_wrap_0(chartInstance, &(*c15_pEmxArray)->
          data[c15_b_i]);
      }

      if ((*c15_pEmxArray)->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray
                          )->data);
      }
    }

    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)*c15_pEmxArray);
    *c15_pEmxArray = (c15_emxArray_cell_wrap_0 *)NULL;
  }
}

static void c15_emxCopyStruct_cell_wrap_0(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_cell_wrap_0 *c15_dst, const c15_cell_wrap_0 *c15_src,
  const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxCopy_real_T(chartInstance, &c15_dst->f1, &c15_src->f1, c15_srcLocation);
}

static void c15_emxCopy_real_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_real_T **c15_dst, c15_emxArray_real_T * const
  *c15_src, const emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_numElDst;
  int32_T c15_numElSrc;
  int32_T c15_i;
  c15_numElDst = 1;
  c15_numElSrc = 1;
  for (c15_i = 0; c15_i < (*c15_dst)->numDimensions; c15_i++) {
    c15_numElDst *= (*c15_dst)->size[c15_i];
    c15_numElSrc *= (*c15_src)->size[c15_i];
  }

  for (c15_i = 0; c15_i < (*c15_dst)->numDimensions; c15_i++) {
    (*c15_dst)->size[c15_i] = (*c15_src)->size[c15_i];
  }

  c15_emxEnsureCapacity_real_T(chartInstance, *c15_dst, c15_numElDst,
    c15_srcLocation);
  for (c15_i = 0; c15_i < c15_numElSrc; c15_i++) {
    (*c15_dst)->data[c15_i] = (*c15_src)->data[c15_i];
  }
}

static void c15_emxEnsureCapacity_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T *c15_emxArray, int32_T c15_oldNumel,
  const emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_newNumel;
  int32_T c15_i;
  int32_T c15_newCapacity;
  void *c15_newData;
  if (c15_oldNumel < 0) {
    c15_oldNumel = 0;
  }

  c15_newNumel = 1;
  for (c15_i = 0; c15_i < c15_emxArray->numDimensions; c15_i++) {
    c15_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c15_newNumel, (uint32_T)
      c15_emxArray->size[c15_i], c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  if (c15_newNumel > c15_emxArray->allocatedSize) {
    c15_newCapacity = c15_emxArray->allocatedSize;
    if (c15_newCapacity < 16) {
      c15_newCapacity = 16;
    }

    while (c15_newCapacity < c15_newNumel) {
      if (c15_newCapacity > 1073741823) {
        c15_newCapacity = MAX_int32_T;
      } else {
        c15_newCapacity <<= 1;
      }
    }

    c15_newData = emlrtCallocMex((uint32_T)c15_newCapacity, sizeof(int32_T));
    if (c15_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c15_srcLocation,
        chartInstance->c15_fEmlrtCtx);
    }

    if (c15_emxArray->data != NULL) {
      memcpy(c15_newData, (void *)c15_emxArray->data, sizeof(int32_T)
             * (uint32_T)c15_oldNumel);
      if (c15_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)
                          c15_emxArray->data);
      }
    }

    c15_emxArray->data = (int32_T *)c15_newData;
    c15_emxArray->allocatedSize = c15_newCapacity;
    c15_emxArray->canFreeData = true;
  }
}

static void c15_emxInit_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxArray_int32_T *c15_emxArray;
  int32_T c15_i;
  *c15_pEmxArray = (c15_emxArray_int32_T *)emlrtMallocMex(sizeof
    (c15_emxArray_int32_T));
  if ((void *)*c15_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray = *c15_pEmxArray;
  c15_emxArray->data = (int32_T *)NULL;
  c15_emxArray->numDimensions = c15_numDimensions;
  c15_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c15_numDimensions);
  if ((void *)c15_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray->allocatedSize = 0;
  c15_emxArray->canFreeData = true;
  for (c15_i = 0; c15_i < c15_numDimensions; c15_i++) {
    c15_emxArray->size[c15_i] = 0;
  }
}

static void c15_emxFree_int32_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_int32_T **c15_pEmxArray)
{
  if (*c15_pEmxArray != (c15_emxArray_int32_T *)NULL) {
    if (((*c15_pEmxArray)->data != (int32_T *)NULL) && (*c15_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)*c15_pEmxArray);
    *c15_pEmxArray = (c15_emxArray_int32_T *)NULL;
  }
}

static void c15_emxEnsureCapacity_boolean_T(SFc15_VehicleSimME131InstanceStruct *
  chartInstance, c15_emxArray_boolean_T *c15_emxArray, int32_T c15_oldNumel,
  const emlrtRTEInfo *c15_srcLocation)
{
  int32_T c15_newNumel;
  int32_T c15_i;
  int32_T c15_newCapacity;
  void *c15_newData;
  if (c15_oldNumel < 0) {
    c15_oldNumel = 0;
  }

  c15_newNumel = 1;
  for (c15_i = 0; c15_i < c15_emxArray->numDimensions; c15_i++) {
    c15_newNumel = (int32_T)emlrtSizeMulR2012b((uint32_T)c15_newNumel, (uint32_T)
      c15_emxArray->size[c15_i], c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  if (c15_newNumel > c15_emxArray->allocatedSize) {
    c15_newCapacity = c15_emxArray->allocatedSize;
    if (c15_newCapacity < 16) {
      c15_newCapacity = 16;
    }

    while (c15_newCapacity < c15_newNumel) {
      if (c15_newCapacity > 1073741823) {
        c15_newCapacity = MAX_int32_T;
      } else {
        c15_newCapacity <<= 1;
      }
    }

    c15_newData = emlrtCallocMex((uint32_T)c15_newCapacity, sizeof(boolean_T));
    if (c15_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c15_srcLocation,
        chartInstance->c15_fEmlrtCtx);
    }

    if (c15_emxArray->data != NULL) {
      memcpy(c15_newData, (void *)c15_emxArray->data, sizeof(boolean_T)
             * (uint32_T)c15_oldNumel);
      if (c15_emxArray->canFreeData) {
        emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)
                          c15_emxArray->data);
      }
    }

    c15_emxArray->data = (boolean_T *)c15_newData;
    c15_emxArray->allocatedSize = c15_newCapacity;
    c15_emxArray->canFreeData = true;
  }
}

static void c15_emxInit_boolean_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_boolean_T **c15_pEmxArray, int32_T
  c15_numDimensions, const emlrtRTEInfo *c15_srcLocation)
{
  c15_emxArray_boolean_T *c15_emxArray;
  int32_T c15_i;
  *c15_pEmxArray = (c15_emxArray_boolean_T *)emlrtMallocMex(sizeof
    (c15_emxArray_boolean_T));
  if ((void *)*c15_pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray = *c15_pEmxArray;
  c15_emxArray->data = (boolean_T *)NULL;
  c15_emxArray->numDimensions = c15_numDimensions;
  c15_emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
    c15_numDimensions);
  if ((void *)c15_emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(c15_srcLocation, chartInstance->c15_fEmlrtCtx);
  }

  c15_emxArray->allocatedSize = 0;
  c15_emxArray->canFreeData = true;
  for (c15_i = 0; c15_i < c15_numDimensions; c15_i++) {
    c15_emxArray->size[c15_i] = 0;
  }
}

static void c15_emxFree_boolean_T(SFc15_VehicleSimME131InstanceStruct
  *chartInstance, c15_emxArray_boolean_T **c15_pEmxArray)
{
  if (*c15_pEmxArray != (c15_emxArray_boolean_T *)NULL) {
    if (((*c15_pEmxArray)->data != (boolean_T *)NULL) && (*c15_pEmxArray)
        ->canFreeData) {
      emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                        ->data);
    }

    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)(*c15_pEmxArray)
                      ->size);
    emlrtFreeMex2018a(chartInstance->c15_fEmlrtCtx, (void *)*c15_pEmxArray);
    *c15_pEmxArray = (c15_emxArray_boolean_T *)NULL;
  }
}

static int32_T c15_div_s32(SFc15_VehicleSimME131InstanceStruct *chartInstance,
  int32_T c15_numerator, int32_T c15_denominator, uint32_T c15_ssid_src_loc,
  int32_T c15_offset_src_loc, int32_T c15_length_src_loc)
{
  int32_T c15_quotient;
  uint32_T c15_absNumerator;
  uint32_T c15_absDenominator;
  boolean_T c15_quotientNeedsNegation;
  uint32_T c15_tempAbsQuotient;
  (void)chartInstance;
  if (c15_denominator == 0) {
    if (c15_numerator >= 0) {
      c15_quotient = MAX_int32_T;
    } else {
      c15_quotient = MIN_int32_T;
    }

    _SFD_OVERFLOW_DETECTION(SFDB_DIVIDE_BY_ZERO, c15_ssid_src_loc,
      c15_offset_src_loc, c15_length_src_loc);
  } else {
    if (c15_numerator < 0) {
      c15_absNumerator = ~(uint32_T)c15_numerator + 1U;
    } else {
      c15_absNumerator = (uint32_T)c15_numerator;
    }

    if (c15_denominator < 0) {
      c15_absDenominator = ~(uint32_T)c15_denominator + 1U;
    } else {
      c15_absDenominator = (uint32_T)c15_denominator;
    }

    c15_quotientNeedsNegation = ((c15_numerator < 0) != (c15_denominator < 0));
    c15_tempAbsQuotient = c15_absNumerator / c15_absDenominator;
    if (c15_quotientNeedsNegation) {
      c15_quotient = -(int32_T)c15_tempAbsQuotient;
    } else {
      c15_quotient = (int32_T)c15_tempAbsQuotient;
    }
  }

  return c15_quotient;
}

static void init_dsm_address_info(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc15_VehicleSimME131InstanceStruct
  *chartInstance)
{
  chartInstance->c15_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c15_b_lanes = (uint8_T (*)[256000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c15_curvature = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c15_VehicleSimME131_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2808973460U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1992504278U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1435031773U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1773507298U);
}

mxArray* sf_c15_VehicleSimME131_get_post_codegen_info(void);
mxArray *sf_c15_VehicleSimME131_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KNFU1YBdcWVL0nQ667SpV");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(400);
      pr[1] = (double)(640);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c15_VehicleSimME131_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_VehicleSimME131_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,2);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Morphop_binary_tbb_Buildable"));
  mxSetCell(mxcell3p, 1, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  return(mxcell3p);
}

mxArray *sf_c15_VehicleSimME131_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("erode_binary_twod_tbb");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c15_VehicleSimME131_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c15_VehicleSimME131_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c15_VehicleSimME131(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"curvature\",},{M[8],M[0],T\"is_active_c15_VehicleSimME131\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_VehicleSimME131_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_VehicleSimME131InstanceStruct *chartInstance =
      (SFc15_VehicleSimME131InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _VehicleSimME131MachineNumber_,
           15,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_VehicleSimME131MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_VehicleSimME131MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _VehicleSimME131MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"lanes");
          _SFD_SET_DATA_PROPS(1,2,0,1,"curvature");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,453);
        _SFD_CV_INIT_EML_IF(0,1,0,95,104,305,411);
        _SFD_CV_INIT_EML_IF(0,1,1,109,143,207,304);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,98,104,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,112,143,-1,4);

        {
          unsigned int dimVector[2];
          dimVector[0]= 400U;
          dimVector[1]= 640U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
          c15_b_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _VehicleSimME131MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_VehicleSimME131InstanceStruct *chartInstance =
      (SFc15_VehicleSimME131InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c15_b_lanes);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c15_curvature);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sdtGz0qYHTAhHMChpPcks4B";
}

static void sf_opaque_initialize_c15_VehicleSimME131(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
  initialize_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_VehicleSimME131(void *chartInstanceVar)
{
  enable_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_VehicleSimME131(void *chartInstanceVar)
{
  disable_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_VehicleSimME131(void *chartInstanceVar)
{
  sf_gateway_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c15_VehicleSimME131(SimStruct* S)
{
  return get_sim_state_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c15_VehicleSimME131(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c15_VehicleSimME131(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_VehicleSimME131InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_VehicleSimME131_optimization_info();
    }

    finalize_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_VehicleSimME131(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_VehicleSimME131((SFc15_VehicleSimME131InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c15_VehicleSimME131(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_VehicleSimME131_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,15,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 15);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3471006398U));
  ssSetChecksum1(S,(232620211U));
  ssSetChecksum2(S,(264123548U));
  ssSetChecksum3(S,(20277894U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_VehicleSimME131(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_VehicleSimME131(SimStruct *S)
{
  SFc15_VehicleSimME131InstanceStruct *chartInstance;
  chartInstance = (SFc15_VehicleSimME131InstanceStruct *)utMalloc(sizeof
    (SFc15_VehicleSimME131InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc15_VehicleSimME131InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_VehicleSimME131;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_VehicleSimME131;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_VehicleSimME131;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_VehicleSimME131;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_VehicleSimME131;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_VehicleSimME131;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_VehicleSimME131;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_VehicleSimME131;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_VehicleSimME131;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_VehicleSimME131;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_VehicleSimME131;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c15_VehicleSimME131(chartInstance);
}

void c15_VehicleSimME131_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_VehicleSimME131(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_VehicleSimME131(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_VehicleSimME131(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_VehicleSimME131_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
