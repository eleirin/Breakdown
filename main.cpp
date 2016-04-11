#include <SFML/Graphics.hpp>
#include "ObjectManager.h"
#include "Bullet.h"
#include "Pattern.h"
#include "Heroin.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Breakdown");
	sf::Clock c;	

        MasterManager all_layers;
        BulletManager *all_bullets = all_layers.add<BulletManager>();
        ObjectManager<> *all_objects = all_layers.add<ObjectManager<>>();
        all_objects->add<Heroin>(*all_bullets);
        //all_objects->add<Spiral>(MathVector(1, 1), *all_bullets);

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

				default:
					break;
				}
				break;

			default:
				break;
			}
		}

		//update
                all_layers.update(dt);

		//draw
		window.clear();
		window.draw(all_layers);
		window.display();
	}

	return 0;
}
