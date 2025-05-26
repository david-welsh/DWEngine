//
//  RenderSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#include "RenderSystem.hpp"
#include "../components/RenderableComponent.hpp"
#include "../../assets/types/SpriteSheetAsset.hpp"
#include <SDL_image.h>

void RenderSystem::update(float deltaTime) {
    clear();
    auto c = em.getEntitiesWithComponents<CameraComponent, PositionComponent>()[0];
    auto& cameraPos = em.getComponent<PositionComponent>(c);
    auto& camera = em.getComponent<CameraComponent>(c);
    for (auto& entity : em.getEntitiesWithComponents<RenderableComponent, PositionComponent>()) {
        auto& renderable = em.getComponent<RenderableComponent>(entity);
        auto& position = em.getComponent<PositionComponent>(entity);

        auto sprite = getOrCreate(renderable.assetId);
        sprite->setCurrent(renderable.currentFrame);
        auto p = toScreenSpace(cameraPos, camera, position.x, position.y, sprite->getWidth(), sprite->getHeight());
        sprite->render(renderer, p.first, p.second, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
    }
    present();
}

std::pair<int, int> RenderSystem::toScreenSpace(PositionComponent& cameraPos, CameraComponent& camera, float x, float y, int w, int h) {
    std::pair<int,int> result{x, y};
    float cameraX = x - cameraPos.x;
    float cameraY = y - cameraPos.y;
    
    result.first = static_cast<int>((cameraX / camera.width) * config.screenRes.width);
    result.second = config.screenRes.height - static_cast<int>((cameraY / camera.height) * config.screenRes.height) - h;
        
    return result;
}


// c at 0, 0
// 50, 50
// == 50, 670

// c at 20, 20
// 50, 50
// == 30, 690

std::shared_ptr<SpriteSheet> RenderSystem::getOrCreate(std::string id) {
    if (!spriteCache.contains(id)) {
        loadRenderable(&am.getAsset<SpriteSheetAsset>(id));
    }
    auto it = spriteCache.find(id);
    if (it != spriteCache.end()) {
        return it->second;
    }
    return nullptr;
}

RenderSystem::~RenderSystem() {
}

void RenderSystem::free() { 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;
    
    IMG_Quit();
    TTF_Quit();
}

bool RenderSystem::init() {
    bool success = true;
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }
    
    window = SDL_CreateWindow(config.gameTitle.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              config.screenRes.width,
                              config.screenRes.height,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! %s\n", SDL_GetError());
        success = false;
    } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            
            int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
            
            if (TTF_Init() == -1) {
                printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                success = false;
            } else {
//                for (auto & fa: fontsToLoad) {
//                    fonts.insert({ fa->getPath(), TTF_OpenFont(fa->getPath().c_str(), 28) });
//                }
            }
        }
    }
    return success;
}

void RenderSystem::loadRenderable(Asset *asset) {
    if (asset->getAssetType() == ASSET_SPRITE_SHEET) {
        SpriteSheetAsset* t = (SpriteSheetAsset*) asset;
        auto spr = std::make_shared<SpriteSheet>();
        if (spr->loadFromFile(renderer, t->getPath(), t->getRows(), t->getColumns())) {
            spr->setCurrent(0);
            spriteCache.emplace(t->getId(), spr);
        }
    }
}

void RenderSystem::clear() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void RenderSystem::present() {
    SDL_RenderPresent(renderer);
}

