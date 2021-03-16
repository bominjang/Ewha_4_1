//
//  Created by 장보민 on 2021/03/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode* link;
}ListNode;

typedef struct
{
    ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL;
}

void printList(LinkedListType* L)
{
    //head포인터가 가리키는 첫 노드부터, link가 NULL일때까지
    for(ListNode* p = L->head; p != NULL; p=p->link)
    {
        printf("[%d] -> ", p->data);
    }
    printf("NULL\n");
}

void addItem(LinkedListType* L, int pos, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i=0;i<pos-1;i++)
    {
        before = before->link;
    }
    node->data = item;
    node->link = before->link;
    before->link = node;
}

void addFirst(LinkedListType* L, int item)
{
    //노드 할당
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    //노드에 데이터 넣기
    node->data = item;
    node->link = L->head;
    //헤드 포인터를 노드에 연결
    L->head = node;
}

void addLast(LinkedListType* L, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    node->link = NULL;
    
    ListNode* before = L->head;
    while(before->link != NULL)
    {
        before = before->link;
    }
    before->link = node;
}

void removeItem(LinkedListType* L, int pos, int item)
{
    ListNode* target;
    ListNode* before = L->head;
    for(int i=0;i<pos-1;i++)
    {
        before = before->link;
    }
    target = before->link;
    before->link = target->link;
}

void removeFirst(LinkedListType* L)
{
    L->head = L->head->link;
}

void removeLast(LinkedListType* L)
{
    ListNode* before = L->head;
    while(before->link->link != NULL)
    {
        before = before->link;
    }
    before->link = NULL;
}

int get(LinkedListType* L, int pos)
{
    ListNode* p = L->head;
    for(int i=1;i<pos;i++)
    {
        p = p->link;
    }
    return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
    ListNode* p = L->head;
    for(int i=1;i<pos;i++)
    {
        p = p->link;
    }
    p->data = item;
}

void main() {
    LinkedListType list;
    init(&list);
    
    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    addLast(&list, 50); printList(&list);
    
    getchar();
    addItem(&list, 1, 40); printList(&list);
    addItem(&list, 1, 50); printList(&list);
    addItem(&list, 3, 60); printList(&list);
    
    getchar();
    removeItem(&list, 1, 50); printList(&list);
    removeItem(&list, 1, 40); printList(&list);
    
    getchar();
    removeFirst(&list); printList(&list);
    removeLast(&list); printList(&list);
    
    int pos;
    printf("\n몇 번 노드의 값을 반환할까요?");
    scanf("%d", &pos);
    printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));
}
