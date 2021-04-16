set(LIB_NAME "swarmus-propolis-os-interface")
set(LIB_ALIAS "SwarmUS::Propolis::OS")

set(LIB_SOURCES
)

set(LIB_HEADERS
        include/IAbstractTask.h
        include/IConditionVariable.h
        include/IMutex.h
        )

add_library(${LIB_NAME} INTERFACE)
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})

target_sources(${LIB_NAME} INTERFACE ${LIB_HEADERS} ${LIB_SOURCES})

target_include_directories(${LIB_NAME}
        INTERFACE
        include
        )

add_subdirectory(freertos)
add_subdirectory(posix)
add_subdirectory(common)
