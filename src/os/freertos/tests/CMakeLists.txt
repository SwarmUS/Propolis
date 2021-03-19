set(TEST_NAME test-propolis-freertos-static-utils)
 
set(TEST_SOURCES
    MutexUnitTests.cpp
    AbstractTaskUnitTests.cpp
    TaskUnitTests.cpp
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
        SwarmUS::Propolis::OS::FreeRTOS
        SwarmUS::Propolis::OS::Common
)

add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})
