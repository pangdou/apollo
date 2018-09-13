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

/**
 * @file
 **/

#ifndef MODULES_PLANNING_TOOLKITS_OPTIMIZERS_SIDE_PASS_PATH_OPTIMIZER_H_
#define MODULES_PLANNING_TOOLKITS_OPTIMIZERS_SIDE_PASS_PATH_OPTIMIZER_H_

#include "modules/planning/proto/dp_poly_path_config.pb.h"
#include "modules/planning/proto/planning_config.pb.h"

#include "modules/planning/toolkits/optimizers/path_optimizer.h"

namespace apollo {
namespace planning {

/**
 * @class SidePassPathOptimizer
 * @brief SidePassPathOptimizer does path planning with dynamic programming
 * algorithm.
 */
class SidePassPathOptimizer final : public PathOptimizer {
 public:
  SidePassPathOptimizer();

  bool Init(const ScenarioConfig::ScenarioTaskConfig &config) override;

 private:
  apollo::common::Status Process(const SpeedData &speed_data,
                                 const ReferenceLine &reference_line,
                                 const common::TrajectoryPoint &init_point,
                                 PathData *const path_data) override;

 private:
  DpPolyPathConfig config_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_TOOLKITS_OPTIMIZERS_SIDE_PASS_PATH_OPTIMIZER_H_
