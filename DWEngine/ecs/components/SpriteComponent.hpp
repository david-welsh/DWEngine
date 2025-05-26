//
//  SpriteComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class SpriteComponent: public Component {
public:
    std::string idle;
    std::string left;
    std::string right;
};

void from_json(const nlohmann::json& j, SpriteComponent& a);

#endif /* SpriteComponent_hpp */
