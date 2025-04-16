function(add_c_executable EXECUTABLE SOLVER)
    set(MAIN_CPP ${CMAKE_CURRENT_BINARY_DIR}/main.${SOLVER}.cpp)
    set(EXECUTABLE_SOLVER ${EXECUTABLE}_${SOLVER})

    configure_file(../main.${SOLVER}.cpp.in ${MAIN_CPP})

    add_executable(${EXECUTABLE_SOLVER}
        ../common.cpp
        ${MAIN_CPP}
        model.c
    )

    target_link_libraries(${EXECUTABLE_SOLVER} SUNDIALS::cvode SUNDIALS::kinsol)

    add_custom_command(TARGET ${EXECUTABLE_SOLVER} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy ${EXECUTABLE_SOLVER} ${CMAKE_BINARY_DIR}/${EXECUTABLE_SOLVER})
endfunction()

function(build_executable EXECUTABLE)
    set(ONE_VALUE_KEYWORDS
        ENDING_POINT
        POINT_INTERVAL
        STEP
    )

    cmake_parse_arguments(ARG "" "${ONE_VALUE_KEYWORDS}" "" ${ARGN})

    if("${ARG_ENDING_POINT}" STREQUAL "")
        set(ENDING_POINT 1000.0)
    else()
        set(ENDING_POINT ${ARG_ENDING_POINT})
    endif()

    if("${ARG_POINT_INTERVAL}" STREQUAL "")
        set(POINT_INTERVAL 1.0)
    else()
        set(POINT_INTERVAL ${ARG_POINT_INTERVAL})
    endif()

    if("${ARG_STEP}" STREQUAL "")
        set(STEP 0.1)
    else()
        set(STEP ${ARG_STEP})
    endif()

    include_directories(${CMAKE_CURRENT_SOURCE_DIR})

    add_c_executable(${EXECUTABLE} cvode)
    add_c_executable(${EXECUTABLE} fe)
endfunction()
