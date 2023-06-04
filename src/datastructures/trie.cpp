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
    TrieNode *pNode = &root;
    // Over the range of characters in the key, either nagivate
    // through the tree by ascisigning to pNode, or create a new node
    // if one does not yet exist for a character
    for (char const &c : key)
    {
        int char_index = c - TRIE_FIRST_CHAR;
        if (pNode->children[char_index] == nullptr)
        {
            pNode->children[char_index] = make_shared<TrieNode>();
            pNode->is_end_of_word = false;
        }
        pNode = pNode->children[char_index].get();
    }

    // node will now be at the end of an iteration, so it points to a word.
    pNode->is_end_of_word = true;
}

bool Trie::Search(const string &key)
{
    bool contains_key = true;
    TrieNode *pNode = &root;
    // Over the range of characters in the key, either nagivate
    // through the tree by ascisigning to pNode, or create a new node
    // if one does not yet exist for a character
    for (char const &c : key)
    {
        int char_index = c - TRIE_FIRST_CHAR;
        if (pNode->children[char_index] != nullptr)
        {
            pNode = pNode->children[char_index].get();
        }
        else
        {
            contains_key = false;
        }
    }
    return (contains_key ? pNode->is_end_of_word : false);
}