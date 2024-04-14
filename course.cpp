#include "course.h"

Course::Course(std::string courseSymbol, std::string courseName) {
    this->courseSymbol = courseSymbol;
    this->courseName = courseName;
}

std::string Course::getCourseSymbol() const {
    return courseSymbol;
}

std::string Course::getCourseName() const {
    return courseName;
}

void Course::setCourseSymbol(std::string symbol) {
    courseSymbol = symbol;
}

void Course::setCourseName(std::string name) {
    courseName = name;
}
