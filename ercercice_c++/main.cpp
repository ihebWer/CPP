#include "password.hpp"
#include "user.hpp"
#include <cassert>
#include <iostream>

int main() {
    Password pwd("toto", false);
    User user(1, pwd);

    // Test password encryption
    assert(pwd.str() != "toto"); // Password should be encrypted

    // Save user
    user.save();

    // Retrieve user and test login
    User* retrieved_user = &User::get(1); // Utilise un pointeur pour éviter la copie
    assert(retrieved_user->login("toto") == 1); // Utilise "->" pour accéder aux membres

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
