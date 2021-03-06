#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct
{
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType *h)
{
    h->heap_size = 0;
}

void upHeap(HeapType* h)
{
    int i = h->heap_size;
    int key = h->heap[i]; //넣은 값
    
    while((i!=1) && (key < h->heap[i/2])) //루트가 아니고, 삽입하려는 값이 부모의 값보다 작을 때 (*최소힙)
    {
        h->heap[i] = h->heap[i/2]; //부모값과 change
        i /= 2;
    }
    h->heap[i] = key;
}

void insertItem(HeapType *h, int key)
{
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    upHeap(h);
}

void downHeap(HeapType *h)
{
    int temp = h->heap[1];
    int parent = 1, child = 2;
    
    while(child <= h->heap_size) //child가 internal이면서
    {
        if((child < h->heap_size) && (h->heap[child]> h->heap[child+1])) //내 오른쪽에도 노드가 있고, 왼쪽 자식이 오른쪽 자식보다 크면
            child++; //오른쪽 자식을 smaller로
        if(temp <= h->heap[child])
            break;
        h->heap[parent] = h->heap[child]; //부모와 자식 자리 바꿔주기
        //한 단계 내려가기
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
}

int removeMin(HeapType *h)
{
    int key = h->heap[1];
    h->heap[1] = h->heap[h->heap_size]; //last를 넣어줌
    h->heap_size -= 1;
    
    downHeap(h);
    return key;
}

void heapSort(HeapType *h, int list[])
{
    HeapType heap;
    init(&heap);
    //힙 복사
    for(int i=1;i <= h->heap_size; i++)
    {
        heap.heap[i] = h->heap[i];
        heap.heap_size++;
    }
    for(int i=1; i <= h->heap_size; i++)
    {
        list[i] = removeMin(&heap); //작은값부터 순차적으로 저장
    }
}

void printArray(int list[], int n)
{
    for(int i=1;i<=n;i++) printf("[%d] ", list[i]);
    printf("\n");
}

void printHeap(HeapType* h)
{
    for(int i=1;i<=h->heap_size;i++)
    {
        printf("[%d] ", h->heap[i]);
    }
    printf("\n");
}

void inPlaceHeapSort(HeapType *h)
{
    int size = h->heap_size;
    int key; //최소값 기억할 변수
    for(int i=0; i<size; i++)
    {
        key = removeMin(h);
        h->heap[h->heap_size+1] = key; //오른쪽에서 왼쪽으로 움직이면서 넣자.
    }
}

void main(){
    HeapType heap;
    int list[MAX_ELEMENT] = {0};
    init(&heap);
    srand(time(NULL));
    init(&heap);
    for(int i=0;i<15;i++)
    {
        insertItem(&heap, rand()%100);
    }
    printHeap(&heap);
    
    inPlaceHeapSort(&heap);
    getchar();
    for(int i=1; heap.heap[i]>0;i++)
    {
        printf("[%d] ", heap.heap[i]); //최소값이 제일 뒤로 정렬된 배열
    }
}
