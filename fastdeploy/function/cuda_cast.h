// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "fastdeploy/core/fd_tensor.h"

namespace fastdeploy {

/** Cast the type of the data in GPU buffer.
    @param in The input tensor.
    @param out The output tensor
    @param stream CUDA stream
*/
FASTDEPLOY_DECL void CudaCast(const FDTensor& in, FDTensor* out,
                              cudaStream_t stream);

}  // namespace fastdeploy