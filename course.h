#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string courseSymbol;
    std::string courseName;

public:
    Course(std::string courseSymbol, std::string courseName);
    std::string getCourseSymbol() const;
    std::string getCourseName() const;
    void setCourseSymbol(std::string symbol);
    void setCourseName(std::string name);
};

#endif
