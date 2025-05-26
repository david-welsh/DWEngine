cmake_minimum_required(VERSION 3.31)
project(DWEngine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE ENGINE_SOURCES DWEngine/*.cpp)
add_executable(DWEngine ${ENGINE_SOURCES})

find_package(Lua REQUIRED)
target_include_directories(DWEngine PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(DWEngine PRIVATE ${LUA_LIBRARIES})

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(DWEngine
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(DWEngine PRIVATE avif)
target_link_libraries(DWEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

find_package(SDL2_mixer CONFIG REQUIRED)
target_link_libraries(DWEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(DWEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

target_include_directories(DWEngine PRIVATE external/sol2)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(DWEngine PRIVATE nlohmann_json::nlohmann_json)

if (WIN32)
    target_link_libraries(
            DWEngine PRIVATE SDL2main
    )
endif()