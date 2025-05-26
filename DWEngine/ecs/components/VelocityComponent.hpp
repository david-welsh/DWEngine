//
//  VelocityComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef VelocityComponent_hpp
#define VelocityComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class VelocityComponent: public Component {
public:
    float maxV;
    float vx, vy;
};

void from_json(const nlohmann::json& j, VelocityComponent& r);

#endif /* VelocityComponent_hpp */
