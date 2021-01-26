set(LIB_NAME "swarmus-propolis-pheromones-common")
set(LIB_ALIAS "SwarmUS::Propolis::Pheromones::Common")


add_library(${LIB_NAME} INTERFACE)
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    INTERFACE
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>
)
