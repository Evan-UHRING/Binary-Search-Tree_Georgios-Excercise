#include "display.cpp"


void init() {
    amountOfConsoles = 5;
    createBST();
}

int main(){
    init();
    mainMenu();
    cout << "\nProgram terminated." << endl;
    return 0;
}
