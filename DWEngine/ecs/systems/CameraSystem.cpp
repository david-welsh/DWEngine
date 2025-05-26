//
//  CameraSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 23/06/2024.
//

#include <cmath>

#include "CameraSystem.hpp"
#include "../components/CameraComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/PositionComponent.hpp"

void CameraSystem::update(float deltaTime) {
    auto p = em.getEntitiesWithTag("player")[0];
    auto c = em.getEntitiesWithComponents<CameraComponent, PositionComponent, VelocityComponent>()[0];
    
    auto& cameraPos = em.getComponent<PositionComponent>(c);
    auto& playerPos = em.getComponent<PositionComponent>(p);
    
    auto& camera = em.getComponent<CameraComponent>(c);
    
    auto& cameraVel = em.getComponent<VelocityComponent>(c);
    auto& playerVel = em.getComponent<VelocityComponent>(p);
    
    float xDiff = playerPos.x - cameraPos.x;
    
    float cameraThird = (1 / 3.0) * camera.width;
    
    if (xDiff > 2 * cameraThird) {
        cameraVel.vx = std::fabs(playerVel.vx);
    } else if (xDiff < cameraThird) {
        cameraVel.vx = -std::fabs(playerVel.vx);
    } else {
        cameraVel.vx = 0.0;
    }
    
    float yDiff = playerPos.y - cameraPos.y;
    
    float cameraHeight = (1 / 4.0) * camera.height;
    
    if (yDiff > cameraHeight) {
        cameraVel.vy = std::fabs(playerVel.vy);
    } else if (cameraPos.y < 1) {
        cameraPos.y = 0;
        cameraVel.vy = 0;
    } else if (yDiff < cameraHeight) {
        cameraVel.vy = -std::fabs(playerVel.vy);
    } else {
        cameraVel.vy = 0.0;
    }
}
