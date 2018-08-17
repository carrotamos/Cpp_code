find_path (isam_INCLUDE_DIR isam.h /usr/local/include/isam/ /usr/include/isam/)
find_library (isam_LIBRARY NAMES libisam.a PATH /usr/lib /usr/local/lib)

IF (isam_INCLUDE_DIR AND isam_LIBRARY )
    SET (isam_FOUND TRUE)
ENDIF (isam_INCLUDE_DIR AND isam_LIBRARY )

IF (isam_FOUND)
    MESSAGE (STATUS "Found Isam: "  ${isam_LIBRARY}  )
ELSE (isam_FOUND)
    MESSAGE (FATAL_ERROR "Could not found isam!!")
ENDIF (isam_FOUND)
