add_library(Core STATIC
        Include/Core/Log/Log.h
        Include/Core/Core.h
        Include/Core/Base/SmartPointer.h
        Include/Core/Base/Memory.h
        Src/Base/Memory.cpp
)
add_library(Loom::Core ALIAS Core)

target_include_directories(Core
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Src
)

#----------------------------------------
# Dependencies3
#----------------------------------------
target_link_libraries(Core
        PUBLIC glm::glm Tracy::TracyClient
        PRIVATE spdlog::spdlog
)

target_compile_features(Core PUBLIC cxx_std_20)

loom_set_warnings(Core)