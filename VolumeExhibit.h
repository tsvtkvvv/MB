#pragma once
#include "Exhibit.h"

class VolumeExhibit : public Exhibit {
protected:
    double width;
    double height;
    double length;

public:
    VolumeExhibit(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length);
    VolumeExhibit(const std::string& country, const std::string& name, int year, double width, double height, double length);

    virtual std::string Info() const override;
    virtual double getVolArea() const;

    virtual ~VolumeExhibit() {}
};
