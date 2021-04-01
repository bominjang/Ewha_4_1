#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list[], int n)//배열과 원소개수 전달
{
    int least, temp;
    for (int i=0;i<n-1;i++)//n-2까지
    {
        least = i; //min_location
        for(int j=i+1;j<n;j++)
        {
            if(list[j]<list[least])
                least = j;
        }
        SWAP(list[i], list[least], temp);
    }
}

void insertion_sort(int list[], int n)
{
    int i, j, key;
    for(i=1; i<n; i++)
    {
        key = list[i];
        for(j=i-1;j>=0 && list[j]>key; j--)
        {
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    //두번째 원소부터
    for(i=first+gap; i<=last; i=i+gap)
    {
        key = list[i];
        for(j=i-gap;j>=first && list[j]>key; j=j-gap)
        {
            list[j+gap] = list[j];
        }
        list[j+gap] = key;
    }
}
/*

 */

void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap=n/2;gap>0;gap=gap/2)
    {
        if(gap%2 == 0) gap++;
        for(i=0;i<gap;i++)
            inc_insertion_sort(list, i, n-1, gap); // i = 시작, n-1 = 마지막
    }
}

void main(){
    int list[MAX_SIZE];
    srand(time(NULL));
    
    for(int i=0;i<MAX_SIZE;i++)
    {
        //0~99까지의 수
        list[i] = rand() % 100;
        for(int j=0;j<i;j++)
            //중복 허용 X
            if(list[i] == list[j])
                i--;
    }
    
    for(int i=0;i<MAX_SIZE;i++)
        printf("%d ", list[i]);
    printf("\n\n");
    getchar();
    
    
    //selection_sort(list, MAX_SIZE);
    shell_sort(list, MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++){
        printf("%d ", list[i]);
    }
        
    printf("\n\n");
}
