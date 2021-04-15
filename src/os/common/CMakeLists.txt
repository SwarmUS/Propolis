set(LIB_NAME "swarmus-propolis-os-common")
set(LIB_ALIAS "SwarmUS::Propolis::OS::Common")

set(LIB_SOURCES
        src/LockGuard.cpp
        )

set(LIB_HEADERS
        include/LockGuard.h
        include/ThreadSafeQueue.h
        )

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>

        )

target_link_libraries(${LIB_NAME}
        PUBLIC
        SwarmUS::Propolis::Cpp::Common
        SwarmUS::Propolis::OS
)
