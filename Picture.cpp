#include "Picture.h"
#include "Room.h"
#include <sstream>
#include <exception>

Picture::Picture(const std::string& author, const std::string& country, const std::string& name, int year, double width, double length)
    : Exhibit(author, country, name, year), width(width), length(length)
{
    if (width < 0 || length < 0) {
        throw std::invalid_argument("Width/Length of the picture can`t equal zero");
    }
}

Picture::Picture(const std::string& name, const std::string& country, int year, double width, double length)
    : Exhibit(name, country, year), width(width), length(length)
{
    if (width < 0 || length < 0) {
        throw std::invalid_argument("Width/Length of the picture can`t equal zero");
   }
}
double Picture::getArea() const
{
    return width * length;
}


std::string Picture::Info() const
{
    std::ostringstream result;

    result << Exhibit::Info();
    result << "Type: Picture" << std::endl;
    result << "Dimensions: " << width << "x" << length << " meters" << std::endl;

    return result.str();
}


