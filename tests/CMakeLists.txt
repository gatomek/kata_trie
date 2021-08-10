cmake_minimum_required(VERSION 3.16)

enable_testing()

#set(Boost_DEBUG ON)
#set(Boost_USE_STATIC_LIBS OFF)

cmake_policy (SET CMP0074 NEW)

find_package ( Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories ( ${Boost_INCLUDE_DIRS} ../include)

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (test_trie test_trie )

target_compile_features(test_trie PRIVATE cxx_std_17)

target_link_libraries (test_trie trie_lib ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME test_trie COMMAND test_trie)
