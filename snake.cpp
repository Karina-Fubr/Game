#pragma once


#include "snake.hpp"

Snake::Snake() {
	x = 4; y = 4;
	for (int i = 0; i < 3; i++) {
		tail.push_back(sf::Vector2(x, y + i + 1));
	}
}

void Snake::move(int dx, int dy, sf::Vector2f& fruit) {
	int sx = tail[tail.size() - 1].x;
	int sy = tail[tail.size() - 1].y;

	for (int i = tail.size() - 1; i >= 1; i--) {
		tail[i] = tail[i - 1];
	}
	tail[0].x = x; tail[0].y = y;
	x = x + dx;
	y = y + dy;
	if (x < 0) {
		x = 12;
	}
	else if (x > 12) {
		x = 0;
	} if (y < 0) {
		y = 12;
	}
	else if (y > 12) {
		y = 0;
	}

	for (int i = 0; i < tail.size(); i++) {
		if ((x == tail[i].x) && (y == tail[i].y)) {
			x = 4; y = 4;
			tail.clear();
			for (int i = 0; i < 3; i++) {
				tail.push_back(sf::Vector2(x, y + i + 1));
			}
			break;
		}
	}

	if ((x == fruit.x) && (y == fruit.y)) {
		fruit.x = 2 + std::rand() % 10;
		fruit.y = 2 + std::rand() % 10;

		sf::Vector2 new_cell(sx, sy);
		tail.push_back(new_cell);
	}
}

void Snake::draw(sf::RenderWindow& window) {
	sf::RectangleShape head(sf::Vector2f(size, size));
	head.setPosition(x * size, y * size);
	head.setFillColor(sf::Color(0, 128, 128));
	window.draw(head);

	for (int i = 0; i < tail.size(); i++) {
		sf::RectangleShape tail_cell(sf::Vector2f(size, size));
		tail_cell.setFillColor(sf::Color(0, 100, 100));
		tail_cell.setPosition(tail[i].x * size, tail[i].y * size);
		window.draw(tail_cell);
	}
}