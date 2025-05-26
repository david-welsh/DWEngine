//
//  SpriteSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "SpriteSystem.hpp"

#include "../components/SpriteComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/AnimationComponent.hpp"

void SpriteSystem::update(float deltaTime) { 
    for (auto& e: em.getEntitiesWithComponents<SpriteComponent, VelocityComponent, AnimationComponent>()) {
        auto& s = em.getComponent<SpriteComponent>(e);
        auto& v = em.getComponent<VelocityComponent>(e);
        auto& a = em.getComponent<AnimationComponent>(e);
        auto before = a.currentAnimation;
        if (v.vx < -10) {
            a.currentAnimation = s.left;
        } else if (v.vx > 10) {
            a.currentAnimation = s.right;
        } else {
            a.currentAnimation = s.idle;
        }
        a.reset = a.reset || before != a.currentAnimation;
    }
}
