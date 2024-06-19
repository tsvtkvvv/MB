#include <iostream>
#include <limits>
#include "Room.h"
#include "Picture.h"
#include "Sculpture.h"
#include "ScientificInstrument.h"
#include "VolumeExhibit.h"
#include "ArchelogicalExhibit.h"

namespace console {
    void clearConsoleScreen() {
        std::cout << "\033[2J\033[1;1H";
    }
}

using namespace std;

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

        if (room) {
            cout << "Room has already been created!" << endl;
            return;
        }

        room = new Room(length, width, height, 0, 0, 0);

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
            cout << "Type: Picture" << endl; 
            return picture;
        }
        else {
            Picture picture(name, country, year, width, length);
            cout << endl << picture.Info() << endl;
            cout << "Type: Picture" << endl; 
            return picture;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Picture("", "", 0, 0, 0);
}

void processSculpture(Room* room) {
    string author, country, name;
    int year;
    double length, width, height;

    try {
        cout << "Enter sculpture details:" << endl;
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


        Sculpture sculpture(author, country, name, year, width, height, length);

        if (room->addExhibit(sculpture)) {
            cout << "Sculpture added to the room." << endl;
            cout << "Type: Sculpture" << endl; 
        }
        else {
            cerr << "Error adding sculpture to the room." << endl;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void processScientificInstrument(Room* room) {
    string author, country, name;
    int year;
    double length, width, height;

    try {
        cout << "Enter scientific instrument details:" << endl;
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

        ScientificInstrument instrument(author, country, name, year, width, height, length);

        if (room->addExhibit(instrument)) {
            cout << "Scientific instrument added to the room." << endl;
            cout << "Type: Scientific Instrument" << endl; 
        }
        else {
            cerr << "Error adding scientific instrument to the room." << endl;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void processArchaeologicalArtifact(Room* room) {
    string author, country, name;
    int year;
    double length, width, height;

    try {
        cout << "Enter archaeological artifact details:" << endl;
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

        ArchaeologicalArtifact artifact(author, country, name, year, width, height, length);

        if (room->addExhibit(artifact)) {
            cout << "Archaeological artifact added to the room." << endl;
            cout << "Type: Archaeological Artifact" << endl; 
        }
        else {
            cerr << "Error adding archaeological artifact to the room." << endl;
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        case 2:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
                break;
            }
            cout << "Enter the number of exhibit do you want to create? " << endl;
            cout << "1. Picture" << endl;
            cout << "2. Sculpture" << endl;
            cout << "3. Scientific Instrument" << endl;
            cout << "4. Archaeological Artifact" << endl;
            int optionEx;
            cin >> optionEx;
            switch (optionEx) {
            case 1: {
                Picture picture = processPicture();
                if (!room->addExhibit(picture)) {
                    cerr << "There was an error adding the picture to the room." << endl;
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
                cerr << "Invalid option." << endl;
                break;
            }
            break;
        case 3:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
                break;
            }
            room->displayExhibitsInfo();
            break;
        case 4:
            if (room == nullptr) {
                cout << "You need to create a room first!" << endl;
                break;
            }
            cout << room->Info() << endl;
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cerr << "Invalid option. Please enter a number from 1 to 5." << endl;
            break;
        }

    } while (option != 5);

    delete room; 
    return 0;
}
