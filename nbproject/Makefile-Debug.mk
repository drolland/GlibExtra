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
	${OBJECTDIR}/gx_merge_sort.o \
	${OBJECTDIR}/gx_printf.o \
	${OBJECTDIR}/gx_qsort.o \
	${OBJECTDIR}/gx_tim_sort.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/gx_bench_sort.o \
	${TESTDIR}/tests/gx_test_csv_file.o \
	${TESTDIR}/tests/gx_test_msort.o \
	${TESTDIR}/tests/gx_test_qsort.o

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

${OBJECTDIR}/gx_merge_sort.o: gx_merge_sort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_merge_sort.o gx_merge_sort.c

${OBJECTDIR}/gx_printf.o: gx_printf.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_printf.o gx_printf.c

${OBJECTDIR}/gx_qsort.o: gx_qsort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_qsort.o gx_qsort.c

${OBJECTDIR}/gx_tim_sort.o: gx_tim_sort.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_tim_sort.o gx_tim_sort.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/gx_bench_sort.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `pkg-config --libs glib-2.0`  

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/gx_test_csv_file.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `pkg-config --libs glib-2.0`  

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/gx_test_msort.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `pkg-config --libs glib-2.0`  

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/gx_test_qsort.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `pkg-config --libs glib-2.0`  


${TESTDIR}/tests/gx_bench_sort.o: tests/gx_bench_sort.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -std=c11 `pkg-config --cflags glib-2.0` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/gx_bench_sort.o tests/gx_bench_sort.c


${TESTDIR}/tests/gx_test_csv_file.o: tests/gx_test_csv_file.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -std=c11 `pkg-config --cflags glib-2.0` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/gx_test_csv_file.o tests/gx_test_csv_file.c


${TESTDIR}/tests/gx_test_msort.o: tests/gx_test_msort.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -std=c11 `pkg-config --cflags glib-2.0` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/gx_test_msort.o tests/gx_test_msort.c


${TESTDIR}/tests/gx_test_qsort.o: tests/gx_test_qsort.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -g -I. -std=c11 `pkg-config --cflags glib-2.0` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/gx_test_qsort.o tests/gx_test_qsort.c


${OBJECTDIR}/gx_csv_file_nomain.o: ${OBJECTDIR}/gx_csv_file.o gx_csv_file.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gx_csv_file.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_csv_file_nomain.o gx_csv_file.c;\
	else  \
	    ${CP} ${OBJECTDIR}/gx_csv_file.o ${OBJECTDIR}/gx_csv_file_nomain.o;\
	fi

${OBJECTDIR}/gx_merge_sort_nomain.o: ${OBJECTDIR}/gx_merge_sort.o gx_merge_sort.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gx_merge_sort.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_merge_sort_nomain.o gx_merge_sort.c;\
	else  \
	    ${CP} ${OBJECTDIR}/gx_merge_sort.o ${OBJECTDIR}/gx_merge_sort_nomain.o;\
	fi

${OBJECTDIR}/gx_printf_nomain.o: ${OBJECTDIR}/gx_printf.o gx_printf.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gx_printf.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_printf_nomain.o gx_printf.c;\
	else  \
	    ${CP} ${OBJECTDIR}/gx_printf.o ${OBJECTDIR}/gx_printf_nomain.o;\
	fi

${OBJECTDIR}/gx_qsort_nomain.o: ${OBJECTDIR}/gx_qsort.o gx_qsort.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gx_qsort.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_qsort_nomain.o gx_qsort.c;\
	else  \
	    ${CP} ${OBJECTDIR}/gx_qsort.o ${OBJECTDIR}/gx_qsort_nomain.o;\
	fi

${OBJECTDIR}/gx_tim_sort_nomain.o: ${OBJECTDIR}/gx_tim_sort.o gx_tim_sort.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/gx_tim_sort.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gx_tim_sort_nomain.o gx_tim_sort.c;\
	else  \
	    ${CP} ${OBJECTDIR}/gx_tim_sort.o ${OBJECTDIR}/gx_tim_sort_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -g -std=c11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
