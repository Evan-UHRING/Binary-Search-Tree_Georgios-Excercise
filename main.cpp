#include <iostream>

using namespace std;

void clearScreen(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

int main(){
    clearScreen();
    cout << "feur" << endl;
    return 0;
}