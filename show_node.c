#include "ttt.h"
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv ){
    if (argc > 1){
        init_boards();
        init_board(START_BOARD);
        join_graph(START_BOARD);
        compute_score();
        int i;
        for (i = 1; i < argc; i++){
            int board_hash = atoi(argv[i]);
            if (board_hash >= 0 && board_hash < HSIZE && htable[board_hash].init){
                print_node(htable[board_hash]);
            } else {
                printf("Board with chosen hash (%i) is not possible in real tic-tac-toe.\n", board_hash);
            }
        }
    }
}