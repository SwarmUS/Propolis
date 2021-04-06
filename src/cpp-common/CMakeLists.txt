set(LIB_NAME "swarmus-propolis-cpp-common")
set(LIB_ALIAS "SwarmUS::Propolis::Cpp::Common")

# Installation destinations
set(CPP-COMMON_LIB_INSTALL_DEST "lib/pheromones")
set(CPP-COMMON_INCLUDE_INSTALL_DEST "include/pheromones")


set(LIB_SOURCES
)

set(LIB_HEADERS
    include/cpp-common/ICircularQueue.h
    include/cpp-common/CircularQueue.h
    include/cpp-common/CircularQueue.tpp
    include/cpp-common/CircularQueueStack.h
    include/cpp-common/CppUtils.h
    include/cpp-common/IHashMap.h
    include/cpp-common/HashMap.h
    include/cpp-common/HashMap.tpp
    include/cpp-common/HashFunction.h
    include/cpp-common/HashMapStack.h
)

add_library(${LIB_NAME} STATIC ${LIB_HEADERS} ${LIB_SOURCES})
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME})
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        src
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()

install(TARGETS ${LIB_NAME} EXPORT ${LIB_NAME} DESTINATION "${CPP-COMMON_LIB_INSTALL_DEST}")
install(FILES ${LIB_HEADERS} DESTINATION "${CPP-COMMON_INCLUDE_INSTALL_DEST}")

install(EXPORT ${LIB_NAME} DESTINATION "${CPP-COMMON_LIB_INSTALL_DEST}")