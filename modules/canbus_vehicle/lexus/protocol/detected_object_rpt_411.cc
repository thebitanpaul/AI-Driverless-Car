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

#include "modules/canbus_vehicle/lexus/protocol/detected_object_rpt_411.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace lexus {

using ::apollo::drivers::canbus::Byte;

Detectedobjectrpt411::Detectedobjectrpt411() {}
const int32_t Detectedobjectrpt411::ID = 0x411;

void Detectedobjectrpt411::Parse(const std::uint8_t* bytes, int32_t length,
                                 Lexus* chassis) const {
  chassis->mutable_detected_object_rpt_411()
      ->set_front_object_distance_high_res(
          front_object_distance_high_res(bytes, length));
  chassis->mutable_detected_object_rpt_411()->set_front_object_distance_low_res(
      front_object_distance_low_res(bytes, length));
}

// config detail: {'name': 'front_object_distance_high_res', 'offset': 0.0,
// 'precision': 0.001, 'len': 24, 'is_signed_var': False, 'physical_range':
// '[0|16777.215]', 'bit': 31, 'type': 'double', 'order': 'motorola',
// 'physical_unit': 'm'}
double Detectedobjectrpt411::front_object_distance_high_res(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 5);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'name': 'front_object_distance_low_res', 'offset': 0.0,
// 'precision': 0.001, 'len': 24, 'is_signed_var': False, 'physical_range':
// '[0|16777.215]', 'bit': 7, 'type': 'double', 'order': 'motorola',
// 'physical_unit': 'm'}
double Detectedobjectrpt411::front_object_distance_low_res(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 2);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}
}  // namespace lexus
}  // namespace canbus
}  // namespace apollo
