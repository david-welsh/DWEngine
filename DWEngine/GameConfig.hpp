//
//  GameConfig.hpp
//  SDLSprites4
//
//  Created by David Welsh on 10/06/2024.
//

#ifndef GameConfig_hpp
#define GameConfig_hpp

#include <string>
#include <nlohmann/json.hpp>

struct Resolution {
    int width;
    int height;
};

struct GameConfig {
    float masterVolume;
    float musicVolume;
    float sfxVolume;
    
    Resolution screenRes;
    int fpsCap;
    
    std::string gameTitle;
};

void from_json(const nlohmann::json& j, Resolution& r);
void from_json(const nlohmann::json& j, GameConfig& g);

#endif /* GameConfig_hpp */
