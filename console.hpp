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

void inOrderTraversal(Console* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        cout << root->release << endl;
        inOrderTraversal(root->rightChild);
    }
}
