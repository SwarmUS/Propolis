set(TEST_NAME test-propolis-posix)
 
set(TEST_SOURCES
    CompileTest.cpp
)

set(TEST_HEADERS

)

add_executable(${TEST_NAME} ${TEST_SOURCES} ${TEST_HEADERS})

target_link_libraries(${TEST_NAME}
    PUBLIC
        gtest
        gtest_main
        gmock

        SwarmUS::Propolis::OS::POSIX
        SwarmUS::Propolis::OS::Common
)
add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})
