set(LIB_NAME "swarmus-propolis-os-posix")
set(LIB_ALIAS "SwarmUS::Propolis::OS::POSIX")

set(LIB_SOURCES
    src/ConditionVariable.cpp
    src/Mutex.cpp
)

set(LIB_HEADERS
    include/AbstractTask.tpp
    include/AbstractTask.h

    include/BaseTask.h
    include/BaseTask.tpp

    include/ConditionVariable.h

    include/Mutex.h

    include/OSMacros.h
    include/Task.h
)

add_library(${LIB_NAME} INTERFACE)
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_sources(${LIB_NAME} INTERFACE ${LIB_HEADERS} ${LIB_SOURCES})

get_target_property(OS_INTERFACE_INCLUDES SwarmUS::Propolis::OS INTERFACE_INCLUDE_DIRECTORIES)

target_include_directories(${LIB_NAME}
    INTERFACE
        ${OS_INTERFACE_INCLUDES}
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
       $<INSTALL_INTERFACE:include>

)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
