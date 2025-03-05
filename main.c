#include "apc.h"
#include <stdio.h>
#include <string.h>
/* Name :Bayya Chaithanya
   Date : 21/12/2024
   Project name :Arbitary Precision calculator
   */

int main(int argc, char *argv[])
{
	/* Declare the pointer */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;
	//checking command line aruguments are eqaul to 4
        if(argc == 4)
	{
		//call the read and validate function for validating the operands 
		if(read_and_validate(argv) == SUCCESS)
		{
			//storing the operator 
			char operator = argv[2][0];
	          	switch(operator)
	         	{
		      	case '+':
				//call the insert_digit function to perform the insert operands to linked lists
				insert_digit(&head1, &tail1, &head2, &tail2, argv);
				/* Call the function to perform the addition operation */
                        	if(addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				{
					printf("Result of Addition is : ");
					print_list(headR, 1);//call the function to print the result linked list
				}
				//if addition operation is not succesfull print unsuccesfull
				else
				{
					printf("Addition unsuccesfull\n");
				}
				break;//breaking the switch case 
		     	case '-':
				int flag = 0;//decalring and initilizing flag variable
				int len1 = strlen(argv[1]);//finding length of 1st operand
				int len2 = strlen(argv[3 ]);//finding length of 2nd operand
				int cmpvalue = strcmp(argv[1], argv[3]);//comparing the two operands and storing the return value
				//checking the two operands lengths if 1st operand is greaterthan 2nd operand
				//storing the first operand in head1 and second operand in head2
				if(len1 > len2 || (len1 == len2 && cmpvalue > 0))
					//call the insert digit function to store the operands
					insert_digit(&head1, &tail1, &head2, &tail2, argv);
				//checking the two operands lengths if 1st operand is lessthan 2nd operand
				//storing the first operand in head2 and second operand in head1
				else if(len1 < len2 || (len1 == len2 && cmpvalue < 0))
				{
					//call the insert digit function to store the operands
					insert_digit(&head2, &tail2, &head1, &tail1, argv);
					flag = 1;//storing flag variable with 1 , becuse the output will be in negative 
				}
				//if both lenghts are equal directly storing the 0 to result linked list
				else if(len1 == len2 && cmpvalue == 0)
				{
					insert_first(&headR, &tailR, cmpvalue);//call the insert first function to store the 0
					printf("Result of Subtraction is : ");
				        print_list(headR, 1);//call the print list function to print the result
					return FAILURE;
				}
				/* Call the function to perform the subtraction operation */
				if(subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				{
					//if flag is 1 then print the result with '-' sign
					if(flag == 1)
					{
						printf("Result of Subtraction is :-");               
						flag = 0;
						remove_zero(headR); //call the remove zero function
					}
					else
					{
						//printing the result without negative sign
						 printf("Result of Subtraction is :");
						 remove_zero(headR);//call the remove zero function
					}

				}
				else
				{
					printf("Subtraction unsuccesfull\n");
				}
				
	                	break;
		     	case 'x':
				//call the insert digit function to store the operands
				insert_digit(&head1, &tail1, &head2, &tail2,argv);
				/* Call the function to perform the multiplication operation */
			       if(multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
			       {
				       printf("Result of Multiplication is: ");
				       print_list(tailR, 0);//call the print list function to print the result linked list
			       }
			       else
			       {
				       printf("multplication unsuucessfull\n");
			       }
				break;
		     	case '/':
				//call the insert digit function to store the operands
                                  insert_digit(&head1, &tail1, &head2, &tail2, argv);
				/* Call the function to perform the division operation */
				  if(division(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
				  {
					  printf("Division Completed\n");
				  }
			          else
				  {
					  printf("Division unsuucessfull\n");
				  }
		        	break;
		     	default:
		         	printf("Invalid input:-(  Try again...\n");
	        	}
		}
	}
	else
	{
		printf("Entered Arguments are less than four.Please try again\n");
		printf("please enter ./a.out operend1 operator operend2 in this formate\n");
		return 0;
	}
   
      	   
}
