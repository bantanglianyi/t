#ifndef _PLAY_H_
#define _PLAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE 9
#define LIST 9
#define LINE_S LINE+2
#define LIST_S LIST+2
#define number 10

void page();
void board_init(char board[LINE_S][LIST_S], int line, int list, char set);
void displayboard(char board[LINE_S][LIST_S], int line, int list);
void release_thunder(char board[LINE_S][LIST_S], int line, int list);
void removalmines(char board_1[LINE_S][LIST_S], char board[LINE_S][LIST_S], int line, int list);

#endif
