find_path (Pita_INCLUDE_DIRS pita.h /usr/local/include/pita)

find_library (PITA_CORE NAMES libpita_core.so PATHS /usr/local/lib)
find_library (PITA_SLAM NAMES libpita_slam.so PATHS /usr/local/lib)

set(Pita_LIBRARIES ${PITA_CORE})

list(APPEND Pita_LIBRARIES ${PITA_SLAM})

foreach(iterm ${Pita_LIBRARIES})
    MESSAGE(STATUS "Find Pita LIB: " ${iterm})
endforeach()

IF (Pita_INCLUDE_DIRS AND Pita_LIBRARIES )
    SET (Pita_FOUND TRUE)
ENDIF (Pita_INCLUDE_DIRS AND Pita_LIBRARIES)

MESSAGE (STATUS "debug: "  ${Pita_FOUND})

IF(Pita_FOUND)
    MESSAGE (STATUS "Found pita: "  ${Pita_INCLUDE_DIRS})
ELSE(Pita_FOUND)
    MESSAGE (FATAL_ERROR "Could not found pita!!")
ENDIF (Pita_FOUND)
