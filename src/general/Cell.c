#include"Cell.h"

/**
@name create_cell
@brief creates a cell from two coordinates
    If x or y are below 0, it will set that coordinate to 0
@param x the x coordinate
@param y the y coordinate
@return the new cell created
*/
cell * create_cell(int x,int y){
   cell * c = (cell *) calloc(1,sizeof(cell));
   c->x = x > 0 ? x : 0;
   c->y = y > 0 ? y : 0;
   return c;
}

/**
@name copy_cell
@brief copy a source cell to another one
    The destination cell must be reserved
@param dst the destination cell
@param source the source cell
@return OK if operation succesfull or ERROR
*/
STATUS copy_cell (cell * dst, const cell *source){
  if (dst == NULL || source == NULL)
	return ERROR;
  dst->x = source->x;
  dst->y = source->y;
  return OK;
}

/**
@name equals_cell
@brief method to compare if two cells are in the same position
@param fst the first cell
@param snd the second cell
@return TRUE if both coordinates are the same, FALSE otherwise
*/
BOOL equals_cell (cell *fst, cell *snd){
	if ((fst->x == snd->x) && (fst->y == snd->y))
		return TRUE;
	else
		return FALSE;
}

/**
@name destroy_cell
@brief it frees the cell memory
@param c the cell to be freed
@return OK if operation succesfull or ERROR
*/
STATUS destroy_cell(cell * c){
  free(c);
  return OK;
}

/**
@name print_cell
@brief it prints the coordinates of the cell
@param c the cell to be freed
@return nothing
*/
void print_cell(cell c){
  printf("[%d, %d]", c.y,c.x);
  return;
}

/**
@name print_terminal_cell
@brief it prints a character 'O' in the terminal position of the cell 
@param c the cell to be printed
@return nothing
*/
void print_terminal_cell(cell c){
  printf("\033[%d;%dHO\n", c.y+1,c.x+1);
  return;
}


