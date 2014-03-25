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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/DB/noteDB.o \
	${OBJECTDIR}/DB/sha1.o \
	${OBJECTDIR}/DummyHandler.o \
	${OBJECTDIR}/Handler.o \
	${OBJECTDIR}/HandlerFactory.o \
	${OBJECTDIR}/SessionCache.o \
	${OBJECTDIR}/SessionManager.o \
	${OBJECTDIR}/SigninHandler.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lfcgi++ -lfcgi -ljsoncpp -lmysqlclient

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f2

${TESTDIR}/TestFiles/f2: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DB/noteDB.o: DB/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteDB.o DB/noteDB.cpp

${OBJECTDIR}/DB/sha1.o: DB/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/sha1.o DB/sha1.cpp

${OBJECTDIR}/DummyHandler.o: DummyHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyHandler.o DummyHandler.cpp

${OBJECTDIR}/Handler.o: Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Handler.o Handler.cpp

${OBJECTDIR}/HandlerFactory.o: HandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HandlerFactory.o HandlerFactory.cpp

${OBJECTDIR}/SessionCache.o: SessionCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionCache.o SessionCache.cpp

${OBJECTDIR}/SessionManager.o: SessionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionManager.o SessionManager.cpp

${OBJECTDIR}/SigninHandler.o: SigninHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SigninHandler.o SigninHandler.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/UnitTest4SessionCache.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/UnitTest4SigninHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/UnitTest4SessionCache.o: tests/UnitTest4SessionCache.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SessionCache.o tests/UnitTest4SessionCache.cpp


${TESTDIR}/tests/UnitTest4SigninHandler.o: tests/UnitTest4SigninHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SigninHandler.o tests/UnitTest4SigninHandler.cpp


${OBJECTDIR}/DB/noteDB_nomain.o: ${OBJECTDIR}/DB/noteDB.o DB/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/noteDB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteDB_nomain.o DB/noteDB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/noteDB.o ${OBJECTDIR}/DB/noteDB_nomain.o;\
	fi

${OBJECTDIR}/DB/sha1_nomain.o: ${OBJECTDIR}/DB/sha1.o DB/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/sha1.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/sha1_nomain.o DB/sha1.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/sha1.o ${OBJECTDIR}/DB/sha1_nomain.o;\
	fi

${OBJECTDIR}/DummyHandler_nomain.o: ${OBJECTDIR}/DummyHandler.o DummyHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DummyHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyHandler_nomain.o DummyHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DummyHandler.o ${OBJECTDIR}/DummyHandler_nomain.o;\
	fi

${OBJECTDIR}/Handler_nomain.o: ${OBJECTDIR}/Handler.o Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Handler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Handler_nomain.o Handler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Handler.o ${OBJECTDIR}/Handler_nomain.o;\
	fi

${OBJECTDIR}/HandlerFactory_nomain.o: ${OBJECTDIR}/HandlerFactory.o HandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/HandlerFactory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HandlerFactory_nomain.o HandlerFactory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/HandlerFactory.o ${OBJECTDIR}/HandlerFactory_nomain.o;\
	fi

${OBJECTDIR}/SessionCache_nomain.o: ${OBJECTDIR}/SessionCache.o SessionCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SessionCache.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionCache_nomain.o SessionCache.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SessionCache.o ${OBJECTDIR}/SessionCache_nomain.o;\
	fi

${OBJECTDIR}/SessionManager_nomain.o: ${OBJECTDIR}/SessionManager.o SessionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SessionManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionManager_nomain.o SessionManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SessionManager.o ${OBJECTDIR}/SessionManager_nomain.o;\
	fi

${OBJECTDIR}/SigninHandler_nomain.o: ${OBJECTDIR}/SigninHandler.o SigninHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SigninHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SigninHandler_nomain.o SigninHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SigninHandler.o ${OBJECTDIR}/SigninHandler_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
