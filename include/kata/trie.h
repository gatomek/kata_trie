#ifndef TRIE
#define TRIE

#include <vector>


namespace kata
{
    using namespace std;

    class TrieNode final
    {
    private:
        TrieNode();
        TrieNode( int v);
        TrieNode( bool end);

    public:
        ~TrieNode();

    private:
        int m_Value { 0 };
        bool m_End { false };
        vector<TrieNode*> m_Children;

    public:
        static TrieNode* MakeEndNode();
        static TrieNode* MakeValueNode( int value);
        static TrieNode* MakeEmptyNode();

    public:
        void Insert( const vector<int>& vec, size_t size, size_t n);

    public:
        inline bool ValueEquals( int value) const;
        inline bool IsEndNode() const;
        bool Check( const vector<int>& vec, size_t size, size_t n) const;

    private:
        void MarkEnd();

    private:
        bool CheckEnd() const;
    };

    class Trie final
    {
    public:
        Trie() = default;
        Trie( const Trie& trie) = delete;
        ~Trie();

    private:
        TrieNode* m_Root { nullptr };

    private:
        TrieNode* MakeRoot();

    public:
        void Insert( const vector<int>& in);
        bool Find( const vector<int>& vec);
        void Clear();
    };
}

#endif /* TRIE */
