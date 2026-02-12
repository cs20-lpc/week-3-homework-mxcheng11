#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    std::string location;

public:
    Course();
    Course(const std::string& n, const std::string& l);

    friend std::ostream& operator<<(std::ostream&, const Course&);
};

#endif // COURSE_HPP