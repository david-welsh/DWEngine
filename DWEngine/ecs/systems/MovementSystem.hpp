//
//  MovementSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef MovementSystem_hpp
#define MovementSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

class MovementSystem: public EntitySystem {
public:
    MovementSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* MovementSystem_hpp */
