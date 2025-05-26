//
//  MusicComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef MusicComponent_hpp
#define MusicComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class MusicComponent: public Component {
public:
    std::string music;
    bool playing{false};
};

void from_json(const nlohmann::json& j, MusicComponent& a);

#endif /* MusicComponent_hpp */
