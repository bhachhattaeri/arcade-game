#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

//g++ arcade.cpp -lsfml-graphics -lsfml-window -lsfml-system

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    
    sf::Sprite sprite;
    // Create a graphical text to display
    sf::Font font;
    
    sf::Text text("Hello SFML", font, 50);
    // Load a music to play
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(40, 20));
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(0, 0);
    window.draw(rectangle);
    sf::RectangleShape enemy;
    enemy.setSize(sf::Vector2f(40, 20));
    enemy.setOutlineColor(sf::Color::Blue);
    enemy.setOutlineThickness(1);
    enemy.setPosition(20, 500);
    window.draw(enemy);
    sf::CircleShape circle;
    circle.setRadius(2);
    circle.setOutlineThickness(5);
    circle.setPosition(20, 20);
    int i = 0;
    int j = 0;
    window.draw(circle);
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(rectangle);
        window.draw(enemy);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    // left key is pressed: move our character
            rectangle.setPosition(++j, 0);

          ///  character.move(1, 0);
        }
        circle.setPosition(20+j, 20+i);
        //rectangle.setPosition(j, 0);
//		enemy.setPosition(20, 500-j/4);
        enemy.setPosition(20, 500-i/4);

		window.draw(circle);
		i+=4;
		//j++;
		if(i>=550){
			i = 0;
		}
		if(j >= 500){
			j = 0;
		}
        window.display();
        window.clear();
        
    }
    return EXIT_SUCCESS;
}