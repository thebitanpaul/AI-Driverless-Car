/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
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

#include "modules/canbus_vehicle/devkit/protocol/ultr_sensor_2_508.h"

#include "gtest/gtest.h"

namespace apollo {
namespace canbus {
namespace devkit {
class Ultrsensor2508Test : public ::testing::Test {
 public:
  virtual void SetUp() {}
};

TEST_F(Ultrsensor2508Test, General) {
  uint8_t data[8] = {0xE2, 0x95, 0x06, 0x58, 0x08, 0xD6, 0x02, 0x44};
  int32_t length = 8;
  Devkit cd;
  Ultrsensor2508 ultrsensor2;
  ultrsensor2.Parse(data, length, &cd);

  EXPECT_EQ(data[0], 0b11100010);
  EXPECT_EQ(data[1], 0b10010101);
  EXPECT_EQ(data[2], 0b00000110);
  EXPECT_EQ(data[3], 0b01011000);
  EXPECT_EQ(data[4], 0b00001000);
  EXPECT_EQ(data[5], 0b11010110);
  EXPECT_EQ(data[6], 0b00000010);
  EXPECT_EQ(data[7], 0b01000100);

  EXPECT_EQ(cd.ultr_sensor_2_508().uiuss9_tof_indirect(), 28);
  EXPECT_EQ(cd.ultr_sensor_2_508().uiuss8_tof_indirect(), 1000);
  EXPECT_EQ(cd.ultr_sensor_2_508().uiuss11_tof_indirect(), 10);
  EXPECT_EQ(cd.ultr_sensor_2_508().uiuss10_tof_indirect(), 39);
}

}  // namespace devkit
}  // namespace canbus
}  // namespace apollo
