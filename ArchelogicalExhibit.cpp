#include "ArchelogicalExhibit.h"
#include <sstream>

ArchaeologicalArtifact::ArchaeologicalArtifact(const std::string& author, const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(author, country, name, year, width, height, length) {}

ArchaeologicalArtifact::ArchaeologicalArtifact(const std::string& country, const std::string& name, int year, double width, double height, double length)
    : VolumeExhibit(country, name, year, width, height, length) {}

std::string ArchaeologicalArtifact::Info() const {
    std::ostringstream oss;
    oss << VolumeExhibit::Info();
    oss << "Archaeological Artifact: " << std::endl;
    oss << "Dimensions: " << width << "x" << height << "x" << length << " meters" << std::endl;
    return oss.str();
}

double ArchaeologicalArtifact::getVolume() const {
    return width * height * length;
}
