#pragma once
#include "Exhibit.h"


class VolumeExhibit: public Exhibit
{
private:
	
	double width;
	double height;
	double length;
public:
	VolumeExhibit(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length);
	VolumeExhibit(const std::string& name, const std::string& country, int year, double width, double height, double lenght);

	virtual std::string Info() const;

};

