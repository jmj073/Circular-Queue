#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <malloc.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
} Node;

typedef struct tagCircularQueue {
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
} CQ;

void CQ_CreateQueue(CQ** Queue, int Capacity);
void CQ_DestroyQueue(CQ* Queue);
int CQ_IsEmpty(CQ* Queue);
int CQ_IsFull(CQ* Queue);
int CQ_Enqueue(CQ* Queue, ElementType Data);
ElementType CQ_Dequeue(CQ* Queue);
int CQ_GetSize(CQ* Queue);

#endif //CIRCULAR_QUEUE_H