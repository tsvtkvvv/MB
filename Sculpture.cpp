#include "Sculpture.h"
#include <sstream>

Sculpture::Sculpture(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(author, country, name, year, width, height, length) {
    if (width < 0 || length < 0 || height < 0) {
        throw std::invalid_argument("Width/Length/Height of the picture can`t equal zero");
    }
}

Sculpture::Sculpture(const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(country, name, year, width, height, length) {
    if (width < 0 || length < 0 || height < 0) {
        throw std::invalid_argument("Width/Length/Height of the picture can`t equal zero");
    }
}

std::string Sculpture::Info() const {
    std::ostringstream oss;
    oss << "Sculpture: " << std::endl;
    oss << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;
    return oss.str();
}

double Sculpture::getVolArea() const {
    return width *  length;
}
