set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(common)

find_package(SUNDIALS REQUIRED cvode)

include_directories(.)

file(GLOB ITEMS LIST_DIRECTORIES TRUE "*")

foreach(ITEM ${ITEMS})
    if(IS_DIRECTORY ${ITEM})
        add_subdirectory(${ITEM})
    endif()
endforeach()
