
#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    find_package(ist_slam REQUIRED)
#    target_link_libraries(MY_TARGET_NAME PUBLIC ist_slam)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was ist_slam-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

set_and_check(IST_SLAM_CMAKE_DIR "${PACKAGE_PREFIX_DIR}/share/ist_slam/cmake")

set(CERES_DIR_HINTS /home/ubuntu/zrbase/install_isolated/lib/cmake/Ceres)
set(IST_SLAM_HAS_GRPC OFF)

if (ist_slam_FIND_QUIETLY)
   set(QUIET_OR_REQUIRED_OPTION "QUIET")
elseif (ist_slam_FIND_REQUIRED)
   set(QUIET_OR_REQUIRED_OPTION "REQUIRED")
else ()
   set(QUIET_OR_REQUIRED_OPTION "")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${IST_SLAM_CMAKE_DIR}/modules)

find_package(Ceres ${QUIET_OR_REQUIRED_OPTION} HINTS ${CERES_DIR_HINTS})
if (WIN32)
    find_package(glog REQUIRED)
endif()
find_package(Abseil ${QUIET_OR_REQUIRED_OPTION})
if(IST_SLAM_HAS_GRPC)
   find_package(async_grpc ${QUIET_OR_REQUIRED_OPTION})
endif()

include("${IST_SLAM_CMAKE_DIR}/Ist_slamTargets.cmake")

unset(QUIET_OR_REQUIRED_OPTION)
