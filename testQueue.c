#include "testQueue.h"

void testEnqueue(void)
{
	Queue p = { NULL, NULL};
	int newCustomer = 1, newServiceTime = 2, newTotalTime = 2;
	int succes = 0;

	succes = enqueue(&p, newCustomer, newServiceTime, newTotalTime);

	if (succes == 1)
	{
		printf("Memory made.\n");

		if ((p.pHead != NULL) && (p.pTail != NULL) && (p.pHead == p.pTail))
		{
			printf("Updataed pHead and pTail.\n");

			if ((p.pHead->CustomerNumber == 1) && (p.pHead->ServiceTime == 2) && (p.pHead->TotalTime == 2) && (p.pHead->pNext == NULL))
			{
				printf("Initialized the node successfully!\n");
				printf("Test case passed!\n");
			}
			else
			{
				printf("Failed to initialize the node!\n");
			}
		}
		else
		{
			printf("Failed to update pHead and pTail");
		}
	}
	else
	{
		printf("Failed to allocate memory.\n");
	}
}

void testDequeue(void)
{
	Queue p = { NULL, NULL };
	int success = 0;

	success = enqueue(&p, 1, 2, 2);
	success = enqueue(&p, 2, 1, 3);

	dequeue(&p);
	printQueue(p);
}