#include "ttt.h"
#include <stdio.h>

int main( int argc, char **argv ){
    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);
    int i;
    int nodes_count = 0;
    for (i = 0; i < HSIZE; i++){
        nodes_count += htable[i].init;
    }
    printf("Count of the possible nodes in real tic-tac-toe game is: %i\n", nodes_count);
}