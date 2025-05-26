//
//  FrictionComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "FrictionComponent.hpp"

void from_json(const nlohmann::json& j, FrictionComponent& a) {
    j.at("friction").get_to(a.friction);
    j.at("airFriction").get_to(a.airFriction);
}
