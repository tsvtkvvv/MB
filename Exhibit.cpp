#include "Exhibit.h"
#include <sstream>
#include <exception>

Exhibit::Exhibit(const std::string& author, const std::string& country, const std::string& name, int year) :
	author(author), country(country), name(name), year(year){
	if (year < 0) {
		throw std::invalid_argument("Year can`t equal 0");
	}
}

Exhibit::Exhibit(const std::string& name, const std::string& country, int year) : name(name), country(country), year(year) {
	if (year < 0) {
		throw std::invalid_argument("Year can`t equal 0");
	}
}

double Exhibit::getArea() const
{
	return 0;
}

std::string Exhibit::Info() const
{
	std::ostringstream result;
	
	if (!author.empty()) {
		result << "Author: " << author << std::endl;
	}
	else {
		result << "Author: Unknown" << std::endl;
	}
	result << "Name: " << name << std::endl;
	result << "Country: " << country << std::endl;
	result << "Year: " << year << std::endl;

	return result.str();

}


