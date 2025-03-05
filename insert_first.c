#include "apc.h"

int insert_first(Dlist **headR, Dlist **tailR, int data)
{

    	Dlist *new = malloc(sizeof(Dlist));
    	if(new == NULL)
    	{
        	return FAILURE;
    	}
    	new -> data = data;
    	new -> prev = NULL;
    	new -> next = *headR;
    	if(*headR == NULL)
    	{
        	*headR = new;
        	*tailR = new;
        	return SUCCESS;
    	}
    	(*headR)-> prev = new;
    	*headR = new;
	
   	return SUCCESS;
   
}
