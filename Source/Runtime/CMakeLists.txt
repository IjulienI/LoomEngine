add_executable(Runtime Src/RuntimeMain.cpp)

target_link_libraries(Runtime PRIVATE Loom::Engine)

loom_set_warnings(Runtime)