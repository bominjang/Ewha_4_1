#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

/*
 1단계
 5 3 8 1 2 7
 3 5 8 1 2 7
 3 5 1 8 2 7
 3 5 1 2 8 7
 3 5 1 2 7 8
 8은 가장 큰 값으로 정렬 완료
 -----------
 2단계에서는 7까지 정렬 완료
 3단계 에서는 5까지 정렬.
 
 단계를 지나면서 오른쪽부터 한 칸씩 한 칸씩 줄어듦.
 */

void bubble_sort(int list[], int n)
{
    int temp;
    printf("정렬할 원소 : ");
    for(int i=0;i<n;i++)
        printf("%d ", list[i]);
    printf("\n\n");
    printf("<<<<<<<<<<<<버블 정렬 수행>>>>>>>>>>>>>>>");
    //오른쪽에서부터 정렬
    for(int i=n-1;i>0;i--)
    {
        printf("\n%d 단계>>\n", n-i);
        for(int j = 0; j<i; j++)
        {
            if(list[j]>list[j+1])
                SWAP(list[j], list[j+1], temp);
        }
        for (int t=0; t<n; t++)
            printf("%3d", list[t]);
    }
}

void main(){
    int list[6] = {5, 3, 8, 1, 2, 7};
    bubble_sort(list, 6);
    
    
    getchar();
}
