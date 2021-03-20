//
//  Created by 장보민 on 2021/03/20.
//

#include <stdio.h>
#include <stdlib.h>

int* removeCandle(int* A, int n, int pos)
{
    for(int i=pos;i<n-1;i++)
    {
        A[i] = A[i+1];
    }
    return A;
}

int runSimulation(int* A, int n, int k)
{
    int r=0;//순회
    while(n>1)
    {
        r = (r+k)%n;
        printf("%d번 양초가 꺼졌습니다. 남은 양초의 개수 : %d\n", A[r], n-1);
        A = removeCandle(A, n, r);
        n--;
    }
    return A[0];
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
