//
//  CollisionSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#include "CollisionSystem.hpp"

#include "../components/VelocityComponent.hpp"
#include "../components/GravityComponent.hpp"


bool CollisionSystem::isColliding(PositionComponent &posA, CollidableComponent &colA, PositionComponent &posB, CollidableComponent &colB) {
    return posA.x < posB.x + colB.width &&
       posA.x + colA.width > posB.x &&
       posA.y < posB.y + colB.height &&
       posA.y + colA.height > posB.y;
}

void CollisionSystem::resolveCollision(int entityA,
                                       PositionComponent &posA,
                                       CollidableComponent &colA,
                                       int entityB,
                                       PositionComponent &posB,
                                       CollidableComponent &colB) {
    if (!colA.isSolid && !colB.isSolid) return;
    float overlapX = std::min(posA.x + colA.width, posB.x + colB.width) - std::max(posA.x, posB.x);
    float overlapY = std::min(posA.y + colA.height, posB.y + colB.height) - std::max(posA.y, posB.y);
    
    if (overlapX < overlapY) {
        if (posA.x < posB.x) {
            if (colA.isMovable) {
                posA.x -= overlapX;
            } else if (colB.isMovable) {
                posB.x += overlapX;
            }
        } else {
            if (colA.isMovable) {
                posA.x += overlapX;
            } else if (colB.isMovable) {
                posB.x -= overlapX;
            }
        }
    } else {
        if (posA.y < posB.y) {
            if (colA.isMovable) {
                posA.y -= overlapY;
                if (em.hasComponent<VelocityComponent>(entityA)) {
                    auto& velA = em.getComponent<VelocityComponent>(entityA);
                    velA.vy = 0;
                }
                if (!colB.isMovable) colA.isGrounded = true;
            } else if (colB.isMovable) {
                posB.y += overlapY;
                if (em.hasComponent<VelocityComponent>(entityB)) {
                    auto& velB = em.getComponent<VelocityComponent>(entityB);
                    velB.vy = 0;
                }
                if (!colA.isMovable) colB.isGrounded = true;
            }
        } else {
            if (colA.isMovable) {
                posA.y += overlapY;
                if (em.hasComponent<VelocityComponent>(entityA)) {
                    auto& velA = em.getComponent<VelocityComponent>(entityA);
                    velA.vy = 0;
                }
            } else if (colB.isMovable) {
                posB.y -= overlapY;
                if (em.hasComponent<VelocityComponent>(entityB)) {
                    auto& velB = em.getComponent<VelocityComponent>(entityB);
                    velB.vy = 0;
                }
            }
        }
    };
}

void CollisionSystem::update(float deltaTime) { 
    auto entities = em.getEntitiesWithComponents<PositionComponent, CollidableComponent>();
    
    for (int i = 0; i < entities.size(); i++) {
        for (int j = i + 1; j < entities.size(); j++) {
            auto& posA = em.getComponent<PositionComponent>(entities[i]);
            auto& colA = em.getComponent<CollidableComponent>(entities[i]);
            auto& posB = em.getComponent<PositionComponent>(entities[j]);
            auto& colB = em.getComponent<CollidableComponent>(entities[j]);

            if (isColliding(posA, colA, posB, colB)) {
                resolveCollision(entities[i], posA, colA, entities[j], posB, colB);
            }
        }
    }
}
