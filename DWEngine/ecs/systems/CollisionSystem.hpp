//
//  CollisionSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef CollisionSystem_hpp
#define CollisionSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/CollidableComponent.hpp"

class CollisionSystem: public EntitySystem {
    bool isColliding(PositionComponent& posA, 
                     CollidableComponent& colA,
                     PositionComponent& posB,
                     CollidableComponent& colB);
    
    void resolveCollision(int entityA,
                          PositionComponent &posA,
                          CollidableComponent &colA,
                          int entityB,
                          PositionComponent &posB,
                          CollidableComponent &colB);
public:
    CollisionSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* CollisionSystem_hpp */
