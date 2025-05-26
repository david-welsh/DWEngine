//
//  GameConfig.cpp
//  CDEngine
//
//  Created by David Welsh on 23/06/2024.
//

#include "GameConfig.hpp"

void from_json(const nlohmann::json& j, Resolution& r) {
    j.at("width").get_to(r.width);
    j.at("height").get_to(r.height);
}
void from_json(const nlohmann::json& j, GameConfig& g) {
    j.at("masterVolume").get_to(g.masterVolume);
    j.at("musicVolume").get_to(g.musicVolume);
    j.at("sfxVolume").get_to(g.sfxVolume);
    j.at("screenRes").get_to(g.screenRes);
    j.at("fpsCap").get_to(g.fpsCap);
    j.at("gameTitle").get_to(g.gameTitle);
}
