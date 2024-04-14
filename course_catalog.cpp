#include "course_catalog.h"
#include <iostream>

CourseCatalog::CourseCatalog() {
    courses.push_back(Course("CSCI101", "Introduction to Computer Science"));
    courses.push_back(Course("MATH201", "Calculus I"));
    // Add more courses as needed
}

void CourseCatalog::addCourse(const Course& course) {
    courses.push_back(course);
}

Course CourseCatalog::getCourseByID(const std::string& courseID) const {
    for (const auto& course : courses) {
        if (course.getCourseSymbol() == courseID) {
            return course;
        }
    }
    return Course("", "");
}

void CourseCatalog::printCatalog() const {
    std::cout << "Course Catalog:\n";
    for (const auto& course : courses) {
        std::cout << course.getCourseSymbol() << ": " << course.getCourseName() << "\n";
    }
}
