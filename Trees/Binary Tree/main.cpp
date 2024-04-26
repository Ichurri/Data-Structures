#include "ArrayBinaryTree.h"
#include <conio.h>

int main()
{
    int capacity;
    cout << "Enter the capacity of the binary tree: ";
    cin >> capacity;
    cout << endl;

    ArrayBinaryTree<int> binaryTree(capacity);

    for (int i = 0; i < capacity; i++)
    {
        //int randomValue = rand() % 10;
        //binaryTree.insertRandom(randomValue);
        binaryTree.insertRandom(i);
    }

    cout << "Inorder traversal: ";
    binaryTree.inOrderTraversal(0);
    cout << endl;

    cout << "Preorder traversal: ";
    binaryTree.preOrderTraversal(0);
    cout << endl;

    cout << "Postorder traversal: ";
    binaryTree.postOrderTraversal(0);
    cout << endl;

    cout << "Number of nodes: " << binaryTree.countNodes() << endl;
    cout << "Height of the tree: " << binaryTree.calculateHeight() << endl;

    /*
    int choice;
    do
    {
        cout << "1. Insert random element." << endl;
        cout << "2. Count nodes in the tree." << endl;
        cout << "3. Calculate the tree height." << endl;
        cout << "4. In-order traversal." << endl;
        cout << "5. Pre-order traversal." << endl;
        cout << "6. Post-order traversal." << endl;
        cout << "7. Show tree." << endl;
        cout << "0. Exit." << endl;
        cout << "Select an option: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter the element to insert: ";
            cin >> data;
            binaryTree.insertRandom(data);
            break;
        }
        case 2:
            cout << "Number of nodes in the tree: " << binaryTree.countNodes() << endl;
            break;
        case 3:
            cout << "Height of the tree: " << binaryTree.calculateHeight() << endl;
            break;
        case 4:
            cout << "In-order traversal: ";
            binaryTree.inOrderTraversal(0);
            cout << endl;
            break;
        case 5:
            cout << "Pre-order traversal: ";
            binaryTree.preOrderTraversal(0);
            cout << endl;
            break;
        case 6:
            cout << "Post-order traversal: ";
            binaryTree.postOrderTraversal(0);
            cout << endl;
            break;
        case 7:
            binaryTree.showArraw();  // Note: This should be showArray() if corrected in ArrayBinaryTree.h
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

        _getch();

    } while (choice != 0);

    */
}
