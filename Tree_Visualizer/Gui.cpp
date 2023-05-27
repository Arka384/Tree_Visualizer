#include "Gui.hpp"

Gui::Gui()
{
	//XDDDD
}

void Gui::createVisualization(BinaryTree& tree)
{
	this->totalNodes = tree.getNodeCount();
	this->height = tree.findHeight(tree.root);
	this->maxGap = std::pow(2, height - 1) * 50;

	generateStructure(tree.root, parentPos, rootPos, height, maxGap);
}

void Gui::generateStructure(Node* root, sf::Vector2f parentPos, sf::Vector2f pos, int height, int gap)
{
	if (root == nullptr)
		return;
	if (height == 0)
		return;
	
	//create node
	sf::CircleShape node;
	node.setRadius(10.f);
	node.setOrigin(sf::Vector2f(node.getGlobalBounds().width / 2, node.getGlobalBounds().height / 2));
	node.setPosition(pos);
	nodes.push_back(node);
	

	parentPos = node.getPosition();
	sf::Vector2f leftPos = sf::Vector2f(pos.x - ((gap / 2) / 2), pos.y + 50);
	//create edge
	float dx = parentPos.x - leftPos.x;
	float dy = parentPos.y - leftPos.y;
	float dist = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
	float angle = std::atan2(dy, dx);
	angle = -(angle * (180 / 3.14156));
	sf::RectangleShape edge;
	edge.setSize(sf::Vector2f(dist, 5));
	edge.setRotation(angle);
	edge.setPosition(parentPos);
	edges.push_back(edge);
	////
	generateStructure(root->left, parentPos, leftPos, height - 1, gap/2);


	parentPos = node.getPosition();
	sf::Vector2f rightPos = sf::Vector2f(pos.x + ((gap / 2) / 2), pos.y + 50);
	//create edge
	dx = parentPos.x - rightPos.x;
	dy = parentPos.y - rightPos.y;
	dist = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
	angle = std::atan2(dy, dx);
	angle = -(angle * (180 / 3.14156));
	edge.setSize(sf::Vector2f(dist, 5));
	edge.setRotation(angle);
	edge.setPosition(parentPos);
	edges.push_back(edge);
	////
	generateStructure(root->right, parentPos, rightPos, height - 1, gap/2);

}

void Gui::renderTree(sf::RenderWindow& window)
{
	for (auto i = nodes.begin(); i != nodes.end(); i++)
		window.draw(*i);
	for (auto i = edges.begin(); i != edges.end(); i++)
		window.draw(*i);
}
