
#include <stdio.h>

#include "tickets.h"
#include "general.h"

#define SIZE 7 //Seven days a weak.

void doTickets()
{
	int ticketPerDay[SIZE] = {0};
	inItTickets(ticketPerDay);
	
	int most ,least;
	int mostDay = 0, leastDay = 0;

	getMostLeast(ticketPerDay, &most, &least, &mostDay, &leastDay, SIZE);

	mostDay += 1;
	leastDay += 1;
	printf("Most ticket sold: %d on day %d\nLeast tickets sold: %d on day %d\n", most, mostDay, least, leastDay);
		
}







//Inserts tickets from the user.
void inItTickets(int* arr)
{
	int day, ts;
	do
	{
		printf("Enter day number:\n");
		scanf("%d", &day);
		if(checkDay(day) && day != 0)
		{
			printf("Enter number of tickets sold:\n");
			scanf("%d", &ts);
			if(checkTickets(ts))
				*(arr + day - 1) += ts;
		}
	}while(day != 0);
}

//Checks for a valid number of day.
int checkDay(int day)
{
	if(day < 0 || day > SIZE)
	{
		printf("Day must be between 1 and %d, or 0 to cancel\n", SIZE);
		return 0;
	}
	else
		return 1;

}

//Checks for a valid number of tickets.
int checkTickets(int ts)
{
	if(ts >= 0)
		return 1;
	else 
	{
		printf("Number of tickets sold cannot be negative");
		return 0;
	}
}


