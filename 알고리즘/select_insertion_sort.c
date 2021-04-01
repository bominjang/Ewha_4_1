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
    int i, j, save;
    for(i=1;i<n;i++)
    {
        save = list[i];
        for(j=i-1;j>=0 && list[j]>save; j--)
        {
            list[j+1] = list[j];
        }
        list[j+1] = save;
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
    insertion_sort(list, MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++){
        printf("%d ", list[i]);
    }
        
    printf("\n\n");
}
