// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
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

#include "fastdeploy_capi/fd_type.h"

#include <opencv2/imgcodecs.hpp>

#include "fastdeploy_capi/fd_common.h"

#ifdef __cplusplus
extern "C" {
#endif

FD_C_Mat FD_C_Imread(const char* imgpath) {
  cv::Mat image = cv::imread(imgpath);
  return new cv::Mat(image);
}

FD_C_Bool FD_C_Imwrite(const char* savepath, FD_C_Mat img) {
  cv::Mat cv_img = *(reinterpret_cast<cv::Mat*>(img));
  bool result = cv::imwrite(savepath, cv_img);
  return result;
}

void FD_C_DestroyMat(FD_C_Mat mat) { delete reinterpret_cast<cv::Mat*>(mat); }

#ifdef __cplusplus
}
#endif
