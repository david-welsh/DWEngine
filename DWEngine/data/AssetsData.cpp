//
//  AssetsData.cpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#include "AssetsData.hpp"

void from_json(const nlohmann::json& j, AssetsData& a) {
    j.at("sprites").get_to(a.sprites);
    j.at("music").get_to(a.music);
    j.at("sounds").get_to(a.sounds);
    j.at("scripts").get_to(a.scripts);
}
