set(LIB_NAME "swarmus-propolis-pheromones")
set(LIB_ALIAS "SwarmUS::Propolis::Pheromones")

include(pheromones/common)
pheromones_fetch_populate()

include(DefaultPheromonesOptions.cmake) # not a module, need to specify "".cmake"

configure_file(include/pheromones/PheromonesSettings.in.h include/pheromones/PheromonesSettings.h)

# Installation destinations
set(PROPOLIS-PHEROMONES_LIB_INSTALL_DEST "lib/swarmus-propolis-pheromones")
set(PROPOLIS_PHEROMONES_INCLUDE_INSTALL_DEST "include/pheromones")

set(LIB_SOURCES
    src/HiveMindHostDeserializer.cpp
    src/HiveMindHostSerializer.cpp
    src/HiveMindHostAccumulatorSerializer.cpp

    src/MessageDTO.cpp
    src/ResponseDTO.cpp
    src/RequestDTO.cpp
    src/GenericResponseDTO.cpp
    src/GreetingDTO.cpp

    src/BuzzMessageDTO.cpp

    src/FunctionCallArgumentDTO.cpp
    src/FunctionCallRequestDTO.cpp
    src/FunctionCallResponseDTO.cpp

    src/FunctionListLengthRequestDTO.cpp
    src/FunctionListLengthResponseDTO.cpp
    src/FunctionDescriptionDTO.cpp
    src/FunctionDescriptionArgumentDTO.cpp
    src/FunctionDescriptionArgumentTypeDTO.cpp
    src/FunctionDescriptionRequestDTO.cpp
    src/FunctionDescriptionResponseDTO.cpp

    src/UserCallRequestDTO.cpp
    src/UserCallResponseDTO.cpp
    src/UserCallTargetDTO.cpp

    src/HiveMindHostApiRequestDTO.cpp
    src/HiveMindHostApiResponseDTO.cpp
    src/BytesDTO.cpp
    src/NeighborPositionDTO.cpp
    src/GetNeighborRequestDTO.cpp
    src/GetNeighborsListRequestDTO.cpp
    src/GetNeighborResponseDTO.cpp
    src/GetNeighborsListResponseDTO.cpp
    src/GetAgentsListRequestDTO.cpp
    src/GetAgentsListResponseDTO.cpp

    src/IpDiscoveryDTO.cpp
    src/NetworkApiDTO.cpp

    src/HiveConnectHiveMindApiDTO.cpp

    src/interloc/InterlocStateDTO.cpp
    src/interloc/SetInterlocStateDTO.cpp
    src/interloc/ConfigureTWRCalibrationDTO.cpp
    src/interloc/ConfigureAngleCalibrationDTO.cpp
    src/interloc/InterlocConfigurationDTO.cpp
    src/interloc/InterlocStateChangeDTO.cpp
    src/interloc/InterlocAPIDTO.cpp
    src/interloc/InterlocOutputMessageDTO.cpp
    src/interloc/InterlocRawAngleDataDTO.cpp
    src/interloc/InterlocRxFrameInfoDTO.cpp
    src/interloc/InterlocRxFrameRawAngleDataDTO.cpp

    src/HiveConnectNetworkAccessDTO.cpp
    src/HiveConnectRootNode.cpp
    src/HiveConnectMeshEnableDTO.cpp
    src/HiveConnectNetworkConfigSetRequestDTO.cpp
    src/HiveConnectNetworkConfigSetResponseDTO.cpp
    src/HiveConnectNetworkConfigGetRequestDTO.cpp src/HiveConnectNetworkConfigGetResponse.cpp)

set(LIB_HEADERS
    include/pheromones/HiveMindHostDeserializer.h
    include/pheromones/IHiveMindHostDeserializer.h
    include/pheromones/HiveMindHostSerializer.h
    include/pheromones/IHiveMindHostSerializer.h
    include/pheromones/HiveMindHostAccumulatorSerializer.h
    include/pheromones/IProtobufStream.h
    include/pheromones/IProtobufInputStream.h
    include/pheromones/IProtobufOutputStream.h

    include/pheromones/FunctionCallArgumentDTO.h
    include/pheromones/FunctionCallRequestDTO.h
    include/pheromones/FunctionCallResponseDTO.h

    include/pheromones/BuzzMessageDTO.h

    include/pheromones/FunctionListLengthRequestDTO.h
    include/pheromones/FunctionListLengthResponseDTO.h
    include/pheromones/FunctionDescriptionDTO.h
    include/pheromones/FunctionDescriptionArgumentDTO.h
    include/pheromones/FunctionDescriptionArgumentTypeDTO.h
    include/pheromones/FunctionDescriptionRequestDTO.h
    include/pheromones/FunctionDescriptionResponseDTO.h

    include/pheromones/GenericResponseDTO.h
    include/pheromones/GreetingDTO.h
    include/pheromones/MessageDTO.h
    include/pheromones/ResponseDTO.h
    include/pheromones/RequestDTO.h
    include/pheromones/UserCallRequestDTO.h
    include/pheromones/UserCallTargetDTO.h
    include/pheromones/UserCallResponseDTO.h

    include/pheromones/HiveMindHostApiResponseDTO.h
    include/pheromones/HiveMindHostApiRequestDTO.h
    include/pheromones/BytesDTO.h
    include/pheromones/NeighborPositionDTO.h
    include/pheromones/GetNeighborRequestDTO.h
    include/pheromones/GetNeighborsListRequestDTO.h
    include/pheromones/GetNeighborResponseDTO.h
    include/pheromones/GetNeighborsListResponseDTO.h
    include/pheromones/GetAgentsListRequestDTO.h
    include/pheromones/GetAgentsListResponseDTO.h

    include/pheromones/HiveConnectHiveMindApiDTO.h

    include/pheromones/IpDiscoveryDTO.h
    include/pheromones/NetworkApiDTO.h

    include/pheromones/interloc/InterlocStateDTO.h
    include/pheromones/interloc/SetInterlocStateDTO.h
    include/pheromones/interloc/ConfigureTWRCalibrationDTO.h
    include/pheromones/interloc/ConfigureAngleCalibrationDTO.h
    include/pheromones/interloc/InterlocAPIDTO.h
    include/pheromones/interloc/InterlocConfigurationDTO.h
    include/pheromones/interloc/InterlocStateChangeDTO.h
    include/pheromones/interloc/InterlocRxFrameInfoDTO.h
    include/pheromones/interloc/InterlocRxFrameRawAngleDataDTO.h
    include/pheromones/interloc/InterlocRawAngleDataDTO.h
    include/pheromones/interloc/InterlocOutputMessageDTO.h

    include/pheromones/HiveConnectNetworkAccessDTO.h
    include/pheromones/HiveConnectRootNodeDTO.h
    include/pheromones/HiveConnectMeshEnableDTO.h
    include/pheromones/HiveConnectNetworkConfigSetRequestDTO.h
    include/pheromones/HiveConnectNetworkConfigSetResponseDTO.h
    include/pheromones/HiveConnectNetworkConfigGetRequestDTO.h
    include/pheromones/HiveConnectNetowrkConfigGetResponseDTO.h)

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
       $<INSTALL_INTERFACE:${PROPOLIS_PHEROMONES_INCLUDE_INSTALL_DEST}>
       $<INSTALL_INTERFACE:${PROPOLIS-PHEROMONES_LIB_INSTALL_DEST}>

    PRIVATE
       include/pheromones
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        protobuf-nanopb-static
        SwarmUS::Pheromones
)


if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

install(TARGETS ${LIB_NAME} EXPORT ${LIB_NAME} DESTINATION "${PROPOLIS-PHEROMONES_LIB_INSTALL_DEST}")
install(FILES ${LIB_HEADERS} DESTINATION "${PROPOLIS_PHEROMONES_INCLUDE_INSTALL_DEST}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/pheromones/PheromonesSettings.h DESTINATION "${PROPOLIS_PHEROMONES_INCLUDE_INSTALL_DEST}")
install(FILES swarmus-propolis-pheromones-config.cmake DESTINATION "${PROPOLIS-PHEROMONES_LIB_INSTALL_DEST}")

install(EXPORT ${LIB_NAME} DESTINATION "${PROPOLIS-PHEROMONES_LIB_INSTALL_DEST}")
