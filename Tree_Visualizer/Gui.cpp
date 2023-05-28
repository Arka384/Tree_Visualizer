#include "Gui.hpp"

Gui::Gui()
{
	//XDDDD
	if (!this->nodeValuefont.loadFromFile("res/fonts/comic_sans.ttf"))
		exit(1);
}

void Gui::createVisualization(BinaryTree& tree, const sf::Vector2i& windowSize)
{
	this->totalNodes = tree.getNodeCount();
	this->height = tree.findHeight(tree.root);
	this->maxGap = std::pow(2, height - 1) * 50;
	this->rootPos = sf::Vector2f(windowSize.x / 2, 50);

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
	node.setFillColor(nodeColor);
	node.setRadius(nodeSize);
	node.setOrigin(sf::Vector2f(node.getGlobalBounds().width / 2, node.getGlobalBounds().height / 2));
	node.setPosition(pos);
	nodes.push_back(node);

	sf::Text nodeData;
	nodeData.setFont(nodeValuefont);
	nodeData.setString(std::to_string(root->getData()));
	nodeData.setCharacterSize(nodeValueFontSize);
	nodeData.setOrigin(nodeData.getGlobalBounds().width / 2, nodeData.getGlobalBounds().height * 1.5 / 2);
	nodeData.setPosition(node.getPosition());
	nodeValues.push_back(nodeData);


	parentPos = node.getPosition();
	sf::Vector2f leftPos = sf::Vector2f(pos.x - ((gap / 2) / 2), pos.y + 50);
	//create edge
	if (root->right != nullptr) {	//left checks right
		float dx = parentPos.x - leftPos.x;
		float dy = parentPos.y - leftPos.y;
		float dist = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
		float angle = std::atan2(dy, dx);
		angle = -(angle * (180 / 3.14156));
		sf::RectangleShape edge;
		edge.setSize(sf::Vector2f(dist, edgeWidth));
		edge.setRotation(angle);
		edge.setPosition(parentPos);
		edges.push_back(edge);
	}
	////
	generateStructure(root->left, parentPos, leftPos, height - 1, gap/2);


	parentPos = node.getPosition();
	sf::Vector2f rightPos = sf::Vector2f(pos.x + ((gap / 2) / 2), pos.y + 50);
	//create edge
	if (root->left != nullptr) {	//right checks left
		float dx = parentPos.x - rightPos.x;
		float dy = parentPos.y - rightPos.y;
		float dist = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
		float angle = std::atan2(dy, dx);
		angle = -(angle * (180 / 3.14156));
		sf::RectangleShape edge;
		edge.setSize(sf::Vector2f(dist, edgeWidth));
		edge.setRotation(angle);
		edge.setPosition(parentPos);
		edges.push_back(edge);
	}
	////
	generateStructure(root->right, parentPos, rightPos, height - 1, gap/2);

}

void Gui::renderTree(sf::RenderWindow& window)
{
	for (auto i = edges.begin(); i != edges.end(); i++)
		window.draw(*i);
	for (auto i = nodes.begin(); i != nodes.end(); i++)
		window.draw(*i);
	for (auto i = nodeValues.begin(); i != nodeValues.end(); i++)
		window.draw(*i);
}
