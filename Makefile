# Makefile for Graph class and program driver - Jeff Braun

#Macros to specify compiler, compiler/linking flags, target file
C++  = c++
CFLAGS = -g -Wall -Werror
LD = c++
LDFLAGS =
LIBS =
OBJS = MIPS_Assembler.o FileIO.o AssemblerMIPS.o
EXEC = MIPS_Assembler

#Rules to create target file Driver
# If any files on line with colon are modified, then recompile the object file
all:		$(EXEC)

$(EXEC):	$(OBJS)
		$(LD) $(LDFLAGS) -o $(EXEC) $(OBJS) $(LIBS)
		
FileIO.o: FileIO.h FileIO.cpp
		$(C++) $(CFLAGS) -c FileIO.cpp
		
AssemblerMIPS.o:	AssemblerMIPS.h AssemblerMIPS.cpp
		$(C++) $(CFLAGS) -c AssemblerMIPS.cpp
		
MIPS_Assembler.o:	FileIO.h AssemblerMIPS.h MIPS_Assembler.cpp
		$(C++) $(CFLAGS) -c MIPS_Assembler.cpp

clean:
		rm -f $(OBJS) $(EXEC) 

