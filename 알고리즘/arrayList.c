//
//  Created by 장보민 on 2021/03/16.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int V[SIZE];
    int n; //원소의 개수
}ArrayList;

void init(ArrayList* L)
{
    L->n = 0;
}

void traverse(ArrayList* L)
{
    for(int i=0;i<L->n;i++)
        printf("[%d]", L->V[i]);
    printf("\n");
}

void add(ArrayList* L, int pos, int item)
{
    if(L->n == SIZE){
        printf("FullListException...\n");
        exit(1);
    }
    //invalidPosException.... 0<=pos <= L->n 인지. 구현하기
    for(int i=L->n -1; i>=pos; i--)
    {
        L->V[i+1] = L->V[i];
    }//한 칸씩 우측으로 shift
    L->V[pos] = item;
    L->n++;
}

int removeItem(ArrayList* L, int pos)
{
    //exception 처리 empty, invalidposition 처리해주기
    int item = L->V[pos];
    for(int i=pos+1;i<L->n;i++)
    {
        L->V[i-1] = L->V[i];
    }
    L->n--;
    return item;
}

void main() {
    ArrayList list;
    init(&list);
    
    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40);traverse(&list);
    add(&list, 3, 50); traverse(&list);
    
    getchar();
    removeItem(&list, 1); traverse(&list);
    removeItem(&list, 2); traverse(&list);
}
