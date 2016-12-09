#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/gx_csv_file.o \
	${OBJECTDIR}/gx_sort_divide.o \
	${OBJECTDIR}/gx_test_common.o \
	${OBJECTDIR}/tests/gx_test_csv_file.o \
	${OBJECTDIR}/tests/gx_test_sort_divide_conquer.o


# C Compiler Flags
CFLAGS=`pkg-config --cflags glib-2.0` 

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglibextra.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglibextra.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglibextra.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglibextra.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libglibextra.a

${OBJECTDIR}/gx_csv_file.o: gx_csv_file.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_csv_file.o gx_csv_file.c

${OBJECTDIR}/gx_sort_divide.o: gx_sort_divide.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_sort_divide.o gx_sort_divide.c

${OBJECTDIR}/gx_test_common.o: gx_test_common.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_test_common.o gx_test_common.c

${OBJECTDIR}/tests/gx_test_csv_file.o: tests/gx_test_csv_file.c
	${MKDIR} -p ${OBJECTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tests/gx_test_csv_file.o tests/gx_test_csv_file.c

${OBJECTDIR}/tests/gx_test_sort_divide_conquer.o: tests/gx_test_sort_divide_conquer.c
	${MKDIR} -p ${OBJECTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tests/gx_test_sort_divide_conquer.o tests/gx_test_sort_divide_conquer.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
