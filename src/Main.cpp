#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Laser.h"
#include "Player.h"

int main()
{
    sf::Texture playerTexture;
    playerTexture.loadFromFile("res/enemy.png");
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    Player player(sf::Vector2f(200.0f, 500.0f), playerSprite);




    std::vector<Entity> entities;
    entities.reserve(60);
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("res/enemy.png");
    sf::Sprite enemySprite;
    enemySprite.setTexture(enemyTexture);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 12; ++j)
            entities.emplace_back(Entity(sf::Vector2f(40*j, 30 + 40*i), enemySprite));
    //330

    std::vector<Laser> lasers;
    sf::Texture laserTexture;
    laserTexture.loadFromFile("res/enemy.png");
    sf::Sprite laserSprite;
    laserSprite.setTexture(laserTexture);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    MoveDirection currentDirection = MoveDirection::Right;

    sf::Clock clock;
    float timeStep;
    float lastFrameTime = 0.0f;
    int count = 0;
    int lastShot = 60;

    clock.restart();
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.handleInput(lasers, laserSprite, lastShot);

        for(auto& entity : entities)
            entity.onUpdate(currentDirection);

        for(auto& laser : lasers)
            laser.onUpdate();


        auto i = std::begin(lasers);

        while (i != std::end(lasers))
        {
            int collided = i->collides(entities);
            if (collided != -1)
            {
                if(collided != -2)
                    entities.erase(entities.begin() + collided);
                i = lasers.erase(i);
            }
            else
                ++i;
        }


        window.clear();

        window.draw(player.getSprite());

        for(auto& entity : entities)
            window.draw(entity.getSprite());

        for(auto& laser : lasers)
            window.draw(laser.getSprite());



        window.display();

        float time = clock.getElapsedTime().asSeconds();
        timeStep = time - lastFrameTime;
        lastFrameTime = time;
        std::cout << timeStep << "\n";

        if (timeStep < 1.0f / 60.0f)
            sf::sleep(sf::seconds(1.0f / 60.0f - timeStep ));

        count++;
        if(count == 1650)
        {
            count = 0;
            currentDirection = ((currentDirection == MoveDirection::Right)? MoveDirection::Left : MoveDirection::Right);
        }
        lastShot--;
    }

    return 0;
}