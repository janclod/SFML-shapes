#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "config.h"
#include "common.h"

int main(int argc, char * argv [])
{
	// import configuration
	Config config;
	// create a new window with size from the configuration file
	sf::RenderWindow window(sf::VideoMode(config.getWindowConfig()[0],
					      config.getWindowConfig()[1]),
				"The Oosterparkwijk");
	// load font
	sf::Font myFont = loadFont(config);
	// load circles shapes and labels
	std::vector<sf::CircleShape> circles = loadCircles(config);
	std::vector<sf::Text> textsCircle = loadCircleTexts(circles, myFont, config);
	// load rectangle shapes and labels
	std::vector<sf::RectangleShape> rects = loadRects(config);
	std::vector<sf::Text> textsRect = loadRectTexts(rects, myFont, config);
	// main loop - continues for each frame while window is open
	while (window.isOpen())
	{
		// event handling
		sf::Event event; // create an event object
		// close window if 'X' is clicked
		while (window.pollEvent(event))
		{
			windowClose(window, event);
		}
		window.clear();	// clear the window and paint background black (default)
		// iterate over the circles
		// possible improvements is to wrap these two for loops into functions
		for (size_t i = 0; i < circles.size(); i++)
		{
			// if the circle is at the edge,
			// update speed accordingly inside Config object
			isCircleOutside(window, circles[i], config, i);
			// update position circle
			updatePositionCircle(circles[i], config, i);
			// basic rendering function calls
			window.draw(circles[i]); // draw circle	
			// move the text along with the circle
			updatePositionCircleText(textsCircle[i], config, i);
			window.draw(textsCircle[i]);	// draw the text
		}
		// iterate over the rectangles
		for (size_t i = 0; i < rects.size(); i++)
		{
			// if the shape is at the edge,
			// update speed accordingly inside Config object
			isRectOutside(window, rects[i], config, i);
			// update position rectangle
			updatePositionRect(rects[i], config, i);
			// basic rendering function calls
			window.draw(rects[i]); // draw rectangle	
			// move the text along with the rectangle
			updatePositionRectText(textsRect[i], config, i);
			window.draw(textsRect[i]);	// draw the text
		}
		
		window.display(); // call the window display function to paint everything
	}	
	return 0;
}
