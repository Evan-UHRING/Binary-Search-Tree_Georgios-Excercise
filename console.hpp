#include <iostream>

using namespace std;

typedef struct console{
    int release;
    int sales;
    struct console* leftChild;
    struct console* rightChild;
} Console;

Console* root = NULL;

void insertBST(int data)
{
    Console* newNode = new Console;
    newNode->release = data;
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

            if(data < parent->release) // go to the left subtree
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
    switch (root->release) {
        case 2017: cout << "Nintendo Switch release date: "; break;
        case 1985: cout << "NES release date: "; break;
        case 1977: cout << "Atari 2600 release date: "; break;
        case 2005: cout << "Xbox 360 release date: "; break;
        case 1994: cout << "PS1 release date: "; break;
        default: cout << "Console release date: "; break;
    }
    cout << root->release << endl;
    
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

int consolesReleases[5];
