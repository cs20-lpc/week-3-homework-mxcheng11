#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Course.hpp"

class Student {
private:
    int id;
    std::string name;
    double gpa;
    LinkedList<Course> courses;

public:
    Student();
    Student(int, const std::string&, double);

    int getId() const;
    void addCourse(const Course&);
    bool hasCourses() const;
    const LinkedList<Course>& getCourses() const;

    friend std::ostream& operator<<(std::ostream&, const Student&);
};

#endif // STUDENT_HPP