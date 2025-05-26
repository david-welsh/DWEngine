//
//  GravityComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef GravityComponent_hpp
#define GravityComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class GravityComponent: public Component {
public:
    float gForce;
};

void from_json(const nlohmann::json& j, GravityComponent& r);

#endif /* GravityComponent_hpp */
