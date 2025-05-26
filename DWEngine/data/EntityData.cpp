//
//  EntityData.cpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#include "EntityData.hpp"

void from_json(const nlohmann::json& j, EntityData& e) {
    j.at("id").get_to(e.id);
    j.at("type").get_to(e.type);
    j.at("tags").get_to(e.tags);
    j.at("components").get_to(e.components);
}
