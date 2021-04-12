find_package(Nanopb REQUIRED)
find_package(swarmus-pheromones REQUIRED)

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/swarmus-propolis-pheromones.cmake)