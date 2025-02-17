/* Copyright 2023, The GenC Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License
==============================================================================*/

#ifndef GENC_CC_INTEROP_BACKENDS_JAVA_OPEN_AI_H_
#define GENC_CC_INTEROP_BACKENDS_JAVA_OPEN_AI_H_

#include <jni.h>

#include "absl/status/statusor.h"
#include "third_party/llama.cpp/proto/v0/computation.pb.h"

namespace genc {

absl::StatusOr<v0::Value> OpenAiCall(JavaVM* jvm, jobject open_ai_client,
                                     const v0::Value& func,
                                     const v0::Value& arg);

}  // namespace genc

#endif  // GENC_CC_INTEROP_BACKENDS_JAVA_OPEN_AI_H_
