//
//  PositionComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class PositionComponent: public Component {
public:
    float x, y;
};

void from_json(const nlohmann::json& j, PositionComponent& p);

#endif /* PositionComponent_hpp */
