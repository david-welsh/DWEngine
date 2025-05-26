//
//  Entity.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <string>

class EntityManager;

class Entity {
    int id;
    EntityManager& em;
public:
    Entity(int id, EntityManager& em): id(id), em(em) {}
    
    template <typename T>
    T& getComponent();
    
    int getId() const { return id; }
};

#include "EntityManager.hpp"

template <typename T>
T& Entity::getComponent() {
    return em.getComponent<T>(id);
}

#endif /* Entity_hpp */
