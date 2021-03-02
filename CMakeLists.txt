#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(msis_xray)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()





#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})

#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(msis_xray  msis_xray.cc ${sources} ${headers} ${TOOLS_FORTRAN_OBJECTS})
target_link_libraries(msis_xray ${Geant4_LIBRARIES} ${HBOOK_LIBRARIES} )



# install and link periodic boundary conditions library

#find_package(g4pbc REQUIRED NO_MODULE)
#include_directories(${g4pbc_INCLUDE_DIRS})
#target_link_libraries(msis_xray g4pbc::g4pbc)

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build TestEm4. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#

set(MSIS_XRAY_DATA
  )

foreach(_data ${MSIS_XRAY_DATA})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_data}
    ${PROJECT_BINARY_DIR}/${_data}
    COPYONLY
    )
endforeach()

set(MSIS_XRAY_SCRIPTS
  )

foreach(_script ${MSIS_XRAY_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

foreach(_script ${MSIS_XRAY_RAMDISK})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_rd}
    ${PROJECT_BINARY_DIR}/${_rd}
    COPYONLY
    )
endforeach()

set(MSIS_XRAY_DOC
  )

foreach(_doc ${MSIS_XRAY_DOC})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_doc}
    ${PROJECT_BINARY_DIR}/${_doc}
    COPYONLY
    )
endforeach()


#----------------------------------------------------------------------------
# Copy the link to the macro directory and copy the macro directory with
# all of its files.

file( COPY ${PROJECT_SOURCE_DIR}/data
  DESTINATION ${PROJECT_BINARY_DIR})

file( COPY ${PROJECT_SOURCE_DIR}/macros
  DESTINATION ${PROJECT_BINARY_DIR})

file( COPY ${PROJECT_SOURCE_DIR}/scripts
  DESTINATION ${PROJECT_BINARY_DIR})

file( COPY ${PROJECT_SOURCE_DIR}/ramdisk
    DESTINATION ${PROJECT_BINARY_DIR})

file( COPY ${PROJECT_SOURCE_DIR}/doc
  DESTINATION ${PROJECT_BINARY_DIR})
#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS msis_xray DESTINATION bin)
