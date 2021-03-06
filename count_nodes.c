#include "ttt.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[]){
    
    int i=0;
    int total;

    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);

    for(i=0;i<HSIZE;i++){
        //counts each init table
        if(htable[i].init == 1){
            total++;
        }
    }
    printf("%d\n",total);

    return(0);
}