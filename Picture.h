#pragma once
#include "Exhibit.h"
class Picture : public Exhibit
{
private:
	double width, length;
public:
	Picture(const std::string& author, const std::string& country, const std::string& name, int year, double width, double length);
	Picture(const std::string& name, const std::string& country, int year, double width, double length);

	double getArea() const override;


	
	std::string Info() const override;
	
};

