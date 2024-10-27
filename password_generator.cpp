#include <iostream>
#include <random>
#include <string>
// Nourine this is for you.
// I love you SO MUCH
std::string generateSecurePassword(int length) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*";
    std::random_device rd; 
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        password += characters[distribution(generator)];
    }
    return password;
}

int main() {
    int length;
    std::cout << "Enter the desired password length: ";
    std::cin >> length;

    if (length < 1) {
        std::cerr << "Password length must be greater than 0." << std::endl;
        return 1;
    }

    std::string password = generateSecurePassword(length);
    std::cout << "Generated Secure Password: " << password << std::endl;

    return 0;
}
