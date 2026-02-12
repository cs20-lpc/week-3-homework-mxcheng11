#include "Student.hpp"

Student::Student() : id(0), name(""), gpa(0.0) {}
Student::Student(int i, const std::string& n, double g) : id(i), name(n), gpa(g) {}

int Student::getId() const { return id; }

void Student::addCourse(const Course& c) {
    courses.append(c);
}

bool Student::hasCourses() const {
    return !courses.isEmpty();
}

const LinkedList<Course>& Student::getCourses() const {
    return courses;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << s.id << " " << s.name << " " << s.gpa;
    if (s.courses.isEmpty()) {
        out << " None";
    } else {
        out << "\n  Courses:\n";
        // indent courses for nicer output
        const LinkedList<Course>& cl = s.getCourses();

        // We'll print each course on its own indented line
        // Using the LinkedList operator<< would print without indentation;
        // so iterate via getElement(index).
        for (int i = 0; i < cl.getLength(); ++i) {
            out << "   " << cl.getElement(i);
            if (i != cl.getLength() - 1) out << "\n";
        }
    }
    return out;
}