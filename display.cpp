#include <iostream>
#include "console.hpp"

using namespace std;

bool inputException = false;
int input = 1;

void clearScreen(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

int userInputInt(bool* exception){
    int num;

    cin >> num;

    // Check for type mismatch of the input
    if (cin.fail()) 
    {
        // Clear the failbit and ignore the remaining input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        *exception = true;
    }
    else 
    {
        // Input is valid
        *exception = false;
    }

    return num;
}

void handleException()
{
    if (inputException)
    {
        cout << "Invalid input! Expected a number from the list." << endl;
        inputException = false;
    }
    else
        cout << endl;
}

void displayFoundDate(){
    while (input != 0 || inputException){
        clearScreen();
        Console* result = findConsole(root, input);
        if (result != NULL) {
            detectDates(result);
            inputException = false;
        } else {
            cout << "Console with release date " << input << " not found.\n";
        }

        cout << endl;
        handleException();
        cout << "0| Go to main menu" << endl;
        cout << "Or look for another console: ";
        input = userInputInt(&inputException);
        if(input != 0)
            inputException = true;
    }
}

void finder() {
    while (input != 0 || inputException) {
        clearScreen();
        cout << "Look for a release date" << endl << endl;
        handleException();
        cout << "0| Go to main menu -> ";
        input = userInputInt(&inputException);
        
        if (input != 0) 
            inputException = true;

        displayFoundDate();
    }
    input = 2;
}

void displayReleaseDates(){
    while (input != 0 || inputException){
        clearScreen();
        inOrderTraversal(root);
        cout << endl;
        handleException();
        cout << "0| Go to main menu? -> ";
        input = userInputInt(&inputException);
        if(input != 0)
            inputException = true;
    }
    input = 1;
}

void mainMenu()
{
    while (input != 0 || inputException)
    {
        clearScreen();
        cout << "          Welcome on Console BST!\n"
            << "-----------------------------------------\n"
            << "1| Display consoles\n"
            << "2| Find a console\n"
            << "0| Exit\n" << endl;
        handleException();

        cout << "Your choice -> ";
        input = userInputInt(&inputException);

        if(input == 1){
            displayReleaseDates();
        } else if (input == 2){
            finder();
        } else if (input != 0){
            inputException = true;
        }
    }
}

