//
// Created by pteki on 2020-11-12.
//

#include "Laser.h"


Laser::Laser(const sf::Vector2f &pos, const sf::Sprite &spr) : Object(pos, spr)
{
}

void Laser::onUpdate()
{
    sprite.move(sf::Vector2f(0.0f, -0.6f));
}

int Laser::collides(const std::vector<Entity>& entities)
{
    for (int i = 0; i < entities.size(); ++i)
    {
        sf::Vector2f entityPosition = entities[i].getPosition();
        if(entityPosition.x < this->getPosition().x && entityPosition.x + 30 > this->getPosition().x
        && entityPosition.y + 20 > this->getPosition().y)
            return i;
    }
    if(this->getPosition().y <= 0.0f)
        return -2;
    return -1;
}
