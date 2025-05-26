//
//  EntitiesData.cpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#include "EntitiesData.hpp"

void from_json(const nlohmann::json& j, EntitiesData& e) {
    j.at("entities").get_to(e.entities);
}
