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

Console* randomConsole() {
    if (root == NULL) {
        cout << "Error: The tree is empty. No consoles available." << endl;
        return nullptr;
    }
    int i = rand() % amountOfConsoles + 1;
    Console* result = findConsole(root, i);
    if (result == NULL) {
        cout << "Error: Could not find a console for release date " << result->release << "." << endl;
    }
    return result;
}

void displayFoundDate(Console* result){
    bool success = false;
    while (input != 0 || inputException){
        clearScreen();
        if (input == result->release){
            cout << "Well done!" << endl;
            detectDates(result);
            success = true;
        } else {
            cout << "Console with release date " << input << " not found.\n";
            success = false;
        }

        cout << endl;
        cout << "0| Go to main menu ";
        if (!success)
            cout << "\nOr retry look for the release date of " << result->name << ": \n" << endl;
        handleException();
        cout << "Your choice -> ";
        input = userInputInt(&inputException);
    }
}

void adder() {
    string nameData = "NULL";
    int releaseData = 0;
    int validation = 3;
    while (validation != 2 && validation != 1 && validation != 0 || inputException) {
        clearScreen();
        cout << "Let's add more consoles ! :D" << endl << endl;
        
        if(nameData == "NULL")
        {
            cout << "What is the name of this console? -> ";
            cin >> nameData ;
        }
        else if(releaseData == 0)
        {
            cout << "Name of the console: " << nameData << endl;
            handleException();
            cout << "When was it released? -> ";
            releaseData = userInputInt(&inputException);
        }
        else if(validation != 2 && validation != 1 && validation != 0 || inputException)
        {
            cout << "Name of the console: " << nameData << endl;
            cout << "Its release " << releaseData << "\n" << endl;
            cout << "1| All gut :D\n"
                 << "2| NO not gut :(\n"
                 << "0| Go back (I want to be a monkey)\n" << endl;
            handleException();
            cout << "Your choice -> ";
            validation = userInputInt(&inputException);
            if(validation != 0 && validation != 1 && validation != 2)
                inputException = true;
        }
        else if(validation == 0)
            break;
        if(validation == 2)
        {
            nameData = "NULL";
            releaseData = 0;
            validation = 3;
        }
    }
    if(validation == 1)
        addConsole(nameData, releaseData);
    input = 3;
}

void finder() {
    while (input != 0 || inputException) {
        clearScreen();
        Console* result = randomConsole();
        if (result == nullptr) {
            break;
        }
        
        cout << "Look for the release date of " << result->name << endl << endl;
        handleException();
        cout << "Answer -> ";
        input = userInputInt(&inputException);

        displayFoundDate(result);
        break;
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
            << "3| Add more consoles\n"
            << "0| Exit\n" << endl;
        handleException();

        cout << "Your choice -> ";
        input = userInputInt(&inputException);

        if(input == 1){
            displayReleaseDates();
        } else if (input == 2){
            finder();
        } else if (input == 3){
            adder();
        } else if (input != 0){
            inputException = true;
        }
    }
}

