#ifndef BOARD_H
#define BOARD_H
#include"general/List.h"

typedef struct board{
	list *l;
	int width;
	int height;

	int * number_neighbours;
    int lenght_number_neighbours;

	int * posible_neighbours;
    int lenght_posible_neighbours;


} board;

/**
@name create_board
@brief stores the memory needed for a board 
@param width the number of columns
@param height the number of rows
@param number_neighbours the number of live neighbours that a cell needs to start living
@param posible_neighbours an array of posible neighbours that a cell needs to continue living
@return a board
*/
board * create_board(int width, int height, int* number_neighbours, int lenght1,int *posible_neighbours,int lenght2);

/**
@name neighs
@brief it obtains the neighbours of a cell
@param b the board
@param c the cell
@return a list of cells that are neighbours of the cell 
*/
list * neighs(board b,cell c);

/**
@name is_empty
@brief checks if a cell is dead
@param b the board
@param c the cell
@return true if is dead false otherwise
*/
BOOL is_empty(board b, cell *c);

/**
@name is_alive
@brief checks if a cell is alive
@param b the board
@param c the cell
@return true if is alive false otherwise
*/
BOOL is_alive(board b, cell *c);

/**
@name live_neighbours
@brief it obtains the number of alive neighbours of a cell
@param b the board
@param c the cell
@return the number of neighbours
*/
int live_neighbours(board b, cell c);

/**
@name survivors
@brief it obtains the number of survivors of a board
@param b the board
@return the list of survivors
*/
list * survivors(board b);

/**
@name remove_duplicates
@brief it removes duplicates from a list
@param b the board
@return the list of survivors
*/
list * remove_duplicates(list *l);

/**
@name births
@brief calculates the cells that have been created 
@param b the board
@return the list of new cells
*/
list * births (board b);

/**
@name next_generation
@brief returns the births and the survivors of a board
@param b the board
@return the list of new cells
*/
void next_generation(board *b);

/**
@name print_board_terminal
@brief prints the board in the terminal
@param b the board
@return void
*/
void print_board_terminal(board *b);

/**
@name destroy_board
@brief frees the memory that a board is using
@param b the board
@return void
*/
void destroy_board(board * b);

/**
@name read_from_file
@brief reads a board from a file
@param path the path of the file
@return void
*/
board * read_from_file(char * path);
#endif

