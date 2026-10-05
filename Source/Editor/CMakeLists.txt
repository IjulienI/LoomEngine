add_executable(Editor
        Src/EditorMain.cpp
)

target_include_directories(Editor
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Editor
        PUBLIC Loom::Engine)

loom_set_warnings(Editor)