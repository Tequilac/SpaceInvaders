//
// Created by pteki on 2020-11-12.
//

#include "Object.h"

Object::Object(const sf::Vector2f &pos, const sf::Sprite& spr) : sprite(spr)
{
    sprite.setPosition(pos);
}

const sf::Vector2f& Object::getPosition() const
{
    return sprite.getPosition();
}

const sf::Sprite& Object::getSprite()
{
    return sprite;
}


