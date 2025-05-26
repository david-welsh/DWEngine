//
//  InputComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "InputComponent.hpp"

void from_json(const nlohmann::json& j, InputComponent& a) {
    j.at("jumpPower").get_to(a.jumpPower);    
}
