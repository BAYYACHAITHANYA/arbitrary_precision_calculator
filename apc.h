#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
/* Macro */
#define SUCCESS 0
#define FAILURE -1
/*Structure definition*/
typedef struct node
{
	struct node *prev;//prev pointer with self refrentail structure
	int data;
	struct node *next;//next pointer with self refrentail structure
}Dlist;

/*Include the prototypes here*/
int read_and_validate(char *argv[]);

/*store the operands into the list*/
void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/* store the result into the list*/
int insert_first(Dlist **headR, Dlist **tailR, int data);

/* for Addition*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* for Subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* for Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* for Divistion*/
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
 
/* To print the result */
void print_list(Dlist *headR, int flag);

/* to remove zeros in first node */   
void remove_zero(Dlist *headR);

/* to delete the complete list*/
int delete_list(Dlist **head, Dlist **tail);
#endif
