set(LIB_NAME "swarmus-propolis-c-common")
set(LIB_ALIAS "SwarmUS::Propolis::C::Common")


set(LIB_SOURCES
    src/circular_buff.c
    src/software_crc.c
)

set(LIB_HEADERS
    include/c-common/circular_buff.h
    include/c-common/software_crc.h
)

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        src
        include/c-common
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
