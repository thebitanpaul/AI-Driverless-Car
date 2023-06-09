/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include "modules/monitor/common/recurrent_runner.h"
#include "modules/common_msgs/monitor_msgs/system_status.pb.h"

namespace apollo {
namespace monitor {

// Check if we need to switch to safe mode, and then
// 1. Notify driver to take action.
// 2. Trigger Guardian if no proper action was taken.
class FunctionalSafetyMonitor : public RecurrentRunner {
 public:
  FunctionalSafetyMonitor();
  void RunOnce(const double current_time);

 private:
  bool CheckSafety();
};

}  // namespace monitor
}  // namespace apollo
