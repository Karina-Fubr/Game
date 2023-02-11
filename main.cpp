#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <random>
#include "snake.hpp"
 
int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Zmeika");
	sf::Vector2f fruit(7, 7);
	Snake snake = Snake();

	int dx = 1, dy = 0;
	int time = std::clock();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				dx = -1; dy = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				dx = 1; dy = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				dx = 0; dy = -1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				dx = 0; dy = 1;
			}
        }
        window.clear(sf::Color(100, 200, 100));
		if (std::clock() > time + 300) {
			snake.move(dx, dy, fruit);
			time = std::clock();
		}
		snake.draw(window);
		sf::RectangleShape fruit_shape(sf::Vector2f(50, 50));
		fruit_shape.setFillColor(sf::Color(200, 100, 0));
		fruit_shape.setPosition(fruit.x * 50, fruit.y * 50);
		window.draw(fruit_shape);
        window.display();
    }

}