#include <SDL2/SDL.h>
#include <string>
#include <sstream>
#include <format>
#include <fstream>
#include <nlohmann/json.hpp>

#include "time/Timer.hpp"
#include "assets/AssetManager.hpp"
#include "ecs/systems/AudioSystem.hpp"
#include "ecs/systems/RenderSystem.hpp"
#include "ecs/systems/MovementSystem.hpp"
#include "ecs/systems/GravitySystem.hpp"
#include "ecs/systems/AnimationSystem.hpp"
#include "ecs/systems/CollisionSystem.hpp"
#include "ecs/systems/InputSystem.hpp"
#include "ecs/systems/SpriteSystem.hpp"
#include "ecs/systems/FrictionSystem.hpp"
#include "ecs/systems/IntelligenceSystem.hpp"
#include "ecs/systems/CameraSystem.hpp"
#include "ecs/EntityManager.hpp"
#include "ecs/SystemManager.hpp"

bool init() {
    bool success = true;
    
    if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
        printf( "Failed to initialise SDL. Error: %s\n", SDL_GetError() );
        success = false;
    }
    
    return success;
}

void load(std::string rootPath, AssetManager& assetManager, EntityManager& entityManager) {
    assetManager.loadAssets(std::format("{}/assets/assets.json", rootPath));
    entityManager.loadEntities(std::format("{}/assets/entities.json", rootPath));
}

void close(SystemManager& systemManager) {
    systemManager.free();
    SDL_Quit();
}

void registerSystems(SystemManager& systemManager) {
    systemManager.registerSystem<RenderSystem>();
    systemManager.registerSystem<InputSystem>();
    systemManager.registerSystem<IntelligenceSystem>();
    systemManager.registerSystem<CameraSystem>();
    systemManager.registerSystem<MovementSystem>();
    systemManager.registerSystem<GravitySystem>();
    systemManager.registerSystem<AnimationSystem>();
    systemManager.registerSystem<CollisionSystem>();
    systemManager.registerSystem<AudioSystem>();
    systemManager.registerSystem<FrictionSystem>();
    systemManager.registerSystem<SpriteSystem>();
}

int main() {
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        std::string basePath = std::format("{}..", SDL_GetBasePath());

        printf("SDL base path: %s\n", basePath.c_str());
        
        std::string path = std::format("{}/config/config.json", basePath);
        std::ifstream f(path);
        nlohmann::json data = nlohmann::json::parse(f);
        GameConfig gameConfig = data.get<GameConfig>();
        
        AssetManager assetManager(basePath);
        EntityManager entityManager;
        SystemManager systemManager(entityManager, assetManager, gameConfig);
        registerSystems(systemManager);        
        systemManager.init();
        
        load(basePath, assetManager, entityManager);
        bool quit = false;
        
        SDL_Event e;
        
        Timer frameDeltaTimer;
        
        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
                }
            }

            float deltaTime = frameDeltaTimer.getTicks() / 1000.f;
            frameDeltaTimer.start();
            
            systemManager.update(deltaTime);
        }
        
        close(systemManager);
    }
    
    return 0;
}
