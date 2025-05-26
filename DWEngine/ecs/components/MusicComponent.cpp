//
//  MusicComponent.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "MusicComponent.hpp"

void from_json(const nlohmann::json& j, MusicComponent& a) {
    j.at("music").get_to(a.music);
}
