add_executable(Sandbox Src/SandboxMain.cpp)

target_link_libraries(Sandbox PRIVATE Loom::Engine)

loom_set_warnings(Sandbox)