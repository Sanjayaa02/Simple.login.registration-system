#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Global variable to store the currently logged-in user
string loggedInUser = "";

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    // Check if the username already exists
    ifstream inFile("users.txt");
    string existingUsername;
    while (inFile >> existingUsername) {
        if (existingUsername == username) {
            cout << "Username already exists. Please choose a different one.\n";
            return;
        }
    }
    inFile.close();

    cout << "Enter a password: ";
    cin >> password;

    // Save the new user to the file
    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "Registration successful.\n";
}

// Function to validate user login
bool loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream inFile("users.txt");
    string storedUsername, storedPassword;

    while (inFile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            loggedInUser = username; // Set the currently logged-in user
            cout << "Login successful. Welcome, " << loggedInUser << "!\n";
            inFile.close();
            return true;
        }
    }

    cout << "Invalid username or password. Please try again.\n";
    inFile.close();
    return false;
}

int main() {
    int choice;

    do {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Show Saved Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // Do something after successful login
                    // For example, you can call another function or perform other tasks
                }
                break;
            case 3:
                if (!loggedInUser.empty()) {
                    cout << "Currently logged-in user: " << loggedInUser << endl;
                } else {
                    cout << "No user is currently logged in.\n";
                }
                break;
            case 4:
                cout << "Exiting program, Thank You.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
