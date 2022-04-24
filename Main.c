#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
		char* str = (char*)malloc(13);
		str = "#omer#dahan#";
		flipBetweenHashes(str);
		Stack s;
		s.head = NULL;
		push(&s, 'D');
		push(&s, 'E');
		push(&s, 'F');
		push(&s, 'A');
		push(&s, 'B');
		push(&s, 'C');

		rotateStack(&s, 3);
}