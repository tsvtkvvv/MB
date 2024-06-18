#pragma once
#include <vector>
#include "Exhibit.h"

class Room {
private:
    double length, width, height, usableWallArea, usableFloorArea, allRoomArea;
    double remainingFloorArea, remainingWallArea;
    std::vector<Exhibit> exhibits;

public:
    Room(double length, double width, double height, double usableWallArea, double usableFloorArea, double allRoomArea);

    double floorArea();
    double wallArea();
    double allArea();
    bool canFitExhibit(double exhibitArea) const;
    bool addExhibit(const Exhibit& exhibit);
    void displayExhibitsInfo() const;
    std::string Info() const;
    int getExhibitCount() const; 
};
