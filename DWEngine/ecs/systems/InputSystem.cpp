//
//  InputSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include <cmath>

#include "InputSystem.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/CollidableComponent.hpp"
#include "../components/FrictionComponent.hpp"
#include "../components/InputComponent.hpp"
#include "../components/AccelerationComponent.hpp"
#include "../components/SoundComponent.hpp"
#include "SDL2/SDL.h"

void InputSystem::update(float deltaTime) { 
    for (auto& entity: em.getEntitiesWithComponents<InputComponent>()) {
        auto& i = em.getComponent<InputComponent>(entity);
        const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
        auto& a = em.hasComponent<AccelerationComponent>(entity) ? em.getComponent<AccelerationComponent>(entity).a : DEFAULT_ACCEL;

        if (currentKeyStates[SDL_SCANCODE_LEFT]) {
            if (em.hasComponent<VelocityComponent>(entity)) {
                auto& vel = em.getComponent<VelocityComponent>(entity);
                vel.vx = (a * -vel.maxV + (1 - a) * vel.vx);
                if (std::fabs(vel.vx) < THRESHOLD) vel.vx = 0.0f;
            }
            if (em.hasComponent<FrictionComponent>(entity)) {
                em.getComponent<FrictionComponent>(entity).isMoving = true;
            }
        } else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
            if (em.hasComponent<VelocityComponent>(entity)) {
                auto& vel = em.getComponent<VelocityComponent>(entity);
                vel.vx = a * vel.maxV + (1 - a) * vel.vx;
                if (std::fabs(vel.vx) < THRESHOLD) vel.vx = 0.0f;
            }
            if (em.hasComponent<FrictionComponent>(entity)) {
                em.getComponent<FrictionComponent>(entity).isMoving = true;
            }
        } else {
            if (em.hasComponent<FrictionComponent>(entity)) {
                em.getComponent<FrictionComponent>(entity).isMoving = false;
            }
        }
        
        if (currentKeyStates[SDL_SCANCODE_SPACE]) {
            if (em.hasComponent<VelocityComponent>(entity) && em.hasComponent<CollidableComponent>(entity)) {
                auto& c = em.getComponent<CollidableComponent>(entity);
                if (c.isGrounded) {
                    em.getComponent<VelocityComponent>(entity).vy -= i.jumpPower;
                    if (em.hasComponent<SoundComponent>(entity)) {
                        em.getComponent<SoundComponent>(entity).toPlay.push("jump");
                    }
                }
            }
        }
    }
}
