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
CND_DISTDIR=dist
CND_BUILDDIR=build


# Object Directory
OBJECTDIR=${CND_BUILDDIR}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/utils.o \
	${OBJECTDIR}/db.o \
	${OBJECTDIR}/servicio.o \
	${OBJECTDIR}/archivo.o \
	${OBJECTDIR}/lista.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
#DEBUG
#CFLAGS=-Wall -DDEBUG -g3
#Sin Debug
CFLAGS=-Wall -g3

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpq -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f Makefile ${CND_DISTDIR}/medizip

${CND_DISTDIR}/medizip: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}
	${LINK.c} -o ${CND_DISTDIR}/medizip ${OBJECTFILES} ${LDLIBSOPTIONS} 
	${RM} -fr ${CND_BUILDDIR}
	${RM} -fr core


${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c
	
	
${OBJECTDIR}/db.o: db.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/db.o db.c

${OBJECTDIR}/utils.o: utils.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/utils.o utils.c

${OBJECTDIR}/servicio.o: servicio.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/servicio.o servicio.c	

${OBJECTDIR}/archivo.o: archivo.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/archivo.o archivo.c

${OBJECTDIR}/lista.o: lista.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(CC) $(CFLAGS) -c -MMD -MP -MF $@.d -o ${OBJECTDIR}/lista.o lista.c

# Clean Targets
clean: ${CLEAN_SUBPROJECTS}
	${RM} -fr ${CND_BUILDDIR}
	${RM} -fr ${CND_DISTDIR}
	${RM} -fr core

# Subprojects
.clean-subprojects:


