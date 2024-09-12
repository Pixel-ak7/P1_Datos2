# Agregar el ejecutable de pruebas
add_executable(runTests test_mpointer.cpp ../MPointerGC.cpp)

# Enlazar GoogleTest con el ejecutable de pruebas
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
