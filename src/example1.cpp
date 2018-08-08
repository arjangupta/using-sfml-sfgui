#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	sf::Text text;

	text.setString("Hello World");

	text.setCharacterSize(16);

	sf::Window window;
	window.draw(text);
	
	return 0;
}