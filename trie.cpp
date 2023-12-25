#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertFunc(TrieNode *root, string word)
    {
        // base case
        if (!word.length())
        {
            root->isTerminal = true;
            return;
        }

        // Assumption: Word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertFunc(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertFunc(root, word);
    }

    bool searchFunc(TrieNode *root, string word)
    {
        // base case
        if (!word.length())
        {
            return root->isTerminal;
        }

        // Assumption: Word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return false;
        }

        return searchFunc(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchFunc(root, word);
    }

    void removeFunc(TrieNode *root, string word)
    {
        // base case
        if (!word.length())
        {
            root->isTerminal = false;
            return;
        }

        // Assumption: Word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index])
        {
            child = root->children[index];
        }
        // absent
        else
        {
            return;
        }

        removeFunc(child, word.substr(1));

        // If child is not a terminal node and doesn't have any children, delete it
        if (!child->isTerminal)
        {
            bool isEmpty = true;
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i])
                {
                    isEmpty = false;
                    break;
                }
            }
            if (isEmpty)
            {
                delete child;
                root->children[index] = NULL;
            }
        }
    }

    void removeWord(string word)
    {
        removeFunc(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ABCD");
    cout << "Present or not : " << t->searchWord("ABC") << endl;
    cout << "Present or not : " << t->searchWord("ABCD") << endl;
    t->removeWord("ABCD");
    cout << "Afer Removal, Present or not : " << t->searchWord("ABCD") << endl;
    return 0;
}
