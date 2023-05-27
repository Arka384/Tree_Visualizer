#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gui.hpp"
#include "Loader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tree test", sf::Style::Close);

	BinaryTree* tree = new BinaryTree();
	Loader* loader = new Loader();
	loader->generateTree(*tree);
	tree->Inorder(tree->root);

	Gui* gui = new Gui(*tree);
	Node* par = nullptr;
	sf::Vector2f temp = sf::Vector2f(0, 0);
	gui->generateStructure(tree->root, temp, gui->getRootPos(), gui->getHeight(), gui->getMaxGap());

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
			default:
				break;
			}
		}


		window.clear();
		gui->renderTree(window);
		window.display();

	}
}