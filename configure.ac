AC_PREREQ([2.69])
AC_INIT([image-tools], [0.1], [martin@rootuser.dk])
AC_CONFIG_SRCDIR([ImageInfo.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([opencv_core], [checkHardwareSupport])
AC_CHECK_LIB([opencv_highgui], [imread])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h opencv2/highgui/highgui.hpp])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
