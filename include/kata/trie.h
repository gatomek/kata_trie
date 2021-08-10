#ifndef TRIE
#define TRIE

#include <vector>


namespace kata
{
    using namespace std;

    template<typename T>
    class TrieNode final
    {
    private:
        TrieNode();
        TrieNode( T v);
        TrieNode( bool end);

    public:
        ~TrieNode();

    private:
        T m_Value;
        bool m_End { false };
        vector<TrieNode*> m_Children;

    public:
        static TrieNode* MakeEndNode();
        static TrieNode* MakeValueNode( T value);
        static TrieNode* MakeEmptyNode();

    public:
        void Insert( const vector<T>& vec, size_t size, size_t n);

    public:
        inline bool ValueEquals( T value) const;
        inline bool IsEndNode() const;
        bool Check( const vector<T>& vec, size_t size, size_t n) const;

    private:
        void MarkEnd();

    private:
        bool CheckEnd() const;
    };

        template<typename T>
    TrieNode<T>::TrieNode()
    {
    }

    template <typename T>
    TrieNode<T>::TrieNode( T v)
    {
        m_Value = v;
    }

    template<typename T>
    TrieNode<T>::TrieNode( bool end)
    {
        m_End = end;
    }

    template<typename T>
    TrieNode<T>::~TrieNode()
    {
        for( TrieNode<T>* node : m_Children)
            delete node;
    }

    template<typename T>
    TrieNode<T>* TrieNode<T>::MakeEndNode()
    {
        return new TrieNode<T>( true);
    }

    template<typename T>
    TrieNode<T>* TrieNode<T>::MakeValueNode( T value)
    {
        return new TrieNode<T>( value);
    }

    template<typename T>
    TrieNode<T>* TrieNode<T>::MakeEmptyNode()
    {
        return new TrieNode<T>();
    }

    template<typename T>
    inline bool TrieNode<T>::ValueEquals( T value) const
    {
        return m_Value == value;
    }

    template<typename T>
    inline bool TrieNode<T>::IsEndNode() const
    {
        return m_End;
    }

    template<typename T>
    void TrieNode<T>::Insert( const vector<T>& vec, size_t size, size_t n)
    {
        if( n == size)
        {
            MarkEnd();
            return;
        }

        const T value = vec.at( n);

        TrieNode<T>* target { nullptr };

        for( TrieNode<T>* node : m_Children)
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

    template<typename T>
    bool TrieNode<T>::Check( const vector<T>& vec, size_t size, size_t n) const
    {
        if( n == size)
            return CheckEnd();

        const T value = vec.at( n);

        for( const TrieNode<T>* const node : m_Children)
            if( node->ValueEquals( value))
                return node->Check( vec, size, n + 1);

        return false;
    }

    template<typename T>
    void TrieNode<T>:: MarkEnd()
    {
        if( ! CheckEnd())
            m_Children.push_back( TrieNode::MakeEndNode());
    }

    template<class T>
    bool TrieNode<T>::CheckEnd() const
    {
        for( const TrieNode<T>* const node : m_Children)
            if( node->IsEndNode())
                return true;

        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename T>
    class Trie
    {
    public:
        Trie() = default;
        Trie( const Trie<T>& trie) = delete;
        ~Trie();

    private:
        TrieNode<T>* m_Root { nullptr };

    private:
        TrieNode<T>* MakeRoot();

    public:
        void Insert( const vector<T>& in);
        bool Find( const vector<T>& vec);
        void Clear();
    };

    template<typename T>
    Trie<T>::~Trie()
    {
        Clear();
    }

    template<typename T>
    TrieNode<T>* Trie<T>::MakeRoot()
    {
        if( m_Root == nullptr)
            m_Root = TrieNode<T>::MakeEmptyNode();

        return m_Root;
    }

    template<typename T>
    void Trie<T>::Insert( const vector<T>& in)
    {
        MakeRoot()->Insert( in, in.size(), 0);
    }

    template<typename T>
    bool Trie<T>::Find( const vector<T>& vec)
    {
        return MakeRoot()->Check( vec, vec.size(), 0);
    }

    template<typename T>
    void Trie<T>::Clear()
    {
        if( m_Root != nullptr)
        {
            delete m_Root;
            m_Root = nullptr;
        }
    }

}

#endif /* TRIE */
