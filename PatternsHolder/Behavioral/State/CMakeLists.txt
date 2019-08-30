cmake_minimum_required (VERSION 3.8)

set (TARGET_NAME State)

add_library( ${TARGET_NAME} STATIC )

#Enable support of C++17
if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17" )
else()
    target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
endif()

target_include_directories(
	${TARGET_NAME}
	PUBLIC
	${Boost_INCLUDE_DIRS}
)

target_sources(
	${TARGET_NAME}
        PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/SmartTeapot.cpp
	${CMAKE_CURRENT_LIST_DIR}/SmartTeapot.hpp
	${CMAKE_CURRENT_LIST_DIR}/TeapotState.hpp
	${CMAKE_CURRENT_LIST_DIR}/TeapotState.cpp
	${CMAKE_CURRENT_LIST_DIR}/RunMinimalExample.hpp
)

target_link_libraries(
	${TARGET_NAME}
	${Boost_LIBRARIES}
)