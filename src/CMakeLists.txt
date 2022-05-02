
message(STATUS ${CMAKE_CPP_COMPILER})

set(game_sources main.cpp FrameWork.cpp HandleWindow.cpp)

set(ext_sources "C:/Users/bibi/Downloads/glfw-3.3.7/glfw-3.3.7/deps/glad_gl.c")

list(APPEND EXTRA_LIBS "C:/Users/bibi/Downloads/glfw-3.3.7/glfw-3.3.7/src/libglfw3.a")

list(APPEND EXTRA_INCLUDES "C:/Users/bibi/Downloads/glfw-3.3.7/glfw-3.3.7/include" "C:/Users/bibi/Downloads/glfw-3.3.7/glfw-3.3.7/deps")

add_executable(game ${game_sources} ${ext_sources} ${game_headers})

target_include_directories(game PUBLIC "${PROJECT_BINARY_DIR}/include" "../include" ${EXTRA_INCLUDES})

target_link_libraries(game PUBLIC ${EXTRA_LIBS})
