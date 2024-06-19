#include <iostream>
#include <limits>
#include "Room.h"
#include "Picture.h"
#include "Sculpture.h"
#include "ScientificInstrument.h"
#include "ArchelogicalExhibit.h"
#include "VolumeExhibit.h"
namespace console {
    void clearConsoleScreen() {
        std::cout << "\033[2J\033[1;1H";
    }
}

void processRoom(Room*& room) {
    double length, width, height;

    try {
        console::clearConsoleScreen();
        std::cout << "\nPlease create the room and enter main parameters:" << std::endl;
        std::cout << "Length of the room = ";
        std::cin >> length;
        std::cout << "Width of the room = ";
        std::cin >> width;
        std::cout << "Height of the room = ";
        std::cin >> height;

        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Please enter numeric values for dimensions.");
        }

        if (room) {
            std::cout << "Room has already been created!" << std::endl;
            return;
        }

        room = new Room(length, width, height, 0, 0, 0);

        room->allArea();
        std::cout << room->Info() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

Picture processPicture() {
    std::string author, country, name;
    int year;
    double length, width;

    try {
        std::cout << "Enter exhibit details:" << std::endl;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Country: ";
        std::getline(std::cin, country);

        std::cout << "Year: ";
        std::cin >> year;

        std::cout << "Length: ";
        std::cin >> length;

        std::cout << "Width: ";
        std::cin >> width;

        std::cout << "Is the author known? 1 - yes, 2 - no: ";
        int option;
        std::cin >> option;

        if (option != 1 && option != 2) {
            throw std::invalid_argument("Invalid option. Please enter 1 or 2.");
        }
        std::cin.ignore();
        if (option == 1) {
            std::cout << "Author: ";
            std::getline(std::cin, author);
            Picture picture(author, country, name, year, width, length);
            std::cout << std::endl << picture.Info() << std::endl;

            return picture;
        }
        else {
            Picture picture(name, country, year, width, length);
            std::cout << std::endl << picture.Info() << std::endl;

            return picture;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Picture("", " ", 0, 0, 0);
}

void processSculpture(Room* room) {
    std::string author, country, name;
    int year;
    double length, width, height;

    try {
        std::cout << "Enter sculpture details:" << std::endl;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Country: ";
        std::getline(std::cin, country);

        std::cout << "Year: ";
        std::cin >> year;

        std::cout << "Length: ";
        std::cin >> length;

        std::cout << "Width: ";
        std::cin >> width;

        std::cout << "Height: ";
        std::cin >> height;

        Sculpture sculpture(author, country, name, year, width, height, length);

        if (room->addExhibit(sculpture)) {
            std::cout << "Sculpture added to the room." << std::endl;
        }
        else {
            std::cerr << "Error adding sculpture to the room." << std::endl;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void processScientificInstrument(Room* room) {
    std::string author, country, name;
    int year;
    double length, width, height;

    try {
        std::cout << "Enter scientific instrument details:" << std::endl;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Country: ";
        std::getline(std::cin, country);

        std::cout << "Year: ";
        std::cin >> year;

        std::cout << "Length: ";
        std::cin >> length;

        std::cout << "Width: ";
        std::cin >> width;

        std::cout << "Height: ";
        std::cin >> height;

        ScientificInstrument instrument(author, country, name, year, width, height, length);

        if (room->addExhibit(instrument)) {
            std::cout << "Scientific instrument added to the room." << std::endl;
        }
        else {
            std::cerr << "Error adding scientific instrument to the room." << std::endl;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void processArchaeologicalArtifact(Room* room) {
    std::string author, country, name;
    int year;
    double length, width, height;

    try {
        std::cout << "Enter archaeological artifact details:" << std::endl;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Country: ";
        std::getline(std::cin, country);

        std::cout << "Year: ";
        std::cin >> year;

        std::cout << "Length: ";
        std::cin >> length;

        std::cout << "Width: ";
        std::cin >> width;

        std::cout << "Height: ";
        std::cin >> height;

        ArchaeologicalArtifact artifact(author, country, name, year, width, height, length);

        if (room->addExhibit(artifact)) {
            std::cout << "Archaeological artifact added to the room." << std::endl;
        }
        else {
            std::cerr << "Error adding archaeological artifact to the room." << std::endl;
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    Room* room = nullptr;

    std::cout << "\t\tHello! This is my individual task - class hierarchy of Museum " << std::endl;
    std::cout << "\t\tPress enter to start" << std::endl;
    std::cin.get();
    console::clearConsoleScreen();
    int option;
    do {
        std::cout << "\n\tPress key '1' to create a room." <<
            "\n\tPress key '2' to create an exhibit." <<
            "\n\tPress key '3' to display exhibits in the room." <<
            "\n\tPress key '4' to display room info." <<
            "\n\tPress key '5' to exit." << std::endl;
        std::cin >> option;

        switch (option) {
        case 1:
            processRoom(room);
            std::cin.get();
            break;
        case 2:
            if (room == nullptr) {
                std::cout << "You need to create a room first!" << std::endl;
                break;
            }
            std::cout << "Enter the number of exhibit do you want to create? " << std::endl;
            std::cout << "1. Picture" << std::endl;
            std::cout << "2. Sculpture" << std::endl;
            std::cout << "3. Scientific Instrument" << std::endl;
            std::cout << "4. Archaeological Artifact" << std::endl;
            int optionEx;
            std::cin >> optionEx;
            switch (optionEx) {
            case 1: {
                Picture picture = processPicture();
                if (!room->addExhibit(picture)) {
                    std::cerr << "There was an error adding the picture to the room." << std::endl;
                }
                break;
            }
            case 2: {
                processSculpture(room);
                break;
            }
            case 3: {
                processScientificInstrument(room);
                break;
            }
            case 4: {
                processArchaeologicalArtifact(room);
                break;
            }
            default:
                std::cerr << "Invalid option." << std::endl;
                break;
            }
            break;
        case 3:
            if (room == nullptr) {
                std::cout << "You need to create a room first!" << std::endl;
                break;
            }
            room->displayExhibitsInfo();
            break;
        case 4:
            if (room == nullptr) {
                std::cout << "You need to create a room first!" << std::endl;
                break;
            }
            std::cout << room->Info() << std::endl;
            break;
        case 5:
            std::cout << "Exiting program..." << std::endl;
            break;
        default:
            std::cerr << "Invalid option. Please enter a number from 1 to 5." << std::endl;
            break;
        }

    } while (option != 5);

    delete room;
    return 0;
}
