#ifndef _MAZE__H_
#define _MAZE__H_

#include "Stack.h"

#define N 6

typedef struct Pos
{
	int _row;
	int _col;
}Pos;

int GetPath(int maze[N][N], int row, int col);
void PrintMaze(int maze[N][N]);

#endif