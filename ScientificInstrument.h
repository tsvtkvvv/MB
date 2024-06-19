#pragma once
#include "VolumeExhibit.h"


class ScientificInstrument : public VolumeExhibit {
public:
    ScientificInstrument(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length);
    ScientificInstrument(const std::string& country, const std::string& name, int year, double width, double height, double length);

     std::string Info() const override;
    double getVolArea() const override;
    
};


