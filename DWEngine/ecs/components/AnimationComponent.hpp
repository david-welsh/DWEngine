//
//  AnimationComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef AnimationComponent_hpp
#define AnimationComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class AnimationComponent: public Component {
public:
    std::string currentAnimation;
    bool reset{true};
    float timeSinceLastFrame{0.0f};
};

void from_json(const nlohmann::json& j, AnimationComponent& a);

#endif /* AnimationComponent_hpp */
