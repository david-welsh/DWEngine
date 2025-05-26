//
//  CameraComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 22/06/2024.
//

#include "CameraComponent.hpp"

void from_json(const nlohmann::json& j, CameraComponent& a) {
    j.at("width").get_to(a.width);
    j.at("height").get_to(a.height);
}
