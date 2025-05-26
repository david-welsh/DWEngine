//
//  RenderableComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef RenderableComponent_hpp
#define RenderableComponent_hpp

#include <string>

#include "Component.hpp"
#include <nlohmann/json.hpp>

class RenderableComponent: public Component {
public:
    std::string assetId;
    int currentFrame{0};
};

void from_json(const nlohmann::json& j, RenderableComponent& r);

#endif /* RenderableComponent_hpp */
