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

#include "modules/canbus_vehicle/neolix_edu/protocol/aeb_rearwheelspeed_354.h"

#include "glog/logging.h"

#include "gtest/gtest.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace neolix_edu {

class Aebrearwheelspeed354Test : public ::testing::Test {
 public:
  virtual void SetUp() {}
};

TEST_F(Aebrearwheelspeed354Test, reset) {
  uint8_t data[8] = {0x67, 0x62, 0x63, 0x64, 0x51, 0x52, 0x53, 0x54};
  int32_t length = 8;
  Neolix_edu cd;
  Aebrearwheelspeed354 accel_cmd;
  accel_cmd.Parse(data, length, &cd);
  EXPECT_EQ(data[0], 0b01100111);
  EXPECT_EQ(data[1], 0b01100010);
  EXPECT_EQ(data[2], 0b01100011);
  EXPECT_EQ(data[3], 0b01100100);
  EXPECT_EQ(data[4], 0b01010001);
  EXPECT_EQ(data[5], 0b01010010);
  EXPECT_EQ(data[6], 0b01010011);
  EXPECT_EQ(data[7], 0b01010100);

  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rl_valid(),
            false);
  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rl(), 254.44);
  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rr_valid(),
            false);
  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rr(), 208.18);
  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rl_direct(), 1);
  EXPECT_EQ(cd.aeb_rearwheelspeed_354().wheelspeed_rr_direct(), 1);
}

}  // namespace neolix_edu
}  // namespace canbus
}  // namespace apollo
