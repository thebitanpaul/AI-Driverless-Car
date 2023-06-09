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

#include "modules/canbus_vehicle/ge3/protocol/scu_bcm_304.h"
#include "gtest/gtest.h"

namespace apollo {
namespace canbus {
namespace ge3 {

class Scubcm304Test : public ::testing::Test {
 public:
  virtual void SetUp() {}
};

TEST_F(Scubcm304Test, reset) {
  Scubcm304 scubcm304;
  int32_t length = 8;
  Ge3 chassis_detail;
  uint8_t bytes[8] = {0x01, 0x02, 0x03, 0x04, 0x11, 0x12, 0x13, 0x14};

  scubcm304.Parse(bytes, length, &chassis_detail);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_vehreversest(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_rightturnlampst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_rearfoglampst(), 1);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_parkinglampst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_lowbeamst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_leftturnlampst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_keyst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_hornst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_highbeamst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_hazardlampst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_frontfoglampst(), 0);
  EXPECT_DOUBLE_EQ(chassis_detail.scu_bcm_304().bcm_brakelightswitchst(),
                   0);
}

}  // namespace ge3
}  // namespace canbus
}  // namespace apollo
