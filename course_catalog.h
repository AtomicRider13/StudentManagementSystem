#ifndef COURSE_CATALOG_H
#define COURSE_CATALOG_H

#include "course.h"
#include <string>
#include <vector>

class CourseCatalog {
private:
    std::vector<Course> courses;

public:
    CourseCatalog();
    void addCourse(const Course& course);
    Course getCourseByID(const std::string& courseID) const;
    void printCatalog() const;
};

#endif
