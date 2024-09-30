#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maze_solve(char maze[][8], int x_start, int y_start, int x_end, int y_end, int* step, char path[]);
void print_steps(char path[], int steps);

int main() {
	int is_path;	
	int step = 0;/*�]���ܼ�:�O�_�����|�B�B�J�ơB���|�B�a��*/
	char path[100];
	char maze[8][8] = {   
		/* Y */
		/* 0 */  {'X',    'X',    ' ',    ' ',    ' ',    'X',    'X',    'X'},
		/* 1 */  {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		/* 2 */  {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		/* 3 */  {' ',    'X',    ' ',    'X',    ' ',    ' ',    ' ',    'X'},
		/* 4 */  {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		/* 5 */  {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		/* 6 */  {' ',    'X',    ' ',    'X',    ' ',    'X',    ' ',    'X'},
		/* 7 */  {' ',    ' ',    ' ',    'X',    ' ',    'X',    ' ',    ' '}
		/* / */ /* 0 */ /* 1 */ /* 2 */ /* 3 */ /* 4 */ /* 5 */ /* 6 */ /* 7 */ /* X */
	};
	is_path = maze_solve(maze, 0, 1, 7, 7, &step, path);
	if (is_path) {
		print_steps(path, step);	
	}
	else {
		printf("no path\n");
	}
	return 0;
}

int maze_solve(char maze[][8], int x_start, int y_start, int x_end, int y_end,int* step,char path[]) {/*�禡*/
	int ans = 0;
	if (maze[y_start][x_start] == 'X' || x_start >= 8 || y_start >= 8 || x_start < 0 || y_start < 0) {/*�Y�Ӯ欰��ζW�X�d��*/
		ans = 0;/*�^��0*/
	}
	else if (x_start == x_end && y_start == y_end) {/*�Y����I�h�^��1*/
		ans = 1;
	}
	else {
		maze[y_start][x_start] = 'X';/*�g�L���|�]�����קK���ƨ�*/
		if (maze_solve(maze, x_start+1, y_start, x_end, y_end, step , path)) {/*�W�U���k���j�h��*/
			path[(*step)++] = 'R';
			ans = 1;
		}
		if (maze_solve(maze, x_start-1, y_start, x_end, y_end, step, path)) {
			path[(*step)++] = 'L';
			ans = 1;
		}
		if (maze_solve(maze, x_start , y_start+1, x_end, y_end, step, path)) {
			path[(*step)++] = 'D';
			ans = 1;
		}
		if (maze_solve(maze, x_start , y_start-1, x_end, y_end, step, path)) {
			path[(*step)++] = 'U';
			ans = 1;
		}
	}
	return ans;/*�^�Ǹ��|*/
}
void print_steps(char path[], int step) {/*��X���|*/
	for (int i = step - 1; i >= 0; --i) {

		printf("Step %2d: ", step - i);/*�q�᭱��X�^�ӡA�]�����j�ҥH�O�Ϫ�*/
		switch (path[i]) {
		case 'L':
			printf("go left\n");
			break;
		case 'R':
			printf("go right\n");
			break;
		case 'D':
			printf("go down\n");
			break;
		case 'U':
			printf("go up\n");
			break;
		}
	}
}