//
//  CollidableComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "CollidableComponent.hpp"

void from_json(const nlohmann::json& j, CollidableComponent& a) {
    j.at("width").get_to(a.width);
    j.at("height").get_to(a.height);
    j.at("isSolid").get_to(a.isSolid);
    j.at("isMovable").get_to(a.isMovable);
}
