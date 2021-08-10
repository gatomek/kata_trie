#include <kata/trie.h>

namespace kata
{
    TrieNode::TrieNode()
    {
    }

    TrieNode::TrieNode( int v)
    {
        m_Value = v;
    }

    TrieNode::TrieNode( bool end)
    {
        m_End = end;
    }

    TrieNode::~TrieNode()
    {
        for( TrieNode* node : m_Children)
            delete node;
    }

    TrieNode* TrieNode::MakeEndNode()
    {
        return new TrieNode( true);
    }

    TrieNode* TrieNode::MakeValueNode( int value)
    {
        return new TrieNode( value);
    }

    TrieNode* TrieNode::MakeEmptyNode()
    {
        return new TrieNode();
    }

    inline bool TrieNode::ValueEquals( int value) const
    {
        return m_Value == value;
    }

    inline bool TrieNode::IsEndNode() const
    {
        return m_End;
    }

    void TrieNode::Insert( const vector<int>& vec, size_t size, size_t n)
    {
        if( n == size)
        {
            MarkEnd();
            return;
        }

        const int value = vec.at( n);

        TrieNode* target { nullptr };

        for( TrieNode* node : m_Children)
            if( node->ValueEquals( value))
            {
                target = node;
                break;
            }

        if( target == nullptr)
        {
            target = TrieNode::MakeValueNode( value);
            m_Children.push_back( target);
        }

        target->Insert( vec, size, n + 1);
    }

    bool TrieNode::Check( const vector<int>& vec, size_t size, size_t n) const
    {
        if( n == size)
            return CheckEnd();

        const int value = vec.at( n);

        for( const TrieNode* const node : m_Children)
            if( node->ValueEquals( value))
                return node->Check( vec, size, n + 1);

        return false;
    }

    void TrieNode:: MarkEnd()
    {
        if( ! CheckEnd())
            m_Children.push_back( TrieNode::MakeEndNode());
    }

    bool TrieNode::CheckEnd() const
    {
        for( const TrieNode* const node : m_Children)
            if( node->IsEndNode())
                return true;

        return false;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////

    Trie::~Trie()
    {
        Clear();
    }

    TrieNode* Trie::MakeRoot()
    {
        if( m_Root == nullptr)
            m_Root = TrieNode::MakeEmptyNode();

        return m_Root;
    }

    void Trie::Insert( const vector<int>& in)
    {
        MakeRoot()->Insert( in, in.size(), 0);
    }

    bool Trie::Find( const vector<int>& vec)
    {
        return MakeRoot()->Check( vec, vec.size(), 0);
    }

    void Trie::Clear()
    {
        if( m_Root != nullptr)
        {
            delete m_Root;
            m_Root = nullptr;
        }
    }
}
