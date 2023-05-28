#include "Gui.hpp"
#include "Loader.hpp"

int main()
{
	const sf::Vector2i windowSize = sf::Vector2i(1280, 720);
	sf::Vector2i mousePos, lastMousePos;
	bool mouseDown = false;
	float dt = 0;
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Tree test", sf::Style::Close);

	BinaryTree* tree = new BinaryTree();
	Loader* loader = new Loader();
	Gui* gui = new Gui(windowSize);
	sf::Time tme;
	sf::Clock clk;

	loader->loadTraversals();
	loader->generateTree(*tree);

	std::thread v_thread(&Gui::createVisualization, gui, std::ref(*tree), std::ref(windowSize));
	

	while (window.isOpen()) {
		tme = clk.restart();
		dt = tme.asMilliseconds();

		sf::Event e;
		while (window.pollEvent(e)) {
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonPressed:
				lastMousePos = mousePos;
				mouseDown = true;
				break;
			case sf::Event::MouseButtonReleased:
				mouseDown = false;
				break;
			default:
				break;
			}
		}
		mousePos = sf::Mouse::getPosition(window);

		if(mouseDown == true)
			gui->updateView(mousePos, lastMousePos, dt);
		window.setView(gui->getView());

		if (gui->isGenerated()) {
			gui->setGenereated(false);
			v_thread.join();
		}


		window.clear();
		gui->renderTree(window);
		window.display();

	}

	try {
		v_thread.join();	//extreme case, ended abruptly before completion
	}
	catch (...) {
		std::cout << std::current_exception;
	}
}