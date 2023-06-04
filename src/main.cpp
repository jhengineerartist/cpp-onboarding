#include <iostream>
#include "datastructures/trie.h"
using namespace std;

int main()
{
    Trie trie;
    bool contains_key = false;

    trie.InsertKey("kindness");
    contains_key = trie.Search("kind");
    contains_key = trie.Search("kindness");
    trie.InsertKey("kind");
    contains_key = trie.Search("kind");

    cout << "Hello World! " << contains_key << endl;

    return 0;
}