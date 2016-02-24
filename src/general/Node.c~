#include"Node.h"

/**
@name create_node
@brief it creates a node from an element
@param e the element that will be used in the node
@return the node if the operation was successfull or NULL otherwise
*/
node * create_node (const element *e){
  node * aux = NULL;
  if (e == NULL)
    return NULL;
  
  aux = (node *) calloc(1,sizeof(node));
  if (aux == NULL)
    return NULL;
  
  if (copy_element(&aux->element, e) == ERROR){
    free(aux);
    return NULL;
  }

  return aux;
}

/**
@name destroy_node
@brief it frees the memory of the node
@param node the node to be freed
@return void
*/
void destroy_node(node *node){
  destroy_element(&node->element);
  free(node);
}

/**
@name print_node
@brief print the node in the terminal
@param node the node to be printed
@return void
*/
void print_node(node node){
  print_element(node.element);
}
