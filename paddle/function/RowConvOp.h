/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include "Function.h"

namespace paddle {

/**
 * \brief The forward of row convolution.
 *
 * \param[out] out      The output data and shape is h x d. h is the sum of
 *                      time steps of all samples in one mini-batch.
 * \param[in]  in       The input data and shape is h x d.
 * \param[in]  filter   The filter and shape is k x d. The lookahead step
 *                      number plus one equals k.
 * \param[in]  seq      The sequence start positions.
 *
 */
template <DeviceType DType>
void RowConv(typename Tensor<real, DType>::Matrix& out,
             const typename Tensor<real, DType>::Matrix& in,
             const typename Tensor<real, DType>::Matrix& filter,
             const typename Tensor<int, DType>::Vector& seq);

/**
 * \brief The backward of row convolution.
 *
 * \param[in]  outG     The gradient w.r.t output data.
 * \param[in]  in       The input data.
 * \param[in]  filter   The filter.
 * \param[out] inG      The gradient w.r.t input data.
 * \param[out] filterG  The gradient w.r.t filter.
 * \param[in]  seq      The sequence start positions.
 *
 */
template <DeviceType DType>
void RowConvGrad(const typename Tensor<real, DType>::Matrix& outG,
                 const typename Tensor<real, DType>::Matrix& in,
                 const typename Tensor<real, DType>::Matrix& filter,
                 typename Tensor<real, DType>::Matrix& inG,
                 typename Tensor<real, DType>::Matrix& filterG,
                 const typename Tensor<int, DType>::Vector& seq);
}  // namespace paddle