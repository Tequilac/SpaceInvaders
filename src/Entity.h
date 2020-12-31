//
// Created by pteki on 2020-11-12.
//

#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H


#include "Object.h"
#include "MoveDirection.h"

class Entity : public Object
{
public:
    Entity(const sf::Vector2f& pos, const sf::Sprite& spr);

    void onUpdate(MoveDirection direction);
};


#endif //SPACEINVADERS_ENTITY_H
