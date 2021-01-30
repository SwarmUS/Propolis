set(TEST_NAME test-propolis-hivemind-host)
 
set(TEST_SOURCES
    FunctionCallArgumentDTOUnitTests.cpp
    FunctionCallRequestDTOUnitTests.cpp
    RequestDTOUnitTests.cpp
    MessageDTOUnitTests.cpp
  
    HiveMindSerializerUnitTests.cpp
    HiveMindSerializerIntegrationTests.cpp

    HiveMindDeserializerUnitTests.cpp
    HiveMindDeserializerIntegrationTests.cpp
)

set(TEST_HEADERS
    mocks/ProtobufStreamInterfaceMock.h
    mocks/ProtobufStreamBufferInterfaceMock.h
)

add_executable(${TEST_NAME} ${TEST_SOURCES} ${TEST_HEADERS})

target_link_libraries(${TEST_NAME}
    PUBLIC
        gtest
        gtest_main
        gmock

        SwarmUS::Propolis::Pheromones::HiveMind::Host
)

add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})
