add_executable (demo_trie demo_trie.cpp)

target_compile_features(demo_trie PRIVATE cxx_std_17)

target_link_libraries (demo_trie trie_lib)
