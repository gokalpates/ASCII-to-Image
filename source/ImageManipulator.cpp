#include "ImageManipulator.hpp"

ImageManipulator::ImageManipulator():
	image(nullptr),
	gradient(nullptr)
{
	gradient = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\" ^ `'. ";

	std::cout << "NOTE: Try not to exceed 330 pixel height and 670 width for better results.\n";
	std::cout << "If you have bigger screen dimensions, then you can go for bigger values.\n\n";

	std::cout << "Enter a image file name to convert ascii art: ";
	std::cin >> resourceFileName;

	std::cout << "Enter a text file name to write asscii art: ";
	std::cin >> targetFileName;

	std::cout << "IMPORTANT NOTE: Do not forget to zoom out in txt file and maximize screen!!!\n";

	writeToFile();
}

inline char ImageManipulator::calculateGradient(sf::Color& pixelColor)
{
	float r, g, b, L;
	r = pixelColor.r;
	g = pixelColor.g;
	b = pixelColor.b;
	L = (r * 0.2126f + g * 0.7152f, b * 0.0722f);
	size_t charIndexToReturn = (size_t)(72.f * L);
	char returnThis = gradient[charIndexToReturn];
	return returnThis;
}

void ImageManipulator::writeToFile()
{
	this->image = new sf::Image;
	if (!image->loadFromFile(resourceFileName))
	{
		std::cout << "ERROR: Program could not load image to convert ascii art!\n";
		std::exit(1);
	}
	sf::Vector2u size = this->image->getSize();

	std::ofstream outputFile(targetFileName);
	if (!outputFile.is_open())
	{
		std::cout << "ERROR: Program could not create or open txt file to write!\n";
		std::exit(1);
	}

	for (size_t i = 0; i < size.y; i++)
	{
		for (size_t j = 0; j < size.x; j++)
		{
			sf::Color pixelColor = this->image->getPixel(j, i);
			outputFile.put(calculateGradient(pixelColor));
		}
		outputFile.put('\n');
	}

	outputFile.close();
}
