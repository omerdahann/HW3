#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>


/***************** Stack ADT Implementation *****************/

typedef struct Node {
	char data;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* head;
}Stack;


void initStack(Stack* s)
{
	s->head = -1; //אתחול

}

void destroyStack(Stack* s)
{
	make_empty(s);
	free(s);
}

void push(Stack* s, char data)
{
	Node* hadash = (Node*)calloc(1, sizeof(Node));
	if (hadash == NULL)
	{
		printf("No Memory");
		return;
	}
	hadash->data = data;
	if (isEmpty(*s))
	{
		s->head = hadash;
		s->head->data = data;
		s->head->next = NULL;
		return;
	}
	hadash->next = s->head;
	s->head = hadash;

}

char pop(Stack* s)
{
	if (isEmpty(*s))
	{
		printf("Empty Stack");
		return;
	}
	Node* tmp;
	tmp = s->head;
	char data = s->head->data;
	s->head = s->head->next;
	free(tmp);
	return data;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == -1)
		return 1;
	else
		return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	int i = 0;
	int size = strlen(sentence);
	Stack s;
	initStack(&s);
	while (i < size)
	{
		if (sentence[i] == '#')
			for (int j = i + 1; j < size; j++)
			{
				if (sentence[j] != '#')
				{
					Push(&s, sentence[j]);
				}
				else
				{
					for (int k = j; k - i > 1; k--)
					{
						printf("%c", Pop(&s));
					}
					i = j + 1;
					break;
				}

			}
		else
			printf("%c", sentence[i++]);
	}
}


Node* Duplicate(const Node* s)
{
	if (s == NULL)
	{
		return NULL;
	}
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = s->data;
	new->next = Duplicate(s->next);
	return new;
}

int isPalindrome(Stack* s)
{
	int flag = 1;
	if (isEmpty(s))
	{
		printf("Empty Stack");
		return 1;
	}

	Stack new, flip;
	new.head = Duplicate(s->head);
	flip.head = NULL;
	while (!isEmpty(new))
	{
		push(&flip, pop(&new));
	}
	new.head = Duplicate(s->head);
	while (pop(&new) == pop(&flip) && !isEmpty(new))
	{
		flag = 1;
	}
	if (!isEmpty(new))
	{
		flag = 0;
	}
	printf("%d", flag);
	while (!isEmpty(new))
	{
		pop(&flip);
		pop(&new);
	}
	return flag;
}

void rotateStack(Stack* s, int n)
{
	Stack tmp1, tmp2;;
	initStack(&tmp1);
	initStack(&tmp2);
	while (!IsEmpty(s))
		Push(&tmp1, Pop(s));

	while (n > 0)
	{
		Push(&tmp2, Pop(&tmp1));
		n--;
	}
	while (!IsEmpty(&tmp1))
		Push(s, Pop(&tmp1));
	while (!IsEmpty(&tmp2))
		Push(&tmp1, Pop(&tmp2));

	while (!IsEmpty(&tmp1))
		Push(s, Pop(&tmp1));
}