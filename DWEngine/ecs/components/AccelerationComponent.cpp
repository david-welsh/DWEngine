//
//  AccelerationComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#include "AccelerationComponent.hpp"

void from_json(const nlohmann::json& j, AccelerationComponent& r) {
    j.at("a").get_to(r.a);
}
