/**
  ******************************************************************************
  * @file    ppg_network_data.h
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

#ifndef PPG_NETWORK_DATA_H
#define PPG_NETWORK_DATA_H
#pragma once

#include "ppg_network_config.h"
#include "ppg_network_data_params.h"

AI_DEPRECATED
#define AI_PPG_NETWORK_DATA_ACTIVATIONS(ptr_)  \
  ai_ppg_network_data_activations_buffer_get(AI_HANDLE_PTR(ptr_))

AI_DEPRECATED
#define AI_PPG_NETWORK_DATA_WEIGHTS(ptr_)  \
  ai_ppg_network_data_weights_buffer_get(AI_HANDLE_PTR(ptr_))


AI_API_DECLARE_BEGIN


extern const ai_u64 s_ppg_network_weights_array_u64[3745];



/*!
 * @brief Get network activations buffer initialized struct.
 * @ingroup ppg_network_data
 * @param[in] ptr a pointer to the activations array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_ppg_network_data_activations_buffer_get(const ai_handle ptr);

/*!
 * @brief Get network weights buffer initialized struct.
 * @ingroup ppg_network_data
 * @param[in] ptr a pointer to the weights array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_ppg_network_data_weights_buffer_get(const ai_handle ptr);

/*!
 * @brief Get network weights array pointer as a handle ptr.
 * @ingroup ppg_network_data
 * @return a ai_handle pointer to the weights array
 */
AI_DEPRECATED
AI_API_ENTRY
ai_handle ai_ppg_network_data_weights_get(void);


/*!
 * @brief Get network params configuration data structure.
 * @ingroup ppg_network_data
 * @return true if a valid configuration is present, false otherwise
 */
AI_API_ENTRY
ai_bool ai_ppg_network_data_params_get(ai_network_params* params);


AI_API_DECLARE_END

#endif /* PPG_NETWORK_DATA_H */

