/* bitfunctions */

#include <stdio.h>         /*  printf()                 */
#include <assert.h>        /*  assert                   */
#define BITWIDTH (32)      /*  macro bitwith            */
#define ONE (1)  
#define TRUE (1)
#define FALSE (0)          /*  macro for checking bits  */

double Pow2(unsigned int x, int y);
int IsnPowerOfTwe(unsigned n);
int IsnPowerOfTweLoop(unsigned int n);
unsigned int AddOne(unsigned int x);
void IsThreeBitsLitten(unsigned int* arr, int Length_of_arr);
unsigned int CountLittenBit(unsigned int n);
unsigned int DeBy16(unsigned int n);
int IsBitTwoAndSixON(unsigned int n);
int IsBitTwoORSixON(unsigned int n);
void swap(unsigned int* num1, unsigned int* num2);


int main (void)
{	
	
	return 0;
	
}

/* funcion that returns y to the power of 2 */

double Pow2(unsigned int x, int y)
{
	return x << y;
}

/* power of 2 function with the O(1) */

int IsnPowerOfTwe(unsigned int n)
{
  if(0 == n && ! (n & (n-1)))
  {
  	return 0;
  }
  else 
  {
  	return 1;
  }
}

/* power of 2 function with O(n) */

int IsnPowerOfTweLoop(unsigned int n)
{
    if (n > 1)
    {
        while (n%2 == 0)
        {
        	n >>= 1;
        }
    }
    return n == 1;
}

unsigned int AddOne(unsigned int n)
{
	unsigned int i = 0;
	unsigned int result = n;
	unsigned int one =1;

	/*go thought the number from 0 bit to the beginning, */
	/*while current bit is not zero*/

	while(((n >> i)& ONE ) == 0)
	{
	/*set the current bit in the result as 0*/
		result = result >> i << i;
		++i;
	}
	 /*set the current bit to 1*/
	result |= one <<i;
	return result;
}
	
/*this function takes an array of ints and prints out 
the elements which has exactly 3 set bits */


void IsThreeBitsLitten(unsigned int* arr, int Length_of_arr)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int count = 0;
	for(i = 0;i < (unsigned int) Length_of_arr; ++i, ++arr) 
	{
		for(j = 0, count = 0; j < BITWIDTH; ++j)
		{
			if(((*arr >> j) & ONE )== 1)
			{
				++count;
				if(count > 3)
				{
					break;
				}
			}
		}
		if(count == 3)
		{
			printf("%d\n",*arr);
		}
		
	}

}
/*this function takes an insigned int as it's input 
and prints out howmany of it's bits are set bits */


unsigned int CountLittenBit(unsigned int n)
{
	unsigned int i = 0;
	unsigned int one = 1;
	unsigned int count = 0;
	printf("%d\n",n);

	for(i = 0; i < BITWIDTH ; ++i)
	{
		if(((n >> i) & one) == 1)
		{
			++count;
		}
	}

	return count;
}
/*this function takes an unsigned int and 
returns the closest smaller number that is 
divided by 16 without remainder */


unsigned int DeBy16(unsigned int n)
{
	return (n >> 4) << 4;
}

/*this function checkes if an unsigned int has
it's 2nd anf 6th bit litten */


int IsBitTwoAndSixON(unsigned int n)
{
	if((((n >> 1) & ONE) == 1) && (((n >> 5) & ONE) == 1))
	{
		return TRUE;
	}
	else
		return FALSE;
}
/*this function takes an unsigned int and returns 
true if it has set bit on the 2nd or 6th position
from the left */

int IsBitTwoORSixON(unsigned int n)
{
	if((((n >> 1) & ONE) == 1) || (((n >> 5) & ONE) == 1))
	{
		return TRUE;
	}
	else
		return FALSE;
}




/*this function takes an unsigned int 
and swaps their valus without a 3rd variable */




void swap(unsigned int* num1, unsigned int* num2)
{ 	
	if(num1 == num2)
	{
		puts("ERROR : same address");
	}

	*num1 = *num1 ^ *num2;
	*num2 = *num1 ^ *num2;
	*num1 = *num1 ^ *num2;

}