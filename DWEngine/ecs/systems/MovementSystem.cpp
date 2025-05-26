//
//  MovementSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#include "MovementSystem.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/CollidableComponent.hpp"
#include "../components/VelocityComponent.hpp"

void MovementSystem::update(float deltaTime) {
    for (auto& entity: em.getEntitiesWithComponents<VelocityComponent, PositionComponent>()) {
        auto& pos = em.getComponent<PositionComponent>(entity);
        auto& vel = em.getComponent<VelocityComponent>(entity);
        
        pos.x += vel.vx * deltaTime;
        pos.y += vel.vy * deltaTime;
        
        if (vel.vy != 0.0f) {
            if (em.hasComponent<CollidableComponent>(entity)) {
                em.getComponent<CollidableComponent>(entity).isGrounded = false;
            }
        }
    }
}
