#ifndef CONFIG_H
#define	CONFIG_H

#include "font.h"
#include "circle.h"
#include "rectangle.h"

#include <vector>

// Class for storing configuration of application
class Config
{
public:
	Config(const std::string file  = "config.txt");

	std::vector<int>& getWindowConfig() { return m_windowConfig; };

	FontConfig& getFontConfig() { return m_fontConfig; };

	std::vector<Circle>& getCircles() { return m_circles; }
	
	std::vector<Rectangle>& getRects() { return m_rects; }
private:
	std::vector<int> m_windowConfig;
	FontConfig m_fontConfig;
	std::vector<Circle> m_circles;
	std::vector<Rectangle> m_rects;
};
#endif // CONFIG_H
