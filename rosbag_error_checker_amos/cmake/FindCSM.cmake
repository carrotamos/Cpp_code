
find_path (CSM_H_DIR csm.h /usr/local/include/csm/csm)
set(CSM_INCLUDE_DIR ${CSM_H_DIR}/..)
find_library (CSM_LIBRARY libcsm_eigen.a PATH /usr/local/lib)

if(CSM_INCLUDE_DIR AND CSM_LIBRARY )
    set (CSM_FOUND TRUE)
endif()

if (CSM_FOUND)
    message (STATUS "Found CSM:
    library path: ${CSM_LIBRARY};
    include path: ${CSM_INCLUDE_DIR}"  )
else()
    message (FATAL_ERROR "Could not found csm!!")
endif ()
