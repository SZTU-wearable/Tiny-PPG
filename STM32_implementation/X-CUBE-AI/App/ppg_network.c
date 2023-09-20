/**
  ******************************************************************************
  * @file    ppg_network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue May  9 01:18:54 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "ppg_network.h"
#include "ppg_network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_ppg_network
 
#undef AI_PPG_NETWORK_MODEL_SIGNATURE
#define AI_PPG_NETWORK_MODEL_SIGNATURE     "d194b1a5ee37949b574bff94572917cb"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue May  9 01:18:54 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_PPG_NETWORK_N_BATCHES
#define AI_PPG_NETWORK_N_BATCHES         (1)

static ai_ptr g_ppg_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_ppg_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_6_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_14_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_14_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 80, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_10_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_10_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_separableconv_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_11_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_separableconv_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_11_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_19_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_19_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_separableconv_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  seg_out_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_separableconv_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  seg_out_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  input_2_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1920, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1920, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 320, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_separableconv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_4_separableconv_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_separableconv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_5_separableconv_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_separableconv_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_separableconv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_separableconv_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7680, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_6_separableconv_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_separableconv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 30720, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_9_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)
/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_8_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_7_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_separableconv_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)
/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_6_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  separable_conv1d_7_separableconv_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  concatenate_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 960, AI_STATIC)
/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_9_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_10_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)
/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  up_sampling1d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 960, AI_STATIC)
/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_9_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_11_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 960, AI_STATIC)
/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 960, AI_STATIC)
/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_17_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  up_sampling1d_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1920, AI_STATIC)
/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  seg_out_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1920, AI_STATIC)
/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_8_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_8_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_16_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_7_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_7_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_15_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  batch_normalization_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)
/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_6_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_6_conv2d_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_6_conv2d_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_14_scale, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_14_scale_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_14_bias, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_14_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_conv2d_weights, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 80, 1), AI_STRIDE_INIT(4, 4, 4, 4, 320),
  1, &separable_conv1d_4_conv2d_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_10_conv2d_weights, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 4, 1, 1, 1), AI_STRIDE_INIT(4, 4, 16, 16, 16),
  1, &conv1d_10_conv2d_weights_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_conv2d_bias, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &separable_conv1d_4_conv2d_bias_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_10_conv2d_bias, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_10_conv2d_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_separableconv_weights, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 8), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &separable_conv1d_4_separableconv_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_11_conv2d_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_11_conv2d_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_separableconv_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &separable_conv1d_4_separableconv_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_11_conv2d_bias, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_11_conv2d_bias_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_conv2d_weights, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 40, 8), AI_STRIDE_INIT(4, 4, 4, 4, 160),
  1, &separable_conv1d_5_conv2d_weights_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_19_scale, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_19_scale_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_conv2d_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &separable_conv1d_5_conv2d_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_19_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_19_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_separableconv_weights, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &separable_conv1d_5_separableconv_weights_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  seg_out_conv2d_weights, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 1), AI_STRIDE_INIT(4, 4, 4, 4, 12),
  1, &seg_out_conv2d_weights_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_separableconv_bias, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &separable_conv1d_5_separableconv_bias_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  seg_out_conv2d_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &seg_out_conv2d_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  input_2_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1920), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &input_2_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_conv2d_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1920), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &separable_conv1d_4_conv2d_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_conv2d_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 20, 16), AI_STRIDE_INIT(4, 4, 4, 4, 80),
  1, &separable_conv1d_6_conv2d_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_separableconv_output, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 960), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &separable_conv1d_4_separableconv_output_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_4_separableconv_scratch0, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 2), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &separable_conv1d_4_separableconv_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_conv2d_output, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 960), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &separable_conv1d_5_conv2d_output_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_conv2d_bias, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &separable_conv1d_6_conv2d_bias_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_separableconv_output, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 480), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &separable_conv1d_5_separableconv_output_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_5_separableconv_scratch0, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 2), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &separable_conv1d_5_separableconv_scratch0_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_conv2d_output, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 480), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &separable_conv1d_6_conv2d_output_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_separableconv_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &separable_conv1d_6_separableconv_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_separableconv_output, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 240), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &separable_conv1d_6_separableconv_output_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_separableconv_scratch0, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 2), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &separable_conv1d_6_separableconv_scratch0_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_conv2d_output, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 240), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &separable_conv1d_7_conv2d_output_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_6_separableconv_bias, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &separable_conv1d_6_separableconv_bias_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_separableconv_output, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 240), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &separable_conv1d_7_separableconv_output_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_9_conv2d_output, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_9_conv2d_output_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_conv2d_weights, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 7, 32), AI_STRIDE_INIT(4, 4, 4, 4, 28),
  1, &separable_conv1d_7_conv2d_weights_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_17_output, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_17_output_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_8_conv2d_output, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_8_conv2d_output_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_conv2d_bias, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &separable_conv1d_7_conv2d_bias_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_16_output, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_16_output_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_7_conv2d_output, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_7_conv2d_output_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_separableconv_weights, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 128), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &separable_conv1d_7_separableconv_weights_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_15_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_15_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_6_conv2d_output, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_6_conv2d_output_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  separable_conv1d_7_separableconv_bias, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &separable_conv1d_7_separableconv_bias_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_14_output, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_14_output_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  concatenate_1_output, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 240), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &concatenate_1_output_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_9_conv2d_weights, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 3, 1), AI_STRIDE_INIT(4, 4, 512, 512, 1536),
  1, &conv1d_9_conv2d_weights_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_10_conv2d_output, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 240), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_10_conv2d_output_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  up_sampling1d_2_output, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 960), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &up_sampling1d_2_output_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_9_conv2d_bias, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_9_conv2d_bias_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_11_conv2d_output, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 960), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_11_conv2d_output_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_19_output, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 960), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_19_output_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_17_scale, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_17_scale_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  up_sampling1d_3_output, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1920), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &up_sampling1d_3_output_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  seg_out_conv2d_output, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1920), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &seg_out_conv2d_output_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_17_bias, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_17_bias_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_8_conv2d_weights, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 3, 1), AI_STRIDE_INIT(4, 4, 512, 512, 1536),
  1, &conv1d_8_conv2d_weights_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_8_conv2d_bias, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_8_conv2d_bias_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_16_scale, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_16_scale_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_16_bias, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_16_bias_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_7_conv2d_weights, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 3, 1), AI_STRIDE_INIT(4, 4, 512, 512, 1536),
  1, &conv1d_7_conv2d_weights_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_7_conv2d_bias, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv1d_7_conv2d_bias_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_15_scale, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_15_scale_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  batch_normalization_15_bias, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &batch_normalization_15_bias_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_6_conv2d_weights, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 3, 1), AI_STRIDE_INIT(4, 4, 512, 512, 1536),
  1, &conv1d_6_conv2d_weights_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  seg_out_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &up_sampling1d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &seg_out_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &seg_out_conv2d_weights, &seg_out_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  seg_out_conv2d_layer, 32,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &seg_out_conv2d_chain,
  NULL, &seg_out_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_sigmoid_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 0, 1, 0), 
)


AI_STATIC_CONST ai_float up_sampling1d_3_scales_data[] = { 2, 1, 1.0, 1 };
AI_ARRAY_OBJ_DECLARE(
    up_sampling1d_3_scales, AI_ARRAY_FORMAT_FLOAT,
    up_sampling1d_3_scales_data, up_sampling1d_3_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  up_sampling1d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &up_sampling1d_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  up_sampling1d_3_layer, 31,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample,
  &up_sampling1d_3_chain,
  NULL, &seg_out_conv2d_layer, AI_STATIC, 
  .scales = &up_sampling1d_3_scales, 
  .center = true, 
  .mode = AI_UPSAMPLE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &batch_normalization_19_scale, &batch_normalization_19_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_19_layer, 30,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &batch_normalization_19_chain,
  NULL, &up_sampling1d_3_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_11_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &up_sampling1d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_11_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_11_conv2d_weights, &conv1d_11_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_11_conv2d_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_11_conv2d_chain,
  NULL, &batch_normalization_19_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float up_sampling1d_2_scales_data[] = { 4, 1, 1.0, 1 };
AI_ARRAY_OBJ_DECLARE(
    up_sampling1d_2_scales, AI_ARRAY_FORMAT_FLOAT,
    up_sampling1d_2_scales_data, up_sampling1d_2_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  up_sampling1d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &up_sampling1d_2_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  up_sampling1d_2_layer, 28,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample,
  &up_sampling1d_2_chain,
  NULL, &conv1d_11_conv2d_layer, AI_STATIC, 
  .scales = &up_sampling1d_2_scales, 
  .center = true, 
  .mode = AI_UPSAMPLE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_10_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concatenate_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_10_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_10_conv2d_weights, &conv1d_10_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_10_conv2d_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_10_conv2d_chain,
  NULL, &up_sampling1d_2_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concatenate_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 4, &batch_normalization_14_output, &batch_normalization_15_output, &batch_normalization_16_output, &batch_normalization_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concatenate_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concatenate_1_layer, 24,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concatenate_1_chain,
  NULL, &conv1d_10_conv2d_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &batch_normalization_14_scale, &batch_normalization_14_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_14_layer, 20,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &batch_normalization_14_chain,
  NULL, &concatenate_1_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_6_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_6_conv2d_weights, &conv1d_6_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_6_conv2d_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_6_conv2d_chain,
  NULL, &batch_normalization_14_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 5), 
  .filter_pad = AI_SHAPE_INIT(4, 5, 0, 5, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &batch_normalization_15_scale, &batch_normalization_15_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_15_layer, 21,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &batch_normalization_15_chain,
  NULL, &conv1d_6_conv2d_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_7_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_7_conv2d_weights, &conv1d_7_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_7_conv2d_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_7_conv2d_chain,
  NULL, &batch_normalization_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 9), 
  .filter_pad = AI_SHAPE_INIT(4, 9, 0, 9, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &batch_normalization_16_scale, &batch_normalization_16_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_16_layer, 22,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &batch_normalization_16_chain,
  NULL, &conv1d_7_conv2d_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_8_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_8_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_8_conv2d_weights, &conv1d_8_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_8_conv2d_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_8_conv2d_chain,
  NULL, &batch_normalization_16_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 14), 
  .filter_pad = AI_SHAPE_INIT(4, 14, 0, 14, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  batch_normalization_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &batch_normalization_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &batch_normalization_17_scale, &batch_normalization_17_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  batch_normalization_17_layer, 23,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &batch_normalization_17_chain,
  NULL, &conv1d_8_conv2d_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_9_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_9_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_9_conv2d_weights, &conv1d_9_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_9_conv2d_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1d_9_conv2d_chain,
  NULL, &batch_normalization_17_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 19), 
  .filter_pad = AI_SHAPE_INIT(4, 19, 0, 19, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_7_separableconv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_7_separableconv_weights, &separable_conv1d_7_separableconv_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_7_separableconv_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &separable_conv1d_7_separableconv_chain,
  NULL, &conv1d_9_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_7_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_6_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_7_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_7_conv2d_weights, &separable_conv1d_7_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_7_conv2d_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &separable_conv1d_7_conv2d_chain,
  NULL, &separable_conv1d_7_separableconv_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 3, 0, 3, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_6_separableconv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_6_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_6_separableconv_weights, &separable_conv1d_6_separableconv_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_6_separableconv_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_6_separableconv_layer, 12,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &separable_conv1d_6_separableconv_chain,
  NULL, &separable_conv1d_7_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(1, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 1, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_6_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_5_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_6_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_6_conv2d_weights, &separable_conv1d_6_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_6_conv2d_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &separable_conv1d_6_conv2d_chain,
  NULL, &separable_conv1d_6_separableconv_layer, AI_STATIC, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 9, 0, 10, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_5_separableconv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_5_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_5_separableconv_weights, &separable_conv1d_5_separableconv_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_5_separableconv_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_5_separableconv_layer, 8,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &separable_conv1d_5_separableconv_chain,
  NULL, &separable_conv1d_6_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(1, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 1, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_5_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_4_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_5_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_5_conv2d_weights, &separable_conv1d_5_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_5_conv2d_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &separable_conv1d_5_conv2d_chain,
  NULL, &separable_conv1d_5_separableconv_layer, AI_STATIC, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 19, 0, 20, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_4_separableconv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_4_separableconv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_4_separableconv_weights, &separable_conv1d_4_separableconv_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_4_separableconv_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_4_separableconv_layer, 4,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &separable_conv1d_4_separableconv_chain,
  NULL, &separable_conv1d_5_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(1, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 1, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  separable_conv1d_4_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &separable_conv1d_4_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &separable_conv1d_4_conv2d_weights, &separable_conv1d_4_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  separable_conv1d_4_conv2d_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &separable_conv1d_4_conv2d_chain,
  NULL, &separable_conv1d_4_separableconv_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 39, 0, 40, 0), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 29960, 1, 1),
    29960, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 125808, 1, 1),
    125808, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PPG_NETWORK_IN_NUM, &input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PPG_NETWORK_OUT_NUM, &seg_out_conv2d_output),
  &separable_conv1d_4_conv2d_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 29960, 1, 1),
      29960, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 125808, 1, 1),
      125808, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PPG_NETWORK_IN_NUM, &input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PPG_NETWORK_OUT_NUM, &seg_out_conv2d_output),
  &separable_conv1d_4_conv2d_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool ppg_network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_ppg_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_2_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 59280);
    input_2_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 59280);
    
    separable_conv1d_4_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 58796);
    separable_conv1d_4_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 58796);
    
    separable_conv1d_4_separableconv_scratch0_array.data = AI_PTR(g_ppg_network_activations_map[0] + 66896);
    separable_conv1d_4_separableconv_scratch0_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 66896);
    
    separable_conv1d_4_separableconv_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 35696);
    separable_conv1d_4_separableconv_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 35696);
    
    separable_conv1d_5_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 33744);
    separable_conv1d_5_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 33744);
    
    separable_conv1d_5_separableconv_scratch0_array.data = AI_PTR(g_ppg_network_activations_map[0] + 64464);
    separable_conv1d_5_separableconv_scratch0_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 64464);
    
    separable_conv1d_5_separableconv_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 33648);
    separable_conv1d_5_separableconv_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 33648);
    
    separable_conv1d_6_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 31664);
    separable_conv1d_6_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 31664);
    
    separable_conv1d_6_separableconv_scratch0_array.data = AI_PTR(g_ppg_network_activations_map[0] + 31408);
    separable_conv1d_6_separableconv_scratch0_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 31408);
    
    separable_conv1d_6_separableconv_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 62384);
    separable_conv1d_6_separableconv_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 62384);
    
    separable_conv1d_7_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 93104);
    separable_conv1d_7_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 93104);
    
    separable_conv1d_7_separableconv_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 48);
    separable_conv1d_7_separableconv_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 48);
    
    conv1d_9_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 122928);
    conv1d_9_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 122928);
    
    batch_normalization_17_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 122928);
    batch_normalization_17_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 122928);
    
    conv1d_8_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 123888);
    conv1d_8_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 123888);
    
    batch_normalization_16_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 123888);
    batch_normalization_16_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 123888);
    
    conv1d_7_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 124848);
    conv1d_7_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 124848);
    
    batch_normalization_15_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 124848);
    batch_normalization_15_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 124848);
    
    conv1d_6_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 0);
    conv1d_6_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 0);
    
    batch_normalization_14_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 960);
    batch_normalization_14_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 960);
    
    concatenate_1_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 1920);
    concatenate_1_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 1920);
    
    conv1d_10_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 0);
    conv1d_10_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 0);
    
    up_sampling1d_2_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 960);
    up_sampling1d_2_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 960);
    
    conv1d_11_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 4800);
    conv1d_11_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 4800);
    
    batch_normalization_19_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 0);
    batch_normalization_19_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 0);
    
    up_sampling1d_3_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 3840);
    up_sampling1d_3_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 3840);
    
    seg_out_conv2d_output_array.data = AI_PTR(g_ppg_network_activations_map[0] + 11520);
    seg_out_conv2d_output_array.data_start = AI_PTR(g_ppg_network_activations_map[0] + 11520);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool ppg_network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_ppg_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv1d_6_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_6_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 0);
    conv1d_6_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 0);
    
    batch_normalization_14_scale_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_14_scale_array.data = AI_PTR(g_ppg_network_weights_map[0] + 4);
    batch_normalization_14_scale_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 4);
    
    batch_normalization_14_bias_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_14_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 8);
    batch_normalization_14_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 8);
    
    separable_conv1d_4_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_4_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 12);
    separable_conv1d_4_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 12);
    
    conv1d_10_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_10_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 332);
    conv1d_10_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 332);
    
    separable_conv1d_4_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_4_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 348);
    separable_conv1d_4_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 348);
    
    conv1d_10_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_10_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 352);
    conv1d_10_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 352);
    
    separable_conv1d_4_separableconv_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_4_separableconv_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 356);
    separable_conv1d_4_separableconv_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 356);
    
    conv1d_11_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_11_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 388);
    conv1d_11_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 388);
    
    separable_conv1d_4_separableconv_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_4_separableconv_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 392);
    separable_conv1d_4_separableconv_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 392);
    
    conv1d_11_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_11_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 424);
    conv1d_11_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 424);
    
    separable_conv1d_5_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_5_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 428);
    separable_conv1d_5_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 428);
    
    batch_normalization_19_scale_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_19_scale_array.data = AI_PTR(g_ppg_network_weights_map[0] + 1708);
    batch_normalization_19_scale_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 1708);
    
    separable_conv1d_5_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_5_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 1712);
    separable_conv1d_5_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 1712);
    
    batch_normalization_19_bias_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_19_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 1744);
    batch_normalization_19_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 1744);
    
    separable_conv1d_5_separableconv_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_5_separableconv_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 1748);
    separable_conv1d_5_separableconv_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 1748);
    
    seg_out_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    seg_out_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 2260);
    seg_out_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 2260);
    
    separable_conv1d_5_separableconv_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_5_separableconv_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 2272);
    separable_conv1d_5_separableconv_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 2272);
    
    seg_out_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    seg_out_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 2336);
    seg_out_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 2336);
    
    separable_conv1d_6_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_6_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 2340);
    separable_conv1d_6_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 2340);
    
    separable_conv1d_6_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_6_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 3620);
    separable_conv1d_6_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 3620);
    
    separable_conv1d_6_separableconv_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_6_separableconv_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 3684);
    separable_conv1d_6_separableconv_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 3684);
    
    separable_conv1d_6_separableconv_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_6_separableconv_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 5732);
    separable_conv1d_6_separableconv_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 5732);
    
    separable_conv1d_7_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_7_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 5860);
    separable_conv1d_7_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 5860);
    
    separable_conv1d_7_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_7_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 6756);
    separable_conv1d_7_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 6756);
    
    separable_conv1d_7_separableconv_weights_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_7_separableconv_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 6884);
    separable_conv1d_7_separableconv_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 6884);
    
    separable_conv1d_7_separableconv_bias_array.format |= AI_FMT_FLAG_CONST;
    separable_conv1d_7_separableconv_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 23268);
    separable_conv1d_7_separableconv_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 23268);
    
    conv1d_9_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_9_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 23780);
    conv1d_9_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 23780);
    
    conv1d_9_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_9_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 25316);
    conv1d_9_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 25316);
    
    batch_normalization_17_scale_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_17_scale_array.data = AI_PTR(g_ppg_network_weights_map[0] + 25320);
    batch_normalization_17_scale_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 25320);
    
    batch_normalization_17_bias_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_17_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 25324);
    batch_normalization_17_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 25324);
    
    conv1d_8_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_8_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 25328);
    conv1d_8_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 25328);
    
    conv1d_8_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_8_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 26864);
    conv1d_8_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 26864);
    
    batch_normalization_16_scale_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_16_scale_array.data = AI_PTR(g_ppg_network_weights_map[0] + 26868);
    batch_normalization_16_scale_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 26868);
    
    batch_normalization_16_bias_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_16_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 26872);
    batch_normalization_16_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 26872);
    
    conv1d_7_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_7_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 26876);
    conv1d_7_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 26876);
    
    conv1d_7_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_7_conv2d_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 28412);
    conv1d_7_conv2d_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 28412);
    
    batch_normalization_15_scale_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_15_scale_array.data = AI_PTR(g_ppg_network_weights_map[0] + 28416);
    batch_normalization_15_scale_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 28416);
    
    batch_normalization_15_bias_array.format |= AI_FMT_FLAG_CONST;
    batch_normalization_15_bias_array.data = AI_PTR(g_ppg_network_weights_map[0] + 28420);
    batch_normalization_15_bias_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 28420);
    
    conv1d_6_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_6_conv2d_weights_array.data = AI_PTR(g_ppg_network_weights_map[0] + 28424);
    conv1d_6_conv2d_weights_array.data_start = AI_PTR(g_ppg_network_weights_map[0] + 28424);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_ppg_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_PPG_NETWORK_MODEL_NAME,
      .model_signature   = AI_PPG_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 2559848,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_ppg_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_PPG_NETWORK_MODEL_NAME,
      .model_signature   = AI_PPG_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 2559848,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_ppg_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_ppg_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_ppg_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_ppg_network_create(network, AI_PPG_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_ppg_network_data_params_get(&params) != true) {
        err = ai_ppg_network_get_error(*network);
        return err;
    }
#if defined(AI_PPG_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_PPG_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_ppg_network_init(*network, &params) != true) {
        err = ai_ppg_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_ppg_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_ppg_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_ppg_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_ppg_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= ppg_network_configure_weights(net_ctx, params);
  ok &= ppg_network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_ppg_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_ppg_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_PPG_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

