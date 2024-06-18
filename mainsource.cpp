#include <iostream>
#include <limits>
#include "Room.h"
#include "Exhibit.h"
#include "Picture.h"
#include "VolumeExhibit.h"

using namespace std;

namespace console {
    void clearConsoleScreen() {
        cerr << "\033[2J\033[1;1H";
    }
}

void processRoom(Room*& room) {
    double length, width, height;

    try {
        console::clearConsoleScreen();
        cout << "\nPlease create the room and enter main parameters:" << endl;
        cout << "Length of the room = ";
        cin >> length;
        cout << "Width of the room = ";
        cin >> width;
        cout << "Height of the room = ";
        cin >> height;

        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter numeric values for dimensions.");
        }

        room = new Room(length, width, height, 0, 0, 0);

        
        room->floorArea();
        room->wallArea();
        room->allArea();

        cout << room->Info() << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

Picture processPicture() {
    string author, country, name;
    int year;
    double length, width;

    try {
        cout << "Enter exhibit details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Country: ";
        getline(cin, country);

        cout << "Year: ";
        cin >> year;

        cout << "Length: ";
        cin >> length;

        cout << "Width: ";
        cin >> width;

        cout << "Is the author known? 1 - yes, 2 - no: ";
        int option;
        cin >> option;

        if (option != 1 && option != 2) {
            throw invalid_argument("Invalid option. Please enter 1 or 2.");
        }
        cin.ignore();
        if (option == 1) {
            cout << "Author: ";
            getline(cin, author);
            Picture picture(author, country, name, year, width, length);
            cout << endl << picture.Info() << endl;

            return picture;
        }
        else {
            Picture picture(name, country, year, width, length);
            cout << endl << picture.Info() << endl;

            return picture;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Picture("", "", "", 0, 0, 0);
}

void processVolumeExhibit(Room* room) {
    string name, country, author;
    int year;
    double length, width, height;

    try {
        cout << "Enter Volume Exhibit details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Country: ";
        getline(cin, country);

        cout << "Year: ";
        cin >> year;

        cout << "Length: ";
        cin >> length;

        cout << "Width: ";
        cin >> width;

        cout << "Height: ";
        cin >> height;

        cin.ignore(); 

        cout << "Is the author known? 1 - yes, 2 - no: ";
        int option;
        cin >> option;

        if (option != 1 && option != 2) {
            throw invalid_argument("Invalid option. Please enter 1 or 2.");
        }

        cin.ignore(); 

        if (option == 1) {
            cout << "Author: ";
            getline(cin, author);
            VolumeExhibit volumeExhibit(author, country, name, year, width, height, length);
            cout << endl << volumeExhibit.Info() << endl;

            if (!room->addExhibit(volumeExhibit)) {
                cout << "Exhibit does not fit in the room." << endl;
            }
        }
        else {
            VolumeExhibit volumeExhibit(name, country, year, width, height, length);
            cout << endl << volumeExhibit.Info() << endl;

            if (!room->addExhibit(volumeExhibit)) {
                cout << "Exhibit does not fit in the room." << endl;
            }
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Room* room = nullptr;

    cout << "\t\tHello! This is my individual task - class hierarchy of Museum " << endl;
    cout << "\t\tPress enter to start" << endl;
    cin.get();
    console::clearConsoleScreen();
    int option;
    do {
        cout << "\n\tPress key '1' to create a room." <<
            "\n\tPress key '2' to create an exhibit." <<
            "\n\tPress key '3' to display exhibits in the room." <<
            "\n\tPress key '4' to display room info." <<
            "\n\tPress key '5' to exit." << endl;
        cin >> option;

        switch (option) {
        case 1:
            processRoom(room);
            cin.get();
            break;
        case 2:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
                break;
            }
            cout << "Enter the number of exhibit do you want to create? " << endl;
            cout << "1. Picture" << endl;
            cout << "2. Volume Exhibit" << endl;
            int optionEx;
            cin >> optionEx;
            switch (optionEx) {
            case 1: {
                Picture picture = processPicture();
                if (!room->addExhibit(picture)) {
                    cout << "Exhibit does not fit in the room." << endl;
                }
                cin.get();
                console::clearConsoleScreen();
                break;
            }
            case 2:
                processVolumeExhibit(room);
                cin.get();
                console::clearConsoleScreen();
                break;
            default:
                cerr << "Invalid option. Please enter 1 or 2." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            break;
        case 3:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
            }
            else {
                room->displayExhibitsInfo();
            }
            break;
        case 4:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
            }
            else {
                cout << room->Info() << endl;
            }
            break;
        case 5:
            cout << "Exiting program...." << endl;
            break;
        default:
            cerr << "Invalid option. Please enter 1, 2, 3, 4, or 5." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (option != 5);

    delete room;

    return 0;
}
