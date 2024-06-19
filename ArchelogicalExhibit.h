#pragma once
#include "VolumeExhibit.h"

class ArchaeologicalArtifact : public VolumeExhibit {
public:
    ArchaeologicalArtifact(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length);
    ArchaeologicalArtifact(const std::string& country, const std::string& name, int year, double width, double height, double length);

     std::string Info() const override;
     double getVolArea() const override;
};
