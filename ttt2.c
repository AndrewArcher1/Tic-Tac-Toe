#include "ttt.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>


void init_boards(){
    
    int h=0;

    for(h=0; h< HSIZE; h++ ){
        //sets the init of each node to 0
        htable[h].init = 0;
    }

}

int depth(Board board){
    
    int x =0;
    int total=0;

    for(x=0; x < BSIZE; x++){
        //counts the amount of X's anf O's on the board
        if((board[x]== 'X' )|| (board[x]==  'O')){
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
            //checks the winning postion for a win of X
            if(board[pos2idx[WINS[col][row]]]=='X'){
                x++;
            }
            //checks the winning postions for a win of O
            if(board[pos2idx[WINS[col][row]]]=='O') {
                o++;
            }
            if(x==3){
                //return X if X won
                return 'X';
            }
            if(o==3){
                //return O is O won
                return 'O';
            }
            
        }
        x=0;
        o=0; 

    }

    if(depth(board) == 9){
        return '-';
    }

    return '?';
}
char turn (Board board){
    //if the game is over return -
    if(depth(board)==9|| (winner(board) == 'X')|| (winner(board)=='O')){
        return '-';
    }

    if(depth(board)%2 == 0||depth(board)==0){
        //if X's turn return X
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

    int hash=0;

    int hashbuff=0;

    Board boardBuff;
    
    //if there is no winner make the next board
    if(winner(board) == '?'){
        hash = board_hash(board);
    for(j=0; j<9; j++){
        
        if(board[pos2idx[j]] == 'O'|| board[pos2idx[j]] == 'X'){
            //set illegal moves to -1
            htable[hash].move[j] = -1;
            
        }else{
            
            strcpy(boardBuff,board);
            
            boardBuff[pos2idx[j]] = turn(boardBuff);
            
            hashbuff = board_hash(boardBuff);
            
            htable[hash].move[j] = hashbuff;

            if(htable[hashbuff].init == 0){
                //if the board is not made make it
                init_board(boardBuff);
                join_graph(boardBuff);
                
            }
                
        }

    }

    }

}

void compute_score(){



}

int best_move(int board){

    return 0;
}
