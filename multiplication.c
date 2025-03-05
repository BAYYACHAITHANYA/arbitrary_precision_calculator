#include "apc.h"
#include <stdio.h> 

/* Function to perform multiplication operation */
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{     //decalring temp variables
	Dlist *temp1 = *tail1;//storing first linked list tail address to temp1 variable
	Dlist *temp2 = *tail2;//storing second linked list tail address to temp2 variable
	//decalare and initilize temparary varaibles with NULL
        Dlist *headR1 = NULL, *tailR1 = NULL, *headR2 = NULL, *tailR2 = NULL, *backuphead = NULL, *backuptail = NULL;
	int num1, num2, i, res = 0, carry = 0, count = 0;//decalraring variables
        //traversing the first list upto null
	while(temp1 != NULL)
	{
		num1 = temp1 -> data;//storing the first linked list data to num1
		num2 = temp2 -> data;//storing the second linked list data to num2
		res = num1 * num2 + carry;//performing multiplication operation and storing the result to res variable
		carry = res / 10;//storing carry to variable
		res = res % 10;//storing the result without carry
		insert_first(&headR1, &tailR1, res);//call insert first functiion to store the result in temparary list
		temp1= temp1 -> prev;//storing prev node address to temp1
	}
	count++;//incrementing the count variable if temp2 is updated with prev node address
	if(carry != 0)
	{
		insert_first(&headR1, &tailR1, carry);//storing carry in the temparory list
	}
	temp2 = temp2 -> prev;//storing the prev node address of second linked list in temp2 variable
	while(temp2 != NULL)//traversing the second linked list upto null
	{
		for(i = 0; i < count; i++)
		{
			insert_first(&headR2, &tailR2, 0);//inserting 0 to the temparary list by count times
		}
		temp1 = *tail1;//again storing the temp1 with first linked list address
		carry = 0;
		while(temp1 != NULL)//traversing the first linked list upto NULL
		{
			num1 = temp1 -> data;//storing the first linked list data to num1
			num2 = temp2 -> data;//storing the second linked list data to num2
			res = num1 * num2 + carry;//performing multiplication operation and storing the result to res variable
			carry = res / 10;//caclulating carry and stroing in the variable
			res = res % 10;//storing the result without carry
			insert_first(&headR2, &tailR2, res);//call insert first functiion to store the result in temparary list
			temp1 = temp1 -> prev;//storing prev node address to temp1
		}
		if(carry != 0)
		{
			insert_first(&headR2, &tailR2, carry);//storing carry in the temparory list
		}
		addition(&headR1, &tailR1, &headR2, &tailR2, &backuphead, &backuptail);//call addition function and store the result in backuplist
		//print_list(backuphead);
		delete_list(&headR1, &tailR1);//call delete list function to delete temparary list1
		delete_list(&headR2, &tailR2);//call delete list function to delete temparary list2

		temp1 = backuptail;//storing backup list tail address to temp1
		while(temp1 != NULL)//trvaersing the bacuplist upto null
		{
			insert_first(&headR1, &tailR1, temp1 -> data);//call insert first functiion to store the result in temparary list
			temp1 = temp1 -> prev;//storing prev node address to temp1
		}
		delete_list(&backuphead, &backuptail);//call delete list function to delete bacuplist
		count++;
		temp2 = temp2 -> prev;//storing prev node address to temp1
		
	}
	temp1 = headR1;//storing temparory list1 tail address to temp1
	while(temp1 != NULL)
	{
		insert_first(headR, tailR, temp1 -> data);//call insert first function to store the result in result list
		temp1 = temp1 -> next;//storing next node address to temp1
	}
	delete_list(&headR1, &tailR1);//call delete list function to delete temparary list1
	return SUCCESS;//returing success after performing the operation to main
	
}
	
	

