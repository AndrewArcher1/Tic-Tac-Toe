#include "ttt.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    int i;
    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);

    for(i=1;i<argc; i++){
        //prints the inputed node
    print_node(htable[atoi(argv[i])]);
    }
    return(0);
}
