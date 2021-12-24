#include "circle.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Circle::Circle(std::string name,
	       float x,
	       float y,
	       float sx,
	       float sy,
	       sf::Color c,
	       float r)
	: m_name{name}
	, m_x{x}
	, m_y{y}
	, m_sx{sx}
	, m_sy{sy}
	, m_color{c}
	, m_radius{r}
{
	#ifndef NDEBUG
	std::cout << "Constructed Circle" << std::endl;
	#endif // NDEBUG
}
