#include <iostream>
#include "console.hpp"

using namespace std;

void clearScreen(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined (__gnu_linux__) || defined (__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

void init(int releases[5]) {
    releases[0] = 2017;  // Nintendo Switch release year
    releases[1] = 1985;  // NES release year
    releases[2] = 1977;  // Atari 2600 release year
    releases[3] = 2005;  // Xbox 360 release year
    releases[4] = 1994;  // PS1 release year
}

int main(){
    clearScreen();
    int consolesReleases[5];
    init(consolesReleases);
    for(int i = 0; i < 5; i++)
    {
        insertBST(consolesReleases[i]);
    }
    inOrderTraversal(root);
    return 0;
}
