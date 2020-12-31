//
// Created by pteki on 2020-11-12.
//

#ifndef SPACEINVADERS_PLAYER_H
#define SPACEINVADERS_PLAYER_H


#include <SFML/Graphics/Sprite.hpp>
#include "Object.h"
#include "Laser.h"

class Player : public Object
{
public:
    Player(const sf::Vector2f &pos, const sf::Sprite& spr);

    void handleInput(std::vector<Laser>& lasers, const sf::Sprite& laserSprite, int& lastShot);

};


#endif //SPACEINVADERS_PLAYER_H
