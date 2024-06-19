#pragma once
#include "VolumeExhibit.h"

class Sculpture : public VolumeExhibit {
public:
    Sculpture(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length);
    Sculpture(const std::string& country, const std::string& name, int year, double width, double height, double length);

     std::string Info() const override;
     double getVolArea() const override;
};
