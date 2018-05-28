# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build aufgabe_2_und_3
add_executable(aufgabe_2_und_3 aufgabe_2_und_3.cpp)

# Build aufgabe_6
add_executable(aufgabe_6 
aufgabe_6.cpp 
circle.cpp)

# Build aufgabe_9
add_executable(aufgabe_9 aufgabe_9.cpp)

# Build aufgabe_11
add_executable(aufgabe_11 aufgabe_11.cpp)  
  
# Build aufgabe_12
add_executable(aufgbae_12 aufgbae_12.cpp) 

# Build aufgabe_13
add_executable(aufgabe_13 aufgabe_13.cpp)  

