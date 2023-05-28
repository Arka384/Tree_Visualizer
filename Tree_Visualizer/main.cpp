#include "Gui.hpp"
#include "Loader.hpp"

int main()
{
	const sf::Vector2i windowSize = sf::Vector2i(1280, 720);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Tree test", sf::Style::Close);

	BinaryTree* tree = new BinaryTree();
	Loader* loader = new Loader();
	loader->loadTraversals();

	loader->generateTree(*tree);

	Gui* gui = new Gui();
	gui->createVisualization(*tree, windowSize);
	

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