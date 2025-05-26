//
//  AudioSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef AudioSystem_hpp
#define AudioSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"
#include "../../assets/AssetManager.hpp"
#include "../../assets/types/MusicAsset.hpp"
#include "../../assets/types/SoundAsset.hpp"
#include "../../GameConfig.hpp"

#include "SDL_mixer.h"

class AudioSystem: public EntitySystem {
    std::map<std::string, Mix_Music*> music;
    std::map<std::string, Mix_Chunk*> sfx;
public:
    AudioSystem(EntityManager& em, AssetManager& am, GameConfig& config);
    
    void update(float deltaTime) override;
    
    bool load(SoundAsset& asset);
    
    bool load(MusicAsset& asset);
    
    void playMusic(std::string id);
    
    void playSfx(std::string id);
    
    void stopMusic();
    
    void free() override;

    void updateConfig(GameConfig gameConfig);
};

#endif /* AudioSystem_hpp */
