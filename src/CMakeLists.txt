add_executable(CppCodingConventions main.cpp math/Vector3d.cpp foo/foo.cpp)
set_property(TARGET CppCodingConventions PROPERTY CXX_STANDARD 17)

target_link_libraries(CppCodingConventions PRIVATE m)
target_include_directories(CppCodingConventions PRIVATE ../include)