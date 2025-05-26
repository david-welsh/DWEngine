//
//  SpriteComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "SpriteComponent.hpp"

void from_json(const nlohmann::json& j, SpriteComponent& a) {
    j.at("idle").get_to(a.idle);
    j.at("left").get_to(a.left);
    j.at("right").get_to(a.right);
}
