#include "display.cpp"


void init() {
    consolesReleases[0] = 2017;  // Nintendo Switch release year
    consolesReleases[1] = 1985;  // NES release year
    consolesReleases[2] = 1977;  // Atari 2600 release year
    consolesReleases[3] = 2005;  // Xbox 360 release year
    consolesReleases[4] = 1994;  // PS1 release year
    for(int i = 0; i < 5; i++)
    {
        insertBST(consolesReleases[i]);
    }
}

int main(){
    init();
    mainMenu();
    cout << "\nProgram terminated." << endl;
    return 0;
}
