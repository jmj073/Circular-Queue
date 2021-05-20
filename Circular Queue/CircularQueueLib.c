#include "CircularQueueHeader.h"

//ť ����
void CQ_CreateQueue(CQ** Queue, int Capacity) {
	(*Queue) = (CQ*)malloc(sizeof(CQ));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

//ť ����
void CQ_DestroyQueue(CQ* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

//ť�� �� á����
int CQ_IsFull(CQ* Queue) {
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	return (Queue->Rear + 1) == Queue->Front;
}

//ť�� �������
int CQ_IsEmpty(CQ* Queue) {
	return Queue->Front == Queue->Rear;
}

//��� ����
int CQ_Enqueue(CQ* Queue, ElementType Data) {
	if (CQ_IsFull(Queue)) //�������� ���������� ������ ������!!!
		return -1;
	Queue->Nodes[Queue->Rear].Data = Data;
	if (Queue->Rear == Queue->Capacity)
		Queue->Rear = 0;
	else
		Queue->Rear++;
	return 1;
}

//��� ����
ElementType CQ_Dequeue(CQ* Queue) {
	ElementType Data = Queue->Nodes[Queue->Front].Data;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Data;
}

//ť�� ũ��
int CQ_GetSize(CQ* Queue) {
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

