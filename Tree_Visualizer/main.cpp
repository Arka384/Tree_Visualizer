#include "Gui.hpp"
#include "Loader.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tree test", sf::Style::Close);

	BinaryTree* tree = new BinaryTree();
	Loader* loader = new Loader();
	loader->loadTraversals();

	loader->generateTree(*tree);

	Gui* gui = new Gui();
	gui->createVisualization(*tree);
	

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