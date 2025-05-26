//
//  AnimationSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#include "AnimationSystem.hpp"

#include "../components/RenderableComponent.hpp"
#include "../components/AnimationComponent.hpp"
#include "../../assets/types/SpriteSheetAsset.hpp"

void AnimationSystem::update(float deltaTime) {
    for (auto& entity: em.getEntitiesWithComponents<RenderableComponent, AnimationComponent>()) {
        auto& r = em.getComponent<RenderableComponent>(entity);
        auto& a = em.getComponent<AnimationComponent>(entity);
        
        a.timeSinceLastFrame += deltaTime;
        
        if (a.timeSinceLastFrame > FRAME_TIME) {
            auto& s = am.getAsset<SpriteSheetAsset>(r.assetId);
            auto anim = s.getAnimation(a.currentAnimation);
            
            if (a.reset) {
                r.currentFrame = anim.first;
                a.reset = false;
            } else {
                r.currentFrame++;
                if (r.currentFrame > anim.second) r.currentFrame = anim.first;
            }
            a.timeSinceLastFrame -= FRAME_TIME;
        }
    }
}
