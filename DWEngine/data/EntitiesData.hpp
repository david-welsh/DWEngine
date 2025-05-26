//
//  EntitiesData.hpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#ifndef EntitiesData_hpp
#define EntitiesData_hpp

#include <vector>
#include <nlohmann/json.hpp>
#include "EntityData.hpp"
#include "AssetData.hpp"

struct EntitiesData {
    std::vector<EntityData> entities;
};

void from_json(const nlohmann::json& j, EntitiesData& e);

#endif /* EntitiesData_hpp */
