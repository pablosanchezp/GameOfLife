#include"List.h"

/**
@name create_list
@brief destroys (frees) memory of an element that have been stored
@return a list or NULL
*/
list * create_list(){
  list * l = (list *) calloc(1,sizeof(list));
  return l;
}

/**
@name ini_list
@brief initialize a list setting all the pointers to NULL
@param l the list to initialize
@return OK or ERROR
*/
STATUS ini_list(list *l){
  if (l == NULL)
    return ERROR;
  l->first = NULL;
  l->last = NULL;
  return OK;
}

/**
@name is_empty_list
@brief checks if a list is empty
@param l the list to check if it is empty
@return OK or ERROR
*/
BOOL is_empty_list(list *l){
  if (l == NULL)
    return TRUE;

  if (l->first == NULL)
    return TRUE;

  return FALSE;
}

/**
@name first_list
@brief returns in the second argument the first element of a list
@param l the list 
@param e the element that will be updated
@return OK or ERROR
*/
STATUS first_list(list *l, element *e){
  if (l == NULL)
    return ERROR;

  if (is_empty_list(l) == TRUE)
    return ERROR;

  return copy_element(e, &l->first->element);
}

/**
@name insert_first_list
@brief inserts an element in the first position of the list
@param l the list 
@param e the element that will be inserted
@return OK or ERROR
*/
STATUS insert_first_list(list *l,element e){
  node *p;
  p = create_node(&e);
  /*One element*/
  if (l->first == NULL){
    l->first = p;
    l->last = p;
  } else{
    p->next = l->first;
    l->first = p;
  }
  return OK;
}


/**
@name extract_first_list
@brief extracs the first element in the list
@param l the list 
@param e the element that will be inserted
@return OK or ERROR
*/
STATUS extract_first_list(list *l, element *e){
  node *p;
  if (l == NULL)
    return ERROR;
  
  if (is_empty_list(l) == TRUE)
    return ERROR;

  /*One element*/
  if (l->first->next == NULL){
    p = l->first;
    copy_element(e, &l->first->element);
    destroy_node(p);
    ini_list(l);
  }else{
    p = l->first;
    copy_element(e, &l->first->element);
    l->first = p->next;
    destroy_node(p);
  }

  return OK;
}

/**
@name concat_list
@brief joins two list in one
@param dst the destination list
@param origin the list that will be copied
@return OK or ERROR
*/
void concat_list(list *dst , list * origin){
  node * p = origin->first;
  element e;
  while (p != NULL){
    copy_element(&e, &p->element);
    insert_last_list(dst,e);
	destroy_element(&e);
    p=p->next;
  }
}

/**
@name insert_last_list
@brief inserts an element in the last position of the list
@param l the list on which the element will be inserted
@param e the element to be inserted
@return OK or ERROR
*/
STATUS insert_last_list(list * l, element e){
  node * p;
  p = create_node(&e);
  if (p == NULL)
    return ERROR;
  
  if (l->first == NULL){
    l->first = p;
    l->last = p;
  }else{
    l->last->next = p;
    l->last = p;
  }
  return OK;
}

/**
@name extract_last_list
@brief extract the last element of a list
@param l the list on which the element will be extracted
@param e the element to be extracted
@return OK or ERROR
*/
STATUS extract_last_list(list *l, element *e){
  node * p;
  if (l == NULL)
    return ERROR;
  if (is_empty_list(l) == TRUE)
    return ERROR;
  
  if (l->first->next == NULL){
    p= l->first;
    copy_element(e, &l->first->element);
    destroy_node(p);
    ini_list(l);
  }else{
    p= l->first;
    while(p->next->next != NULL)
      p=p->next;
    copy_element(e, &p->next->element);
    destroy_node(p->next);
    p->next = NULL;
  }

  return OK;
}

/**
@name lenght_list
@brief computed the length of a list 
@param l the list 
@return the length of the list (from 0 to n)
*/
int lenght_list(list * l){
  int i = 0;
  node *p;
  if (l == NULL)
    return -1;
  if (is_empty_list(l) == TRUE)
    return 0;
  
  p = l->first;
  for (i = 0;p != l->last; i++)
    p=p->next;

  i++;
  return i;

}

/**
@name destroy_list
@brief free all the memory used by the list
@param l the list
@return void
*/
void destroy_list(list *l){
  element e;
  if (l == NULL)
    return;

  while (is_empty_list(l) == FALSE){
    extract_first_list(l,&e);
    destroy_element(&e);
  }
	
  free(l);
}

/**
@name search_list
@brief search an element in the list 
@param l the list
@param e the element to be searched
@return TRUE if the element is in the list FALSE otherwise
*/
BOOL search_list(list l , element e){
	 node *p = l.first;
	 while (p != NULL){
		if (equals_element(p->element,e) == TRUE)
			return TRUE;
		p=p->next;
	 }
	return FALSE;
}

/**
@name print_list
@brief prints all elements of the list 
@param l the list
@return void
*/
void print_list(list *l){
  node * p;
  if (l == NULL)
    return;

  p = l->first;
  while (p != NULL){
    print_node(*p);
    p=p->next;
  }
}
