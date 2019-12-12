CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)
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
DEAL_II_INITIALIZE_CACHED_VARIABLES()
#-------------------------------- Set up tests ------------------------------
PROJECT(constitutive)
ADD_SUBDIRECTORY(test)

