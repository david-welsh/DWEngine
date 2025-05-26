//
//  AnimationComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "AnimationComponent.hpp"

void from_json(const nlohmann::json& j, AnimationComponent& a) {
    j.at("currentAnimation").get_to(a.currentAnimation);
}
