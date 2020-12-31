//
// Created by pteki on 2020-11-12.
//

#ifndef SPACEINVADERS_OBJECT_H
#define SPACEINVADERS_OBJECT_H


#include <SFML/System.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Object
{
public:
    explicit Object(const sf::Vector2f& pos, const sf::Sprite& spr);

    const sf::Vector2f& getPosition() const;

    const sf::Sprite& getSprite();

protected:
    sf::Sprite sprite;
};


#endif //SPACEINVADERS_OBJECT_H
