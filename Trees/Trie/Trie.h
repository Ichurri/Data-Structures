#pragma once
#include "Node.h"
#include <vector>

using namespace std;

class TrieTree
{
private:
    Node* root;
    void findAllWithPrefixHelper(Node* index, string currentPrefix, vector<string>& results);
public:
    TrieTree();
    ~TrieTree() {};

    void insert(const string& data);
    bool search(const string& data);

    vector<string> findAllWithPrefix(const string& prefix);
};

inline void TrieTree::findAllWithPrefixHelper(Node* index, string currentPrefix, vector<string>& results)
{
    if (index == nullptr)
        return;

    if (index->getIsLeaf())
        results.push_back(currentPrefix);

    Node* child = index->getFirstChild();
    while (child != nullptr)
    {
        findAllWithPrefixHelper(child, currentPrefix + child->getData(), results);
        child = child->getBrother();
    }
}

TrieTree::TrieTree()
{
    root = new Node('\0');
}

void TrieTree::insert(const string& data)
{
    Node* current = root;
    for (char c : data)
    {
        Node* child = current->getFirstChild();
        Node* prevChild = nullptr;

        // Find the child node corresponding to the current character.
        while (child != nullptr && child->getData() != c)
        {
            prevChild = child;
            child = child->getBrother();
        }

        if (child == nullptr)
        {
            Node* newNode = new Node(c);
            if (prevChild != nullptr)
                prevChild->setBrother(newNode);
            else
                current->setFirstChild(newNode);
            current = newNode;
        }
        else // If a child node is found for the current character, advance to the next level of the Trie.
            current = child;
    }
    // Mark the last node as a leaf.
    current->setIsLeaf(true);
}

bool TrieTree::search(const string& data)
{
    Node* node = root;
    for (char c : data)
    {
        node = node->getFirstChild();
        while (node != nullptr && node->getData() != c)
            node = node->getBrother();
        if (node == nullptr)
            return false;
    }
    // Check if the last node is a leaf.
    return node->getIsLeaf();
}

inline vector<string> TrieTree::findAllWithPrefix(const string& prefix)
{
    vector<string> results;

    Node* node = root;
    for (char c : prefix)
    {
        node = node->getFirstChild();
        while (node != nullptr && node->getData() != c)
            node = node->getBrother();
        if (node == nullptr)
            return results; // No prefix found on the Trie.
    }

    findAllWithPrefixHelper(node, prefix, results);

    return results;
}