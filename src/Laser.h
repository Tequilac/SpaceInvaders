//
// Created by pteki on 2020-11-12.
//

#ifndef SPACEINVADERS_LASER_H
#define SPACEINVADERS_LASER_H


#include <SFML/Graphics/Image.hpp>
#include <optional>
#include "Object.h"
#include "Entity.h"

class Laser : public Object
{
public:
    Laser(const sf::Vector2f &pos, const sf::Sprite &spr);

    void onUpdate();

    int collides(const std::vector<Entity>& entities);
private:
};


#endif //SPACEINVADERS_LASER_H
