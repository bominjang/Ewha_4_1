//
//  Created by 장보민 on 2021/03/20.
//

#include <stdio.h>
#include <stdlib.h>

int runSimulation(int* A, int n, int k)
{
    int r=0;
    int N = n;
    while(n>1)
    {
        int i=0;
        while(i<k)
        {
            r = (r+1)%N;
            if(A[r]!=0){i++;}
        }
        printf("%d번째 양초가 꺼졌습니다.\n", A[r]);
        A[r] = 0;
        n--;
        while(A[r]==0)
        {
            r = (r+1)%N;
        }
    }
    return A[r];
}

int* buildList(int* A, int n)
{
    for(int i=0;i<n;i++)
    {
        A[i] = i+1;
    }
    return A;
}

int candle(int n, int k){
    int* A = (int*)malloc(sizeof(int)*n);
    A = buildList(A, n);
    return runSimulation(A, n, k);
}

int main() {
    int a = candle(7, 3);
    printf("마지막 양초는 %d번째 양초입니다.\n", a);
    
    return 0;

}
