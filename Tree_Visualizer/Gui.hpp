#pragma once
#include <SFML/Graphics.hpp>
#include "BinaryTree.hpp"
#include <iostream>
#include <stack>
#include <list>

class Gui
{
private:
	int totalNodes = 0;
	int height = 0;
	int maxGap = 0;
	Node* parent = nullptr;
	sf::Vector2f parentPos = sf::Vector2f(0, 0);
	sf::Vector2f rootPos = sf::Vector2f(400, 50);

	std::list<sf::CircleShape> nodes;
	std::list<sf::RectangleShape> edges;

public:
	Gui();
	
	void createVisualization(BinaryTree& tree);
	void generateStructure(Node* root, sf::Vector2f parentPos, sf::Vector2f pos, int height, int gap);
	void renderTree(sf::RenderWindow& window);
};

