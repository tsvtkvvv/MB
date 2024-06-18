#include "Room.h"
#include <iostream>
#include <exception>
#include <iomanip>
#include <sstream>

Room::Room(double length, double width, double height, double usableWallArea, double usableFloorArea, double allRoomArea) :
    length(length), width(width), height(height), usableWallArea(usableWallArea), usableFloorArea(usableFloorArea), allRoomArea(allRoomArea),
    remainingFloorArea(0), remainingWallArea(0) {
    if (usableWallArea > allRoomArea) {
        throw std::invalid_argument("Error! Wall area must be lower than all area of room.");
    }
    if (usableWallArea < 0 || allRoomArea < 0 || usableFloorArea < 0) {
        throw std::invalid_argument("Error! Area of wall, floor and of all room equal zero");
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
    return usableWallArea / 4;
}

double Room::allArea() {
    allRoomArea = (floorArea() * 2) + wallArea();
    return allRoomArea;
}

bool Room::canFitExhibit(double exhibitArea) const {
    return exhibitArea <= remainingFloorArea;
}

bool Room::addExhibit(const Exhibit& exhibit) {
    double exhibitArea = exhibit.getArea();
    if (canFitExhibit(exhibitArea)) {
        exhibits.push_back(exhibit);
        remainingFloorArea -= exhibitArea;
        return true;
    }
    std::cerr << "Error: Exhibit does not fit in the room.\n";
    return false;
}

void Room::displayExhibitsInfo() const {
    std::cout << "Exhibits in the room:" << std::endl;
    for (const auto& exhibit : exhibits) {
        std::cout << exhibit.Info() << std::endl;
    }
}

std::string Room::Info() const {
    std::ostringstream result;
    result << std::fixed << std::setprecision(2);
    result << "\nParameters of the room : ";
    result << "\nFloor area = " << usableFloorArea << " sq meters";
    result << "\nWall area = " << usableWallArea << " sq meters";
    result << "\nAll area of the room = " << allRoomArea << " sq meters";
    result << "\nRemaining floor area = " << remainingFloorArea << " sq meters";
    result << "\nRemaining wall area = " << remainingWallArea << " sq meters";
    result << "\nNumber of exhibits = " << exhibits.size(); 
    return result.str();
}

int Room::getExhibitCount() const {
    return exhibits.size();
}
