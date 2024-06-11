
set(target_count 3)
foreach(i RANGE 1 ${target_count})
    add_executable(singleton_lazy98_${i} singleton_lazy98_${i}.cpp)
    set_target_properties(singleton_lazy98_${i} PROPERTIES
            CXX_STANDARD 98
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO)
endforeach()

add_executable(singleton_lazy11 singleton_lazy11.cpp)
add_executable(singleton_eager98 singleton_eager98.cpp)
set_target_properties(singleton_eager98 PROPERTIES
        CXX_STANDARD 98
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)