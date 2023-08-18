/**
  ******************************************************************************
  * @file    ppg_network_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue May  9 01:18:54 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef PPG_NETWORK_DATA_PARAMS_H
#define PPG_NETWORK_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_PPG_NETWORK_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_ppg_network_data_weights_params[1]))
*/

#define AI_PPG_NETWORK_DATA_CONFIG               (NULL)


#define AI_PPG_NETWORK_DATA_ACTIVATIONS_SIZES \
  { 125808, }
#define AI_PPG_NETWORK_DATA_ACTIVATIONS_SIZE     (125808)
#define AI_PPG_NETWORK_DATA_ACTIVATIONS_COUNT    (1)
#define AI_PPG_NETWORK_DATA_ACTIVATION_1_SIZE    (125808)



#define AI_PPG_NETWORK_DATA_WEIGHTS_SIZES \
  { 29960, }
#define AI_PPG_NETWORK_DATA_WEIGHTS_SIZE         (29960)
#define AI_PPG_NETWORK_DATA_WEIGHTS_COUNT        (1)
#define AI_PPG_NETWORK_DATA_WEIGHT_1_SIZE        (29960)



#define AI_PPG_NETWORK_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_ppg_network_activations_table[1])

extern ai_handle g_ppg_network_activations_table[1 + 2];



#define AI_PPG_NETWORK_DATA_WEIGHTS_TABLE_GET() \
  (&g_ppg_network_weights_table[1])

extern ai_handle g_ppg_network_weights_table[1 + 2];


#endif    /* PPG_NETWORK_DATA_PARAMS_H */
