#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/

typedef struct Node {
	unsigned int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* head;
	Node* tail;
}Queue;




void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	make_empty(q);
	free(q);
}

void enqueue(Queue* q, unsigned int data)
{
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		if (newNode == NULL)
		{
			printf("no memory !!!\n\n");
			exit(0);
		}
	
		newNode->data = data;
		if (!isEmpty(q))
		{
			q->tail->next = newNode;
			q->tail = newNode;
			return;
		}
		q->head = q->tail = newNode;

}

unsigned int dequeue(Queue* q)
{
	if (IsEmpty(q))
	{
		printf("it is empty\n");
		return -1;
	}
	Node* pointer = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	int data = pointer->data;
	free(pointer);
	return data;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL)
	{
	return 1;
	}
	return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
		int count = countQueue(q);
		Queue tmp;
		initQueue(&tmp);
		while (count > 1)
		{
			enqueue(&tmp, dequeue(q));
			count--;
		}
	
		while (!isEmpty(&tmp))
		{
			enqueue(q, dequeue(&tmp));
		}
}

void cutAndReplace(Queue* q)
{
	{
	int count = countQueue(q);
	Queue tmp;
	initQueue(&tmp);
	if (count % 2)
	{
		unsigned int avg = 0;
		while (!isEmpty(q))
		{
			avg += q->head->data;
			enqueue(&tmp, dequeue(q));
		}
		avg /= count;
		enqueue(&tmp, avg);
		while (!isEmpty(&tmp))
			enqueue(q, dequeue(&tmp));
		count++;
	}
	count /= 2;
	while (count > 0)
	{
		enqueue(&tmp, dequeue(q));
		count--;
	}
	reverseQueue(q);
	while (!isEmpty(&tmp))
		enqueue(q, dequeue(&tmp));
	
}

}

void sortKidsFirst(Queue* q)
{
	// add your code here
}