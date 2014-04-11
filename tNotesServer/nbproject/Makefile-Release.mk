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
	${OBJECTDIR}/ChangeArticleHandler.o \
	${OBJECTDIR}/ChangeNodeHandler.o \
	${OBJECTDIR}/CreateArticleHandler.o \
	${OBJECTDIR}/CreateNodeHandler.o \
	${OBJECTDIR}/DeleteArticleHandler.o \
	${OBJECTDIR}/DeleteNodeHandler.o \
	${OBJECTDIR}/DummyHandler.o \
	${OBJECTDIR}/DummySyncHandler.o \
	${OBJECTDIR}/FetchArticlesHandler.o \
	${OBJECTDIR}/FetchBriefsHandler.o \
	${OBJECTDIR}/FetchNodesHandler.o \
	${OBJECTDIR}/Handler.o \
	${OBJECTDIR}/HandlerFactory.o \
	${OBJECTDIR}/SessionCache.o \
	${OBJECTDIR}/SessionManager.o \
	${OBJECTDIR}/SigninHandler.o \
	${OBJECTDIR}/SignoutHandler.o \
	${OBJECTDIR}/SignupHandler.o \
	${OBJECTDIR}/SyncHandler.o \
	${OBJECTDIR}/database/dirRelated.o \
	${OBJECTDIR}/database/noteDB.o \
	${OBJECTDIR}/database/noteRelated.o \
	${OBJECTDIR}/database/sha1.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f6

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

${OBJECTDIR}/ChangeArticleHandler.o: ChangeArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ChangeArticleHandler.o ChangeArticleHandler.cpp

${OBJECTDIR}/ChangeNodeHandler.o: ChangeNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ChangeNodeHandler.o ChangeNodeHandler.cpp

${OBJECTDIR}/CreateArticleHandler.o: CreateArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CreateArticleHandler.o CreateArticleHandler.cpp

${OBJECTDIR}/CreateNodeHandler.o: CreateNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CreateNodeHandler.o CreateNodeHandler.cpp

${OBJECTDIR}/DeleteArticleHandler.o: DeleteArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeleteArticleHandler.o DeleteArticleHandler.cpp

${OBJECTDIR}/DeleteNodeHandler.o: DeleteNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeleteNodeHandler.o DeleteNodeHandler.cpp

${OBJECTDIR}/DummyHandler.o: DummyHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummyHandler.o DummyHandler.cpp

${OBJECTDIR}/DummySyncHandler.o: DummySyncHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummySyncHandler.o DummySyncHandler.cpp

${OBJECTDIR}/FetchArticlesHandler.o: FetchArticlesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchArticlesHandler.o FetchArticlesHandler.cpp

${OBJECTDIR}/FetchBriefsHandler.o: FetchBriefsHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchBriefsHandler.o FetchBriefsHandler.cpp

${OBJECTDIR}/FetchNodesHandler.o: FetchNodesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchNodesHandler.o FetchNodesHandler.cpp

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

${OBJECTDIR}/SyncHandler.o: SyncHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SyncHandler.o SyncHandler.cpp

${OBJECTDIR}/database/dirRelated.o: database/dirRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/dirRelated.o database/dirRelated.cpp

${OBJECTDIR}/database/noteDB.o: database/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/noteDB.o database/noteDB.cpp

${OBJECTDIR}/database/noteRelated.o: database/noteRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/noteRelated.o database/noteRelated.cpp

${OBJECTDIR}/database/sha1.o: database/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/sha1.o database/sha1.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/UnitTest4CreateArticleHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/UnitTest4FecthArticlesHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/UnitTest4FecthBriefsHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/UnitTest4SessionCache.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/UnitTest4SigninHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/UnitTest4SyncHandler.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/UnitTest4CreateArticleHandler.o: tests/UnitTest4CreateArticleHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4CreateArticleHandler.o tests/UnitTest4CreateArticleHandler.cpp


${TESTDIR}/tests/UnitTest4FecthArticlesHandler.o: tests/UnitTest4FecthArticlesHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4FecthArticlesHandler.o tests/UnitTest4FecthArticlesHandler.cpp


${TESTDIR}/tests/UnitTest4FecthBriefsHandler.o: tests/UnitTest4FecthBriefsHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4FecthBriefsHandler.o tests/UnitTest4FecthBriefsHandler.cpp


${TESTDIR}/tests/UnitTest4SessionCache.o: tests/UnitTest4SessionCache.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SessionCache.o tests/UnitTest4SessionCache.cpp


${TESTDIR}/tests/UnitTest4SigninHandler.o: tests/UnitTest4SigninHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SigninHandler.o tests/UnitTest4SigninHandler.cpp


${TESTDIR}/tests/UnitTest4SyncHandler.o: tests/UnitTest4SyncHandler.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UnitTest4SyncHandler.o tests/UnitTest4SyncHandler.cpp


${OBJECTDIR}/ChangeArticleHandler_nomain.o: ${OBJECTDIR}/ChangeArticleHandler.o ChangeArticleHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ChangeArticleHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ChangeArticleHandler_nomain.o ChangeArticleHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ChangeArticleHandler.o ${OBJECTDIR}/ChangeArticleHandler_nomain.o;\
	fi

${OBJECTDIR}/ChangeNodeHandler_nomain.o: ${OBJECTDIR}/ChangeNodeHandler.o ChangeNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ChangeNodeHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ChangeNodeHandler_nomain.o ChangeNodeHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ChangeNodeHandler.o ${OBJECTDIR}/ChangeNodeHandler_nomain.o;\
	fi

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

${OBJECTDIR}/CreateNodeHandler_nomain.o: ${OBJECTDIR}/CreateNodeHandler.o CreateNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CreateNodeHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CreateNodeHandler_nomain.o CreateNodeHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CreateNodeHandler.o ${OBJECTDIR}/CreateNodeHandler_nomain.o;\
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

${OBJECTDIR}/DeleteNodeHandler_nomain.o: ${OBJECTDIR}/DeleteNodeHandler.o DeleteNodeHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DeleteNodeHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DeleteNodeHandler_nomain.o DeleteNodeHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DeleteNodeHandler.o ${OBJECTDIR}/DeleteNodeHandler_nomain.o;\
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

${OBJECTDIR}/DummySyncHandler_nomain.o: ${OBJECTDIR}/DummySyncHandler.o DummySyncHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DummySyncHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DummySyncHandler_nomain.o DummySyncHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DummySyncHandler.o ${OBJECTDIR}/DummySyncHandler_nomain.o;\
	fi

${OBJECTDIR}/FetchArticlesHandler_nomain.o: ${OBJECTDIR}/FetchArticlesHandler.o FetchArticlesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FetchArticlesHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchArticlesHandler_nomain.o FetchArticlesHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FetchArticlesHandler.o ${OBJECTDIR}/FetchArticlesHandler_nomain.o;\
	fi

${OBJECTDIR}/FetchBriefsHandler_nomain.o: ${OBJECTDIR}/FetchBriefsHandler.o FetchBriefsHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FetchBriefsHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchBriefsHandler_nomain.o FetchBriefsHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FetchBriefsHandler.o ${OBJECTDIR}/FetchBriefsHandler_nomain.o;\
	fi

${OBJECTDIR}/FetchNodesHandler_nomain.o: ${OBJECTDIR}/FetchNodesHandler.o FetchNodesHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/FetchNodesHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FetchNodesHandler_nomain.o FetchNodesHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/FetchNodesHandler.o ${OBJECTDIR}/FetchNodesHandler_nomain.o;\
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

${OBJECTDIR}/SyncHandler_nomain.o: ${OBJECTDIR}/SyncHandler.o SyncHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/SyncHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SyncHandler_nomain.o SyncHandler.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/SyncHandler.o ${OBJECTDIR}/SyncHandler_nomain.o;\
	fi

${OBJECTDIR}/database/dirRelated_nomain.o: ${OBJECTDIR}/database/dirRelated.o database/dirRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	@NMOUTPUT=`${NM} ${OBJECTDIR}/database/dirRelated.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/dirRelated_nomain.o database/dirRelated.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/database/dirRelated.o ${OBJECTDIR}/database/dirRelated_nomain.o;\
	fi

${OBJECTDIR}/database/noteDB_nomain.o: ${OBJECTDIR}/database/noteDB.o database/noteDB.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	@NMOUTPUT=`${NM} ${OBJECTDIR}/database/noteDB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/noteDB_nomain.o database/noteDB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/database/noteDB.o ${OBJECTDIR}/database/noteDB_nomain.o;\
	fi

${OBJECTDIR}/database/noteRelated_nomain.o: ${OBJECTDIR}/database/noteRelated.o database/noteRelated.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	@NMOUTPUT=`${NM} ${OBJECTDIR}/database/noteRelated.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/noteRelated_nomain.o database/noteRelated.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/database/noteRelated.o ${OBJECTDIR}/database/noteRelated_nomain.o;\
	fi

${OBJECTDIR}/database/sha1_nomain.o: ${OBJECTDIR}/database/sha1.o database/sha1.cpp 
	${MKDIR} -p ${OBJECTDIR}/database
	@NMOUTPUT=`${NM} ${OBJECTDIR}/database/sha1.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/database/sha1_nomain.o database/sha1.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/database/sha1.o ${OBJECTDIR}/database/sha1_nomain.o;\
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
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
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
