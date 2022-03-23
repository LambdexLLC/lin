cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(lbx-lin)

add_library(${PROJECT_NAME} STATIC "source/lin.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE source)

function(TRICKLE_DOWN_FN in_here)

	# Add cmake subdirs
	set(__sbd )
	file(GLOB __sbd RELATIVE "${in_here}" "*/CMakeLists.txt")
	foreach(v IN LISTS __sbd)
		string(REPLACE "/CMakeLists.txt" "" v ${v})
		add_subdirectory(${v})
	endforeach()
	
	# Add .cpp sources
	set(__sbd )
	file(GLOB __sbd RELATIVE "${in_here}" "*.cpp")
	list(TRANSFORM __sbd PREPEND "${in_here}/")
	target_sources(${PROJECT_NAME} PUBLIC ${__sbd})

	# Add .hpp sources
	set(__sbd )
	file(GLOB __sbd RELATIVE "${in_here}" "*.hpp")
	list(TRANSFORM __sbd PREPEND "${in_here}/")
	target_sources(${PROJECT_NAME} PUBLIC ${__sbd})
endfunction()
macro(TRICKLE_DOWN)
	TRICKLE_DOWN_FN(${CMAKE_CURRENT_LIST_DIR})
endmacro()

TRICKLE_DOWN()