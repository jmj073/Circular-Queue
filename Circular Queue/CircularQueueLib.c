#include "CircularQueueHeader.h"

//큐 생성
void CQ_CreateQueue(CQ** Queue, int Capacity) {
	(*Queue) = (CQ*)malloc(sizeof(CQ));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

//큐 삭제
void CQ_DestroyQueue(CQ* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

//큐가 다 찼는지
int CQ_IsFull(CQ* Queue) {
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	return (Queue->Rear + 1) == Queue->Front;
}

//큐가 비었는지
int CQ_IsEmpty(CQ* Queue) {
	return Queue->Front == Queue->Rear;
}

//노드 삽입
int CQ_Enqueue(CQ* Queue, ElementType Data) {
	if (CQ_IsFull(Queue)) //안전성이 높아지지만 연산이 많아짐!!!
		return -1;
	Queue->Nodes[Queue->Rear].Data = Data;
	if (Queue->Rear == Queue->Capacity)
		Queue->Rear = 0;
	else
		Queue->Rear++;
	return 1;
}

//노드 제거
ElementType CQ_Dequeue(CQ* Queue) {
	ElementType Data = Queue->Nodes[Queue->Front].Data;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Data;
}

//큐의 크기
int CQ_GetSize(CQ* Queue) {
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

