## Find source and headers
FILE(GLOB HEADERS *.h)
FILE(GLOB SOURCES *.cpp)

IF(CMAKE_HAS_SORT)
  LIST(SORT HEADERS)
  LIST(SORT SOURCES)
ENDIF(CMAKE_HAS_SORT)

## Build
SET(CMAKE_CXX_FLAGS "-DRLOG_COMPONENT=iolamodel")
ADD_LIBRARY(iolamodel ${SOURCES})
