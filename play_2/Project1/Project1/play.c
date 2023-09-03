#define _CRT_SECURE_NO_WARNINGS 1
#include  "play.h"
void page()
{
	printf("**********************************\n");
	printf("********** 1:��ʼ ****************\n");
	printf("********** 2:���� ****************\n");
	printf("**********************************\n");
}
void board_init(char board[LINE_S][LIST_S], int line_s, int list_s, char set)//��ʼ��
{
	int i, j;
	for(i = 0; i<line_s; i++)
	{
		for (j = 0; j < list_s; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[LINE_S][LIST_S], int line, int list)//���̴�ӡ
{
	int i, j;
	for (i = 0; i <= line; i++)
	{
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i <= line; i++)
	{
		printf(" %d", i);
		for (j = 1; j <= list; j++)
		{
			printf(" %c", board[i][j]);
		}
		printf("\n");
	}
}
void release_thunder(char board[LINE_S][LIST_S], int line, int list)//���õ���
{
	int count = number;
	while (count)
	{
		int x = rand() % line + 1;
		int y = rand() % list + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
char count_mines(char board_1[LINE_S][LIST_S],int x,int y)
{
	return( board_1[x - 1][y - 1] +
		board_1[x - 1][y] + 
		board_1[x - 1][y + 1] + 
		board_1[x][y - 1] + 
		board_1[x][y] + 
		board_1[x][y + 1] +
		board_1[x + 1][y - 1] + 
		board_1[x + 1][y] + 
		board_1[x + 1][y + 1] )-( 9*'0');
}
void removalmines(char board_1[LINE_S][LIST_S], char board[LINE_S][LIST_S], int line, int list)
{
	int x,y;
	int win = LINE * LIST - number;
	while (win)
	{
		printf("���������꣺");
		scanf("%d%d", &x ,&y);
		if (x >= 1 && x < 10 && y >= 1 && y < 10)
		{
			if (board_1[x][y] == '1')
			{
				printf("��ը��\n");
				displayboard(board_1, LINE, LIST);
				break;
			}
			else
			{
				int count_1 = count_mines(board_1, x, y);
				board[x][y] = count_1+'0';
				displayboard(board, LINE, LIST);
				win--;
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (win == 0)
	{
		printf("��ϲͨ��\n");
	}
}
