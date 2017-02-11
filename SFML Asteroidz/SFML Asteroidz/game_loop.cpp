#include <SFML/Graphics.hpp>
#include "logic.cpp"

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(512, 256), "Particles");
	sf::CircleShape	shape(100.f);
	// create the particle system
	ParticleSystem particles(1000);

	// create a clock to track the elapsed time
	sf::Clock clock;

	////////////////////////////////////////////////////////////////////////
	
	sf::Vertex vertex(sf::Vector2f(10, 50), sf::Color::Red, sf::Vector2f(100, 100));
	sf::VertexArray triangle(sf::Triangles, 3);

	// define the position of the triangle's points
	triangle[0].position = sf::Vector2f(10, 10);
	triangle[1].position = sf::Vector2f(150, 10);
	triangle[2].position = sf::Vector2f(100, 100);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;

	// no texture coordinates here, we'll see that later
	//////////////////////////////////////////////////////////////////////

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// make the particle system emitter follow the mouse
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		particles.setEmitter(window.mapPixelToCoords(mouse));

		// update it
		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		// draw it
		window.clear();
		window.draw(triangle);
		window.draw(particles);
		window.display();
	}

	return 0;
}