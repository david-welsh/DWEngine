//
//  FrictionSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "FrictionSystem.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/FrictionComponent.hpp"
#include "../components/CollidableComponent.hpp"

void FrictionSystem::update(float deltaTime) { 
    for (auto& e: em.getEntitiesWithComponents<VelocityComponent, FrictionComponent>()) {
        auto& v = em.getComponent<VelocityComponent>(e);
        auto& f = em.getComponent<FrictionComponent>(e);

        bool grounded = em.hasComponent<CollidableComponent>(e) ? em.getComponent<CollidableComponent>(e).isGrounded : true;
        float mult = f.isMoving ? 0.1f : 1.0f;
        if ((v.vx > 0 && v.vx < 10.0f) || (v.vx < 0 && v.vx > -10.0f)) v.vx = 0;
        if (v.vx > 0) {
            v.vx -= (grounded ? f.friction : f.airFriction) * deltaTime * mult;
        } else if (v.vx < 0) {
            v.vx += (grounded ? f.friction : f.airFriction) * deltaTime * mult;
        }
    }
}
