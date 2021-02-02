set(LIB_NAME "swarmus-propolis-freertos-static-utils")
set(LIB_ALIAS "SwarmUS::Propolis::FreeRTOS::Static::Utils")

set(LIB_SOURCES
    src/LockGuard.cpp
    src/Mutex.cpp
)

set(LIB_HEADERS
    include/freertos-utils/AbstractTask.tpp
    include/freertos-utils/AbstractTask.h
    include/freertos-utils/LockGuard.h
    include/freertos-utils/Mutex.h
)

add_library(${LIB_NAME} INTERFACE)
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_sources(${LIB_NAME} INTERFACE ${LIB_HEADERS} ${LIB_SOURCES})

target_include_directories(${LIB_NAME}
    INTERFACE
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>
       freertos-utils
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
