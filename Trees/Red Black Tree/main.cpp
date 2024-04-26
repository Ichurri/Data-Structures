#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include "RedBlackTree.h"
#include <random>
#include <map>
using namespace std;
using namespace std::chrono;

void prueba()
{
    RedBlackTree<int> tree;

    tree.insertData(10);
    tree.insertData(5);
    tree.insertData(15);
    tree.insertData(3);
    tree.insertData(7);
    tree.insertData(12);
    tree.insertData(18);

    // Find the minimum and maximum value in the tree

    Node<int>* minNode = tree.findMin();
    Node<int>* maxNode = tree.findMax();
    cout << "Maximun value: " << minNode->getData() << endl;
    cout << "Minimun value: " << maxNode->getData() << endl;

    // Calculate the height of the tree
    int height = tree.calculateHeight();
    cout << "Height of the tree: " << height << std::endl;

    // Count the number of nodes in the tree
    int nodeCount = tree.countNodes();
    cout << "Number of nodes in the tree: " << nodeCount << endl;

    cout << "inOrder: " << endl;
    tree.inOrderTraversal();
}

void menu()
{
    RedBlackTree<int> rbt;
    int option, data;

    do
    {
        cout << "-------------Menu----------------" << endl;
        cout << "1. Insert data" << endl;
        cout << "2. Count nodes" << endl;
        cout << "3. Calculate height" << endl;
        cout << "4. Find the smaller data" << endl;
        cout << "5. Find the major data" << endl;
        cout << "6. inOrder" << endl;
        cout << "7. preOrder" << endl;
        cout << "8. postOrder" << endl;
        cout << "9. Delete data" << endl;
        cout << "10. Read file" << endl;
        cout << "11. Mirror" << endl;
        cout << "12. Insert 10000 numbers" << endl;
        cout << "13. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        system("cls");

        switch (option)
        {
        case 1:
            cout << "Enter the data to insert: ";
            cin >> data;
            rbt.insertData(data);
            break;

        case 2:
            cout << "Nodes of the tree: " << rbt.countNodes() << endl;
            break;

        case 3:
            cout << "Tree height: " << rbt.calculateHeight() << endl;
            break;

        case 4:
            cout << "Smaller data of the tree: " << rbt.findMin()->getData() << endl;
            break;

        case 5:
            cout << "Major data of the tree: " << rbt.findMax()->getData() << endl;
            break;

        case 6:
            cout << "InOrder: ";
            rbt.inOrderTraversal();
            cout << endl;
            break;

        case 7:
            cout << "PreOrder: ";
            rbt.preOrderTraversal();
            cout << endl;
            break;

        case 8:
            cout << "PostOrder: ";
            rbt.postOrderTraversal();
            cout << endl;
            break;

        case 9:
            cout << "Enter data to delete: ";
            cin >> data;
            rbt.removeData(data);
            break;

        case 10:
            rbt.readFile(rbt, "ThousandNumbers.txt");
            break;

        case 11:
            rbt.mirror();
            break;

        case 12:
            rbt.readFile(rbt, "ThousandNumbers.txt");
            //rbt.searchOneMillion();
            break;

        case 13:
            cout << "Exit from program." << endl;
            break;

        default:
            cout << "This option doesn't exist." << endl;
            break;
        }
        _getch();
    } while (option != 13);
}

void timeTree()
{
    RedBlackTree<int> tree;

    auto startReadFile = high_resolution_clock::now();
    tree.readFile(tree, "ThousandNumbers.txt"); 
    auto stopReadFile = high_resolution_clock::now();
    auto durationReadFile = duration_cast<microseconds>(stopReadFile - startReadFile);

    cout << "Run time to insert ThousandNumbers: " << durationReadFile.count() << " microseconds" << endl;

    // Measure run time of searchOneMillion function
    auto startSearchOneMillion = high_resolution_clock::now();
    tree.searchOneMillion();
    auto stopSearchOneMillion = high_resolution_clock::now();
    auto durationSearchOneMillion = duration_cast<microseconds>(stopSearchOneMillion - startSearchOneMillion);

    cout << "searchOneMillion run time: " << durationSearchOneMillion.count() << " microseconds" << endl;
}

void timeMap()
{
    map<int, bool> numberMap;

    auto startReadFile = high_resolution_clock::now();
    ifstream inputFile("ThousandNumbers.txt");
    int key;
    while (inputFile >> key) {
        numberMap[key] = true;
    }
    inputFile.close();
    auto stopReadFile = high_resolution_clock::now();
    auto durationReadFile = duration_cast<microseconds>(stopReadFile - startReadFile);

    cout << "Run time to insert numbers from the file: " << durationReadFile.count() << " microseconds" << endl;

    // Generate a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 1000000);

    int randomNumber = distribution(gen);

    auto startSearchOneMillion = high_resolution_clock::now();
    bool found = numberMap.find(randomNumber) != numberMap.end();
    auto stopSearchOneMillion = high_resolution_clock::now();
    auto durationSearchOneMillion = duration_cast<microseconds>(stopSearchOneMillion - startSearchOneMillion);

    cout << "Time to search in std::map: " << durationSearchOneMillion.count() << " microseconds" << endl;

    if (found) 
        cout << "The number " << randomNumber << " was on the map." << endl;
    else 
        cout << "The number " << randomNumber << " is not on the map." << endl;
}

int main()
{
    menu();
}
