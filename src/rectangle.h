#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include <string>

// Class for storing the configuration of rectangle shapes
class Rectangle
{
public:
	Rectangle(std::string name = "rect",
	      float x = 100,
	      float y = 100,
	      float sx = 0.01,
	      float sy = 0.01,
	      sf::Color c = sf::Color(0, 255, 0),
	      float w = 50,
	      float h = 100);
	
	std::string	getName() { return m_name; }
	float		getX() { return m_x; }
	float		getY() { return m_y; }
	float		getSpeedX() { return m_sx; }
	float		getSpeedY() { return m_sy; }
	sf::Color	getColor() { return m_color; }
	float		getWidth() { return m_w; }
	float		getHeight() { return m_h; }
	
	void 		setName(const std::string &name) { m_name = name; }
	void 		setX(const float x) { m_x = x; }
	void 		setY(const float y) { m_y = y; }
	void 		setSpeedX(const float sx) { m_sx = sx; }
	void 		setSpeedY(const float sy) { m_sy = sy; }
	void 		setColor(const sf::Color &c) { m_color = c; }
	void 		setWidth(const float w) { m_w = w; }
	void 		setHeight(const float h) { m_h = h; }
private:
	std::string 	m_name;
	float		m_x;
	float		m_y;
	float		m_sx;
	float		m_sy;
	sf::Color	m_color;
	float		m_w;
	float		m_h;
};
#endif // RECTANGLE_H
