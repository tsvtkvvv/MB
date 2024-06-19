#include "VolumeExhibit.h"
#include <exception>
#include <iostream>
#include <sstream>

VolumeExhibit::VolumeExhibit(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length) :
    Exhibit(author, country, name, year), width(width), length(length), height(height){}

VolumeExhibit::VolumeExhibit(const std::string& name, const std::string& country, int year, double width, double height, double length) :
    Exhibit(name, country, year), width(width), length(length), height(height){}


std::string VolumeExhibit::Info() const {
    std::ostringstream result;

    result << Exhibit::Info();
    result << "Type: Volume Exhibit" << std::endl;
    result << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;

    return result.str();
   
}
double VolumeExhibit::getVolume() const {
    return width * height * length;
}