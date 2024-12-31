#include "user.hpp"
#include "password.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

User::User(int id, Password &password) 
    : id(id), password(std::make_unique<Password>(password)) {
    is_logged_in = false;
}

void User::save() {
    std::ofstream file("users.db", std::ios::app);
    if (file.is_open()) {
        file << id << " " << password->str() << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for saving!" << std::endl;
    }
}

int User::login(char *raw_password) {
    Password temp_password(raw_password, false);
    if (*password == temp_password) {
        is_logged_in = true;
        return 1; // Login successful
    }
    return 0; // Login failed
}

User &User::get(int id) {
    static User user(0, *(new Password("", true))); // Dummy initialization
    std::ifstream file("users.db");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            int user_id;
            std::string encrypted_password;
            if (iss >> user_id >> encrypted_password && user_id == id) {
                Password pwd(encrypted_password, true);
                user = User(user_id, pwd);
                break;
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file for reading!" << std::endl;
    }
    return user;
}
