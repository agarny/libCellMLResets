get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)

build_executable(${DIR}
    ENDING_POINT
        30
    POINT_INTERVAL
        1
    STEP
        0.1
)
