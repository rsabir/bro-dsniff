# Install script for directory: /home/rhost/Downloads/bro-2.4.1/aux/broccoli

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local/bro")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Debug")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
        set(_destfile "/usr/local/bro/etc/broccoli.conf")
        if (NOT "$ENV{DESTDIR}" STREQUAL "")
            # prepend install root prefix with install-time DESTDIR
            set(_destfile "$ENV{DESTDIR}//usr/local/bro/etc/broccoli.conf")
        endif ()
        if (EXISTS ${_destfile})
            message(STATUS "Skipping: ${_destfile} (already exists)")
            execute_process(COMMAND "/usr/bin/cmake" -E compare_files
                /home/rhost/Downloads/bro-2.4.1/aux/broccoli/broccoli.conf ${_destfile} RESULT_VARIABLE _diff)
            if (NOT "${_diff}" STREQUAL "0")
                message(STATUS "Installing: ${_destfile}.example")
                configure_file(/home/rhost/Downloads/bro-2.4.1/aux/broccoli/broccoli.conf ${_destfile}.example COPYONLY)
            endif ()
        else ()
            message(STATUS "Installing: ${_destfile}")
            # install() is not scriptable within install(), and
            # configure_file() is the next best thing
            configure_file(/home/rhost/Downloads/bro-2.4.1/aux/broccoli/broccoli.conf ${_destfile} COPYONLY)
            # TODO: create additional install_manifest files?
        endif ()
    
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/rhost/Downloads/bro-2.4.1/build/aux/broccoli/broccoli-config")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/rhost/Downloads/bro-2.4.1/build/aux/broccoli/src/cmake_install.cmake")
  INCLUDE("/home/rhost/Downloads/bro-2.4.1/build/aux/broccoli/test/cmake_install.cmake")
  INCLUDE("/home/rhost/Downloads/bro-2.4.1/build/aux/broccoli/doc/cmake_install.cmake")
  INCLUDE("/home/rhost/Downloads/bro-2.4.1/build/aux/broccoli/bindings/broccoli-python/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

