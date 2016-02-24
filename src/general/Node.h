#ifndef NODE_H
#define NODE_H

#include"Element.h"
typedef struct node{
  element element;
  struct node * next;
}node;

/**
@name create_node
@brief it creates a node from an element
@param e the element that will be used in the node
@return the node if the operation was successfull or NULL otherwise
*/
node * create_node (const element *e);

/**
@name destroy_node
@brief it frees the memory of the node
@param node the node to be freed
@return void
*/
void destroy_node(node * node);

/**
@name print_node
@brief print the node in the terminal
@param node the node to be printed
@return void
*/
void print_node(node node);

#endif
