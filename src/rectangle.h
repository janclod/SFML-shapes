#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

// Class for storing the configuration of a rectangle shape
class Rectangle
{
public:
	// Default constructor for rectangle
	// @param name name, any string
	// @param x position on the x-axis, any number
	// @param y position on the y-axis, any number
	// @param sx speed over the x-axis, any number
	// @param sy speed over the y-axis, any number
	// @param c fill color of the rectangle, using Color class from SFML
	// @param w rectangle width, any number
	// @param h rectangle height, any number
	
	Rectangle(std::string name = "rect",
	          float x = 100,
	          float y = 100,
	          float sx = 0.01,
	          float sy = 0.01,
	          sf::Color c = sf::Color(0, 255, 0),
	          float w = 50,
	          float h = 100);
	
	// Getters functions
	std::string	getName() const noexcept { return m_name; }
	float		getX() const noexcept { return m_x; }
	float		getY() const noexcept { return m_y; }
	float		getSpeedX() const noexcept { return m_sx; }
	float		getSpeedY() const noexcept { return m_sy; }
	sf::Color	getColor() const noexcept { return m_color; }
	float		getWidth() const noexcept { return m_w; }
	float		getHeight() const noexcept { return m_h; }
	
	// Setter functions
	void 		setName(const std::string &name) { m_name = name; }
	void 		setX(const float x) { m_x = x; }
	void 		setY(const float y) { m_y = y; }
	void 		setSpeedX(const float sx) { m_sx = sx; }
	void 		setSpeedY(const float sy) { m_sy = sy; }
	void 		setColor(const sf::Color &c) { m_color = c; }
	void 		setWidth(const float w) { m_w = w; }
	void 		setHeight(const float h) { m_h = h; }
private:
	// Name
	std::string 	m_name;
	// x position
	float		m_x;
	// y position
	float		m_y;
	// speed over the x-axis
	float		m_sx;
	// speed over the y-axis
	float		m_sy;
	// fill color for rectangle
	sf::Color	m_color;
	// width rectangle
	float		m_w;
	// height rectangle
	float		m_h;
};
#endif // RECTANGLE_H
