#ifndef CELL_H
#define CELL_H
#include"Utils.h"

/**
 * @brief struct of game os live's cell
 *
 * Each cell contains two fields, x and y. x will be the x coordenate of the terminal (from left to right)
 * and y will be the y coordinate (from up to down).
 * 
 */

typedef struct cell{
  int x;
  int y;
}cell;

/**
@name create_cell
@brief creates a cell from two coordinates
    If x or y are below 0, it will set that coordinate to 0
@param x the x coordinate
@param y the y coordinate
@return the new cell created
*/
cell * create_cell(int x,int y);

/**
@name copy_cell
@brief copy a source cell to another one
    The destination cell must be reserved
@param dst the destination cell
@param source the source cell
@return OK if operation succesfull or ERROR
*/
STATUS copy_cell (cell * dst, const cell *source);

/**
@name equals_cell
@brief method to compare if two cells are in the same position
@param fst the first cell
@param snd the second cell
@return TRUE if both coordinates are the same, FALSE otherwise
*/
BOOL equals_cell (cell *fst, cell *snd);

/**
@name destroy_cell
@brief it frees the cell memory
@param c the cell to be freed
@return OK if operation succesfull or ERROR
*/
STATUS destroy_cell(cell * c);

/**
@name print_cell
@brief it prints the coordinates of the cell
@param c the cell to be printed
@return nothing
*/
void print_cell(cell c);

/**
@name print_terminal_cell
@brief it prints a character 'O' in the terminal position of the cell 
@param c the cell to be printed
@return nothing
*/
void print_terminal_cell(cell c);
#endif
