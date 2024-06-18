#pragma once
#include <string>

class Exhibit {
private:
    std::string author;
    std::string country;
    std::string name;
    int year;

public:
    Exhibit(const std::string& author, const std::string& country, const std::string& name, int year);
    Exhibit(const std::string& name, const std::string& country, int year);
    virtual double getArea() const;
    virtual std::string Info() const;
};
