set(LIB_NAME "swarmus-propolis-pheromones-hivemind-host")
set(LIB_ALIAS "SwarmUS::Propolis::Pheromones::HiveMind::Host")

set(LIB_SOURCES
    src/HiveMindDeserializer.cpp

    src/FunctionCallArgumentDTO.cpp
    src/FunctionCallRequestDTO.cpp
    src/MessageDTO.cpp
    src/RequestDTO.cpp
)

set(LIB_HEADERS
    include/hivemind-host/HiveMindDeserializer.h
    include/hivemind-host/IHiveMindDeserializer.h

    include/hivemind-host/FunctionCallArgumentDTO.h
    include/hivemind-host/FunctionCallRequestDTO.h
    include/hivemind-host/MessageDTO.h
    include/hivemind-host/RequestDTO.h
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
    STATIC
        protobuf-nanopb-static
        SwarmUS::Pheromones::HiveMind::Host
        SwarmUS::Propolis::Pheromones::Common
)


if(ENABLE_TESTS)
    #add_subdirectory(tests)
endif()
