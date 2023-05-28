#include "Gui.hpp"
#include "Loader.hpp"

int main()
{
	const sf::Vector2i windowSize = sf::Vector2i(1280, 720);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Tree test", sf::Style::Close);

	BinaryTree* tree = new BinaryTree();
	Loader* loader = new Loader();
	Gui* gui = new Gui();

	loader->loadTraversals();
	loader->generateTree(*tree);

	std::thread v_thread(&Gui::createVisualization, gui, std::ref(*tree), std::ref(windowSize));
	

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

		if (gui->isGenerated()) {
			gui->setGenereated(false);
			v_thread.join();
		}


		window.clear();
		gui->renderTree(window);
		window.display();

	}

	v_thread.join();	//extreme case, ended abruptly before completion
}