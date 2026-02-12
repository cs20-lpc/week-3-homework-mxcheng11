#include "Course.hpp"

Course::Course() : name(""), location("") {}
Course::Course(const std::string& n, const std::string& l) : name(n), location(l) {}

std::ostream& operator<<(std::ostream& out, const Course& c) {
    out << c.name << " " << c.location;
    return out;
}