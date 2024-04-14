#ifndef STUDENT_H
#define STUDENT_H

#include "course.h"
#include <string>
#include <vector>

class Student {
private:
    std::string firstName;
    std::string lastName;
    int studentID;
    std::vector<Course> enrolledCourses;

public:
    Student(std::string first, std::string last, int id, std::vector<Course> courses);
    std::string getFirstName() const;
    std::string getLastName() const;
    int getStudentID() const;
    std::vector<Course> getCourses() const;
    void enrollInCourse(std::string courseID);
    void disenrollfromCourse(std::string courseID);
    void setFirstName(std::string first);
    void setLastName(std::string last);
    void setStudentID(int id);
};

#endif
