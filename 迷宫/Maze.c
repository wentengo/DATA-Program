#include "Maze.h"

int GetPath(int maze[N][N], int row, int col)
{
	int n = 2, tmp = 0, x = row, y = col;
	maze[row][col] = n;
	Stack s;
	StackInit(&s, 36);
	StackPush(&s,  row,  col);
	while (StackEmpty(&s))
	{
		if ((row == 0 || row == N - 1 || col == 0 || col == N - 1) && row != x&&col != y)
			tmp = 1;
		if (maze[row - 1][col] == 1 || ((maze[row][col] + 1) < maze[row - 1][col]))
		{
			if (row - 1 != 0)
			{
				StackPush(&s, row - 1, col);
				maze[--row][col] = ++n;
			}
			else
			{
				StackPop(&s);
				row = StackTop(&s)._row;
				col = StackTop(&s)._col;
				--n;
			}
		}
		else if (maze[row][col + 1] == 1 || ((maze[row][col] + 1) < maze[row][col + 1]))
		{
			if (col + 1 != N)
			{
				StackPush(&s, row, col + 1);
				maze[row][++col] = ++n;
			}
			else
			{
				StackPop(&s);
				row = StackTop(&s)._row;
				col = StackTop(&s)._col;
				--n;
			}
		}
		else if (maze[row][col - 1] == 1 || ((maze[row][col] + 1) < maze[row][col - 1]))
		{
			if (col - 1 != 0)
			{
				StackPush(&s, row, col - 1);
				maze[row][--col] = ++n;
			}
			else
			{
				StackPop(&s);
				row = StackTop(&s)._row;
				col = StackTop(&s)._col;
				--n;
			}
		}
		else if (maze[row + 1][col] == 1 || ((maze[row][col] + 1) < maze[row + 1][col]))
		{
			if (row + 1 != N)
			{
				StackPush(&s, row + 1, col);
				maze[++row][col] = ++n;
			}
			else
			{
				StackPop(&s);
				row = StackTop(&s)._row;
				col = StackTop(&s)._col;
				--n;
			}
		}
		else
		{
			StackPop(&s);
			row = StackTop(&s)._row;
			col = StackTop(&s)._col;
			--n;
		}
	}
	return tmp;
}

void PrintMaze(int maze[N][N])
{
	assert(maze);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%-3d", maze[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int maze[N][N] =
	{
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0 },
		{ 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
	};
	printf("%d\n", GetPath(maze, 5, 2));
	PrintMaze(maze);
	return 0;
}