#include "ScientificInstrument.h"
#include <sstream>

ScientificInstrument::ScientificInstrument(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(author, country, name, year, width, height, length) {
    if (width < 0 || length < 0 || height < 0) {
        throw std::invalid_argument("Width/Length/Height of the picture can`t equal zero");
    }
}

ScientificInstrument::ScientificInstrument(const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(country, name, year, width, height, length) {
    if (width < 0 || length < 0 || height < 0) {
        throw std::invalid_argument("Width/Length/Height of the picture can`t equal zero");
    }
}

std::string ScientificInstrument::Info() const {
    std::ostringstream oss;
    oss << "Scientific Instrument: " << std::endl;
    oss << VolumeExhibit::Info() << std::endl;
    oss << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;
    return oss.str();
}

double ScientificInstrument::getVolArea() const {
    return width * length;
}


