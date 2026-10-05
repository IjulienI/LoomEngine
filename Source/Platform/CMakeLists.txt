add_library(Platform INTERFACE
)
add_library(Loom::Platform ALIAS Platform)

target_include_directories(Platform
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include
         ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Platform
        INTERFACE Loom::Core
         SDL3::SDL3)

#loom_set_warnings(Platform)