//
//  CollidableComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef CollidableComponent_hpp
#define CollidableComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class CollidableComponent: public Component {
public:
    float width, height;
    bool isSolid;
    bool isMovable;
    bool isGrounded{false};
};

void from_json(const nlohmann::json& j, CollidableComponent& a);

#endif /* CollidableComponent_hpp */
