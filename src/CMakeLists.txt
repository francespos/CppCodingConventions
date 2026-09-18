add_executable(CppCodingConventions)

target_sources(CppCodingConventions PRIVATE main.cpp math/vec2.cpp math/mat2.cpp)
set_property(TARGET CppCodingConventions PROPERTY CXX_STANDARD 17)

target_link_libraries(CppCodingConventions PRIVATE m)
target_include_directories(CppCodingConventions PRIVATE ${CMAKE_SOURCE_DIR}/include)