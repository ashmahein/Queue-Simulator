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
#include "testQueue.h"

int main(int argc, char *argv[])
{
	//Queue declaration.
	srand(time(NULL));
	Queue expressLine = { NULL, NULL };
	Queue normalLine = { NULL, NULL };

	//Variable declaration
	int expressLaneCustArrival = 0, expressServiceCust = 0, expServiceTotalTime = 0, expressCustomerNumber = 0;
	int normalLaneCustArrival = 0,  normalServiceCust = 0, norServiceTotalTime = 0, normalCustomerNumber = 0;
	int simulationMin = 0, elapsedTime = 0, custInNormalLine = 0, custInExpressLine = 0, statusNormal = 0, statusExpress = 0;
	int success = 0;

	//Start of program
	printf("Grocery Store Line Simulator!\n");

	//Asks user to enter a simulation time.
	printf("Please enter the amount of time you want to run the simulation for: ");
	scanf("%d", &simulationMin);

	//Clear screen
	system("pause");
	system("cls");

	expressLaneCustArrival = (rand() % 5 + 1); //establishes the arrival time for first customer in the express line.
	normalLaneCustArrival = (rand() % 5 + 3); //establishes the arrival time for the first customer in the normal line.

	for (elapsedTime = 0; elapsedTime <= simulationMin; elapsedTime++) //increments program runtime.
	{
		if (expressLaneCustArrival == elapsedTime)
		{
			expressCustomerNumber += 1; //makes customer.
			expressServiceCust = (rand() % 5 + 1); //gives the customer a service time.

			expServiceTotalTime = expressServiceCust + expServiceTotalTime; //totals up the service time for the whole line.

			success = enqueue(&expressLine, expressCustomerNumber, expressServiceCust, expServiceTotalTime); //add the customer to the line.

			custInExpressLine = 1; //lets the program know there is now a customer in line.

			printf("Customer %d arrived at %d minutes in the express lane.\n", expressCustomerNumber, expressLaneCustArrival);

			expressLaneCustArrival += (rand() % 5 + 1); //establishes the arrival time for a new customer.
		}

		statusExpress = isEmpty(expressLine); //checks to see if the queue is empty or not.

		if ((statusExpress == 0) && (custInExpressLine == 1)) //if queue isn't empty the start decrementing the first customers wait time.
		{
			expressLine.pHead->ServiceTime -= 1; //decrements first customer wait time in line

			if (expressLine.pHead->ServiceTime == 0) //when the customer has been serviced it will dequeue.
			{
				printf("Customer %d has been serviced after %d minutes in the express line.\n", expressLine.pHead->CustomerNumber, expressLine.pHead->TotalTime);
				dequeue(&expressLine); //dequeues first customer in line after they've been serviced
			}
		}

		//SAME AS ABOVE CODE BUT FOR NORMAL LINE
		if (normalLaneCustArrival == elapsedTime)
		{
			normalCustomerNumber += 1; //makes customer.
			normalServiceCust = (rand() % 5 + 1); //gives the customer a service time.

			norServiceTotalTime = normalServiceCust + norServiceTotalTime; //totals up the service time for the whole line.

			success = enqueue(&normalLine, normalCustomerNumber, normalServiceCust, norServiceTotalTime); //add the customer to the line.

			custInNormalLine = 1; //lets the program know there is now a customer in line.

			printf("Customer %d arrived at %d minutes in the normal line.\n", normalCustomerNumber, normalLaneCustArrival);

			normalLaneCustArrival += (rand() % 5 + 1); //establishes the arrival time for a new customer.
		}

		statusNormal = isEmpty(normalLine);

		if ((statusNormal == 0) && (custInNormalLine == 1))
		{
			normalLine.pHead->ServiceTime -= 1;

			if (normalLine.pHead->ServiceTime == 0)
			{
				printf("Customer %d has been serviced after %d minutes in the normal line.\n", normalLine.pHead->CustomerNumber, normalLine.pHead->TotalTime);
				dequeue(&normalLine);
			}
		}
		
		//Prints out the queue every 10 minutes with line information. 
		if (elapsedTime % 10 == 0)
		{
			printf("Express line:\n");
			printQueue(expressLine);
			printf("Normal line:\n");
			printQueue(normalLine);
		}
	}

	//testEnqueue(); -CHECKED/WORKS.
	//testDequeue(); -CHECKED/WORKS.


	system("pause");
	return 0;
}

