#include "Board.h"


/**
@name create_board
@brief stores the memory needed for a board 
@param width the number of columns
@param height the number of rows
@param number_neighbours the number of live neighbours that a cell needs to start living
@param posible_neighbours an array of posible neighbours that a cell needs to continue living
@return a board
*/
board * create_board(int width, int height, int* number_neighbours, int lenght1,int *posible_neighbours,int lenght2){
	board * b = (board *) calloc(1,sizeof(board));
	if (b==NULL)
		return NULL;
	b->width = width;
	b->height = height;
	b->number_neighbours = number_neighbours;
    b->lenght_number_neighbours = lenght1;
	b->posible_neighbours = posible_neighbours;
    b->lenght_posible_neighbours = lenght2;
	b->l = create_list();
	return b;
}

/**
@name neighs
@brief it obtains the neighbours of a cell
@param b the board
@param c the cell
@return a list of cells that are neighbours of the cell 
*/
list * neighs(board b,cell c){
	int i,j;
	int newx;
	int newy;
	list *l = create_list();
	cell *c2;	
	for (i=-1;i< 2;i++){
		for (j = -1; j < 2; j++){
			if (i != 0 || j != 0) {/*Avoid repetitions*/
				newx=i+c.x;
				newy=j+c.y;


				if (newx >= b.width)
                    continue;
					/*newx = 0;*/
				
				if (newy >= b.height)
                    continue;
					/*newy = 0;*/
				
				if (newx < 0)
                    continue;
					/*newx = b.width-1;*/
				
				if (newy < 0)
                    continue;
					/*newy = b.height-1;*/

				c2 = create_cell(newx,newy);		
				insert_first_list(l,c2);
				destroy_cell(c2);
			}
		}
	}
	return l;
}


/**
@name is_empty
@brief checks if a cell is dead
@param b the board
@param c the cell
@return true if is dead false otherwise
*/
BOOL is_empty(board b, cell *c){
	if (is_alive(b, c)==TRUE)
		return FALSE;
	return TRUE;
}

/**
@name is_alive
@brief checks if a cell is alive
@param b the board
@param c the cell
@return true if is alive false otherwise
*/
BOOL is_alive(board b, cell *c){
	node *p=b.l->first;
	while (p!=NULL){
		if (equals_cell(c,p->element)==TRUE)
			return TRUE;
		p=p->next;
	}
	return FALSE;
}

/**
@name live_neighbours
@brief it obtains the number of alive neighbours of a cell
@param b the board
@param c the cell
@return the number of neighbours
*/
int live_neighbours(board b, cell c){
	int result = 0;	
	list * l = neighs(b,c);
	node *p = l->first;	
	while (p != NULL){
		if (is_alive(b,(p->element))==TRUE)
			result++;
		p=p->next;
	}
	destroy_list(l);
	return result;
}

/**
@name survivors
@brief it obtains the number of survivors of a board
@param b the board
@return the list of survivors
*/
list * survivors(board b){
	node *board_lst = b.l->first;
	int i;
	int number;
	list * result = create_list();
	while (board_lst != NULL){
		number = live_neighbours(b, *(board_lst->element));
		for (i=0;i<b.lenght_posible_neighbours;i++){
			if (number == b.posible_neighbours[i]){
				insert_first_list(result,(board_lst->element));
			}		
		}
		board_lst = board_lst->next;
	}
	return result;
}

/**
@name remove_duplicates
@brief it removes duplicates from a list
@param b the board
@return the list of survivors
*/
list * remove_duplicates(list *l){
	list * l2 = create_list();
	node *p = l->first;
	while (p != NULL){
		if (!search_list(*l2, p->element))
			insert_first_list(l2, p->element);
		p=p->next;
	}
	destroy_list(l);
	return l2;
}

/**
@name births
@brief calculates the cells that have been created 
@param b the board
@return the list of new cells
*/
list * births (board b){
    int j;
	node * p = b.l->first;	
	list * result = create_list();
    int n;

	/*Sublists*/
	list * aux = NULL;
	node * p2 = NULL;

	while (p != NULL){ /*For each cell in the list*/
		aux = neighs(b,*(p->element)); /*Obtain the neighbours*/
		p2 = aux->first;
		while (p2 != NULL){
			if (search_list(*result, p2->element) == FALSE && is_empty(b, (p2->element))){
                    n = live_neighbours(b, *(p2->element));
                    for (j = 0 ; j< b.lenght_number_neighbours;j++){
					    if (n == b.number_neighbours[j])
                            insert_first_list(result,p2->element);
                    }	
			}				
			p2 = p2->next;;
		}
		destroy_list(aux);
		p=p->next;
	}
	return result;
}

/**
@name next_generation
@brief returns the births and the survivors of a board
@param b the board
@return the list of new cells
*/
void next_generation(board *b){

	list * result = survivors(*b);

	list * aux = births(*b);

	concat_list(result , aux);
	destroy_list(aux);
	destroy_list(b->l);
	b->l = result;

}

/**
@name print_board_terminal
@brief prints the board in the terminal
@param b the board
@return void
*/
void print_board_terminal(board *b){
	node *p=b->l->first;
	while (p != NULL){
		print_terminal_cell(*(p->element));		
		p=p->next;
	}
	
}

/**
@name destroy_board
@brief frees the memory that a board is using
@param b the board
@return void
*/
void destroy_board(board * b){
	destroy_list(b->l);
	free(b->posible_neighbours);
    free(b->number_neighbours);
	free(b);
}

/**
@name read_from_file
@brief reads a board from a file
@param path the path of the file
@return void
*/
board * read_from_file(char * path){
    int width = 1;
    int height = 1;
    int count =1;
    FILE *file=NULL;
    board *b;
    char c;
    if (path == NULL)
        return NULL;
    file = fopen(path, "r");

    int * n = (int *) calloc(2,sizeof(int)); //Game 23/3
	n[0] = 2;
	n[1] = 3;
    int * n2 = (int *) calloc(1,sizeof(int)); 
    n2[0]=3;
    b= create_board(105, 35, n2,1,n,2);
    

    while ((c = getc(file)) != EOF){
        if (c=='\n'){
            count=0;
            height++;
            width=MAX(width,count);
        }
        if (c == 'O'){
            cell* c = create_cell(count,height);
            insert_first_list(b->l,c);
            destroy_cell(c);
        }
        count++;
    }
    fclose(file);
    return b;
}

