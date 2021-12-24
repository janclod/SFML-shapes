#include "font.h"

#include <SFML/Graphics.hpp>
#include <iostream>

FontConfig::FontConfig(std::string file, int size, sf::Color c)
	: m_fontFile{file}, m_fontSize{size}, m_fontColor{c}
{
	#ifndef NDEBUG
	std::cout << "Constructed FontConfig" << std::endl;
	#endif // NDEBUG
}
