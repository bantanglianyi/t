#define _CRT_SECURE_NO_WARNINGS 1
#include "play.h"
void gome_play()
{
    char thunder_board[LINE_S][LIST_S];
    char select_board[LINE_S][LIST_S];
    //��ʼ��
    board_init(thunder_board, LINE_S, LIST_S, '0');
    board_init(select_board, LINE_S, LIST_S, '*');
    //��ӡ����
    
    displayboard(select_board, LINE, LIST);
    //���õ���
    release_thunder(thunder_board, LINE, LIST);
    displayboard(thunder_board, LINE, LIST);
    //����
    removalmines(thunder_board, select_board, LINE, LIST);

  
    
}
void select()
{
    srand((unsigned int)time(NULL));
    int pattern;
    do
    {
        page();
        printf("��ѡ��:");
        scanf("%d", &pattern);
        switch (pattern)
        {
            case 1:
                gome_play();
                break;
            case 2:
                printf("��Ϸ����\n");
                break;
        }
    } while (pattern!= 2);
}
int main()
{
    select();
    return 0;
}