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

#ifndef GENC_CC_INTRINSICS_PROMPT_TEMPLATE_H_
#define GENC_CC_INTRINSICS_PROMPT_TEMPLATE_H_

#include "absl/status/status.h"
#include "absl/strings/string_view.h"
#include "third_party/llama.cpp/intrinsics/intrinsic_uris.h"
#include "third_party/llama.cpp/runtime/intrinsic_handler.h"
#include "third_party/llama.cpp/proto/v0/computation.pb.h"

namespace genc {
namespace intrinsics {

class PromptTemplate : public InlineIntrinsicHandlerBase {
 public:
  PromptTemplate() : InlineIntrinsicHandlerBase(kPromptTemplate) {}
  virtual ~PromptTemplate() {}

  absl::Status CheckWellFormed(const v0::Intrinsic& intrinsic_pb) const final;
  absl::Status ExecuteCall(const v0::Intrinsic& intrinsic_pb,
                           const v0::Value& arg, v0::Value* result,
                           Context* context) const final;
};

class PromptTemplateWithParameters : public InlineIntrinsicHandlerBase {
 public:
  PromptTemplateWithParameters()
            : InlineIntrinsicHandlerBase(kPromptTemplateWithParameters) {}
  virtual ~PromptTemplateWithParameters() {}

  absl::Status CheckWellFormed(const v0::Intrinsic& intrinsic_pb) const final;
  absl::Status ExecuteCall(const v0::Intrinsic& intrinsic_pb,
                           const v0::Value& arg, v0::Value* result,
                           Context* context) const final;
};

}  // namespace intrinsics
}  // namespace genc

#endif  // GENC_CC_INTRINSICS_PROMPT_TEMPLATE_H_
