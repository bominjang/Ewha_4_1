//
//  main.c
//  algo
//
//  Created by 장보민 on 2021/04/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right, int k)
{
    int pivot, temp, low, high;
    
    pivot = list[k]; //무작위 pivot
    SWAP(list[k], list[right], temp); //hide pivot. 맨 오른쪽 끝으로 옮김
    
    printf("Pivot = %d\n", pivot);
    for(int i=0;i<MAX_SIZE; i++)
        printf("[%d] ",list[i]);
    printf("\n\n");
    //low는 0번부터 시작해야 하므로 -1로 set, high는 right부터 시작해서 right-1부터 비교.(do while 이므로)
    low = left-1;
    high = right;
    
    
    do
    {
        do{
            low++;
        }while(list[low]<pivot); //기준원소보다 작으면 계속 이동
        
        do{
            high--;
        }while(list[high]>pivot); //기준원소보다 크면 계속 이동
        /*
         for(int i=0; i<MAX_SIZE; i++)
             printf("[%d] ", list[i]);
         printf("\nlow = %d, high=%d\n", low, high);
         */
        
        if(low<high)
        {
            SWAP(list[low], list[high], temp);
        }
    }while(low<high);
    
    //low와 high의 위치가 바뀌었으면(즉, low가 high보다 크면) 한 번의 partition이 끝난 것.
    //숨겨뒀던 무작위 pivot과, pivot보다 큰 원소들 중 가장 왼쪽에 있는 원소
    SWAP(list[low], list[right], temp);
    return low; //pivot이 있는 인덱스 return
    
}

void quick_sort(int list[], int left, int right)
{
    if(left<right)
    {
        int k = rand()%(right-left)+left+1;
        int q = partition(list, left, right, k);
        quick_sort(list, left, q-1);//q 왼쪽
        quick_sort(list, q+1, right);//q오른쪽
    }
    
}


void main(int argc, const char * argv[]) {
    int list[MAX_SIZE];
    srand(time(NULL));
    
    for(int i=0;i<MAX_SIZE; i++)
        list[i] = rand()%100;
    
    for(int i=0; i<MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n"); getchar();
    
    quick_sort(list, 0, MAX_SIZE-1);
    for(int i=0; i<MAX_SIZE; i++)
        printf("[%d] ", list[i]);
}

