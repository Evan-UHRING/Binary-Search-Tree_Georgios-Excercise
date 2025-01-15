#include <iostream>

using namespace std;

int consolesReleases[] = {2017, 1985, 1977, 2005, 1994};
string consolesName[] = {"Nintendo switch", "NES", "Atari 2600", "Xbox 360", "PS1"};
int amountOfConsoles = 0;

typedef struct console{
    int release;
    string name;
    struct console* leftChild;
    struct console* rightChild;
} Console;

Console* root = NULL;

void insertBST(int releaseData, string nameData)
{
    Console* newNode = new Console;
    newNode->release = releaseData;
    newNode->name = nameData;
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

Console* findConsole(Console* root, int targetDate){
    if (root == NULL) {
        return NULL; // Base case: no node found.
    }
    if (root->release == targetDate) {
        return root; // Found the console with the target date.
    }
    // Search left and right subtrees.
    Console* leftResult = findConsole(root->leftChild, targetDate);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findConsole(root->rightChild, targetDate);
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
        insertBST(consolesReleases[i], consolesName[i]);
    }
}

void addConsole(string consoleNameData, int consoleReleaseData){
    insertBST(consoleReleaseData, consoleNameData);
    amountOfConsoles++;
}