add_library(Engine INTERFACE)
add_library(Loom::Engine ALIAS Engine)

target_include_directories(Engine
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Include
                  ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Engine
        INTERFACE Loom::Platform)

#loom_set_warnings(Engine)