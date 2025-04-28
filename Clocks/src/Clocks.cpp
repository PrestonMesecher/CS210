// Author: Preston Mesecher
// Course: CS210
// Date: 03.23.2025
// This program takes a user input for time, allows for adding an hour, minute, and second, then outputs time in 12-hour and 24-hour formats.

#include <iostream>
#include <string>

using namespace std;

// Declare functions
void displayClocks(int hour, int minute, int second);
void displayMenu();
void addOneHour(int& hour);
void addOneMinute(int& minute, int& hour);
void addOneSecond(int& second, int& minute, int& hour);
string formatTime(int value);
void getUserTime(int& hour, int& minute, int& second);

int main() {
    // Initialize Variables
    int hour, minute, second;
    int choice = 1;

    // Call function to get initial input
    getUserTime(hour, minute, second);
    // Clear console after input
    system("cls");

    // Loop until user selects exit
    while (true) {

        // Only display clocks on valid input
        if (choice >= 1 && choice <= 4) {
            displayClocks(hour, minute, second);
        }
        cout << endl;

        // Display menu for user input
        displayMenu();

        cin >> choice;

        // Switch between, add hour, add minute, add second, and exit
        switch (choice) {
        case 1: // Add hour
            system("cls");
            cout << "One hour added!" << endl;
            addOneHour(hour);
            break;
        case 2: // Add minute
            system("cls");
            cout << "One minute added!" << endl;
            addOneMinute(minute, hour);
            break;
        case 3: // Add second
            system("cls");
            cout << "One second added!" << endl;
            addOneSecond(second, minute, hour);
            break;
        case 4: // Add exit
            cout << "Exiting program..." << endl;
            return 0;
        default:
            system("cls");
            cout << "Enter your choice : " << choice << endl;
            cout << "Invalid selection. Please choose 1-4." << endl;
            
            // Ensure valid input and clear cin value
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    return 0;
}


void getUserTime(int& hour, int& minute, int& second) {
    cout << "Enter starting time in 24-hour format." << endl;

    // Loop until valid initial input
    while (true) {
        // Get hour
        cout << "Hour (0-23): ";
        cin >> hour;
        if (cin.fail() || hour < 0 || hour > 23) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid hour. Try again." << endl;
            continue;
        }

        // Get minute
        cout << "Minute (0-59): ";
        cin >> minute;
        if (cin.fail() || minute < 0 || minute > 59) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid minute. Try again." << endl;
            continue;
        }

        // Get second
        cout << "Second (0-59): ";
        cin >> second;
        if (cin.fail() || second < 0 || second > 59) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid second. Try again." << endl;
            continue;
        }

        break;
    }
}

void displayClocks(int hour, int minute, int second) {
    // Convert to 12-hour format
    int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;

    // Determine AM or PM
    string ampm = (hour < 12 || hour == 24) ? "A M" : "P M";

    // Format and output clocks in expected style
    cout << "**************************     **************************" << endl;
    cout << "*     12-Hour Clock      *     *     24-Hour Clock      *" << endl;
    cout << "*      "
        << formatTime(hour12) << ":"
        << formatTime(minute) << ":"
        << formatTime(second) << " " << ampm
        << "      *     *       "
        << formatTime(hour) << ":"
        << formatTime(minute) << ":"
        << formatTime(second)
        << "         *" << endl;
    cout << "**************************     **************************" << endl;
    cout << endl;
}


void displayMenu() {
    // Display menu
    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
    cout << "Enter your choice: ";
}


void addOneHour(int& hour) {
    // Add hour
    hour = (hour + 1) % 24;
}

void addOneMinute(int& minute, int& hour) {
    // Add minute and roll over hour if minutes hits 60
    minute++;
    if (minute >= 60) {
        minute = 0;
        addOneHour(hour);
    }
}


void addOneSecond(int& second, int& minute, int& hour) {
    // Add second and roll over minute if seconds hits 60
    second++;
    if (second >= 60) {
        second = 0;
        addOneMinute(minute, hour);
    }
}

string formatTime(int value) {
    // Format with leading zero for single digit entry
    return (value < 10 ? "0" : "") + to_string(value);
}
