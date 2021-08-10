#include <iostream>
#include <vector>

#include "kata/trie.h"

using namespace std;

int main()
{
    cout << "Trie tree demo" << endl;

    kata::Trie<int> trie;
    trie.Insert( {1, 1, 1} );
    trie.Insert( {1, 1, 2} );
    trie.Insert( {1, 1, 3} );

    cout << (trie.Find( {1, 1, 3}) ? "Found" : "Not Found") << endl;

    trie.Clear();

    cout << ( trie.Find( {1, 1, 3}) ? "Found" : "Not Found") << endl;
}

