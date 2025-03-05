#include "apc.h"
#include <stdio.h>
/* FUnction to delete the total list */
int delete_list(Dlist **head, Dlist **tail)
{
	//validating head and tail
	if(*head == NULL || *tail == NULL)
	{
		printf("Info: LIST IS EMPTY\n");
		return FAILURE;//if list is null returning failure
	}

	while(*head != NULL)//traversing the list upto null
	{
		*head = (*head) -> next;//storing next node address to head pointer
		if(*head == NULL)
		{
			free(*tail);//free tail address
			*tail = NULL;//store null to tail
			*head = NULL;//store null to head
			return SUCCESS;//return SUCCESS
		}
		free((*head) -> prev);//free the head of prev address
	}

}
