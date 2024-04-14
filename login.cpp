#include "login.h"

bool Login::authenticate(const std::string& username, const std::string& password) {
    if (username == "admin" && password == "password") {
        return true;
    } else {
        return false;
    }
}
