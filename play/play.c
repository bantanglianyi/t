#include "play.h"

void board_init(char boardplay[line][list],int LINE,int LIST)
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