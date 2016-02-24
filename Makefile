#Compiler
CC = gcc

#Flags
# -g add debugging info
# -Wall compiler warnings
CFLAGS = -g -Wall

SRC = ./src
SRCG = ./src/general
OBJ = ./obj

all: gameoflife


gameoflife: $(OBJ)/GameOfLife.o $(OBJ)/Board.o $(OBJ)/List.o $(OBJ)/Node.o $(OBJ)/Element.o $(OBJ)/Cell.o 
	$(CC) -o gameoflife $(OBJ)/GameOfLife.o $(OBJ)/Board.o $(OBJ)/List.o $(OBJ)/Node.o $(OBJ)/Element.o $(OBJ)/Cell.o 

$(OBJ)/GameOfLife.o:
	$(CC) -c -o $(OBJ)/GameOfLife.o $(CFLAGS) $(SRC)/GameOfLife.c

$(OBJ)/Board.o:
	$(CC) -c -o $(OBJ)/Board.o $(CFLAGS) $(SRC)/Board.c

$(OBJ)/List.o:
	$(CC) -c -o $(OBJ)/List.o $(CFLAGS) $(SRCG)/List.c

$(OBJ)/Node.o:
	$(CC) -c -o $(OBJ)/Node.o $(CFLAGS) $(SRCG)/Node.c

$(OBJ)/Element.o:
	$(CC) -c -o $(OBJ)/Element.o $(CFLAGS) $(SRCG)/Element.c

$(OBJ)/Cell.o:
	$(CC) -c -o $(OBJ)/Cell.o $(CFLAGS) $(SRCG)/Cell.c

clean:
	rm -f  $(OBJ)/*.o gameoflife

autores:
	@ echo "********************************************************"
	@ echo "* Game of life in C language			               *"
	@ echo "* Programmed by:                                       *"
	@ echo "* Pablo Sanchez Perez                                  *"
	@ echo "********************************************************"

#Help comand
#Comando para ver la ayuda
help:
	@ echo "************************************************"
	@ echo "*************** makefile help ******************"
	@ echo "************************************************"
	@ echo "make <comand>"
	@ echo "Comands supported: "
	@ echo "author: shows the information about the creator"
	@ echo "clean: removes all object files and the executable"
