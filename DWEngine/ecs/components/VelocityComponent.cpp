//
//  VelocityComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "VelocityComponent.hpp"

void from_json(const nlohmann::json& j, VelocityComponent& r) {
    j.at("vx").get_to(r.vx);
    j.at("vy").get_to(r.vy);
    j.at("maxV").get_to(r.maxV);
}
