add_executable(CppCodingConventions MyProgram.cpp Math/Vector3.cpp)
set_property(TARGET CppCodingConventions PROPERTY CXX_STANDARD 17)

target_link_libraries(CppCodingConventions PUBLIC m)
target_include_directories(CppCodingConventions PUBLIC ../include)