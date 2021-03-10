#pragma once

#include "SFML.hpp"
#include <iostream>
#include <fstream>

class ImageManipulator
{
public:
	ImageManipulator();

	char calculateGradient(sf::Color& pixelColor);

	void writeToFile();
private:
	std::string resourceFileName, targetFileName;
	sf::Image* image;
	const char* gradient;
};

