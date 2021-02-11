set(LIB_NAME "swarmus-propolis-tests-freertos")
set(LIB_ALIAS "SwarmUS::Propolis::Tests::FreeRTOS")

include(freertos/common)
freertos_fetch_kernel()

set(LIB_SOURCES
    src/freertos_hooks.c
 )

set(LIB_HEADERS
    include/FreeRTOSConfig.h
)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(FreeRTOS COMPONENTS POSIX REQUIRED)


target_include_directories(${LIB_NAME}
    SYSTEM PUBLIC
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

       # Allows freertos to build properly
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/freertos>
       $<INSTALL_INTERFACE:include>
       ${FREERTOS_KERNEL_PATH}/include
       ${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/Posix
)

target_link_libraries(${LIB_NAME}
    PRIVATE    
        Threads::Threads
        FreeRTOS::POSIX

        FreeRTOS::Coroutine
        FreeRTOS::EventGroups
        FreeRTOS::StreamBuffer
        FreeRTOS::Timers
        FreeRTOS::Heap::3

)


# Removing warnings from freertos compilation on executable target
if (DISABLE_EXTERNAL_WARNINGS) 
    target_compile_options(${LIB_NAME} PRIVATE -w)
    set_target_properties(${LIB_NAME} PROPERTIES CXX_CLANG_TIDY "" )
    set_target_properties(${LIB_NAME} PROPERTIES C_CLANG_TIDY "" )
endif()
