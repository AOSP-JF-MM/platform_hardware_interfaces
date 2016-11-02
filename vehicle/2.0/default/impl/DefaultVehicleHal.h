/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef android_hardware_vehicle_V2_0_impl_DefaultVehicleHal_H_
#define android_hardware_vehicle_V2_0_impl_DefaultVehicleHal_H_

#include <VehicleHal.h>
#include <impl/DefaultConfig.h>
#include <utils/SystemClock.h>

namespace android {
namespace hardware {
namespace vehicle {
namespace V2_0 {

namespace impl {

class DefaultVehicleHal : public VehicleHal {
public:
    std::vector<VehiclePropConfig> listProperties() override {
        return std::vector<VehiclePropConfig>(std::begin(kVehicleProperties),
                                              std::end(kVehicleProperties));
    }

    VehiclePropValuePtr get(VehicleProperty property,
                            int32_t areaId,
                            status_t* outStatus) override;

    status_t set(const VehiclePropValue& propValue) override;

    status_t subscribe(VehicleProperty property,
                       int32_t areas,
                       float sampleRate) {
        // TODO(pavelm): implement
        return OK;
    }

    status_t unsubscribe(VehicleProperty property) {
        // TODO(pavelm): implement
        return OK;
    }

private:
    status_t getHvacFanSpeed(int32_t areaId, int32_t* outValue);
    status_t setHvacFanSpeed(int32_t areaId, int32_t value);
private:
    int32_t fanSpeedRow1Left = 3;
    int32_t fanSpeedRow1Right = 5;
    int32_t brightness = 7;
};

}  // impl

}  // namespace V2_0
}  // namespace vehicle
}  // namespace hardware
}  // namespace android


#endif  // android_hardware_vehicle_V2_0_impl_DefaultVehicleHal_H_