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
	sf::Vector2f rootPos = sf::Vector2f(0, 0);

	float nodeSize = 18.f;
	float edgeWidth = 5.f;
	sf::Color nodeColor = sf::Color::Red;
	sf::Font nodeValuefont;
	uint16_t nodeValueFontSize = 20;
	std::list<sf::CircleShape> nodes;
	std::list<sf::RectangleShape> edges;
	std::list<sf::Text> nodeValues;

public:
	Gui();
	
	void createVisualization(BinaryTree& tree, const sf::Vector2i& windowSize);
	void generateStructure(Node* root, sf::Vector2f parentPos, sf::Vector2f pos, int height, int gap);
	void renderTree(sf::RenderWindow& window);
};

