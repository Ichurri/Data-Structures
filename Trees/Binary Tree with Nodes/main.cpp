#include  <conio.h>
#include "ArrayBinaryTree.h" 

using namespace std;

void test()
{
    BinaryTree<int> myTree(16);

    for (int i = 1; i <= 10; i++)
    {
        myTree.insertRandom(i);
    }

    cout << "InOrder traversal: ";
    myTree.inOrder();
    cout << endl;

    cout << "PreOrder traversal: ";
    myTree.preOrder();
    cout << endl;

    cout << "PostOrder traversal: ";
    myTree.postOrder();
    cout << endl;

    cout << "Number of nodes: " << myTree.countNodes() << endl;
    cout << "Height of tree: " << myTree.calculateHeight() << endl;
    cout << "Print array: " << endl;
    myTree.showArray();
    cout << endl;
    cout << endl;
    cout << "Tree mirrored:" << endl;
    myTree.mirror();
    myTree.showArray();
}

void menu()
{
    int maxSize;
    cout << "Enter the maximum size of the binary tree: ";
    cin >> maxSize;

    BinaryTree<int> myTree(maxSize);

    int choice;
    int data;

    do
    {
        cout << "-------------Menu----------------" << endl;
        cout << "1. Insert random data" << endl;
        cout << "2. Count nodes" << endl;
        cout << "3. Calculate height" << endl;
        cout << "4. Traverse inOrder" << endl;
        cout << "5. Traverse preOrder" << endl;
        cout << "6. Traverse postOrder" << endl;
        cout << "7. Mirror" << endl;
        cout << "8. Show array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert: ";
            cin >> data;
            myTree.insertRandom(data);
            break;
        case 2:
            cout << "Number of nodes in the tree: " << myTree.countNodes() << endl;
            break;
        case 3:
            cout << "Height of the tree: " << myTree.calculateHeight() << endl;
            break;
        case 4:
            cout << "InOrder traversal: ";
            myTree.inOrder();
            cout << endl;
            break;
        case 5:
            cout << "PreOrder traversal: ";
            myTree.preOrder();
            cout << endl;
            break;
        case 6:
            cout << "PostOrder traversal: ";
            myTree.postOrder();
            cout << endl;
            break;
        case 7:
            myTree.mirror();
            myTree.showArray();
            break;
        case 8:
            myTree.showArray();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (choice != 0);
}

int main() 
{
    menu();
}
