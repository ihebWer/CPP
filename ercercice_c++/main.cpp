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




    User& u1 = User::get(5);
    User& u2 = User::get(10);
    std::cout << "U2 ID: " << u2.getId() << std::endl; // -> 1 au lieu de 10
    u1.setId(9999);
    std::cout << "U1 ID: " << u2.getId() << std::endl;
    // u2 a maintenant l'id 9999 alors qu'il a été modifié pour u1

    return 0;
}

// Il manque la partie avec les exercices en C
