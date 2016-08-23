#include "ImageManager.h"
#include <string>
#include <map>

sf::Image & ImageManager::GetImage(const std::string &filename)
{
	static std::map<std::string, sf::Image> instances;
	sf::Image* ptr = nullptr;

	auto i = instances.find(filename);
	if( i != instances.end() )
	{
		ptr = &(i->second);
	}
	else
	{
		// if the file hasn't been loaded, make a new instance of it (singleton)
		sf::Image newImage;
		newImage.loadFromFile(filename);

		// and then store the image in instances for use later
		instances[filename] = newImage; // note that assignment op is invoked here
		ptr = &instances[filename]; // assign address to ptr to return
	}
	return *ptr;
}