#include <iostream>
#include <limits>
#include "LinkedList.hpp"
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

int main() {
    LinkedList<Student> students;
    int choice;

    do {
        cout << "\n1. Insert Student\n"
             << "2. Delete Student\n"
             << "3. Search Student\n"
             << "4. Display All\n"
             << "5. Count Students\n"
             << "6. Add a course\n"
             << "7. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eat newline
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            students.append(Student(id, name, gpa));
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < students.getLength(); ++i) {
                if (students.getElement(i).getId() == id) {
                    students.remove(i);
                    cout << "Deleted student with ID " << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found\n";
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < students.getLength(); ++i) {
                if (students.getElement(i).getId() == id) {
                    cout << "Found:\n" << students.getElement(i) << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found\n";
        }
        else if (choice == 4) {
            cout << "Students in List:\n";
            cout << students << endl;
        }
        else if (choice == 5) {
            cout << "Total students: " << students.getLength() << endl;
        }
        else if (choice == 6) {
            int id;
            string cname, loc;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Course Name: ";
            getline(cin, cname);
            cout << "Enter location: ";
            getline(cin, loc);

            bool found = false;
            for (int i = 0; i < students.getLength(); ++i) {
                if (students.getElement(i).getId() == id) {
                    students.getElement(i).addCourse(Course(cname, loc));
                    cout << "Course added to student " << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found\n";
        }
        else if (choice != 7) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}