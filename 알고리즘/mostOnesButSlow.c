#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLS 8

void makeArray(int A[][COLS])
{
    for(int r=0;r<ROWS;r++)
    {
        int count = rand() % 8;
        for(int i=0;i<count;i++){
            A[r][i] = 1;
        }
        for(int j=count;j<COLS;j++){
            A[r][j] = 0;
        }
    }
}

void printArray(int A[][COLS])
{
    for(int r=0;r<ROWS;r++)
    {
        for(int c=0; c<COLS; c++)
        {
            printf("%2d", A[r][c]);
        }
        printf("\n");
    }
    
    printf("\n");
}

void mostOnesButSlow(int A[][COLS])
{
    int jmax = 0;
    int i,j,row;
    
    for(int i=0;i<ROWS;i++)
    {
        j = 0;
        while(j<COLS && A[i][j]==1)
        {
            j++;
        }
        if(j>jmax){
            row = i;
            jmax = j;
        }
    }
    printf("%d행에  %d개의 1이 최대값임", row, jmax);
}


void main()
{
    int A[ROWS][COLS];
    srand(time(NULL)); //난수발생
    makeArray(A);
    printArray(A);
    getchar();
    
    mostOnesButSlow(A);
}
