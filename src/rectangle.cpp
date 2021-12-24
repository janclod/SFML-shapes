#include "rectangle.h"

#include <SFML/Graphics.hpp>
#include <iostream>

Rectangle::Rectangle(std::string name,
		     float x,
		     float y,
		     float sx,
		     float sy,
		     sf::Color c,
		     float w,
		     float h)
	: m_name{name}
	, m_x{x}
	, m_y{y}
	, m_sx{sx}
	, m_sy{sy}
	, m_color{c}
	, m_w{w}
	, m_h{h}
{
	#ifndef NDEBUG
	std::cout << "Constructed Rectangle" << std::endl;
	#endif // NDEBUG
}
