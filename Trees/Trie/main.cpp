#include "Trie.h"
#include <conio.h>

using namespace std;

void test()
{
    TrieTree trie;

    // Insert words on trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("app");

    // Search
    cout << "Searching 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl; 
    cout << "Searching 'apples': " << (trie.search("apples") ? "Found" : "Not found") << endl; 

}

void menu()
{
    TrieTree trie;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Insert word" << endl;
        cout << "2. Search word" << endl;
        cout << "3. Find prefix" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";

        int option;
        cin >> option;

        system("cls");

        switch (option)
        {
        case 1:
        {
            string word;
            cout << "Enter the word you want to insert: ";
            cin >> word;
            trie.insert(word);
            cout << "Word '" << word << "' inserted on Trie." << endl;
            break;
        }
        case 2:
        {
            string word;
            cout << "Enter the word you want to search for: ";
            cin >> word;
            bool encontrado = trie.search(word);
            cout << (encontrado ? "Word found." : "Word not found.") << endl;
            break;
        }
        case 3:
        {
            string prefix;
            cout << "Enter the prefix you want to search: ";
            cin >> prefix;
            vector<string> response = trie.findAllWithPrefix(prefix);
            for (const string& result : response)
                cout << result << endl;
            break;
        }
        case 4:
            cout << "Exit from program." << endl;
        default:
            cout << "Option not valid. Please select a valid option." << endl;
        }
        _getch();
    }
}

int main()
{
    menu();
}