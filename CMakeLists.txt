set(CMAKE_BUILD_TYPE Debug)


project(Canvas)
add_executable(Canvas main.cpp canvas.cpp line.cpp player.cpp ray.cpp)
target_link_libraries(Canvas PRIVATE sfml-graphics sfml-window sfml-system)
