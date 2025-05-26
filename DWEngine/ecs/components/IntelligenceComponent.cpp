//
//  IntelligenceComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#include "IntelligenceComponent.hpp"

void from_json(const nlohmann::json& j, IntelligenceComponent& p) {
    j.at("scriptAsset").get_to(p.scriptAsset);
}
