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

int mostOnes(int A[][COLS])
{
    int i=0, j=0;
    int row;
    
    while(1){
        while(A[i][j]==1){
            j++;
            if(j==COLS-1){
                return i;
            }
        }
        row=i;
        while(A[i][j]==0){
            i++;
            if(i==COLS-1){
                return row;
            }
        }
    }
}


void main()
{
    int A[ROWS][COLS];
    srand(time(NULL)); //난수발생
    makeArray(A);
    printArray(A);
    getchar();
    
    printf("최대 1행은 %d행입니다.\n", mostOnes(A));
}
