/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

#include "modules/common_msgs/chassis_msgs/chassis.pb.h"
#include "modules/data/tools/smart_recorder/proto/smart_recorder_triggers.pb.h"
#include "modules/data/tools/smart_recorder/trigger_base.h"

namespace apollo {
namespace data {

/**
 * @class EmergencyModeTrigger
 * @brief EmergencyMode trigger that fires when emergency mode is engaged
 */
class EmergencyModeTrigger : public TriggerBase {
 public:
  EmergencyModeTrigger();

  void Pull(const cyber::record::RecordMessage& msg) override;
  bool ShouldRestore(const cyber::record::RecordMessage& msg) const override {
    return false;
  };

  virtual ~EmergencyModeTrigger() = default;

 private:
  apollo::canbus::Chassis::DrivingMode cur_driving_mode_ =
      apollo::canbus::Chassis::COMPLETE_MANUAL;
};

}  // namespace data
}  // namespace apollo
