/*******************************************************************************
* Programmer: Ash Mahein                                                      *
* Class: CptS 122; Lab Section 1                                              *
* Programming Assignment: 3                                                   *
* Date: 06/25/16                                                              *
*                                                                             *
* Description: This program is a grocery store simulator. It simulates        *
*              customer arrival, line wait times, and serice times.           *
*                                                                             *
* Relevant Formulas: NONE									                  *
* Collaboration: Andy O'Fallon, Rahul Singhal                                 *
* Websites used: NONE                                                         *
******************************************************************************/
#include "GroceryStore.h"

/*************************************************************
* Function: *makeNode ()                                    *
* Date Created: 06/22/16                                    *
* Date Last Modified: 06/22/16                              *
* Description: Allocates memory for a node to add to the    *
*              queue                                        *
* Input parameters: new customer, service time, and total   *
*                   time                                    *
* Returns: pMem- new node                                   *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
QueueNode *makeNode(int newCustomer, int newServiceTime, int newTotalTime)
{
	QueueNode *pMem = NULL; 

	pMem = (QueueNode *)malloc(sizeof(QueueNode)); //Allocates memory for the node

	//Adds the new feilds to the node.
	if (pMem != NULL)
	{
		pMem->CustomerNumber = newCustomer;
		pMem->ServiceTime = newServiceTime;
		pMem->TotalTime = newTotalTime;
		pMem->pNext = NULL;
	}
	return pMem; //returns the node.
}

/*************************************************************
* Function: isEmpty ()                                      *
* Date Created: 06/22/16                                    *
* Date Last Modified: 06/22/16                              *
* Description: Checks to see if the queue is empty.         *
* Input parameters: the queue                               *
* Returns: success.                                         *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
int isEmpty(Queue line)
{
	return (line.pHead = line.pTail == NULL); //returns a 1 or 0.
}

/*************************************************************
* Function: enqueue ()                                      *
* Date Created: 06/22/16                                    *
* Date Last Modified: 06/23/16                              *
* Description: Add the newly made node to the queue.        *
* Input parameters: new customer, service time, total time  *
*                   and the queue.                          *
* Returns: success.                                         *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
int enqueue(Queue *pQ, int newCustomer, int newServiceTime, int newTotalTime)
{
	QueueNode *pMem = makeNode(newCustomer, newServiceTime, newTotalTime); //makes a new node given the contents.
	int success = 0; //will return 1 or 0 depending on if the node was made.

	if (pMem != NULL)
	{
		success = 1;

		//if there is something in the queue already it will add the new node to the end of the queue.
		if (pQ->pHead != NULL)
		{
			pQ->pTail->pNext = pMem; 
			pQ->pTail = pMem;
		}
		else //it adds the newly made queue to the queue as the first one.
		{
			pQ->pHead = pQ->pTail = pMem;
		}
	}
	return success;
}

/*************************************************************
* Function: dequeue ()                                      *
* Date Created: 06/24/16                                    *
* Date Last Modified: 06/24/16                              *
* Description: Removes memory from the queue.               *
* Input parameters: queue                                   *
* Returns: NONE                                             *
* Preconditions: The queue cannot be empty.                 *
* Postconditions: NONE                                      *
*************************************************************/
void dequeue(Queue *pQ)
{
	QueueNode *pTemp = pQ->pHead; //sets the thing we will free to the head of the list.

	if (pQ->pHead == pQ->pTail)
	{
		pQ->pHead = pQ->pTail = NULL; //if the node being deleted is the only thing in the queue then it will set pHead and pTail to NULL
	}
	else
	{
		pQ->pHead = pQ->pHead->pNext; //If there is something in the list then it sets the next thing in the list to the head of the list.
	}

	free(pTemp); //frees the first node in the list.
	pTemp = NULL;
}

/*************************************************************
* Function: printQueue ()                                   *
* Date Created: 06/24/16                                    *
* Date Last Modified: 06/25/16                              *
* Description: prints the current queue                     *
* Input parameters: the queue                               *
* Returns: NONE                                             *
* Preconditions: NONE                                       *
* Postconditions: NONE                                      *
*************************************************************/
void printQueue(Queue line)
{
	if (line.pHead != NULL) //If there is stuff in the queue then it will print all the information out.
	{
		printf("Customers in line: %d\n", line.pHead->CustomerNumber);
		printf("Service time of current customer: %d\n", line.pHead->ServiceTime);
		printf("Total wait time: %d\n", line.pHead->TotalTime);
	}
	else //If there is nothing in the list it will print the following message.
	{
		printf("No one is currently in the line.\n");
	}

}