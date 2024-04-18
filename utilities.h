#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include "student.h"
#include "course_catalog.h"

namespace Utilities {

    // Declare CourseCatalog object
    extern CourseCatalog courseCatalog;

    // Declare utility functions
    void initializeData();
    void clearScreen();
    void login();
    void enroll();
    void disenroll();
    void viewStudentRoster();
    void viewStudentRecord();
    void enrollStudentIntoCourse(int studentID);
    void disenrollStudentFromCourse(int studentID);
    void courseCatalogMenu();
    void viewCourseCatalog();
    void addCourseToCatalog();
    void removeCourseFromCatalog();
    void waitForEnter();

    // Declare external variables
    extern int nextId;
    extern int selection;
    extern std::string username;
    extern std::string password;
    extern bool authenticated;
    extern std::vector<Student> students;
    extern std::vector<Course> courses;

}

#endif
