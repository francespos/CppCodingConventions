add_executable(LpxDemo main.cpp)
set_property(TARGET LpxDemo PROPERTY CXX_STANDARD 17)
target_link_libraries(LpxDemo PRIVATE lpx)