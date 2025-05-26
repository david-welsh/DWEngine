//
//  AssetData.cpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#include "AssetData.hpp"

void from_json(const nlohmann::json& j, AssetData& a) {
    j.at("id").get_to(a.id);
    j.at("type").get_to(a.type);
    j.at("path").get_to(a.path);
    j.at("data").get_to(a.data);
}
