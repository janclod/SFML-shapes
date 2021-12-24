#ifndef FONTCONFIG_H
#define FONTCONFIG_H

#include <SFML/Graphics.hpp>

#include <string>

// Class for storing configuaration of font
class FontConfig
{
public:
	// Default constructor for font object
	// @param file name of font file, must be a valid font file (.ttf)
	// @param size fron size, any positive number
	// @param c font colot, must of Color class from SFML
	FontConfig(std::string file = "Arial.ttf", int size = 10, sf::Color c = sf::Color());
	
	// Getter
	std::string getFontFile() const noexcept { return m_fontFile; }
	int getFontSize() const noexcept { return m_fontSize; }
	sf::Color getFontColor() const noexcept { return m_fontColor; }
	
	// Setters
	void setFontFile(const std::string file) { m_fontFile = file; }
	void setFontSize(const int size) { m_fontSize = size; }
	void setFontColor(const sf::Color c) { m_fontColor = c; }
private:
	std::string m_fontFile;
	int	    m_fontSize;
	sf::Color   m_fontColor;
};
#endif // FONTCONFIG_H 
