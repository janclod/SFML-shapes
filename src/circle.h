#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <string>

// Class for storing configuration of a circle shape
class Circle
{
public:
	// Default contructor for the circle object
	// @param name name, any string
	// @param x position on the x-axis, any number
	// @param y position on the y-axis, any number
	// @param sx speed over the x-axis, any number
	// @param sy speed over the y-axis, any number
	// @param c fill color of the circle, using Color class from SFML
	// @param x circle radius, any number
	Circle(std::string name = "circle",
	      float x = 100,
	      float y = 100,
	      float sx = 0.01,
	      float sy = 0.01,
	      sf::Color c = sf::Color(0, 255, 0),
	      float r = 50);
	
	// Getter functions
	std::string	getName() const noexcept { return m_name; }
	float		getX() const noexcept { return m_x; }
	float		getY() const noexcept { return m_y; }
	float		getSpeedX() const noexcept { return m_sx; }
	float		getSpeedY() const noexcept { return m_sy; }
	sf::Color	getColor() const noexcept { return m_color; }
	float		getRadius() const noexcept { return m_radius; }
	
	// Setter functions
	void 		setName(const std::string &name) { m_name = name; }
	void 		setX(const float x) { m_x = x; }
	void 		setY(const float y) { m_y = y; }
	void 		setSpeedX(const float sx) { m_sx = sx; }
	void 		setSpeedY(const float sy) { m_sy = sy; }
	void 		setColor(const sf::Color &c) { m_color = c; }
	void 		setRadius(const float r) { m_radius = r; }
private:
	// Name
	std::string 	m_name;
	// x position
	float		m_x;
	// y position
	float		m_y;
	// speed along the x-axis
	float		m_sx;
	// speed along the y-axis
	float		m_sy;
	// fill color
	sf::Color	m_color;
	// circle radius
	float		m_radius;
};
#endif // CIRCLE_H
