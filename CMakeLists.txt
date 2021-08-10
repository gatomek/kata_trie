# command line switches: 
# use BOOST.TESTs?  -DUBTS:BOOL=OFF / -DUBTS:BOOL=ON


cmake_minimum_required ( VERSION 3.16 )

cmake_policy (SET CMP0048 NEW)

project (TRIE VERSION 1.0 DESCRIPTION "Trie (prefix tree) implementation" LANGUAGES CXX)
include (CMake)

message( STATUS "--- CMAKE PROJECT ${CMAKE_PROJECT_NAME} ---")
message( STATUS "--- PROJECT       ${PROJECT_NAME} ---")

cmake_policy (SET CMP0074 NEW)

SET( UBTS OFF CACHE STRING "Use BOOST.TEST tests ?" )

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory (src)
add_subdirectory (apps)
	
if( CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	if( UBTS)
        find_package (Boost REQUIRED)
        enable_testing ()
        add_subdirectory (tests)
	endif()
endif()
