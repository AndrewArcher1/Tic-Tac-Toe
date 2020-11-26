#include "ttt.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>


void init_boards(){
    
    int h=0;

    for(h=0; h< HSIZE; h++ ){
    htable[h].init = 0;
    }

}

int depth(Board board){
    
    int x =0;
    int total=0;

    for(x=0; x < BSIZE; x++){
        if((strcmp(&board[x], "X") == 0)|| (strcmp(&board[x], "O"))==0){
            total++;
        }
    }

    return total;

}

char winner (Board board){
    int col =0;
    int row =0;
    int x =0;
    int o =0;

    for( col=0; col < 8; col++ ){
        for( row=0; row < 3; row++){
            if(strcmp(&board[pos2idx[WINS[col][row]]],"X")==0){
                x++;
            }
            if(strcmp(&board[pos2idx[WINS[col][row]]],"O") == 0){
                o++;
            }
            if(x==3){
                return 'X';
            }
            if(o==3){
                return '0';
            }
            x=0;
            o=0;
        }

    }

    if(depth(board) == 9){
        return '-';
    }

    return '?';
}
char turn (Board board){
    if(depth(board)==9){
        return '-';
    }

    if(depth(board)%2 == 0){
        return 'X';
    }

    return 'O';
}

void init_board(Board board){


   int hash =  board_hash(board);
   
   htable[hash].init = 1;
   strcpy(htable[hash].board, board);
   htable[hash].turn = turn(board);
   htable[hash].depth = depth(board);
   htable[hash].winner = winner(board);

}

void join_graph(Board board){

    int j =0;

    int hash;

    int hashbuff;

    Board boardBuff;
    hash = board_hash(board);
    for(j=0; j<9; j++){
        
        if(isalpha(board[pos2idx[j]])){
            
            htable[hash].move[j] = -1;
            
        }else{
            
            strcpy(boardBuff,board);
            
            boardBuff[pos2idx[j]] = turn(board);
            
            hashbuff = board_hash(boardBuff);
            
            htable[hash].move[j] = hashbuff;

            if(htable[hashbuff].init == 0){
                
                init_board(boardBuff);
                join_graph(boardBuff);
                
            }
                
        }

    }


}

void compute_score(){

}

int best_move(int board){

    return 0;
}
