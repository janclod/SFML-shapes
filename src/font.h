#ifndef FONTCONFIG_H
#define FONTCONFIG_H

#include <SFML/Graphics.hpp>

#include <string>

// Class for storing configuaration of font
class FontConfig
{
public:
	FontConfig(std::string file = "Arial.ttf", int size = 10, sf::Color c = sf::Color());
	
	void setFontFile(std::string file) { m_fontFile = file; }

	void setFontSize(int size) { m_fontSize = size; }

	void setFontColor(sf::Color c) { m_fontColor = c; }

	std::string getFontFile() { return m_fontFile; }

	int getFontSize() { return m_fontSize; }

	sf::Color getFontColor() { return m_fontColor; }
private:
	std::string m_fontFile;
	int	    m_fontSize;
	sf::Color   m_fontColor;
};
#endif // FONTCONFIG_H 
