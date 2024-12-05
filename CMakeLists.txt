cmake_minimum_required(VERSION 3.30.5)
project(sfml-app LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

set(SOURCE_DIR src)
set(SOURCE
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/extra/consts.h
    ${SOURCE_DIR}/extra/textures.h
    ${SOURCE_DIR}/classes/game/game.h ${SOURCE_DIR}/classes/game/game.cpp
    ${SOURCE_DIR}/classes/controller/controller.h ${SOURCE_DIR}/classes/controller/controller.cpp
    ${SOURCE_DIR}/classes/entity/entity.h ${SOURCE_DIR}/classes/entity/entity.cpp
    ${SOURCE_DIR}/classes/player/player.h ${SOURCE_DIR}/classes/player/player.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

install(TARGETS ${CMAKE_PROJECT_NAME})
