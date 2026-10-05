add_library(Editor STATIC
        Src/EditorMain.cpp
)
add_library(Loom::Editor ALIAS Editor)

target_include_directories(Editor
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Editor
        PUBLIC Loom::Platform
        PRIVATE SDL3::SDL3)

loom_set_warnings(Editor)