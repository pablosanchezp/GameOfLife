#ifndef LIST_H
#define LIST_H
#include"Node.h"

typedef struct list {
  node *first;
  node *last;
}list;

/**
@name create_list
@brief destroys (frees) memory of an element that have been stored
@return a list or NULL
*/
list * create_list();

/**
@name ini_list
@brief initialize a list setting all the pointers to NULL
@param l the list to initialize
@return OK or ERROR
*/
STATUS ini_list(list *l);

/**
@name is_empty_list
@brief checks if a list is empty
@param l the list to check if it is empty
@return OK or ERROR
*/
BOOL is_empty_list(list *l);

/**
@name first_list
@brief returns in the second argument the first element of a list
@param l the list 
@param e the element that will be updated
@return OK or ERROR
*/
STATUS first_list(list *l, element *e);

/**
@name insert_first_list
@brief inserts an element in the first position of the list
@param l the list 
@param e the element that will be inserted
@return OK or ERROR
*/
STATUS insert_first_list(list *l,element e);

/**
@name concat_list
@brief joins two list in one
@param dst the destination list
@param origin the list that will be copied
@return OK or ERROR
*/
void concat_list(list *dst , list * origin);

/**
@name extract_first_list
@brief extracs the first element in the list
@param l the list 
@param e the element that will be inserted
@return OK or ERROR
*/
STATUS extract_first_list(list *l, element *e);

/**
@name insert_last_list
@brief inserts an element in the last position of the list
@param l the list on which the element will be inserted
@param e the element to be inserted
@return OK or ERROR
*/
STATUS insert_last_list(list * l, element e);

/**
@name extract_last_list
@brief extract the last element of a list
@param l the list on which the element will be extracted
@param e the element to be extracted
@return OK or ERROR
*/
STATUS extract_last_list(list *l, element *e);

/**
@name search_list
@brief search an element in the list 
@param l the list
@param e the element to be searched
@return TRUE if the element is in the list FALSE otherwise
*/
BOOL search_list(list l , element e);



/**
@name lenght_list
@brief computed the length of a list 
@param l the list 
@return the length of the list (from 0 to n)
*/
int lenght_list(list * l);

/**
@name destroy_list
@brief free all the memory used by the list
@param l the list
@return void
*/
void destroy_list(list *l);

/**
@name print_list
@brief prints all elements of the list 
@param l the list
@return void
*/
void print_list(list *l);

#endif
