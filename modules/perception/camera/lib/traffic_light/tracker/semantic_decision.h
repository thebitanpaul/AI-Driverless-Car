/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <string>
#include <vector>

#include "cyber/common/macros.h"
#include "modules/perception/camera/lib/interface/base_traffic_light_tracker.h"
#include "modules/perception/pipeline/proto/pipeline_config.pb.h"
#include "modules/perception/pipeline/stage.h"

namespace apollo {
namespace perception {
namespace camera {

struct HystereticWindow {
  int hysteretic_count = 0;
  base::TLColor hysteretic_color = base::TLColor::TL_UNKNOWN_COLOR;
};

struct SemanticTable {
  double time_stamp = 0.0;
  double last_bright_time_stamp = 0.0;
  double last_dark_time_stamp = 0.0;
  bool blink = false;
  std::string semantic;
  std::vector<int> light_ids;
  base::TLColor color;
  HystereticWindow hystertic_window;
};

class SemanticReviser final : public BaseTrafficLightTracker {
 public:
  SemanticReviser();
  ~SemanticReviser() = default;

  bool Init(const TrafficLightTrackerInitOptions &options =
                TrafficLightTrackerInitOptions()) override;

  bool Track(const TrafficLightTrackerOptions &options,
             CameraFrame *frame) override;
  base::TLColor ReviseBySemantic(SemanticTable semantic_table,
                                 std::vector<base::TrafficLightPtr> *lights);
  void ReviseByTimeSeries(double time_stamp, SemanticTable semantic_table,
                          std::vector<base::TrafficLightPtr> *lights);
  void UpdateHistoryAndLights(const SemanticTable &cur,
                              std::vector<base::TrafficLightPtr> *lights,
                              std::vector<SemanticTable>::iterator *history);
  void ReviseLights(std::vector<base::TrafficLightPtr> *lights,
                    const std::vector<int> &light_ids, base::TLColor dst_color);

  bool Init(const StageConfig& stage_config) override;

  bool Process(DataFrame* data_frame) override;

  bool IsEnabled() const override { return enable_; }

  std::string Name() const override { return name_; }

 private:
  SemanticReviserConfig semantic_param_;

  float revise_time_s_;
  float blink_threshold_s_;
  float non_blink_threshold_s_;
  int hysteretic_threshold_;
  std::vector<SemanticTable> history_semantic_;

  DISALLOW_COPY_AND_ASSIGN(SemanticReviser);
};

}  // namespace camera
}  // namespace perception
}  // namespace apollo
