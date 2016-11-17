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
#ifndef GROCERY_STORE_H
#define GROCERY_STORE_H


#include <stdio.h>  /* Needed for fscanf ( ), fprintf ( ), fopen ( ), etc. */
#include <stdlib.h> /* Needed for exit ( ) */
#include <time.h>   /* Needed to generate randomness */

//Structs
typedef struct QueueNode
{
	int CustomerNumber;
	int ServiceTime;
	int TotalTime;
	struct queueNode *pNext;
} QueueNode;

typedef struct Queue
{
	QueueNode *pHead;
	QueueNode *pTail;
} Queue;

//fuction prototypes.
QueueNode *makeNode(int newCustomer, int newServiceTime, int newTotalTime);
int enqueue(Queue *pQ, int newCustomer, int newServiceTime, int newTotalTime);
void dequeue(Queue *pQ);
int isEmpty(Queue line);
void printQueue(Queue line);

#endif