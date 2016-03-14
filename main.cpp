#include <SFML/Graphics.hpp>
#include "ObjectManager.h"
#include "Pattern.h"
#include "Heroin.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Breakdown");
	sf::Clock c;	
	ObjectManager h;
	Heroin hero;

	//Main loop
	while(window.isOpen())
	{
		float dt = c.restart().asSeconds();

		//Event loop
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch(event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
				case sf::Keyboard::Space:
					hero.jump();
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		//update
		hero.update(dt);
		h.update(dt);

		//draw
		window.clear();
		window.draw(hero);
		window.draw(h);
		window.display();
	}

	return 0;

}
