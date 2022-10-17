#include "ttt.h"
#include <string.h>

void init_boards(){
    int i;
    for (i = 0; i < HSIZE; i++){
        htable[i].init = 0;
    }
}

int depth( Board board ){
    int dpt = 0;
    int i;
    for (i = 0; i < 9; i++){
        if (board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O') dpt++;
    }
    return dpt;
}

char winner( Board board ){
    int i;
    for (i = 0; i < 8; i++){
        if ((board[pos2idx[WINS[i][0]]] == board[pos2idx[WINS[i][1]]]) && (board[pos2idx[WINS[i][0]]] == board[pos2idx[WINS[i][2]]])){
            return board[pos2idx[WINS[i][0]]];
        }
    }
    if (depth(board) == 9) return '-';

    return '?';
}

char turn( Board board ){
    int dpt = depth(board);
    if (dpt == 9) return '-';
    if (dpt % 2) return 'O';
    else return 'X';
}

void init_board( Board board ){
    int b_hash = board_hash(board);
    htable[b_hash].init = 1;
    htable[b_hash].turn = turn(board);
    htable[b_hash].depth = depth(board);
    strcpy(htable[b_hash].board, board);
    htable[b_hash].winner = winner(board);
}

void join_graph( Board board ){
    int b_hash = board_hash(board);
    int i;
    if (htable[b_hash].winner != '?') return;
    for (i = 0; i < 9; i++){
        if (board[pos2idx[i]] == 'X' || board[pos2idx[i]] == 'O'){
            htable[b_hash].move[i] = -1;
        }
        else {
            Board n_board;
            strcpy(n_board, board);
            n_board[pos2idx[i]] = turn(board);
            int n_b_hash = board_hash(n_board);
            htable[b_hash].move[i] = n_b_hash;
            if (htable[n_b_hash].init) continue;
            init_board(n_board);
            join_graph(n_board);
        }
    }
}

int best_move( int board ){
    int min_score = 2;
    int max_score = -2;
    int best_move;
    int k;
    for (k = 0; k < 9; k++){
        if (htable[board].move[k] != -1){
            if (htable[board].turn == 'O' && htable[htable[board].move[k]].score < min_score){
                min_score = htable[htable[board].move[k]].score;
                best_move = k;
            }
            else if (htable[board].turn == 'X' && htable[htable[board].move[k]].score > max_score){
                max_score = htable[htable[board].move[k]].score;
                best_move = k;
            }
        }
    }

    return best_move;
}

void compute_score(){
    int i, j;
    for (i = 9; i >= 0; i--){
        for (j = 0; j < HSIZE; j++){
            if (!htable[j].init){
                continue;
            }
            if (htable[j].depth == i){
                if (winner(htable[j].board) != '?'){
                    char w = winner(htable[j].board);
                    if (w == 'X') htable[j].score = 1;
                    else if (w == 'O') htable[j].score = -1;
                    else htable[j].score = 0;
                } else {
                    htable[j].score = htable[htable[j].move[best_move(j)]].score;
                }
            }
        }
    }
}