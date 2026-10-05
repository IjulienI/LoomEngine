add_library(Platform STATIC
        DeleteMe.h
)
add_library(Loom::Platform ALIAS Platform)

target_include_directories(Platform
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Platform
        PUBLIC Loom::Core
        PRIVATE SDL3::SDL3)

loom_set_warnings(Platform)