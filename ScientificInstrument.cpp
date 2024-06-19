#include "ScientificInstrument.h"
#include <sstream>

ScientificInstrument::ScientificInstrument(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(author, country, name, year, width, height, length) {}

ScientificInstrument::ScientificInstrument(const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(country, name, year, width, height, length) {}

std::string ScientificInstrument::Info() const {
    std::ostringstream oss;
    oss << "Scientific Instrument: " << std::endl;
    oss << VolumeExhibit::Info() << std::endl;
    oss << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;
    return oss.str();
}

double ScientificInstrument::getVolume() const {
    return width * height * length;
}
