add_library(Engine STATIC
        Src/EngineMain.h
)
add_library(Loom::Engine ALIAS Engine)

target_include_directories(Engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies
#----------------------------------------
target_link_libraries(Engine
        PUBLIC Loom::Platform)

loom_set_warnings(Engine)