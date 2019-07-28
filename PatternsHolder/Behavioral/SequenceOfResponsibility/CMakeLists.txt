cmake_minimum_required (VERSION 3.8)

set (TARGET_NAME SequenceOfResponsibility)

add_library( ${TARGET_NAME} STATIC )

#Enable support of C++17
if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17" )
else()
    target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
endif()

target_sources(
	${TARGET_NAME}
        PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/CommandContextParser.hpp
	${CMAKE_CURRENT_LIST_DIR}/CommandContextParser.cpp
	${CMAKE_CURRENT_LIST_DIR}/RunMinimalExample.hpp
)
