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
	// Default constructor
	// @param file location/name config file
	// 
	// file must have the following format
	//
	// 		Col1		Col2		Col3	Col4	Col5	Col6	Col7	Col8	Col9	Col10	Col11
	// row1		Window		<width>		<height>
	// row2		Font		<font_file	
	// row3		Circle		<name>		x-pos	y-pos	x-speed	y-speed	R-color	G-color	B-color	<radius>
	// row4		Rectangle	<name>		x-pos	y-pos	x-speed	y-speed	r-color	G-color	B-color	<width>	<height>
	//
	// Order matters!
	// The first row must contain information regarding the window size
	// The second row must contain information regarding the font
	// The remaining must contain information about shapes in any order
	Config(const std::string file  = "config.txt");
	
	// Getters by reference (not value)
	// Getting by reference is crucial,
	// if we want to modify configuration
	// when accessing these class members
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
