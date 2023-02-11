#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {

public:
	int x, y;
	int size = 50;
	std::vector<sf::Vector2<int>> tail;

	Snake();

	void move(int dx, int dy, sf::Vector2f& fruit);

	void draw(sf::RenderWindow& window);
};