//
// Created by pteki on 2020-11-12.
//

#include <SFML/Window/Keyboard.hpp>
#include "Player.h"


Player::Player(const sf::Vector2f &pos, const sf::Sprite &spr) : Object(pos, spr)
{
}

void Player::handleInput(std::vector<Laser>& lasers, const sf::Sprite& laserSprite, int& lastShot)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(-0.5f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(0.5f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && lastShot < 0)
    {
        lasers.emplace_back(Laser(sprite.getPosition(), laserSprite));
        lastShot = 60;
    }
}
