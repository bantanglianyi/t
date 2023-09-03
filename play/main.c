#define _CRT_SECURE_NO_WARNINGS 1
#include"play.h"
void board()//页面
{
    printf("********************************************\n");
    printf("****** 1.play      2.not play **************\n");
    printf("********************************************\n");
    
}
void board_init(char boardplay[line][list],int LINE,int LIST)//初始化
{
    int i,j;
    for(i=0;i<LINE;i++)
    {
        for(j=0;j<LIST;j++)
        {
            boardplay[i][j]=' ';
        }
    }
}
void board_bar(char boardplay[line][list],int LINE,int LIST)// 棋盘打印
{
    int i,j;
    for(i=0;i<LINE;i++)
    {
        for(j=0;j<LIST;j++)
        {
            printf(" %C ",boardplay[i][j]);
            if(j<LIST-1)
            printf("|");
        }
          printf("\n");
        if(i<LINE-1)
        {
            for(j=0;j<LIST;j++)
            {
                printf("----");
            }
            printf("\n"); 
        }
          
    }
}
void board_plater(char boardplay[line][list],int LINE,int LIST)//玩家操作
{
    int x=0,y=0;
    while(1)
    {
        printf("play out coord:");
        scanf("%d%d",&x,&y);
        if(x>=1 && x<=LINE && y>=1 &&y<=LIST)
        {
            if(boardplay[x-1][y-1]==' ')
            {
                boardplay[x-1][y-1]='*';
                break;
            }
            else
            {
                printf("this locatlon already not empty\n");
            }
        }
        else
        {
            printf("coord error play anewout\n");
        }

    }
}
void computer_play(char boardplay[line][list],int LINE,int LIST)//电脑操作
{
    int x=0,y=0;
    printf("computer play\n");
    while(1)
    {
        x=rand()%LINE;
        y=rand()%LIST;
        if(x>=1 && x<=LINE && y>=1 &&y<=LIST)
        {
            boardplay[x][y]='#';
            break;
        }
    }
  

}
int draw_judge(char boardplay[line][list],int LINE,int LIST)//平局判断
{
    int i;
    int j;
    for(i=0;i<LINE;i++)
    {
        for(j=0;j<LIST;j++)
        {
            if(boardplay[i][j]==' ')
            {
                return 0;
            }
           
        }
    }
    return 1;

}
char judge(char boardplay[line][list],int LINE,int LIST)//输赢判断
{
    int i;
    for(i=0;i<LINE;i++)
    {
        if(boardplay[i][0]==boardplay[i][1] && boardplay[i][0]==boardplay[i][2] && boardplay[i][0]!=' ')
        {
            return boardplay[i][1];
        }
    }
    for(i=0;i<LIST;i++)
    {
        if(boardplay[0][i]==boardplay[1][i] && boardplay[0][i]==boardplay[2][i] && boardplay[0][i]!=' ')
        {
            return boardplay[0][i];
        }
    }
    if(boardplay[0][0]==boardplay[1][1] && boardplay[0][0]==boardplay[2][2] && boardplay[0][0]!=' ')
    {
        return boardplay[0][0];
    }
    if(boardplay[0][2]==boardplay[1][1] && boardplay[0][2]==boardplay[0][3] && boardplay[0][2]!=' ')
    {
        return boardplay[0][2];
    }
    if(draw_judge(boardplay,line,list)==1)
    {
        return 'Q';
    }
    return 'c';
    

}
void game_play()//游戏执行
{
    char boardplay[line][list]={0};
    board_init(boardplay,line,list);
    board_bar(boardplay,line,list);
    while(1)
    {
        
        board_plater(boardplay,line,list);
        board_bar(boardplay,line,list);
        if(judge(boardplay,line,list)!='c')
        {
            break;
        }
        computer_play(boardplay,line,list);
        board_bar(boardplay,line,list);
        if(judge(boardplay,line,list)!='c')
        {
            break;
        }
    }
    if(judge(boardplay,line,list)=='*')
    {
        printf("player win\n");
    }
    else if(judge(boardplay,line,list)=='#')
    {
        printf("computer win\n");
    }
    else
    {
        printf("draw\n");
    }  
}
void tmst()//判断
{
    int select=0;
    srand((unsigned int)time(NULL));
    do
    {
        board();
        printf("play select:");
        scanf("%d",&select);
        switch(select)
        {
            case 1:
            printf("game start\n");
            game_play();
            break;
            case 2:
            printf("game finish\n");
            break;
            default:
            printf("error");
            break;
        }
    }
    while(select!=2);
}
int main()
{
    tmst();
    return 0;
}