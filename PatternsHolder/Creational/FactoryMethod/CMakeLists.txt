cmake_minimum_required (VERSION 3.8)


add_library( FactoryMethod STATIC )

target_sources(
	FactoryMethod
        PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/RenderContext.hpp
	${CMAKE_CURRENT_LIST_DIR}/RenderContext.cpp
	${CMAKE_CURRENT_LIST_DIR}/ContextCreator.hpp
	${CMAKE_CURRENT_LIST_DIR}/ContextCreator.cpp
)
