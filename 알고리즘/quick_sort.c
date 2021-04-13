#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right)
{
    int pivot, temp, low, high;
    
    //low는 0번에서 시작해서 1번으로 옮긴 다음, right는 15에서 시작해서 14번부터 시작.
    low = left;
    high = right+1;
    pivot = list[left];
    
    do
    {
        do{
            low++;
        }while(list[low]<pivot);
        
        do{
            high--;
        }while(list[high]>pivot);
        
        for(int i=0; i<MAX_SIZE; i++)
            printf("[%d] ", list[i]);
        printf("\nlow = %d, high=%d\n", low, high);
        
        if(low<high)
        {
            SWAP(list[low], list[high], temp);
        }
    }while(low<high);
    
    //low와 high의 위치가 바뀌었으면 한 번의 partition이 끝난 것. pivot과 high의 값을 바꾼다
    //high가 가리키는 값은, pivot보다 작은 애중에 가장 오른쪽에 있는 애
    SWAP(list[left], list[high], temp);
    return high; //pivot이 있는 인덱스 return
    
}

void quick_sort(int list[], int left, int right)
{
    if(left<right)
    {
        int q = partition(list, left, right);
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

