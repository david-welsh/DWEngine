//
//  SystemManager.cpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#include "SystemManager.hpp"

bool SystemManager::init()  {
    bool success = true;
    for (auto& s: systems) {
        success = success && s->init();
    }
    return success;
}

void SystemManager::update(float deltaTime) {
    for (auto& s: systems) {
        s->update(deltaTime);
    }
}


void SystemManager::free() {
    for (auto& s: systems) {
        s->free();
    }
}
