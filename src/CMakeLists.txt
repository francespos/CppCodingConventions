set(LPX_SRC math/vec2.cpp math/mat2.cpp)

add_library(lpx STATIC ${LPX_SRC})
set_property(TARGET lpx PROPERTY CXX_STANDARD 17)

target_link_libraries(lpx PUBLIC m)
target_include_directories(lpx PUBLIC ${CMAKE_SOURCE_DIR}/include)