//
//  SoundComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef SoundComponent_hpp
#define SoundComponent_hpp

#include <queue>

#include "Component.hpp"
#include <nlohmann/json.hpp>

class SoundComponent: public Component {
public:
    std::queue<std::string> toPlay;
};

void from_json(const nlohmann::json& j, SoundComponent& a);

#endif /* SoundComponent_hpp */
