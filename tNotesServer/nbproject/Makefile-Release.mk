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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CreateArticleHandler.o \
	${OBJECTDIR}/DB/ChangeArticleHandler.o \
	${OBJECTDIR}/DB/dirRelated.o \
	${OBJECTDIR}/DB/noteDB.o \
	${OBJECTDIR}/DB/noteRelated.o \
	${OBJECTDIR}/DB/sha1.o \
	${OBJECTDIR}/DeleteArticleHandler.o \
	${OBJECTDIR}/DummyHandler.o \
	${OBJECTDIR}/FecthArticlesHandler.o \
	${OBJECTDIR}/FecthBriefsHandler.o \
	${OBJECTDIR}/FecthNodesHandler.o \
	${OBJECTDIR}/Handler.o \
	${OBJECTDIR}/HandlerFactory.o \
	${OBJECTDIR}/SessionCache.o \
	${OBJECTDIR}/SessionManager.o \
	${OBJECTDIR}/SigninHandler.o \
	${OBJECTDIR}/SignoutHandler.o \
	${OBJECTDIR}/SignupHandler.o \
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
LDLIBSOPTIONS=-lfcgi++ -lfcgi -ljson_linux-gcc-4.6_libmt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f2

${TESTDIR}/TestFiles/f2: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CreateArticleHandler.o: CreateArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CreateArticleHandler.o CreateArticleHandler.cpp

${OBJECTDIR}/DB/ChangeArticleHandler.o: DB/ChangeArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/ChangeArticleHandler.o DB/ChangeArticleHandler.cpp

${OBJECTDIR}/DB/dirRelated.o: DB/dirRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/dirRelated.o DB/dirRelated.cpp

${OBJECTDIR}/DB/noteDB.o: DB/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteDB.o DB/noteDB.cpp

${OBJECTDIR}/DB/noteRelated.o: DB/noteRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteRelated.o DB/noteRelated.cpp

${OBJECTDIR}/DB/sha1.o: DB/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/sha1.o DB/sha1.cpp

${OBJECTDIR}/DeleteArticleHandler.o: DeleteArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeleteArticleHandler.o DeleteArticleHandler.cpp

${OBJECTDIR}/DummyHandler.o: DummyHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyHandler.o DummyHandler.cpp

${OBJECTDIR}/FecthArticlesHandler.o: FecthArticlesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthArticlesHandler.o FecthArticlesHandler.cpp

${OBJECTDIR}/FecthBriefsHandler.o: FecthBriefsHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthBriefsHandler.o FecthBriefsHandler.cpp

${OBJECTDIR}/FecthNodesHandler.o: FecthNodesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthNodesHandler.o FecthNodesHandler.cpp

${OBJECTDIR}/Handler.o: Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Handler.o Handler.cpp

${OBJECTDIR}/HandlerFactory.o: HandlerFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HandlerFactory.o HandlerFactory.cpp

${OBJECTDIR}/SessionCache.o: SessionCache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionCache.o SessionCache.cpp

${OBJECTDIR}/SessionManager.o: SessionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionManager.o SessionManager.cpp

${OBJECTDIR}/SigninHandler.o: SigninHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SigninHandler.o SigninHandler.cpp

${OBJECTDIR}/SignoutHandler.o: SignoutHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SignoutHandler.o SignoutHandler.cpp

${OBJECTDIR}/SignupHandler.o: SignupHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SignupHandler.o SignupHandler.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SessionCache.o tests/UnitTest4SessionCache.cpp


${TESTDIR}/tests/UnitTest4SigninHandler.o: tests/UnitTest4SigninHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SigninHandler.o tests/UnitTest4SigninHandler.cpp


${OBJECTDIR}/CreateArticleHandler_nomain.o: ${OBJECTDIR}/CreateArticleHandler.o CreateArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CreateArticleHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CreateArticleHandler_nomain.o CreateArticleHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CreateArticleHandler.o ${OBJECTDIR}/CreateArticleHandler_nomain.o;\
	fi

${OBJECTDIR}/DB/ChangeArticleHandler_nomain.o: ${OBJECTDIR}/DB/ChangeArticleHandler.o DB/ChangeArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/ChangeArticleHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/ChangeArticleHandler_nomain.o DB/ChangeArticleHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/ChangeArticleHandler.o ${OBJECTDIR}/DB/ChangeArticleHandler_nomain.o;\
	fi

${OBJECTDIR}/DB/dirRelated_nomain.o: ${OBJECTDIR}/DB/dirRelated.o DB/dirRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/dirRelated.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/dirRelated_nomain.o DB/dirRelated.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/dirRelated.o ${OBJECTDIR}/DB/dirRelated_nomain.o;\
	fi

${OBJECTDIR}/DB/noteDB_nomain.o: ${OBJECTDIR}/DB/noteDB.o DB/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/noteDB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteDB_nomain.o DB/noteDB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/noteDB.o ${OBJECTDIR}/DB/noteDB_nomain.o;\
	fi

${OBJECTDIR}/DB/noteRelated_nomain.o: ${OBJECTDIR}/DB/noteRelated.o DB/noteRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/noteRelated.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/noteRelated_nomain.o DB/noteRelated.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/noteRelated.o ${OBJECTDIR}/DB/noteRelated_nomain.o;\
	fi

${OBJECTDIR}/DB/sha1_nomain.o: ${OBJECTDIR}/DB/sha1.o DB/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/DB
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DB/sha1.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DB/sha1_nomain.o DB/sha1.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DB/sha1.o ${OBJECTDIR}/DB/sha1_nomain.o;\
	fi

${OBJECTDIR}/DeleteArticleHandler_nomain.o: ${OBJECTDIR}/DeleteArticleHandler.o DeleteArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DeleteArticleHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeleteArticleHandler_nomain.o DeleteArticleHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DeleteArticleHandler.o ${OBJECTDIR}/DeleteArticleHandler_nomain.o;\
	fi

${OBJECTDIR}/DummyHandler_nomain.o: ${OBJECTDIR}/DummyHandler.o DummyHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DummyHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyHandler_nomain.o DummyHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DummyHandler.o ${OBJECTDIR}/DummyHandler_nomain.o;\
	fi

${OBJECTDIR}/FecthArticlesHandler_nomain.o: ${OBJECTDIR}/FecthArticlesHandler.o FecthArticlesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FecthArticlesHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthArticlesHandler_nomain.o FecthArticlesHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FecthArticlesHandler.o ${OBJECTDIR}/FecthArticlesHandler_nomain.o;\
	fi

${OBJECTDIR}/FecthBriefsHandler_nomain.o: ${OBJECTDIR}/FecthBriefsHandler.o FecthBriefsHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FecthBriefsHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthBriefsHandler_nomain.o FecthBriefsHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FecthBriefsHandler.o ${OBJECTDIR}/FecthBriefsHandler_nomain.o;\
	fi

${OBJECTDIR}/FecthNodesHandler_nomain.o: ${OBJECTDIR}/FecthNodesHandler.o FecthNodesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FecthNodesHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FecthNodesHandler_nomain.o FecthNodesHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FecthNodesHandler.o ${OBJECTDIR}/FecthNodesHandler_nomain.o;\
	fi

${OBJECTDIR}/Handler_nomain.o: ${OBJECTDIR}/Handler.o Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Handler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Handler_nomain.o Handler.cpp;\
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
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HandlerFactory_nomain.o HandlerFactory.cpp;\
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
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionCache_nomain.o SessionCache.cpp;\
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
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SessionManager_nomain.o SessionManager.cpp;\
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
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SigninHandler_nomain.o SigninHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SigninHandler.o ${OBJECTDIR}/SigninHandler_nomain.o;\
	fi

${OBJECTDIR}/SignoutHandler_nomain.o: ${OBJECTDIR}/SignoutHandler.o SignoutHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SignoutHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SignoutHandler_nomain.o SignoutHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SignoutHandler.o ${OBJECTDIR}/SignoutHandler_nomain.o;\
	fi

${OBJECTDIR}/SignupHandler_nomain.o: ${OBJECTDIR}/SignupHandler.o SignupHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SignupHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SignupHandler_nomain.o SignupHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SignupHandler.o ${OBJECTDIR}/SignupHandler_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
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
