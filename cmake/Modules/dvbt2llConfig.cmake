INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DVBT2LL dvbt2ll)

FIND_PATH(
    DVBT2LL_INCLUDE_DIRS
    NAMES dvbt2ll/api.h
    HINTS $ENV{DVBT2LL_DIR}/include
        ${PC_DVBT2LL_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DVBT2LL_LIBRARIES
    NAMES gnuradio-dvbt2ll
    HINTS $ENV{DVBT2LL_DIR}/lib
        ${PC_DVBT2LL_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DVBT2LL DEFAULT_MSG DVBT2LL_LIBRARIES DVBT2LL_INCLUDE_DIRS)
MARK_AS_ADVANCED(DVBT2LL_LIBRARIES DVBT2LL_INCLUDE_DIRS)

