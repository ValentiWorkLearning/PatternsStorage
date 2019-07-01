# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


find_package(Boost 1.68 REQUIRED)
project ("PatternsHolder")

# Include sub-projects.
add_subdirectory ("PatternsHolder/Creational/FactoryMethod")

set (TARGET_NAME PatternsHolder)

add_executable( ${TARGET_NAME} )

target_sources( ${TARGET_NAME}
	PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/PatternsHolder/main.cpp
)

target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(
	${TARGET_NAME}
	FactoryMethod
        ${Boost_LIBRARIES}
)

