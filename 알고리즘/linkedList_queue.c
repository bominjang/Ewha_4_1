//
//  Created by 장보민 on 2021/03/16.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct QueueNode
{
    int data;
    struct QueueNode* link; // QueueNode 타입의 변수를 가리키는 포인터변수
}QueueNode;

typedef struct
{
    QueueNode* front; //queue의 프론트 위치와 rear 위치.
    QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue)
{
    queue->front = queue->rear = NULL;
}

int is_empty(LinkedQueue* queue)
{
    return queue->front == NULL;
}

int dequeue(LinkedQueue* queue)
{
    QueueNode* temp = queue->front;
    int data;
    //exception 처리
    if(is_empty(queue))
    {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    else{
        data = temp->data;
        queue->front = temp->link;
        //temp->link가 NULL이라면 기존 큐에 데이터가 하나밖에 없었다는 뜻이 됨.
        //따라서 queue의 near 역시 NULL로 초기화를 해야함.
        if(queue->front == NULL)
            queue->rear = NULL;
        free(temp);
        return data;
    }
}

void enqueue(LinkedQueue* queue, int data)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->link = NULL;
    if(is_empty(queue))
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->link = temp;
        queue->rear = temp;
    }
}


void print_queue(LinkedQueue* queue)
{
    QueueNode* p;
    for(p = queue->front; p!=NULL;p=p->link)
    {
        printf("|%d| -> ", p->data);
    }
    printf("|NULL|\n");
}

void main() {
    LinkedQueue queue;
    init(&queue);
    
    enqueue(&queue, 10); print_queue(&queue);
    enqueue(&queue, 20); print_queue(&queue);
    enqueue(&queue, 30); print_queue(&queue);
    
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);
    dequeue(&queue); print_queue(&queue);


}
