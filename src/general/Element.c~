#include"Element.h"

/**
@name ini_element
@brief initializes an element (creates it storing memory)
@param init the element to initialize
@return OK if the element has been created successfully or ERROR otherwise
*/
STATUS ini_element(element *init){
  *init = (element) calloc (1,sizeof(cell));
   if (*init == NULL)
    return ERROR;
  else
    return OK;
} 

/**
@name equals_element
@brief compares two elements
@param fst the first element
@param snd the second element
@return TRUE if the elements are the same, FALSE otherwise
*/
BOOL equals_element(element fst, element snd){
	return equals_cell(fst,snd);
}

/**
@name copy_element
@brief copies one element to another. It stores memory.
@param source the element to copy
@param dst the destination element
@return OK if the copy was succesfull or ERROR otherwise
*/
STATUS copy_element(element * dst, const element *source){
  ini_element(dst);
  return copy_cell(*dst, *source);
}

/**
@name destroy_element
@brief destroys (frees) memory of an element that have been stored
@param elem the element to free
@return none
*/
void destroy_element(element *elem){
  destroy_cell(*elem);
}

/**
@name print_element
@brief it prints an element in the terminal
@param e the element to print
@return none
*/
void print_element(element e){
  print_cell(*e);
}
