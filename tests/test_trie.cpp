#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

#include "kata/trie.h"

namespace but = boost::unit_test;
using namespace std;
using namespace kata;

BOOST_AUTO_TEST_CASE( EmptyTrieTest)
{
    Trie trie;
    bool res = trie.Find( {});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie1Test)
{
    Trie trie;
    trie.Insert( {1} );
    bool res = trie.Find( {});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie2Test)
{
    Trie trie;
    trie.Insert( {} );
    bool res = trie.Find( {1});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie3Test)
{
    Trie trie;
    trie.Insert( {} );
    bool res = trie.Find( {});
    BOOST_TEST( res == true);
}

BOOST_AUTO_TEST_CASE( Trie3_1Test)
{
    Trie trie;
    trie.Insert( {} );
    trie.Clear();
    bool res = trie.Find( {});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie4Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    bool res = trie.Find( {1});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie5Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == true);
}

BOOST_AUTO_TEST_CASE( Trie5_1Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    trie.Clear();
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie6Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    bool res = trie.Find( {1,2,3});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie7Test)
{
    Trie trie;
    trie.Insert( {1} );
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie8Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == true);
}

BOOST_AUTO_TEST_CASE( Trie8_1Test)
{
    Trie trie;
    trie.Insert( {1,2} );
    trie.Clear();
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie9Test)
{
    Trie trie;
    trie.Insert( {1,2,3} );
    bool res = trie.Find( {1,2});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie10Test)
{
    Trie trie;
    trie.Insert( {1,1,1} );
    trie.Insert( {1,1,2} );
    trie.Insert( {1,1,3} );
    bool res = trie.Find( {1,1,3});
    BOOST_TEST( res == true);
}

BOOST_AUTO_TEST_CASE( Trie10_1Test)
{
    Trie trie;
    trie.Insert( {1,1,1} );
    trie.Insert( {1,1,2} );
    trie.Insert( {1,1,3} );
    trie.Clear();
    bool res = trie.Find( {1,1,3});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie11Test)
{
    Trie trie;
    trie.Insert( {1,1,1} );
    trie.Insert( {1,1,2} );
    trie.Insert( {1,1,3} );
    bool res = trie.Find( {1,1,4});
    BOOST_TEST( res == false);
}

BOOST_AUTO_TEST_CASE( Trie12Test)
{
    Trie trie;
    trie.Insert( {1,1,1} );
    trie.Insert( {1,1,1} );
    trie.Insert( {1,1,1} );
    bool res = trie.Find( {1,1,1});
    BOOST_TEST( res == true);
}
