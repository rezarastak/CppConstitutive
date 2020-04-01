#----------------------- Finding libraries and package -----------------------
FIND_PACKAGE(deal.II 9.0 QUIET
  HINTS ${DEAL_II_DIR} $ENV{DEAL_II_DIR}
  )
IF(NOT ${deal.II_FOUND})
  MESSAGE(FATAL_ERROR "\n"
    "*** Could not locate a (sufficiently recent) version of deal.II. ***\n\n"
    "You may want to either pass a flag -DDEAL_II_DIR=/path/to/deal.II to cmake\n"
    "or set an environment variable \"DEAL_II_DIR\" that contains this path."
    )
ENDIF()
#-------------------------------- Set up tests ------------------------------
DEAL_II_INITIALIZE_CACHED_VARIABLES()
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/external/include")
FILE(GLOB TARGET_SRC  "*.cc")
ADD_EXECUTABLE(catch2_tests ${TARGET_SRC})
DEAL_II_SETUP_TARGET(catch2_tests)
ADD_CUSTOM_TARGET(tests
    COMMAND ./catch2_tests
    DEPENDS catch2_tests)
