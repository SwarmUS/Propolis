set(LIB_NAME "swarmus-propolis-pheromones-hivemind-host")
set(LIB_ALIAS "SwarmUS::Propolis::Pheromones::HiveMind::Host")

set(LIB_SOURCES
    src/HiveMindHostDeserializer.cpp
    src/HiveMindHostSerializer.cpp

    src/MessageDTO.cpp
    src/ResponseDTO.cpp
    src/RequestDTO.cpp
    src/GenericResponseDTO.cpp
    src/GreetingDTO.cpp

    src/IdRequestDTO.cpp
    src/IdResponseDTO.cpp

    src/FunctionCallArgumentDTO.cpp
    src/FunctionCallRequestDTO.cpp
    src/FunctionCallResponseDTO.cpp
    src/UserCallRequestDTO.cpp
    src/UserCallResponseDTO.cpp
    src/UserCallTargetDTO.cpp


    src/HiveMindApiRequestDTO.cpp
    src/HiveMindApiResponseDTO.cpp
    src/SwarmApiRequestDTO.cpp
    src/SwarmApiResponseDTO.cpp
)

set(LIB_HEADERS
    include/hivemind-host/HiveMindHostDeserializer.h
    include/hivemind-host/IHiveMindHostDeserializer.h
    include/hivemind-host/HiveMindHostSerializer.h
    include/hivemind-host/IHiveMindHostSerializer.h

    include/hivemind-host/FunctionCallArgumentDTO.h
    include/hivemind-host/FunctionCallRequestDTO.h
    include/hivemind-host/FunctionCallResponseDTO.h
    include/hivemind-host/GenericResponseDTO.h
    include/hivemind-host/GreetingDTO.h
    include/hivemind-host/MessageDTO.h
    include/hivemind-host/ResponseDTO.h
    include/hivemind-host/RequestDTO.h
    include/hivemind-host/IdRequestDTO.h
    include/hivemind-host/IdRequestDTO.h
    include/hivemind-host/UserCallRequestDTO.h
    include/hivemind-host/UserCallTargetDTO.h
    include/hivemind-host/UserCallResponseDTO.h

    include/hivemind-host/HiveMindApiResponseDTO.h
    include/hivemind-host/HiveMindApiRequestDTO.h
    include/hivemind-host/SwarmApiResponseDTO.h
    include/hivemind-host/SwarmApiRequestDTO.h
)

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>

    PRIVATE
       include/hivemind-host
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        protobuf-nanopb-static
        SwarmUS::Pheromones::HiveMind::Host
        SwarmUS::Propolis::Pheromones::Common
)


if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
