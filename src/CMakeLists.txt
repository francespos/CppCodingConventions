add_executable(CppCodingConventions)

target_sources(CppCodingConventions PRIVATE main.cpp math/vector3.cpp math/matrix33.cpp)
set_property(TARGET CppCodingConventions PROPERTY CXX_STANDARD 17)

target_link_libraries(CppCodingConventions PRIVATE m)
target_include_directories(CppCodingConventions PRIVATE ../include)