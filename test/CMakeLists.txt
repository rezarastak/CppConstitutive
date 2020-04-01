CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)
#----------------------- Finding libraries and package -----------------------
FIND_PACKAGE(deal.II 9.0 REQUIRED
  HINTS ${DEAL_II_DIR} $ENV{DEAL_II_DIR}
  )
#-------------------------------- Set up tests ------------------------------
DEAL_II_INITIALIZE_CACHED_VARIABLES()
include_directories("${CMAKE_SOURCE_DIR}/include")
FILE(GLOB TARGET_SRC  "*.cc")
ADD_EXECUTABLE(catch2_tests ${TARGET_SRC})
DEAL_II_SETUP_TARGET(catch2_tests)
ADD_CUSTOM_TARGET(tests
    COMMAND ./catch2_tests
    DEPENDS catch2_tests)
