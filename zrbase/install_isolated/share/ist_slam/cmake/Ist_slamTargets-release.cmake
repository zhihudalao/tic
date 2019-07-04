#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ist_slam" for configuration "Release"
set_property(TARGET ist_slam APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ist_slam PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libist_slam.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS ist_slam )
list(APPEND _IMPORT_CHECK_FILES_FOR_ist_slam "${_IMPORT_PREFIX}/lib/libist_slam.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
