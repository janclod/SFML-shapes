#include "config.h"
#include "circle.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

Config::Config(const std::string file)
	: m_windowConfig(std::vector<int> { 800, 600 })
	, m_fontConfig(FontConfig())
	{
		std::cout << "Constructed Config" << std::endl;
		
		std::fstream fin(file);
		if (!fin.is_open())
		{	
			std::cout << "Failed to open file" << std::endl;
		} else {
			std::string s = "";
			int i = 0;
			int color[3] = { 0, 0, 0 };
			if (fin >> s && s == "Window")
			{
				fin >> m_windowConfig[0];
				fin >> m_windowConfig[1];	
			}
			if (fin >> s && s == "Font")
			{
				fin >> s;
				m_fontConfig.setFontFile(s);
				fin >> i;
				m_fontConfig.setFontSize(i);
				fin >> color[0];
				fin >> color[1];
				fin >> color[2];
				m_fontConfig.setFontColor(sf::Color(color[0], color[1], color[2]));
			}

			int countC = 0;
			int countR = 0;
			float f = 0.f;
			while (fin >> s)
			{
				if (s == "Circle")
				{
					m_circles.push_back(Circle());
					fin >> s;
					std::cout << s << std::endl;
					m_circles[countC].setName(s);
					fin >> f;
					m_circles[countC].setX(f);
					fin >> f;
					m_circles[countC].setY(f);
					fin >> f;
					m_circles[countC].setSpeedX(f);
					fin >> f;
					m_circles[countC].setSpeedY(f);
					fin >> color[0];
					fin >> color[1];
					fin >> color[2];
					m_circles[countC].setColor(sf::Color(color[0], color[1], color[2]));
					fin >> f;
					m_circles[countC].setRadius(f);
					countC++;
				}
				if (s == "Rectangle")
				{
					m_rects.push_back(Rectangle());
					fin >> s;
					std::cout << s << std::endl;
					m_rects[countR].setName(s);
					fin >> f;
					m_rects[countR].setX(f);
					fin >> f;
					m_rects[countR].setY(f);
					fin >> f;
					m_rects[countR].setSpeedX(f);
					fin >> f;
					m_rects[countR].setSpeedY(f);
					fin >> color[0];
					fin >> color[1];
					fin >> color[2];
					m_rects[countR].setColor(sf::Color(color[0], color[1], color[2]));
					fin >> f;
					m_rects[countR].setWidth(f);
					fin >> f;
					m_rects[countR].setHeight(f);
					countR++; 
				}
			}
			std::cout << "N circle: " << countC << std::endl;
			std::cout << "N rectangle: " << countR << std::endl;
		}
		fin.close();
	}
