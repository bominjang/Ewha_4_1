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
int sorted[MAX_SIZE]; //정렬한 것들

void merge(int list[], int left, int mid, int right)
{
    int i =left;
    int j = mid+1;
    int k = left;
    int l;
    
    while(i<=mid && j <= right)
    {
        if(list[i]<=list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if(i>mid) //오른쪽에 더 남은 경우
        for(l=j;l<=right;l++){
            sorted[k++] = list[l];
        }
    else
        for(l=i;l<=mid;l++){
            sorted[k++] = list[l];
        }
    
    //sorted의 애를 원래 list로 재복사
    for(l = left; l<=right;l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right) //분할할 수 있으면
    {
        mid = (left+right)/2;
        merge_sort(list, left, mid); //왼쪽 sub
        merge_sort(list, mid+1, right); //오른쪽 sub
        merge(list, left, mid, right);
    }
}

int main(int argc, const char * argv[]) {
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i=0;i<MAX_SIZE;i++)
    {
        list[i] = rand()%100;
        for(int j=0;j<i;j++)
        {
            if(list[i]==list[j])
                i--;
        }
    }
    for(int i=0;i<MAX_SIZE;i++)
    {
        printf("[%d] ",list[i]);
    }
    printf("\n"); getchar();
    
    merge_sort(list, 0, MAX_SIZE-1);
    
    for(int i=0;i<MAX_SIZE;i++)
    {
        printf("[%d] ",list[i]);
    }
    printf("\n");
}

