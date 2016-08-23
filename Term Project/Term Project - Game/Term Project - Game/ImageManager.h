#pragma once
#include <SFML/Graphics.hpp>


class ImageManager
{
public:
	static sf::Image & GetImage(const std::string &filename);
private:
};