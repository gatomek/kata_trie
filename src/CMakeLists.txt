set( HEADER_LIST "${TRIE_SOURCE_DIR}/include/kata/trie.h")

add_library( trie_lib trie.cpp ${HEADER_LIST})

target_include_directories( trie_lib PUBLIC ../include )

target_compile_features( trie_lib PUBLIC cxx_std_17)





