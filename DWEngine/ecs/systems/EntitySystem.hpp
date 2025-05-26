//
//  EntitySystem.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef EntitySystem_hpp
#define EntitySystem_hpp

#include "../EntityManager.hpp"
#include "../../assets/AssetManager.hpp"
#include "../../GameConfig.hpp"

class EntitySystem {
protected:
    EntityManager& em;
    AssetManager& am;
    GameConfig& config;
public:
    EntitySystem(EntityManager& em, AssetManager& am, GameConfig& config): em(em), am(am), config(config) {}
    
    virtual ~EntitySystem() = default;
    
    virtual void update(float deltaTime) = 0;
    
    virtual void free() {}
    
    virtual bool init() { return true; }
};

#endif /* EntitySystem_hpp */
