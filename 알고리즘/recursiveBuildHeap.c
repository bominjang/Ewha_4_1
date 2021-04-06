#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

struct Heap
{
    int H[MAX_ELEMENT];
    int n;
}_Heap; //전역으로 선언

void downHeap(int i)
{
    //비교할 자식노드가 없으면 return
    if(i*2 > _Heap.n) return;
    //_Heap.H를 최대 힙으로 만듦.
    if(_Heap.H[i]<_Heap.H[i*2] || _Heap.H[i]<_Heap.H[i*2+1])
    {
        //왼쪽 자식 노드가 더 큰 경우
        if(_Heap.H[i*2]>_Heap.H[i*2+1])
        {
            int temp;
            temp = _Heap.H[i]; //처리해야 할 부모노드
            _Heap.H[i] = _Heap.H[i*2];
            _Heap.H[i*2] = temp;
            downHeap(i*2); //또 밑에 자식들을 downHeap
        }
        else{
            int temp;
            temp = _Heap.H[i]; //처리해야 할 부모노드
            _Heap.H[i] = _Heap.H[i*2+1];
            _Heap.H[i*2+1] = temp;
            downHeap(i*2+1); //또 밑에 자식들을 downHeap
        }
    }
    else{
        return;
    }
}

void rBuildHeap(int i)
{
    if(i>_Heap.n) return;
    
    if(i*2<=_Heap.n) //왼쪽 자식이 있으면 재귀호출
        rBuildHeap(2*i);
    if(i*2+1<=_Heap.n) //오른쪽 자식이 있으면 재귀호출
        rBuildHeap(2*i+1);
    downHeap(i);
}

int removeMax()
{
    int key = _Heap.H[1];
    _Heap.H[1] = _Heap.H[_Heap.n--]; //첫번째에 마지막 인덱스의 값을 넣어줌 & 원소개수 줄여줌
    downHeap(1); //downHeap으로 정렬
    return key;
}

void inplaceHeapSort()
{
    int size = _Heap.n;
    int key;
    for(int i=0; i<size; i++)
    {
        key = removeMax(); //최대값을 받아오고
        _Heap.H[_Heap.n+1] = key; //오른쪽 끝부터 삽입
    }
}

void printHeap()
{
    for(int i=1; i<=_Heap.n; i++)
    {
        printf("[%d] ", _Heap.H[i]);
    }
    printf("\n");
}

void printArray()
{
    for(int i=1;_Heap.H[i]>0;i++)
    {
        printf("[%d] ", _Heap.H[i]);
    }
    printf("\n");
}

void main(){
    _Heap.n = 0;
    srand(time(NULL));
    printf("입력할 원소의 개수 : ");
    scanf("%d", &_Heap.n);
    
    for(int i=1;i<=_Heap.n;i++)
    {
        _Heap.H[i] = rand()%100;
    }//리스트를 만듦
    rBuildHeap(1);
    printHeap();
    getchar();
    inplaceHeapSort();
    printArray();
}
