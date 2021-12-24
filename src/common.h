#ifndef COMMON_H
#define COMMON_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "config.h"

////////////
// GENERAL /
////////////
// Helper functions for handling basic
// Generate font object based on input from config file
sf::Font loadFont(Config &config);
// Close the window when 'X' is clicked
void windowClose(sf::Window &window, const sf::Event &event);

/////////
// LOAD /
/////////
// Helper functions for generating shapes based on input from config file
// Generate a collection of CircleShape based on input from config file
std::vector<sf::CircleShape> loadCircles(Config &config);
// Generate a collection of text labels for CricleShape based on input from config file
std::vector<sf::Text> loadCircleTexts(const std::vector<sf::CircleShape> &circles, const sf::Font &myFont, Config &config);
// Generate a collection of RectangleShape based on input from config file
std::vector<sf::RectangleShape> loadRects(Config &config);
// Generate a collection of text labels for RectangleShape based on input from config file
std::vector<sf::Text> loadRectTexts(const std::vector<sf::RectangleShape> &rects, const sf::Font &myFont, Config &config);

///////////
// UPDATE /
///////////
// Helper functions for updating shapes and text positions
// Update the postion of CircleShape based on input from config file
void updatePositionCircle(sf::CircleShape &circle, Config &config, const size_t i);
// Update the position of text labels for CircleShape based on input from config file
void updatePositionCircleText(sf::Text &text, Config &config, const size_t i);
// Update the postion of RectangleShape based on input from config file
void updatePositionRect(sf::RectangleShape &rect, Config &config, const size_t i);
// Update the position of text labels for RectangleShape based on input from config file
void updatePositionRectText(sf::Text &text, Config &config, const size_t i);

///////////////
// COLLISION //
///////////////
// Helper function for detecting whether the shape is outside the window
void isCircleOutside(const sf::RenderWindow &win, const sf::CircleShape &circle, Config &config, const size_t &index);
void isRectOutside(const sf::RenderWindow &win, const sf::RectangleShape &rect, Config &config, const size_t &index);

#endif // COMMON_H
