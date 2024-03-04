cmake_minimum_required(VERSION 3.22)
# set the projectX name to the name of your project
project(BallCollision)

set(CMAKE_CXX_STANDARD 14)
# set(SOURCE_FILES main.cpp)

add_executable(BallCollision src/main.cpp src/utilities/MiddleAverageFilter.h src/entity/Ball.cpp src/entity/Ball.h src/system/DrawSystem.cpp src/system/DrawSystem.h src/entity/World.cpp src/entity/World.h src/system/SystemBase.cpp src/system/SystemBase.h src/engine/Game.cpp src/engine/Game.h src/system/MovementSystem.cpp src/system/MovementSystem.h src/system/FpsDebugSystem.cpp src/system/FpsDebugSystem.h src/system/CollisionSystem.cpp src/system/CollisionSystem.h src/utilities/Quadtree.h src/utilities/RectUtils.h src/utilities/Vector2dUtils.h src/system/DrawCollisionSystem.cpp src/system/DrawCollisionSystem.h)
#add_executable(Game ${SOURCE_FILES})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
