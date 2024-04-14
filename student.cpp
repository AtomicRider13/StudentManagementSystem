#include "student.h"
#include "utilities.h"
#include <iostream>

Student::Student(std::string first, std::string last, int id, std::vector<Course> courses) {
    firstName = first;
    lastName = last;
    studentID = id;
    enrolledCourses = courses;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

int Student::getStudentID() const {
    return studentID;
}

std::vector<Course> Student::getCourses() const {
    return enrolledCourses;
}

void Student::enrollInCourse(std::string courseID) {
    // Check if the course is already enrolled
    for (const auto& course : enrolledCourses) {
        if (course.getCourseSymbol() == courseID) {
            std::cout << "Student is already enrolled in course " << courseID << std::endl;
            Utilities::waitForEnter();
            Utilities::clearScreen();
            return;
        }
    }

    // Find the course in the course list
    for (const auto& course : Utilities::courses) {
        if (course.getCourseSymbol() == courseID) {
            enrolledCourses.push_back(course);
            std::cout << "Student enrolled in course " << courseID << std::endl;
            Utilities::waitForEnter();
            Utilities::clearScreen();
            return;
        } 
    }

    // If the course is not found in the course list
    std::cout << "Course " << courseID << " not found" << std::endl;   
    Utilities::waitForEnter();
    Utilities::clearScreen();
}


void Student::disenrollfromCourse(std::string courseID) {
    // Use std::remove_if and lambda function to find and remove the course
    enrolledCourses.erase(std::remove_if(enrolledCourses.begin(), enrolledCourses.end(),
                                         [courseID](const Course& course) {
                                             return course.getCourseSymbol() == courseID;
                                         }),
                          enrolledCourses.end());

    // Check if the course was found and removed
    if (std::count_if(enrolledCourses.begin(), enrolledCourses.end(),
                      [courseID](const Course& course) {
                          return course.getCourseSymbol() == courseID;
                      }) == 0) {
        std::cout << "Student disenrolled from course " << courseID << std::endl;
    } else {
        std::cout << "Student is not enrolled in course " << courseID << std::endl;
    }
    Utilities::waitForEnter();
    Utilities::clearScreen();
}


void Student::setFirstName(std::string first) {
    firstName = first;
}

void Student::setLastName(std::string last) {
    lastName = last;
}

void Student::setStudentID(int id) {
    studentID = id;
}
