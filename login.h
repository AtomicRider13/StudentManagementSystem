#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login {
public:
    static bool authenticate (const std::string& username, const std::string& password);
};

#endif
