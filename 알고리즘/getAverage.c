#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void makeArray(int A[])
{
    for(int i=0;i<SIZE;i++)
    {
       A[i] = rand() %50+50;
    }
}

void printArray(int A[])
{
    for(int i=0;i<SIZE; i++){
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

void prefixAvg1(int A[]){
    int X[SIZE]; //누적배열
    int sum;
    
    for(int i=0;i<SIZE;i++){
        sum = 0;
        for(int j=0;j<=i;j++){
            sum += A[j];
        }
        X[i] = sum/(i+1);
    }
    printArray(X);
}

void prefixAvg2(int A[]){
    int X[SIZE]; //누적배열
    int sum=0;
    
    for(int i=0;i<SIZE;i++){
        sum += A[i];
        X[i] = sum/(i+1);
    }
    printArray(X);
}

void main()
{
    int A[SIZE];
    srand(time(NULL)); //난수발생
    makeArray(A);
    printArray(A);
    getchar();
    prefixAvg1(A);
    prefixAvg2(A); //선형복잡도
}
