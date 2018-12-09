#include <stdio.h>                 /*       EXIT_STATUS        */  
#include <string.h>                /*       string functions   */
#include <assert.h>                /*       assert             */
#include <ctype.h>                 /*       tolower()          */
#include <stdlib.h>                /*       malloc()           */
#include "ws2.h"                   /*       myFunctions        */

void testOptimaStrspn(void);
void TestTrimSpace();

size_t OptimaStrlen(const char* s);
int find_digit(int number, int digit);
char *OptimaStrChr(const char *s, int c);
char *strcat(char *dest, const char *src);
void boom (int start_range, int end_range);
int OptimaStrcmp(const char* s1,const char*s2);
int OptimaStrCaseCmp (char* str1, const char* str2);
char *OptimaStrStr(const char *haystack, const char *needle);
size_t OptimaStrspn(const char * string, const char * accept);



int main()
{   
	TestTrimSpace();
	testOptimaStrspn();
	return 0;
}

size_t OptimaStrlen(const char* s)
{
	int count = 0;

	/* Goes through the string once 
	until '\0' counting the number of loop 
	in count variable */
	
	while (*s != '\0')
	{	
	    ++count;
		++s;
	}
	
	return count;
}




int OptimaStrcmp(const char* s1,const char*s2)
{
    /* goes through both s1 and s2 strings
     comparing each char inside them */
	int result = 0;
    
    /* assert if the function recieves bad input */
	assert (s1 != NULL);
	assert (s2 != NULL);

	while (*s1 != '\0' && *s2 != '\0')
	{
		s1++; 
		s2++; 
	}
    /* substracting element of s2 from s1 *
    if they both are equal it should return 0 */
	result = (*s1-*s2);
	
	return result;
}	

int OptimaStrCaseCmp (char* str1, const char* str2)
{
	/* goes through both s1 and s2 strings
     comparing each char inside them */
	int result= 0;
	
	/* assert if the function recieves bad input */
	assert (str1 != NULL);
	assert (str2 != NULL);

    /* making the function non-case-sencitive    */
	while ((tolower(*str1) == tolower(*str2)) && 
			(*str1 !='\0') && (*str2 != '\0'))
	{
		str1++;
		str2++; 
	}
    /* calculating result */
	result = tolower(*str1) - tolower(*str2);
	return result;
}


char* OptimaStrCpy( char* dest, const char* source)
 {  
 	char* startting_of_dest = dest; 

	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	return  startting_of_dest;
}


char* OptimaStrNcpy(char *dest, const char *sor, size_t n)
{
	char* startting_of_dest = dest;

	while ((n > 0 ) && (*sor != '\0'))
	{	
		n--;
		*dest = *sor;
		dest ++;
		sor ++;
	}

	return startting_of_dest;
}

/* looks for char c in string s, if found returns 
char* pointing at c                             */

char *OptimaStrChr(const char *s, int c)
{

	while ((*s != c ) && (*s != '\0'))
    {	
    	++s;  
	}
	if(*s != '\0')
	{
		return (char*)s;
	}
	else
	{
		return NULL;
	}
}
 
char *OptimaStrStr(const char *haystack, const char *needle)
{

   int haystack_len = strlen(haystack);
   int needle_len = strlen(needle);

   if(haystack_len < needle_len)
   {
   		return NULL;
   }
   while(0 != strncmp(haystack, needle, needle_len) && '\0' != *haystack)
   {
   		++haystack;
   }
 	return (*haystack ? (char*)haystack : NULL);
}


char *OptimaStrDup(const char *original)
{
	/* creating two pointers one to remember the address
	of the duplicate string, the other is for the loop */

    int original_size = 0;
    char* ptr_to_dup = NULL;
    char* ptr_to_dup_for_loop = NULL;

    original_size = strlen(original);
    ptr_to_dup = malloc(sizeof(char)*original_size+1);
    
    /* assert if we get a bad input */

    assert (original == NULL);
    
    ptr_to_dup_for_loop = ptr_to_dup;

    while ('\0' != *original)
    {
        *ptr_to_dup_for_loop = *original;
        ptr_to_dup_for_loop++;
        original++;
    }

    *ptr_to_dup_for_loop = '\0';

    return (ptr_to_dup);
}

size_t OptimaStrspn(const char * string_to_b_scan, const char * accept)
{
	size_t count = 0;

	assert ( NULL != string_to_b_scan && NULL != accept);

	while ('\0' != *string_to_b_scan)
	{
		if (strchr(accept, *string_to_b_scan))
		{
			++count;
			++string_to_b_scan;
		}
		else
		{
			break;
		}
	}

	return count;

}

void testOptimaStrspn(void)
{
   size_t test1 = strspn("abcdefgt1234","xya"); 
   size_t test2 = OptimaStrspn("abcdefgt1234","xya");
   size_t test3 = strspn("123456789","xyi"); 
   size_t test4 = OptimaStrspn("123456789","xyi");
   size_t test5 = strspn("I good","xy I"); 
   size_t test6 = OptimaStrspn("I good","xy I");
   size_t test7 = strspn("abcdefghijklmnop","123"); 
   size_t test8 = OptimaStrspn("abcdefghijklmnop","123");
   size_t test9 = strspn("i am","xyi"); 
   size_t test10 = OptimaStrspn("i am","xyi");
   


   printf("Length of initial segment matching : %lu\n", test1 ); 
   printf("Length of initial segment matching : %lu\n", test2);
   printf("Length of initial segment matching : %lu\n", test3 ); 
   printf("Length of initial segment matching : %lu\n", test4);
   printf("Length of initial segment matching : %lu\n", test5); 
   printf("Length of initial segment matching : %lu\n", test6);
   printf("Length of initial segment matching : %lu\n", test7); 
   printf("Length of initial segment matching : %lu\n", test8);
   printf("Length of initial segment matching : %lu\n", test9); 
   printf("Length of initial segment matching : %lu\n", test10);
}


char *OptimaStrCat(char *dest, const char *src)
{ 
    char *temp = dest;

	size_t size_of_dest = strlen(dest);

	temp += size_of_dest;

	temp = strcpy(temp, src);

	return (dest);

}




int IsPalenDrome ( const char* s)
{
	const char* reverse_s = s;
	int  i = strlen(s)/2;
	reverse_s += strlen(s)-1;

	while (i--)
	{
 		if (tolower(*s) == tolower(*reverse_s))
    	{ 
    		++s;
    		++reverse_s;
    	}
    	else 
    	{
    		return 0;
    	}
	}
	
	return 1;
}




void boom (int start_range, int end_range)

{
 	int  number = start_range;

 	for (; number <= end_range; 
			number++)
 	{
		if (number % 7 == 0 || find_digit(number, 7) != 0) 
		{
				printf("BOOM\n");
		}	
		else
		{	
			printf("%d\n", number);
		}
	}	
}	
	
/* find digit is a function needed for the function Boom */

int find_digit(int number, int digit)

{

	int remainder = 0;
	int existance_count = 0;

	if (number < 0)
	{
		number *= -1;
	}
	while(number)
	{
		remainder = number % 10;
	
		if (remainder == digit)
		{
			++existance_count;
		}

		number /= 10;
	}

	return existance_count ;
}

char* TrimSpace(char * string_original)
{
	size_t len_org = strlen(string_original);
	char * proxy_to_str_org = string_original;
	char * substitute_string = malloc(100 * sizeof(char));

	assert(string_original != NULL);

   /* remove space and tab if there are two 
   back to back space and tab */
	while(len_org)
	{
		if (((*string_original == ' ') && (*string_original +1 == ' ')) || 
			((*string_original == '\t') && (*string_original +1 == '\t')))
		{
			++string_original;
			++proxy_to_str_org;
		}
		else
		{
			*substitute_string = *proxy_to_str_org;
			++substitute_string;
			++proxy_to_str_org;
		}
		--len_org;
	}

	return substitute_string;

}

void TestTrimSpace()
{
	char * test_string1 = "A		~A		~A";
	char * test_string2 = "A~  A~~A";

	char * result1 = TrimSpace(test_string1);
	char * result2 = TrimSpace(test_string2);

	printf("%s\n", result1);
	printf("%s\n", result2);



}
