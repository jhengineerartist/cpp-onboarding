#include <string>
#include <memory>

#define TRIE_ALPHABET_SIZE 26
#define TRIE_FIRST_CHAR 'a'

using namespace std;

struct TrieNode
{
    TrieNode();
    array<shared_ptr<TrieNode>, TRIE_ALPHABET_SIZE> children;
    bool is_end_of_word;
};

class Trie
{
public:
    void InsertKey(const string &key);
    bool Search(const string &key);

private:
    TrieNode root;
};