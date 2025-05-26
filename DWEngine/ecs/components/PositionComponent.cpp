//
//  PositionComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "PositionComponent.hpp"

void from_json(const nlohmann::json& j, PositionComponent& p) {
   j.at("x").get_to(p.x);
   j.at("y").get_to(p.y);
}
