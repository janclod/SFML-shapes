#include "common.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "config.h"

/////////////
// GENERAL //
/////////////
sf::Font loadFont(Config &config)
{
	// let's load a font so we can display some text
	sf::Font myFont;

	// attempt to load the font from a file
	if (!myFont.loadFromFile(config.getFontConfig().getFontFile()))
	{
		// if we can't load the font, print an error
		std::cerr << "Could not load font!" << std::endl;
		exit(-1);
	}

	return myFont;
}

void windowClose(sf::Window &window, const sf::Event &event)
{
	// this event triggers when the window is closed
	if (event.type == sf::Event::Closed)
	{
		#ifndef NDEBUG
		std::cout << "The window was closed" << std::endl;
		#endif // NDEBUG
		window.close();
	}			
}		

//////////
// LOAD //
////////// 
std::vector<sf::CircleShape> loadCircles(Config &config)
{
	std::vector<sf::CircleShape> circles;
	// let's collect the shapes to draw on the screen
	for (auto cConfig : config.getCircles())
	{
		#ifndef NDEBUG
		std::cout << "Collecting " << cConfig.getName() << std::endl;
		#endif // NDEBUG
		sf::CircleShape circle(cConfig.getRadius());	// set the circle size
		circle.setFillColor(cConfig.getColor());	// set the circle color
		circle.setPosition(cConfig.getX(),
				   cConfig.getY());		// set the circle position

		circles.push_back(circle);
	}
	return circles;
}

std::vector<sf::Text> loadCircleTexts(const std::vector<sf::CircleShape> &circles, const sf::Font &myFont, Config &config)
{		
	std::vector<sf::Text> texts;
	for (size_t i = 0; i < circles.size(); i++)
	{
		sf::Text text(config.getCircles()[i].getName(),
			      myFont,
			      config.getFontConfig().getFontSize());

		// set text color to the desired one based on input from
		// the config file
		text.setFillColor(config.getFontConfig().getFontColor());
		// position the text at the center of the shape
		sf::Vector2f pos(circles[i].getPosition().x + (circles[i].getLocalBounds().width / 2) - (text.getLocalBounds().width / 2) - text.getLocalBounds().left,
				circles[i].getPosition().y + (circles[i].getLocalBounds().height / 2) - (text.getLocalBounds().height / 2) - text.getLocalBounds().top);
		text.setPosition(pos);
		texts.push_back(text);
	}
	return texts;
}

std::vector<sf::RectangleShape> loadRects(Config &config)
{
	std::vector<sf::RectangleShape> rects;
	// let's collect the shapes to draw on the screen
	for (auto rConfig : config.getRects())
	{
		#ifndef NDEBUG
		std::cout << "Collecting " << rConfig.getName() << std::endl;
		#endif // NDEBUG
		sf::RectangleShape rect(sf::Vector2f(rConfig.getWidth(),// set rect width
						     rConfig.getHeight()));// set rect height
		rect.setFillColor(rConfig.getColor());		// set the rect color
		rect.setPosition(rConfig.getX(),
				 rConfig.getY());		// set rect position

		rects.push_back(rect);
	}
	return rects;
}

std::vector<sf::Text> loadRectTexts(const std::vector<sf::RectangleShape> &rects, const sf::Font &myFont, Config &config)
{		
	std::vector<sf::Text> texts;
	for (size_t i = 0; i < rects.size(); i++)
	{
		sf::Text text(config.getRects()[i].getName(),
			      myFont,
			      config.getFontConfig().getFontSize());

		// set text color to the desired one based on input from
		// the config file
		text.setFillColor(config.getFontConfig().getFontColor());
		// position the text at the center of the shape
		sf::Vector2f pos(rects[i].getPosition().x + (rects[i].getLocalBounds().width / 2) - (text.getLocalBounds().width / 2) - text.getLocalBounds().left,
				rects[i].getPosition().y + (rects[i].getLocalBounds().height / 2) - (text.getLocalBounds().height / 2) - (text.getLocalBounds().top));
		text.setPosition(pos);
		texts.push_back(text);
	}

	return texts;
}

////////////
// UPDATE //
////////////
void updatePositionCircle(sf::CircleShape &circle, Config &config, const size_t i)
{	
	// basic animation - move the circle to new position
	// based on values given from configuration file
	sf::Vector2f previousPositionShape = circle.getPosition();
	sf::Vector2f moveVectorShape(config.getCircles()[i].getSpeedX(),
				     config.getCircles()[i].getSpeedY());
	sf::Vector2f newPositionShape = previousPositionShape + moveVectorShape;

	circle.setPosition(newPositionShape);
}

void updatePositionCircleText(sf::Text &text, Config &config, const size_t i)
{
	sf::Vector2f previousPositionText = text.getPosition();
	sf::Vector2f moveVectorText(config.getCircles()[i].getSpeedX(),
				    config.getCircles()[i].getSpeedY());
	sf::Vector2f newPositionText = previousPositionText + moveVectorText;
	
	text.setPosition(newPositionText);
}

void updatePositionRect(sf::RectangleShape &rect, Config &config, const size_t i)
{
	// basic animation - move the rectangle to new position
	// based on values given from configuration file
	sf::Vector2f previousPositionShape = rect.getPosition();
	sf::Vector2f moveVectorShape(config.getRects()[i].getSpeedX(),
				     config.getRects()[i].getSpeedY());
	sf::Vector2f newPositionShape = previousPositionShape + moveVectorShape;

	rect.setPosition(newPositionShape);
}

void updatePositionRectText(sf::Text &text, Config &config, const size_t i)
{
	sf::Vector2f previousPositionText = text.getPosition();
	sf::Vector2f moveVectorText(config.getRects()[i].getSpeedX(),
				    config.getRects()[i].getSpeedY());
	sf::Vector2f newPositionText = previousPositionText + moveVectorText;
	
	text.setPosition(newPositionText);
}

///////////////
// COLLISION //
///////////////
void isCircleOutside(const sf::RenderWindow &win, const sf::CircleShape &circle, Config &config, const size_t &index)
{
	if (circle.getPosition().y < 0)
	{
		float newSpeed = config.getCircles()[index].getSpeedY() * -1;
		config.getCircles()[index].setSpeedY(newSpeed);
	}
	if ((circle.getPosition().y + circle.getLocalBounds().height) > win.getSize().y)
	{
		float newSpeed = config.getCircles()[index].getSpeedY() * -1;
		config.getCircles()[index].setSpeedY(newSpeed);
	}
	if (circle.getPosition().x < 0)
	{
		float newSpeed = config.getCircles()[index].getSpeedX() * -1;
		config.getCircles()[index].setSpeedX(newSpeed);
	}	
	if ((circle.getPosition().x + circle.getLocalBounds().width) > win.getSize().x)
	{
		float newSpeed = config.getCircles()[index].getSpeedX() * -1;
		config.getCircles()[index].setSpeedX(newSpeed);
	}	
}

void isRectOutside(const sf::RenderWindow &win, const sf::RectangleShape &rect, Config &config, const size_t &index)
{
	if (rect.getPosition().y < 0)
	{
		float newSpeed = config.getRects()[index].getSpeedY() * -1;
		config.getRects()[index].setSpeedY(newSpeed);
	}
	if ((rect.getPosition().y + rect.getLocalBounds().height) > win.getSize().y)
	{
		float newSpeed = config.getRects()[index].getSpeedY() * -1;
		config.getRects()[index].setSpeedY(newSpeed);
	}
	if (rect.getPosition().x < 0)
	{
		float newSpeed = config.getRects()[index].getSpeedX() * -1;
		config.getRects()[index].setSpeedX(newSpeed);
	}	
	if ((rect.getPosition().x + rect.getLocalBounds().width) > win.getSize().x)
	{
		float newSpeed = config.getRects()[index].getSpeedX() * -1;
		config.getRects()[index].setSpeedX(newSpeed);
	}	
}
