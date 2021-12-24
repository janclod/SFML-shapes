#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <string>

// Class for storing configuration of circle shapes
class Circle
{
public:
	Circle(std::string name = "circle",
	      float x = 100,
	      float y = 100,
	      float sx = 0.01,
	      float sy = 0.01,
	      sf::Color c = sf::Color(0, 255, 0),
	      float r = 50);
	
	std::string	getName() { return m_name; }
	float		getX() { return m_x; }
	float		getY() { return m_y; }
	float		getSpeedX() { return m_sx; }
	float		getSpeedY() { return m_sy; }
	sf::Color	getColor() { return m_color; }
	float		getRadius() { return m_radius; }
	
	void 		setName(const std::string &name) { m_name = name; }
	void 		setX(const float x) { m_x = x; }
	void 		setY(const float y) { m_y = y; }
	void 		setSpeedX(const float sx) { m_sx = sx; }
	void 		setSpeedY(const float sy) { m_sy = sy; }
	void 		setColor(const sf::Color &c) { m_color = c; }
	void 		setRadius(const float r) { m_radius = r; }
private:
	std::string 	m_name;
	float		m_x;
	float		m_y;
	float		m_sx;
	float		m_sy;
	sf::Color	m_color;
	float		m_radius;
};
#endif // CIRCLE_H
