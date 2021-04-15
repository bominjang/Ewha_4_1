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
#define BUCKETS 10
#define DIGITS 2

typedef int element;//요소
typedef struct{
    element data[MAX_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
    return q->front == q->rear;
}

int is_full(QueueType* q)
{
    //front가 rear바로 앞에 있을 때 full.(한 칸 비워놓으니까..?)
    return(q->rear+1)%MAX_SIZE == q->front;
}

void enqueue(QueueType* q, element item)
{
    if(is_full(q)) exit(1);
    
    q->rear = (q->rear+1)% MAX_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if(is_empty(q)) exit(1);
    
    q->front = (q->front+1)%MAX_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q)
{
    if(!is_empty(q))
    {
        int i = q->front;
        do{
            i=(i+1)%MAX_SIZE;
            printf("%d | ", q->data[i]);
            if(i==q->rear)
                break;
        }while(i!=q->front);
    }
    printf("\n");
}

void print_buckets(QueueType queues[])
{
    printf("\n======================\n");
    for(int b=0;b<BUCKETS;b++)
    {
        printf("[%d] ->", b);
        print_queue(&queues[b]);
    }
    printf("\b");
}

void radix_Sort(int list[], int n)
{
    //i 반복, b bucket, d digit
    int i, b, d, factor = 1;
    
    QueueType queues[BUCKETS]; //queue 배열
    
    for(b=0;b<BUCKETS;b++)
    {
        init_queue(&queues[b]);
    }
    
    for(d=0;d<DIGITS;d++)
    {
        for(i=0;i<n;i++)
        {
            //첫째짜리 위치에다가 item을 넣음
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        print_buckets(queues);
        for(b=i=0;b<BUCKETS;b++)
        {
            while(!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        }
        factor *= 10; //둘째자리도 수행할 수 있도록

    }
}

void main(int argc, const char * argv[]) {
    int list[MAX_SIZE];
    srand(time(NULL));
    
    for(int i=0;i<MAX_SIZE;i++)
    {
        list[i] = rand() %100;
    }

    for(int i=0;i<MAX_SIZE;i++)
    {
        printf("[%d] ",list[i]);
    }
    printf("\n\n");
    
    radix_Sort(list, MAX_SIZE);
    for(int i=0;i<MAX_SIZE;i++)
    {
        printf("[%d] ",list[i]);
    }
    printf("\n\n");

}

