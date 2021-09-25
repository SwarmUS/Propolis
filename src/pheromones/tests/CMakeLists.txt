set(TEST_NAME test-propolis-pheromones)
 
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
    UserCallResponseDTOUnitTests.cpp
    UserCallTargetDTOUnitTests.cpp
    
    vm-message/BuzzMessageDTOUnitTests.cpp
    vm-message/BuzzMessagesDTOUnitTests.cpp
  
    HiveMindHostSerializerUnitTests.cpp
    HiveMindHostAccumulatorSerializerUnitTests.cpp
    HiveMindHostSerializerIntegrationTests.cpp
    HiveMindHostAccumulatorSerializerIntegrationTests.cpp

    HiveMindHostDeserializerUnitTests.cpp

    HiveMindHostDeserializerIntegrationTests.cpp

    HiveMindHostApiRequestDTOUnitTests.cpp
    HiveMindHostApiResponseDTOUnitTests.cpp
    BytesDTOUnitTests.cpp
    NeighborPositionDTOUnitTests.cpp
    GetNeighborRequestDTOUnitTests.cpp
    GetNeighborsListRequestDTOUnitTests.cpp
    GetNeighborResponseDTOUnitTests.cpp
    GetNeighborsListResponseDTOUnitTests.cpp
    GetAgentsListRequestDTOUnitTests.cpp
    GetAgentsListResponseDTOUnitTests.cpp

    HiveConnectHiveMindApiDTOUnitTests.cpp

    IPDiscoveryDTOUnitTests.cpp
    NetworkApiDTOUnitTests.cpp

    interloc/InterlocStateDTOUnitTest.cpp
    interloc/SetInterlocStateDTOUnitTests.cpp
    interloc/ConfigureTWRCalibrationDTOUnitTests.cpp
    interloc/InterlocConfigurationDTOUnitTests.cpp
    interloc/InterlocStateChangeDTOUnitTests.cpp
    interloc/InterloAPIDTOUnitTests.cpp
    interloc/InterlocRxFrameInfoDTOUnitTests.cpp
    interloc/InterlocRxFrameRawAngleDataDTOUnitTests.cpp
    interloc/InterlocRawAngleDataDTOUnitTests.cpp
    interloc/InterlocOutputMessageDTOUnitTests.cpp

    HiveConnectNetworkAccessDTOTests.cpp
    HiveConnectRootNodeDTOTests.cpp
    HiveConnectMeshEnableDTOTests.cpp
    HiveConnectNetworkConfigSetRequestDTOTests.cpp
    HiveConnectNetworkConfigSetResponseDTOTests.cpp
    HiveConnectNetworkConfigGetRequestDTOTests.cpp
    HiveConnectNetworkConfigGetResponseDTOTests.cpp)

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

        SwarmUS::Propolis::Pheromones
)

add_test(NAME ${TEST_NAME}
         COMMAND ${TEST_NAME})
