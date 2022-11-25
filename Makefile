# 				MAKEFILE
# *****************************************************
# Compatibilité make clean pour Windows ET Linux

ifeq ($(OS),Windows_NT) 
RM = del /Q /F
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif
#*****************************************************
CC = g++
# ****************************************************
.PHONY: all clean

all: main
 
main: main.o EquationLineaire.o
	$(CC) -o main main.o EquationLineaire.o
 
main.o: main.cpp EquationLineaire.hpp
	$(CC) -c main.cpp EquationLineaire.hpp
 
EquationLineaire.o: EquationLineaire.cpp EquationLineaire.hpp
	$(CC) -c EquationLineaire.cpp EquationLineaire.hpp
	
clean: 
	-$(RM) *.o *.gch main.exe