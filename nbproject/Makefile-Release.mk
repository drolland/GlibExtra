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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/gx_csv_file.o \
	${OBJECTDIR}/gx_merge_sort.o \
	${OBJECTDIR}/gx_qsort.o \
	${OBJECTDIR}/gx_test_msort.o \
	${OBJECTDIR}/tests/gx_test_csv_file.o \
	${OBJECTDIR}/tests/gx_test_qsort.o


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
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_csv_file.o gx_csv_file.c

${OBJECTDIR}/gx_merge_sort.o: gx_merge_sort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_merge_sort.o gx_merge_sort.c

${OBJECTDIR}/gx_qsort.o: gx_qsort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_qsort.o gx_qsort.c

${OBJECTDIR}/gx_test_msort.o: gx_test_msort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_test_msort.o gx_test_msort.c

${OBJECTDIR}/tests/gx_test_csv_file.o: tests/gx_test_csv_file.c
	${MKDIR} -p ${OBJECTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tests/gx_test_csv_file.o tests/gx_test_csv_file.c

${OBJECTDIR}/tests/gx_test_qsort.o: tests/gx_test_qsort.c
	${MKDIR} -p ${OBJECTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O3 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tests/gx_test_qsort.o tests/gx_test_qsort.c

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
