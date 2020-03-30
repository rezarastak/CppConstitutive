DEAL_II_INITIALIZE_CACHED_VARIABLES()
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/external/include")
FILE(GLOB TARGET_SRC  "*.cc")
ADD_EXECUTABLE(catch2_tests ${TARGET_SRC})
DEAL_II_SETUP_TARGET(catch2_tests)
ADD_CUSTOM_TARGET(tests
    COMMAND ./catch2_tests
    DEPENDS catch2_tests)
