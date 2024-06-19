#include "Room.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Picture.h"
#include "VolumeExhibit.h"

Room::Room(double length, double width, double height, double usableWallArea, double usableFloorArea, double allRoomArea)
    : length(length), width(width), height(height), usableWallArea(usableWallArea), usableFloorArea(usableFloorArea), allRoomArea(allRoomArea),
    remainingFloorArea(usableFloorArea), remainingWallArea(usableWallArea / 4) {
    if (length <= 0 || width <= 0 || height <= 0) {
        throw std::invalid_argument("All room dimensions and areas must be positive.");
    }
    if (usableWallArea > allRoomArea) {
        throw std::invalid_argument("Wall area must not exceed the total area of the room.");
    }
}

double Room::floorArea() {
    usableFloorArea = length * width;
    remainingFloorArea = usableFloorArea;
    return usableFloorArea;
}

double Room::wallArea() {
    usableWallArea = (length * height + width * height) * 2;
    remainingWallArea = usableWallArea / 4;
    return usableWallArea;
}

double Room::allArea() {
    allRoomArea = (floorArea() * 2) + wallArea();
    return allRoomArea;
}

bool Room::addExhibit(const Exhibit& exhibit) {
    double exhibitArea = exhibit.getArea();
    if (canFitExhibit(exhibitArea)) {
        if (const Picture* picture = dynamic_cast<const Picture*>(&exhibit)) {
            double pictureArea = picture->getArea();
            if (remainingWallArea <= 0) {
                std::cerr << "Error: You can`t create an exhibit." << std::endl;
                return false;
            }
            remainingWallArea -= pictureArea;
            exhibits.push_back(exhibit);
            return true;
        }
        else if (const VolumeExhibit* volumeExhibit = dynamic_cast<const VolumeExhibit*>(&exhibit)) {
            double volumeArea = volumeExhibit->getVolArea();
            if (remainingFloorArea <= 0) {
                std::cerr << "Error: You can`t create an exhibit." << std::endl;
                return false;
            }
            remainingFloorArea -= volumeArea;
            exhibits.push_back(exhibit);
            return true;
        }
    }

    std::cerr << "Error: Exhibit does not fit in the room." << std::endl;
    return false;
}

bool Room::canFitExhibit(double exhibitArea) const {
    return exhibitArea <= remainingFloorArea;
}

void Room::displayExhibitsInfo() const {
    std::cout << "Exhibits in the room:" << std::endl;
    for (const auto& exhibit : exhibits) {
        std::cout << exhibit.Info() << std::endl;
    }
}

std::string Room::Info() const {
    std::ostringstream result;
    result << "\nParameters of the room:" << std::endl;
    result << "Floor area = " << usableFloorArea << " sq meters" << std::endl;
    result << "Wall area = " << usableWallArea << " sq meters" << std::endl;
    result << "All area of the room = " << allRoomArea << " sq meters" << std::endl;
    result << "Remaining floor area = " << remainingFloorArea << " sq meters" << std::endl;
    result << "Remaining wall area = " << remainingWallArea << " sq meters" << std::endl;
    result << "Number of exhibits = " << exhibits.size() << std::endl;
    return result.str();
}

int Room::getExhibitCount() const {
    return exhibits.size();
}
