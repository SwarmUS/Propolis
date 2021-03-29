set(TEST_NAME test-propolis-hivemind-host)
 
set(TEST_SOURCES
    mocks/Utils.cpp

    FunctionCallArgumentDTOUnitTests.cpp
    FunctionCallRequestDTOUnitTests.cpp
    FunctionCallResponseDTOUnitTests.cpp

    FunctionListLengthRequestDTOUnitTests.cpp
    FunctionListLengthResponseDTOUnitTests.cpp
    FunctionDescriptionDTOUnitTests.cpp
    FunctionDescriptionArgumentDTOUnitTests.cpp
    FunctionDescriptionArgumentTypeDTOUnitTests.cpp
    FunctionDescriptionRequestDTOUnitTests.cpp
    FunctionDescriptionResponseDTOUnitTests.cpp

    RequestDTOUnitTests.cpp
    ResponseDTOUnitTests.cpp
    GreetingDTOUnitTests.cpp
    MessageDTOUnitTests.cpp
    UserCallRequestDTOUnitTests.cpp
    IdRequestDTOUnitTests.cpp
    IdResponseDTOUnitTests.cpp
    UserCallResponseDTOUnitTests.cpp
    UserCallTargetDTOUnitTests.cpp
    
    BuzzMessageDTOUnitTests.cpp
  
    HiveMindHostSerializerUnitTests.cpp
    HiveMindHostAccumulatorSerializerUnitTests.cpp
    HiveMindHostSerializerIntegrationTests.cpp
    HiveMindHostAccumulatorSerializerIntegrationTests.cpp

    HiveMindHostDeserializerUnitTests.cpp

    HiveMindHostDeserializerIntegrationTests.cpp

    HiveMindApiRequestDTOUnitTests.cpp
    HiveMindApiResponseDTOUnitTests.cpp

    IPDiscoveryDTOUnitTests.cpp
    NetworkApiDTOUnitTests.cpp
)

set(TEST_HEADERS
    mocks/Utils.h
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
