#include "Sculpture.h"
#include <sstream>

Sculpture::Sculpture(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(author, country, name, year, width, height, length) {}

Sculpture::Sculpture(const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(country, name, year, width, height, length) {}

std::string Sculpture::Info() const {
    std::ostringstream oss;
    oss << "Sculpture: " << std::endl;
    oss << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;
    return oss.str();
}

double Sculpture::getVolume() const {
    return width * height * length;
}
