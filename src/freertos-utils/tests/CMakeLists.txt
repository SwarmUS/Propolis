set(TEST_NAME test-propolis-freertos-utils)
 
set(TEST_SOURCES
    AbstractTaskUnitTests.cpp
)

set(TEST_HEADERS

)

add_executable(${TEST_NAME} ${TEST_SOURCES} ${TEST_HEADERS})

# Freertos to tests the lib
add_subdirectory(freertos-posix)

target_link_libraries(${TEST_NAME}
    PUBLIC
        gtest
        gtest_main
        gmock

        SwarmUS::Propolis::Tests::FreeRTOS
        SwarmUS::Propolis::FreeRTOS::Utils
)

add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})
