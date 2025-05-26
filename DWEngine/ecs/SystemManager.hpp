//
//  SystemManager.hpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#ifndef SystemManager_hpp
#define SystemManager_hpp

#include <vector>
#include <memory>

#include "systems/EntitySystem.hpp"
#include "../assets/AssetManager.hpp"
#include "../GameConfig.hpp"

class SystemManager {
    std::vector<std::unique_ptr<EntitySystem>> systems;
    
    EntityManager& em;
    AssetManager& am;
    GameConfig& config;
    
public:
    SystemManager(EntityManager& em, AssetManager& am, GameConfig& config): em(em), am(am), config(config) {}
    
    template <typename T>
    void registerSystem();
    
    bool init();
    
    void update(float deltaTime);
    
    void free();
};

template <typename T>
void SystemManager::registerSystem() {
    auto system = std::make_unique<T>(em, am, config);
    systems.push_back(std::move(system));
}

#endif /* SystemManager_hpp */
