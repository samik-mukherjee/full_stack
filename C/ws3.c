#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void freeBuffer(char **buffer);
char** copy_to_buffer(char *envp[]);
void printBuffer(char **buffer);
int lucky_soldier(int total_soldiers);

int main( int argc, char *argv[], char *envp[])
{
	char ** testbuff = NULL; 

	testbuff = copy_to_buffer(envp);
	printBuffer(testbuff);
	freeBuffer(testbuff);

	lucky_soldier(100);

	(void) argc;
	(void) argv;

	return 0;
}

char** copy_to_buffer(char **envp)
{
	char** buffer = NULL;
	size_t number_of_string = 0;
	size_t len_of_each_string = 0;
	size_t i = 0;
	size_t j = 0; 

	while(envp[number_of_string])
	{
		number_of_string++;
	}

	buffer = calloc(number_of_string +1, sizeof(char*));
    
    for (i = 0; i < number_of_string; ++i)
    	
    {
    	len_of_each_string = strlen(envp[i]);

    	buffer[i] = calloc(len_of_each_string +1 , sizeof(char)); 

    	for(j =0; j< len_of_each_string; j++)
    		{
    			buffer[i][j] = tolower(envp[i][j]);
    		}
   
   		
   	}
   	return buffer;
}

void printBuffer(char **buffer)
{
	while(buffer)
	{
		printf("%s\n", *buffer);
		++buffer;
	}

}

void freeBuffer(char **buffer)
{
	char** buffer_start = buffer;

    while(*buffer)
    {
    	free(*buffer);
    	*buffer = NULL;
    	++buffer;
    }

    free(*buffer_start);
    buffer = NULL;
}

int lucky_soldier(int total_soldiers)
{
	int individual = 0;
	int survivor = total_soldiers;
	int stab = 0;
 	char *soldier_arr = calloc(total_soldiers, sizeof (char*));


	do 
	{
		for ( individual = 0 ; individual < total_soldiers; ++individual )
		{
			if ( soldier_arr[individual] == 0 && stab == 0)
			{  

			stab = 1;

			}

			else if  ( soldier_arr[individual] == 0 && stab == 1)

			{

			soldier_arr[individual] = 1;
			stab = 0;
			--survivor;
			
			}
		}

	} while(survivor != 1);


	individual = 0;
	while (soldier_arr[individual] != 0)
	{
		++individual; 
	}

	printf ("the index of the lucky man is individual : %d\n", individual +1);

    free(soldier_arr);
    soldier_arr = NULL;

    return individual;

}