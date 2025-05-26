//
//  RenderSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include "SDL2/SDL.h"
#include <SDL_ttf.h>
#include <memory>

#include "../EntityManager.hpp"
#include "EntitySystem.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/CameraComponent.hpp"
#include "../../assets/AssetManager.hpp"
#include "../../GameConfig.hpp"
#include "../../gfx/SpriteSheet.hpp"

class RenderSystem: public EntitySystem {
    SDL_Renderer* renderer;
    SDL_Window* window;
    
    std::map<std::string, TTF_Font *> fonts;
    std::map<std::string, std::shared_ptr<SpriteSheet>> spriteCache;
    
    std::shared_ptr<SpriteSheet> getOrCreate(std::string id);
    
    std::pair<int, int> toScreenSpace(PositionComponent& cameraPos, CameraComponent& camera, float x, float y, int w, int h);
public:
    RenderSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    ~RenderSystem();
    
    void free() override;
    
    bool init() override;
    
    void loadRenderable(Asset* asset);
    
    void clear();
    void update(float deltaTime) override;
    void present();
};

#endif /* RenderSystem_hpp */
