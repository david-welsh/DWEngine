//
//  GravityComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "GravityComponent.hpp"

void from_json(const nlohmann::json& j, GravityComponent& r) {
    j.at("gForce").get_to(r.gForce);
}
