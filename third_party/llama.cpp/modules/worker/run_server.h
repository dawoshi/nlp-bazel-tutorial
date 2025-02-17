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

#ifndef GENC_CC_MODULES_WORKER_RUN_SERVER_H_
#define GENC_CC_MODULES_WORKER_RUN_SERVER_H_

#include <memory>
#include <string>

#include "absl/status/status.h"
#include "third_party/llama.cpp/runtime/executor.h"

namespace genc {
namespace modules {
namespace worker {

struct RunServerOptions {
  enum ChannelType {
    INSECURE,
    SSL,
  };
  std::string server_address;
  ChannelType channel_type = INSECURE;
  std::string ssl_cert_path;
  std::string ssl_key_path;
  bool use_oak = false;
  bool debug = false;
};

absl::Status RunServer(
    std::shared_ptr<Executor> executor, const RunServerOptions& options);

}  // namespace worker
}  // namespace modules
}  // namespace genc

#endif  // GENC_CC_MODULES_WORKER_RUN_SERVER_H_
