#include "utilities.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace Utilities {
    int nextId = 1;
    string username;
    string password;
    bool authenticated = false;
    vector<Student> students;
    vector<Course> courses;
    CourseCatalog courseCatalog;

    std::string generateRandomString(int length) {
        const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        std::string result;
        for (int i = 0; i < length; ++i) {
            result += chars[rand() % chars.length()];
        }
        return result;
    }

    void initializeData() {
        // Initialize courses
        std::vector<Course> allCourses;
        int numCourses = 30;
        for (int i = 0; i < numCourses; ++i) {
            std::string courseSymbol = "COURSE" + std::to_string(i + 1);
            std::string courseName = "Course " + std::to_string(i + 1);
            allCourses.push_back(Course(courseSymbol, courseName));
        }

        // Initialize students
        std::vector<Student> allStudents;
        int numStudents = 50;
        int numCoursesPerStudent = 5;

        std::srand(std::time(nullptr)); // Seed the random number generator

        for (int i = 0; i < numStudents; ++i) {
            std::vector<Course> studentCourses;

            // Generate 5 random course indices
            std::vector<int> chosenIndices;
            for (int j = 0; j < numCoursesPerStudent; ++j) {
                int randomIndex;
                bool uniqueIndex = false;
                while (!uniqueIndex) {
                    randomIndex = std::rand() % allCourses.size();
                    if (std::find(chosenIndices.begin(), chosenIndices.end(), randomIndex) == chosenIndices.end()) {
                        chosenIndices.push_back(randomIndex);
                        uniqueIndex = true;
                    }
                }
                studentCourses.push_back(allCourses[randomIndex]);
            }

            std::string firstName = "Student" + std::to_string(i + 1);
            std::string lastName = generateRandomString(6); // Generate a random last name
            allStudents.push_back(Student(firstName, lastName, i + 1, studentCourses));
        }

        // Assign the initialized courses and students to the global vectors
        courses = allCourses;
        students = allStudents;

        // Debug output
        cout << "Initialized " << courses.size() << " courses." << endl;
        cout << "Initialized " << students.size() << " students." << endl;
    }

    void clearScreen() {
        // Platform-independent method to clear console
        #ifdef _WIN32
            system("cls");
        #else
            // Assume Unix-like system
            system("clear");
        #endif
    }

    void login() {
        do {
            clearScreen();
            cout << "Welcome to the Student Grade Management System (SGMS)\n";
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "Username: ";
            cin >> username;
            cout << endl;
            cout << "Password: ";
            cin >> password;
            if (username == "admin" && password == "password") {
                authenticated = true;
                clearScreen();
            } else {
                cout << "Incorrect username or password. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while(authenticated == false);  
    }
    
    void enroll() {
        clearScreen();
        string firstName;
        string lastName;
        vector<Course> courses;
        int studentId;
        
        cout << "Add Student" << endl;
        cout << endl;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "\nEnter Last Name: ";
        cin >> lastName;
        studentId=Utilities::nextId;
        
        Student student(firstName, lastName, Utilities::nextId++, courses);

        students.push_back(student);

        cout << "\nStudent enrolled successfully!\n";
        cout << endl;

        waitForEnter();
        clearScreen();
    }

    void disenroll() {
        clearScreen();
        int studentID;

        cout << "Remove Student" << endl;
        cout << "\nEnter Student ID: ";
        cin >> studentID;

        auto it = students.begin();

        while (it != students.end()) {
            if (it->getStudentID() == studentID) {
                it = students.erase(it);
                cout << "Student #" << studentID <<" has been disenrolled\n";
                waitForEnter();
                clearScreen();
            } else {
                it++;
            }
        }
    }

    void viewStudentRoster() {
        clearScreen();
        cout << left << setw(12) << "Student ID" << setw(20) << "Last Name" << "First Name" << endl;

        for(const auto& student : students) {
            cout << left << setw(12) << student.getStudentID() << setw(20) << student.getLastName() << student.getFirstName() << endl;
        }

        waitForEnter();
        clearScreen();
    }

    void viewStudentRecord() {
        clearScreen();
        int studentID;
        int selection;

        cout << "Student Records\n";
        cout << endl;
        cout << "Enter Student ID#: ";
        cin >> studentID;

        bool found = false;
        for (const auto& student : students) {
            if (student.getStudentID() == studentID) {
                found = true;
                cout << "Student: " << student.getLastName() << ", " << student.getFirstName() << "\n";
                cout << "\n";
                cout << "Courses: \n";
                cout << "\n";
                // Assuming the student has a vector of enrolled courses
                for (const auto& course : student.getCourses()) {
                    cout << left << setw(12) << course.getCourseSymbol() << setw(20) << course.getCourseName() << endl;
                }
                break; // Exit the loop once the student is found
            }
        }

        if (!found) {
            cout << "Student with ID#" << studentID << " not found.\n";
        }
        
        cout <<"\n1.Enroll in Course\n";
        cout <<"2.Disenroll from Course\n";
        cout <<"3.Return to Main Menu\n";
        cout << "\nEnter Selection: ";
        cin >> selection;

        do {
            switch (selection) {
                case 1: 
                    enrollStudentIntoCourse(studentID);
                    
                    return;
                case 2:
                    disenrollStudentFromCourse(studentID);
                    return;
                case 3:
                    clearScreen();
                    return;
                default:
                    cout << "\nIncorrect Selection. Try again.";
            }
        } while (selection != 3);
    }

    void enrollStudentIntoCourse(int studentID) {
        bool found = false;
        string courseID;

        cout << "Course enrollment for Student#: " << studentID << endl;
        cout << endl;
        cout << "Enter Course Symbol: ";
        cin >> courseID;

        for (auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.enrollInCourse(courseID);
                found = true;  // Update found flag to indicate that student was found
                break; // Exit the loop once the student is found and enrolled
            }
        }

        if (!found) {
            cout << "Student with ID " << studentID << " not found." << endl;
        }
    }


    void disenrollStudentFromCourse(int studentID) {
        bool found = false;
        string courseID;

        cout << "Enter Course Symbol: ";
        cin >> courseID;

        cout << "Course disenrollment for Student#: " << studentID << endl;
        cout << endl;

        for (auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.disenrollfromCourse(courseID);
                found = true;  // Update found flag to indicate that student was found
                break; // Exit the loop once the student is found and disenrolled
            }
        }

        if (!found) {
            cout << "Student with ID " << studentID << " not found." << endl;
        }
    }


    /*void courseCatalog() {
        int selection;
        do { 
            clearScreen();
            cout << "\nCourse Catalog\n";
            cout << "\n";
            cout << "1.View Course Offerings\n";
            cout << "2.Add Course to Catalog\n";
            cout << "3.Remove Course from Catalog\n";
            cout << "4.Return to Main Menu\n";
            cout << endl;
            cout << "Enter Selection: ";
            cin >> selection;

            switch(selection) {
                case 1:
                    viewCourseCatalog();
                    break;
                case 2:
                    addCourseToCatalog();
                    break;
                case 3:
                    removeCourseFromCatalog();
                    break;
                case 4:
                    clearScreen();
                    return; // Return to the main menu
                default:
                    cout << "\nIncorrect Entry. Try again.\n";
                    break;
            }
        } while (selection != 4); // Keep looping until the user chooses to return to the main menu

        clearScreen();
    }*/

    void viewCourseCatalog() {
        clearScreen();
        cout << "Course Catalog\n\n";
        string courseSymbol;
        string courseName;
        cout << left << setw(25) << "Course Symbol" << setw(30) << "Course Name\n";

        for(const auto& course : courses) {
            courseSymbol = course.getCourseSymbol();
            courseName = course.getCourseName();
            cout << endl;
            cout << left << setw(25) << courseSymbol << setw(30) << courseName << endl;
        }   

        waitForEnter();
        clearScreen();
    }


    void addCourseToCatalog() {
        clearScreen();
        string courseSymbol;
        string courseName;

        cout << "Add Course to Course Catalog\n\n";
        cout << "Course Symbol: ";
        cin >> courseSymbol;
        cout << "Course Name: ";
        cin >> courseName;

        Course course(courseSymbol, courseName);
        courses.push_back(course);

        cout << "Course successfully added to Course Catalog!\n";

        waitForEnter();
        clearScreen();
    }


    void removeCourseFromCatalog() {
        clearScreen();
        string courseSymbol;
        cout << "Remove Course from Course Catalog\n\n";
        cout << "Enter Course Symbol: ";
        cin >> courseSymbol;

        auto it = courses.begin();

        while (it != courses.end()) {
                if (it->getCourseSymbol() == courseSymbol) {
                    it = courses.erase(it);
                    cout << "Course " << courseSymbol <<" has been removed from the Course Catalog\n";
                    return;
                } else {
                    it++;
                }
        }

        waitForEnter();
        clearScreen();
    }

    void waitForEnter() {
        cout << "\nPress Enter to continue...";
        cin.ignore(); // Ignore any leftover characters in the input buffer
        cin.get();    // Wait for Enter key
        clearScreen();
    }

}
