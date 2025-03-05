#include "apc.h"
#include <stdio.h>
#include <string.h>
/* read and validate function */
int read_and_validate(char *argv[])
{
	//checking the given operator is + or - or x or /
          if(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == 'x' || argv[2][0] == '/')
	  {
			char *str = argv[1];//storing the first operand
			while(*str)
			{
				//checking the first operand is above 0 and below 9
				if(*str < '0' || *str > '9')
				{
					printf(" %s is not a digit\n", argv[1]);//printing error messege if it is not a digit
					return FAILURE;//returing failure
				}
				str++;
			}
			char *str1 = argv[3];//storing the second operand
			while(*str1)
			{
				//checking the second operand is above 0 and below 9
				if(*str1 < '0' || *str1 > '9')
				{
					 printf(" %s is not a digit\n", argv[3]);//printing error messege if it is not a digit
					 return FAILURE;
				}
				str1++;
			}
			return SUCCESS;//returning success if both operands are digits
	}
	else
        {
		printf("Enterd operator is not an arithamatic operator.please try aagain\n");
		printf("please enter only + - x and / only\n");
		return FAILURE;//returning failure if operator is not an arithamatic operator

        }
}
/* insert digit function */
void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
	   int len = strlen(argv[1]);//finding the length first operand
	   for(int i = 0; i < len; i++)
           {	//creating the new node	   
	  	Dlist *new = malloc(sizeof(Dlist));
		//validating the new node
		if(new == NULL)
		{
			printf("new memory not allocated\n");
		}
		//updating the node 
	   	new -> data = argv[1][i] - '0';//converting string to integer
	   	new -> prev = *tail1;
	   	new -> next = NULL;
		//head is null storing the new node address to head and tail
	   	if(*head1 == NULL)
	   	{
		   *head1 = new;
		   *tail1 = new;
		   continue;//skiping by using continue
	   	}	
	   	(*tail1) -> next = new;
	   	*tail1 = new;
	   }
	 
	  
	   int len1 = strlen(argv[3]);//finding the length second operand
	   for(int j = 0; j < len1; j++)
	   {
		   //creating the new node
		   Dlist *new = malloc(sizeof(Dlist));
		   //validating the new node
		   if(new == NULL)
		   {
			   printf("new memory not allocated\n");
		   }
		   //updating the node
		   new -> data = argv[3][j] - '0';//converting string to integer
		   new -> prev = *tail2;
		   new -> next = NULL;
		    //head is null storing the new node address to head and tail
		  if(*head2 == NULL)
		  {
			 *head2 = new;
			 *tail2 = new;
			 continue;//skiping by using continue
		  }
	           (*tail2) -> next = new;
	           *tail2 = new;	   
	   }
}
/* function to remove zero in result list before printing */
void remove_zero(Dlist *headR)
{
	while(headR != NULL)//running loop upto null
	{
		//checking the result data list is eqaul to 0
		if(headR -> data == 0 )
		{
			headR = headR -> next;//updating the next node address to head
			free(headR -> prev);//deleting that node
			headR -> prev = NULL;
		}
		else
		    break;//breaking the loop if above condition is false
	}
	print_list(headR, 1);
	
}
/* print list */
void print_list(Dlist *headR, int flag)
{
	/* Cheking the list is empty or not */
	if (headR == NULL)
	{
		printf("INFO : List is empty\n");
	}
	if(flag == 1)
	{
	    while (headR)		
	    {
		    //Printing the list    
		    printf("%d", headR -> data);
		  // Travering in forward direction 
		    headR = headR -> next;
	    }
        }
	else
	{
	    while(headR)		
	    {
		    /* Printing the list */   
		    printf("%d", headR -> data);
		    /* Travering in forward direction */
		    headR = headR -> prev;
             }
	}
	printf("\n");
}

