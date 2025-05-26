//
//  FrictionComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef FrictionComponent_hpp
#define FrictionComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class FrictionComponent: public Component {
public:
    float friction;
    float airFriction;
    bool isMoving{false};
};

void from_json(const nlohmann::json& j, FrictionComponent& a);

#endif /* FrictionComponent_hpp */
