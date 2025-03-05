#include "apc.h"
#include <stdio.h>
/*Function to do division operation */
void remove_leading_zeros(Dlist **head, Dlist **tail);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{

	if (*head2 == NULL || (*head2) -> data == 0) 
	{
        	printf("ERROR: Division by zero \n");
        	return FAILURE;
    	}
    	int count = 0;
    	while (1) 
	{
        	int list1_len = 0, list2_len = 0;
        	Dlist *temp1 = *head1;//take temparary variables and initlize with null
        	Dlist *temp2 = *head2;
        // Calculate size of the first list
        while (temp1 != NULL) 
	{
            list1_len++;//increment the len1
            temp1 = temp1 -> next;//storing next node address in tmep1
        }
        // Calculate size of the second list
        while (temp2 != NULL) 
	{
            list2_len++;//increment the len2
            temp2 = temp2->next;
        }
        // If the size of the first number is smaller than the second, stop division
        if (list1_len < list2_len) 
	{
            break;//breaking the loop and loop will stop
        }
        // If the sizes are equal, compare the numbers digit by digit
        if (list1_len == list2_len) 
	{
            temp1 = *head1;//storing first list head address to temp1
            temp2 = *head2;//storing second list head address to temp2
            int flag = 0;

            while (temp1 != NULL && temp2 != NULL) 
	    {
                if (temp1 -> data > temp2 -> data) 
		{
                    flag = 1;
                    break;//breaking the loop and loop will stop
                } 
		else if (temp1 -> data < temp2 -> data) 
		{
                    flag = -1;
                    break;//breaking the loop and loop will stop
                }
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            if (flag == -1)// If the first number is smaller, stop division 
	    {
                break;//breaking the loop and loop will stop
            }
        }
        // Performing  subtraction
        if (subtraction(head1, tail1, head2, tail2, headR, tailR) == SUCCESS) 
	{
            // call delete list function
            if (delete_list(head1, tail1) == SUCCESS) 
	    {
                    *head1 = *headR;//storing result list head address to first list head1
                    *tail1 = *tailR;//storing result list tail address to first list tail1
                    *headR = NULL;
                    *tailR = NULL;
                // Remove first node zeros
                remove_leading_zeros(head1, tail1);
                count++;//increment the count
            }
	    else 
	     return FAILURE;//returning failure

        }
       	else 
	{

            	printf("Error: Subtraction failed.\n");
            	return FAILURE;//returning failure

        }
        // If the first number becomes zero, stop division
        if (*head1 == NULL || ((*head1) -> data == 0 && (*head1) -> next == NULL)) 
            	break;//breaking the loop and loop will stop
        
    }
    // priting the final count
    printf("Quotient: %d\n", count);
    return SUCCESS;
}

//  function to remove first node zeros
void remove_leading_zeros(Dlist **head, Dlist **tail) 
{
    	while (*head && (*head) -> data == 0) 
	{
        	Dlist *temp = *head;//updating head address to temparary variable
        	*head = (*head)->next;//stroing next  address to head
        	free(temp);
        if (*head) 
	{
            	(*head)->prev = NULL;//making previuos address as null
        } else 
	{
            	*tail = NULL; // List is empty
        }
    }
}
	
