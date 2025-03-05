#include "apc.h"
#include <stdio.h>
/* Function to do addition operation */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//Declare temparary vaiables 
        //declaring varaibles
	Dlist *temp = *tail1;//storing first linked list tail address to temp1
	Dlist *temp1 = *tail2;//storing second linked list tail address to temp2
	int sum, num1 = 0, num2 = 0, carry = 0;
        //traversing the list upto NULL
	while(temp != NULL || temp1 != NULL)
	{
		//traversing temp1 list upto NULL
		if(temp != NULL)
		{
			num1 = temp -> data;//storing the digit to num1 variable
			temp = temp -> prev;//storing prev node address to temp variable
		}
		else
			num1 = 0;//if list reaaches to null making num1 as 0
				 //
		//traversing temp2 list upto NULL
		if(temp1 != NULL)
		{
			num2 = temp1 -> data;//storing the digit to num2 variable
			temp1 = temp1 -> prev;//storing prev node address to temp variable
		}
		else
			num2 = 0;//if list reaaches to null making num1 as 0
		
		sum = carry + num1 + num2;//addiding num1 and num2 variables and carry also
		carry = sum / 10;//caluculating the carry and stroing in the carry vaiable
		sum = sum % 10;//stroing digit without carry
		//printf("Sum = %d carry %d\n", sum, carry);
                insert_first(headR, tailR, sum);//call insert_first function to store the sum
	}
	return SUCCESS;// returning suucess to main function
}
