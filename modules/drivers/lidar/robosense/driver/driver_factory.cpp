/******************************************************************************
 * Copyright 2021 The Apollo Authors. All Rights Reserved.
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

#include "modules/drivers/lidar/robosense/driver/driver_factory.h"

namespace apollo {
namespace drivers {
namespace robosense {

RobosenseDriver* RobosenseDriverFactory::create_driver(
    const apollo::drivers::suteng::SutengConfig& roboconfig_) {
  if (roboconfig_.model() == apollo::drivers::suteng::Model::VLP16) {
    return new Robosense16Driver(roboconfig_);
  } else if (roboconfig_.model() ==
             apollo::drivers::suteng::Model::HELIOS_16P) {
    AINFO << "RobosenseDriverFactory HELIOS_16P 1";
    return new Robosense16PDriver(roboconfig_);
  } else {
    AERROR << "Invalid lidar model, must be VLP16 or HELIOS_16P";
    return nullptr;
  }
}
}  // namespace robosense
}  // namespace drivers
}  // namespace apollo
