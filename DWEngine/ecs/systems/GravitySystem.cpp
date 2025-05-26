//
//  GravitySystem.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "GravitySystem.hpp"

#include "../components/VelocityComponent.hpp"
#include "../components/GravityComponent.hpp"
#include "../components/CollidableComponent.hpp"

void GravitySystem::update(float deltaTime) {
    for (auto& entity: em.getEntitiesWithComponents<VelocityComponent, GravityComponent>()) {
        auto& g = em.getComponent<GravityComponent>(entity);
        auto& vel = em.getComponent<VelocityComponent>(entity);

        bool isGrounded = em.hasComponent<CollidableComponent>(entity) ? em.getComponent<CollidableComponent>(entity).isGrounded : false;
        
        if (isGrounded) {
            vel.vy = 0;
        } else {
            vel.vy = vel.vy - (g.gForce * deltaTime);
        }
    }
}
