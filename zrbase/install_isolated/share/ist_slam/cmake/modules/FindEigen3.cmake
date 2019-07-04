
find_package(Eigen3 QUIET NO_MODULE)
if (NOT EIGEN3_FOUND)
  list(APPEND EIGEN3_POSSIBLE_DIRS
    /usr/local/include/eigen3
    /usr/include/eigen3
  )
  find_path(EIGEN3_INCLUDE_DIR
    NAMES Eigen/Core
    PATHS ${EIGEN3_POSSIBLE_DIRS}
  )
  if (EIGEN3_INCLUDE_DIR AND EXISTS ${EIGEN3_INCLUDE_DIR})
    set(EIGEN3_FOUND TRUE)
  else()
    message(WARNING "Failed to find Eigen3. Please, define the path manually.")
  endif()
endif()
