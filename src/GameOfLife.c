#include "Board.h"
#include <unistd.h>

int main(){

	int i = 0;
    
    board * b= read_from_file("./src/boards/board1.txt");

	printf("\e[1;1H\e[2J");

	for (i = 0; i< 10000;i++){
		print_board_terminal(b);
		next_generation(b);
		printf("\e[1;1H\e[2J");
		
        usleep(100000);
	}
	destroy_board(b);
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return 0;
}
