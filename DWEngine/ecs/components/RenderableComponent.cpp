//
//  RenderableComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "RenderableComponent.hpp"

void from_json(const nlohmann::json& j, RenderableComponent& r) {
    j.at("assetId").get_to(r.assetId);
}
