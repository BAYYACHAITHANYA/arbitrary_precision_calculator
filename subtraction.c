#include "apc.h"
#include <stdio.h>
/*Function to do subtraction operation */
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//decalring temparary variables
	Dlist *temp1 = *tail1;//storing first linked list tail address to temp1
      	Dlist *temp2 = *tail2;//storing second linked list tail address to temp2
	int num1, num2, sub = 0, barrow = 0;
	//traversing first and second linked list upto NULL
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL)//trversing first linked list upto NULL
		{
		   	 num1 = temp1 -> data;//stroing first linked list digit to num1 variable
			 temp1 = temp1 -> prev;//stroing prev node address to temp1 variable
		}
		else
			num1 = 0;//stroing num1 as 0 if temp1 reaches to null
                //trversing first linked list upto NULL
		if(temp2 != NULL)
		{
			 num2 = temp2 -> data;//stroing second linked list digit to num2 variable
			 temp2 = temp2 -> prev;//stroing prev node address to temp2 variable
		}
		else
			num2 = 0;//stroing num2 as 0 if temp2 reaches to null
		
		if(barrow == 1)
		{
			num1 = num1 - 1;//if barrow is eqaul to 1 subtracting -1 with num1
			barrow = 0;//making barrow as 1 after above operation
		}
                //if num1 is lessthan num2 adding 10 to the num1
		if(num1 < num2)
		{
			num1 = num1 + 10;
			barrow = 1;//storing 1 in barrow variable
		}
		sub = num1 - num2;//subtracting num2 form num1		
		insert_first(headR, tailR, sub);//call insert first function to store the result
	}	
	return SUCCESS;//returing suucess to main function
} 
