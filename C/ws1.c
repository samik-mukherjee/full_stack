#include <stdio.h> /* input output library */

	/*protopyting of the functions */
void prinf_hello_world_hex();
int flip(int number);
int swap(int *var1, int *var2);
double power(int exponent);


int main ()

{

	/*flip(1234);
	swap();
	result_pow = power();
	prinf_hello_world_hex();*/
	
	return 0;

}

/*******************************************************************************/


void print_hello_world_hex()
{ 
   /* declaring the array with memory space */
 
	char hello[] = {0x22,0x48,0x65,0x6c, 0x6c, 0x6f, 0x20, 
			0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,0x22};

   /*declaring my variables & calculating the loop condition*/ 

	int i;
	int j = sizeof(hello)/sizeof(char);

   /* looping to print out the eliments of arr hello */

    for( i=0;i<j; i++)
	{	
		printf("%c", hello[i]);
	}
}

/*******************************************************************************/

int swap(int *var1, int *var2)

{

	/* declaring temp variable */
	int temp;

	/* saves var1 one in temp */
	temp = *var1;

	/* assignes var1 to var2 */
 	*var1 = *var2;
	
	/* assignes value of var1 to var2 from temp */
 	*var2 = temp; 
	return 0;

}

/*******************************************************************************/
int flip(int number)
{

/* declaration &  initialization of variable*/

	int  after_flip = 0;

/*multypling by 10 then % by 10 to calculate the the modular remain*/

	while (number)
	{
		after_flip = after_flip * 10 +number %10;
		number /= 10;
	}
/*returning the flipped number*/

	return after_flip;

}


/*******************************************************************************/

/*defining function*/

double power(int exponent)

{
	/*declaring variables and checking if exponent is 0 */
	
	double ten = exponent ? 10.0 : 0;
	int i = 0;
	double result =1.0;

	/*checking if exponent is less than zero */
	if(exponent <0)
	{
		exponent = -exponent;
		ten = .1;
	}
	
	/*running loop to calculate power of 10 */

	for(i=1;i<=exponent;i++)
	{
		result *= ten;	
	}

	return result;

}




