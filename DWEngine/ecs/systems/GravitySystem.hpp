//
//  GravitySystem.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef GravitySystem_hpp
#define GravitySystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

class GravitySystem: public EntitySystem {
public:
    GravitySystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* GravitySystem_hpp */
