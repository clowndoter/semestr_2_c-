#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool validatePassword(string password) {
    bool valid = true;

    if (password.length() < 8) {
        cout << "The password must be 8 characters long" << endl;
        valid = false;
    }
    
    if (regex_search(password, regex("[A-Z]")) == false) {
        cout << "The password must have at least one upper case letter" << endl;
        valid = false;
    }
    
    if (regex_search(password, regex("[a-z]")) == false) {
        cout << "The password must have at least one lower case letter" << endl;
        valid = false;
    }
    
    if (regex_search(password, regex("[0-9]")) == false) {
        cout << "The password must have at least one digit" << endl;
        valid = false;
    }
    
    if (regex_search(password, regex("[!@#$%^&*(),.?\":{}|<>]")) == false) {
        cout << "The password must have at least one special character" << endl;
        valid = false;
    }
    
    return valid;
}

int main() {
    string password;
    bool valid = false;
    
    while (!valid) {
        cout << "Enter a password: ";
        getline(cin, password);
    
        if (validatePassword(password)) {
            cout << "The password is valid." << endl;
            valid = true;
        } else {
            cout << "Invalid password. Please try again." << endl;
        }
    }
    
    return 0;
}
