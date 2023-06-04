#include "trie.h"

using namespace std;

TrieNode::TrieNode()
{
    is_end_of_word = true;
    for (shared_ptr<TrieNode> child : children)
    {
        child = nullptr;
    }
}

void Trie::InsertKey(const string &key)
{
    TrieNode &node = root;
    // Over the range of characters in the key, either nagivate
    // through the tree by ascisigning to pNode, or create a new node
    // if one does not yet exist for a character
    for (char const &c : key)
    {
        int char_index = c - TRIE_FIRST_CHAR;
        if (node.children[char_index] == nullptr)
        {
            node.children[char_index] = make_shared<TrieNode>();
            node.is_end_of_word = false;
        }
        node = *node.children[char_index];
    }

    // node will now be at the end of an iteration, so it points to a word.
    node.is_end_of_word = true;
}

bool Trie::Search(const string &key)
{
    bool contains_key = true;
    TrieNode &node = root;
    // Over the range of characters in the key, either nagivate
    // through the tree by ascisigning to pNode, or create a new node
    // if one does not yet exist for a character
    for (char const &c : key)
    {
        int char_index = c - TRIE_FIRST_CHAR;
        if (node.children[char_index] != nullptr)
        {
            node = *node.children[char_index];
        }
        else
        {
            contains_key = false;
        }
    }
    return (contains_key ? node.is_end_of_word : false);
}