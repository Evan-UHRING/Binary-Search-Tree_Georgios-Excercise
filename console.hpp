#include <iostream>

using namespace std;

int consolesReleases[] = {2017, 1985, 1977, 2005, 1994};
string consolesName[] = {"Nintendo switch", "NES", "Atari 2600", "Xbox 360", "PS1"};
int amountOfConsoles = 5;

typedef struct console{
    int id;
    int release;
    string name;
    struct console* leftChild;
    struct console* rightChild;
} Console;

Console* root = NULL;

void insertBST(int releaseData, string nameData, int id)
{
    Console* newNode = new Console;
    newNode->release = releaseData;
    newNode->name = nameData;
    newNode->id = id;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    Console* parent;
    Console* current;

    if(root == NULL) //tree is empty
    {
        root = newNode;
    }
    else
    {
        current = root;
        parent = NULL;
        while(true)
        {
            parent = current;

            if(releaseData < parent->release) // go to the left subtree
            {
                current = current->leftChild;

                if(current == NULL)
                {
                    parent->leftChild = newNode;
                    return;
                }
            }
            else    // go to the right subtree
            {
                current = current->rightChild;

                if(current == NULL)
                {
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

void detectDates(Console* root){
    cout << root->name << " release date: " << root->release << endl;
}

Console* findConsole(Console* root, int randNb){
    
    if (root == NULL) {
        return NULL; // Base case: no node found.
    }
    //if (root->id == randNb) {
    if (root->id == randNb) {
        return root; // Found the console with the target date.
    }
    // Search left and right subtrees.
    Console* leftResult = findConsole(root->leftChild, randNb);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findConsole(root->rightChild, randNb);
}

void inOrderTraversal(Console* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        detectDates(root);
        inOrderTraversal(root->rightChild);
    }
}

void createBST(){
    for(int i = 0; i < amountOfConsoles; i++)
    {
        insertBST(consolesReleases[i], consolesName[i], i + 1);
    }
}

void addConsole(string consoleNameData, int consoleReleaseData){
    amountOfConsoles++;
    insertBST(consoleReleaseData, consoleNameData, amountOfConsoles);
}

Console* getSuccessor(Console* curr){
    curr = curr->rightChild;
    if (curr != nullptr && curr->leftChild != nullptr)
        curr = curr->leftChild;
    return curr;
}

Console* deleteConsole(Console* root, int release){
    
    if (root == nullptr)
        return root;

    // If release to be searched is in a subtree
    if (root->release > release)
        root->leftChild = deleteConsole(root->leftChild, release);
    else if (root->release < release)
        root->rightChild = deleteConsole(root->rightChild, release);

    // If root matches with the given release
    else {

        // Cases when root has 0 children
        
        // or only right child
        if (root->leftChild == nullptr) {
            Console* temp = root->rightChild;
            delete root;
            return temp;
        }

        // When root has only left child
        if (root->rightChild == nullptr) {
            Console* temp = root->leftChild;
            delete root;
            return temp;
        }

        // When both children are present
        Console* succ = getSuccessor(root);
        root->release = succ->release;
        root->rightChild = deleteConsole(root->rightChild, succ->release);
    }
    amountOfConsoles--;
    return root;
    
}
