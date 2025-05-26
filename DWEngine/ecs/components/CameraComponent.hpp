//
//  CameraComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 22/06/2024.
//

#ifndef CameraComponent_hpp
#define CameraComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class CameraComponent: public Component {
public:
    int width, height;
};

void from_json(const nlohmann::json& j, CameraComponent& a);

#endif /* CameraComponent_hpp */
