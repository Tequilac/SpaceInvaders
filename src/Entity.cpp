//
// Created by pteki on 2020-11-12.
//

#include "Entity.h"


Entity::Entity(const sf::Vector2f &pos, const sf::Sprite &spr) : Object(pos, spr)
{
}

void Entity::onUpdate(MoveDirection direction)
{
    if(direction == MoveDirection::Left)
        sprite.move(sf::Vector2f(-0.2f, 0.0f));
    if(direction == MoveDirection::Right)
        sprite.move(sf::Vector2f(0.2f, 0.0f));
}