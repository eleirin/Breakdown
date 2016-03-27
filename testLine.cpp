#include <SFML/Graphics.hpp>
#include <array>
#include "Bezier.h"

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Breakdown");

        const int size = 100;
        std::array<sf::VertexArray, size> line;
        
        for(int i = 0; i < size; i++)
        {
            line[i] = BezierLine<4>(std::array<MathVector, 4>({ {MathVector(0, 0),  MathVector(0, 600 - i*6), MathVector(600 - i * 6, 0), MathVector(600, 600)} }));
        }

        bool t = true;
	//Main loop
	while(window.isOpen())
	{
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
		

                //draw
		window.clear();
                for(int i = 0; i < size; i++)
                    window.draw(line[i]);

		window.display();

                if(t)
                {
                    sf::Image screen = window.capture();
                    screen.saveToFile("Waaaah10.png");
                    t = false;
                }
	}

	return 0;

}
