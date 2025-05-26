//
//  AudioSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "AudioSystem.hpp"

#include "../components/MusicComponent.hpp"
#include "../components/SoundComponent.hpp"

void AudioSystem::update(float deltaTime) { 
    for (auto& entity: em.getEntitiesWithComponents<MusicComponent>()) {
        auto& m = em.getComponent<MusicComponent>(entity);
        
        if (!m.playing) {
            if (!music.contains(m.music)) {
                auto& a = am.getAsset<MusicAsset>(m.music);
                load(a);
            }
            playMusic(m.music);
            m.playing = true;
        }
    }
    
    for (auto& entity: em.getEntitiesWithComponents<SoundComponent>()) {
        auto& s = em.getComponent<SoundComponent>(entity);
        
        for (; !s.toPlay.empty(); s.toPlay.pop()) {
            auto t = s.toPlay.front();
            if (!sfx.contains(t)) {
                auto& sa = am.getAsset<SoundAsset>(t);
                load(sa);
            }
            playSfx(t);
        }
    }
}

bool AudioSystem::load(SoundAsset& asset) {
    std::string id = asset.getId();
    if (sfx.contains(id)) {
        printf("Tried to load asset already loaded: %s\n", id.c_str());
        return false;
    }
    Mix_Chunk* chunk = Mix_LoadWAV(asset.getPath().c_str());
    if (chunk == nullptr) {
        printf("Failed to load sfx at path %s\n", asset.getPath().c_str());
        return false;
    }
    
    sfx.insert({id, chunk});
    return true;
}

bool AudioSystem::load(MusicAsset& asset) {
    std::string id = asset.getId();
    if (music.contains(id)) {
        printf("Tried to load asset already loaded: %s\n", id.c_str());
        return false;
    }
    Mix_Music* newMusic = Mix_LoadMUS(asset.getPath().c_str());
    if (newMusic == nullptr) {
        printf("Failed to load music at path %s\n", asset.getPath().c_str());
        return false;
    }
    
    music.insert({id, newMusic});
    return true;
}

void AudioSystem::free() {
    for (auto const& x : music) {
        Mix_FreeMusic(x.second);
    }
    for (auto const& x : sfx) {
        Mix_FreeChunk(x.second);
    }
    Mix_Quit();
}

void AudioSystem::playMusic(std::string id) {
    auto const& pos = music.find(id);
    if (pos == music.end()) {
        printf("No matching music for ID %s\n", id.c_str());
    } else {
        Mix_Music* m = pos->second;
        if (Mix_PlayingMusic() != 0) {
            stopMusic();
        }
        Mix_PlayMusic(m, -1);
    }
}

void AudioSystem::stopMusic() {
    Mix_HaltMusic();
}

void AudioSystem::playSfx(std::string id) {
    auto const& pos = sfx.find(id);
    if (pos == sfx.end()) {
        printf("No matching sfx for ID %s\n", id.c_str());
    } else {
        Mix_Chunk* c = pos->second;
        Mix_PlayChannel(-1, c, 0);
    };
}


int calculateVolume(float vol) {
    int volume = vol * MIX_MAX_VOLUME;
    if (volume > MIX_MAX_VOLUME) volume = MIX_MAX_VOLUME;
    if (volume < 0) volume = 0;
    return volume;
}

void AudioSystem::updateConfig(GameConfig gameConfig) {
    Mix_MasterVolume(calculateVolume(gameConfig.masterVolume));
    Mix_VolumeMusic(calculateVolume(gameConfig.musicVolume));
    Mix_Volume(-1, calculateVolume(gameConfig.sfxVolume));
}

AudioSystem::AudioSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer error: %s\n", Mix_GetError());
    }
    updateConfig(config);
}
