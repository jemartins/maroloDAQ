#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_RANLIB

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lGL':
AC_CHECK_LIB([GL], [main])
# FIXME: Replace `main' with a function in `-lQt5Core':
AC_CHECK_LIB([Qt5Core], [main])
# FIXME: Replace `main' with a function in `-lQt5Gui':
AC_CHECK_LIB([Qt5Gui], [main])
# FIXME: Replace `main' with a function in `-lQt5SerialPort':
AC_CHECK_LIB([Qt5SerialPort], [main])
# FIXME: Replace `main' with a function in `-lQt5Widgets':
AC_CHECK_LIB([Qt5Widgets], [main])
# FIXME: Replace `main' with a function in `-lgrace_np':
AC_CHECK_LIB([grace_np], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([floor])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
