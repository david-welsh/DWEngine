//
//  SpriteSheetAssetData.cpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#include "SpriteSheetAssetData.hpp"

void from_json(const nlohmann::json& j, Animation& a) {
    j.at("id").get_to(a.id);
    j.at("from").get_to(a.from);
    j.at("to").get_to(a.to);
}

void from_json(const nlohmann::json& j, SpriteSheetAssetData& a) {
    j.at("rows").get_to(a.rows);
    j.at("columns").get_to(a.columns);
    j.at("animations").get_to(a.animations);
}
