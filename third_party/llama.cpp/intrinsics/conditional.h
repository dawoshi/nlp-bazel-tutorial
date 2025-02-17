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

#ifndef GENC_CC_INTRINSICS_CONDITIONAL_H_
#define GENC_CC_INTRINSICS_CONDITIONAL_H_

#include <optional>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "third_party/llama.cpp/intrinsics/intrinsic_uris.h"
#include "third_party/llama.cpp/runtime/intrinsic_handler.h"
#include "third_party/llama.cpp/proto/v0/computation.pb.h"

namespace genc {
namespace intrinsics {

class Conditional : public ControlFlowIntrinsicHandlerBase {
 public:
  Conditional() : ControlFlowIntrinsicHandlerBase(kConditional) {}

  virtual ~Conditional() {}

  absl::Status CheckWellFormed(const v0::Intrinsic& intrinsic_pb) const final;

  absl::StatusOr<ValueRef> ExecuteCall(const v0::Intrinsic& intrinsic_pb,
                                       std::optional<ValueRef> arg,
                                       Context* context) const final;
};

}  // namespace intrinsics
}  // namespace genc

#endif  // GENC_CC_INTRINSICS_CONDITIONAL_H_
