
/*============================= HEADER ======================================*/


#include <stdio.h>			/* printf */
#include <string.h>			/* strcmp */

#include "vector.h"

#define RED "\x1B[31m" 		/* for failed test results visibility */
#define GREEN "\x1B[32m"	/* for successful test results visibility */
#define RESET "\x1B[0m"		

#define SUCCESS (1) 		/* for successful test results readability */
#define FAIL (0) 			/* for failed test results readability */


/*====================== TEST FUNCTIONS DECLARATION =========================*/



static void	TestVectorFunctions(void);
static void TestResults(char string[], int status);



/*============================== MAIN =======================================*/



int main()
{
	TestVectorFunctions();
	return(0);
}



/*======================= TEST FUNCTIONS CALL ===============================*/



static void	TestVectorFunctions(void)
{
	/* variables for the tests */
	char char1 = 'a';
	char char2 = 'b';
	char char3 = 'c';

	int int1 = 0;
	int int2 = 1;

	char string1[8] = "Hello11"; 
	char string2[8] = "Hello22"; 
	char string3[8] = "Hello33"; 

	Vector_t *vector1 = NULL;
	Vector_t *vector2 = NULL;
	Vector_t *vector3 = NULL;

	printf("----------------------\n\n");

	/* ============================== */

	printf("TESTS OF CREATE, SIZE, CAPACITY AND DESTROY:\n\n");

	vector1 = VectorCreate(6,8);

	0 == VectorSize(vector1) ?
	TestResults ("vector created, size of empty vector", SUCCESS) :
	TestResults ("vector created, size of empty vector", FAIL);

	6 == VectorCapacity(vector1) ?
	TestResults ("capacity of empty vector", SUCCESS) :
	TestResults ("capacity of empty vector", FAIL);

	/* test Vector create and destroy using VLG */
	VectorDestroy(vector1);

	
	printf("----------------------\n\n");
	

	printf("TESTS OF PUSH, POP, GET, SIZE ON 2 VECTORS:\n\n");

	vector1 = VectorCreate(6,8);
	vector2 = VectorCreate(3,4);

	VectorPushBack(vector1, string1);
	VectorPushBack(vector2, &int2);
	VectorPushBack(vector1, string2);
	VectorPushBack(vector2, &int1);
	0 == strcmp(string2, (char*)VectorGetItem(vector1, 1)) &&
	int1 == *(int*)VectorGetItem(vector2, 1)	?
	TestResults ("push and getitem of 2 vectors at the same time", SUCCESS) :
	TestResults ("push and getitem of 2 vectors at the same time", FAIL);

	2 == VectorSize(vector1) &&
	2 == VectorSize(vector2) ?
	TestResults ("size of 2 vectors pushed at the same time", SUCCESS) :
	TestResults ("size of 2 vectors pushed at the same time", FAIL);

	VectorPushBack(vector1, string3);
	VectorPopBack(vector2);
	VectorPopBack(vector1);
	0 == strcmp(string2, (char*)VectorGetItem(vector1, 1)) &&
	int2 == *(int*)VectorGetItem(vector2, 0)	?
	TestResults ("pop and getitem of 2 vectors at the same time", SUCCESS) :
	TestResults ("pop and getitem of 2 vectors at the same time", FAIL);

	VectorDestroy(vector1);
	VectorDestroy(vector2);


	printf("----------------------\n\n");
	

	printf("TESTS OF POPPING EMPTY VECTOR:\n\n");

	vector3 = VectorCreate(1,3);

	VectorPushBack(vector3, &char1);
	VectorPopBack(vector3);
	VectorPopBack(vector3);
	VectorPushBack(vector3, &char2);
	char2 == *(char*)VectorGetItem(vector3, 0)	?
	TestResults ("popping an empty vector", SUCCESS) :
	TestResults ("popping an empty vector", FAIL);

	VectorDestroy(vector3);


	printf("----------------------\n\n");
	

	printf("TESTS OF DYNAMIC SIZE OF VECTOR:\n\n");

	vector3 = VectorCreate(2,1);
	VectorPushBack(vector3, &char1);
	VectorPushBack(vector3, &char2);
	VectorPushBack(vector3, &char3);
	VectorPushBack(vector3, &char1);
	4 == VectorCapacity(vector3) &&
	4 == VectorSize(vector3) &&
	char1 == *(char*)VectorGetItem(vector3, 3) ?
	TestResults ("vector size enlarged on time, new elements pushed", SUCCESS) :
	TestResults ("vector size enlarged on time, new elements pushed", FAIL);

	VectorPushBack(vector3, &char1);
	8 == VectorCapacity(vector3) ?
	TestResults ("vector size is enlarging exponentially", SUCCESS) :
	TestResults ("vector size is enlarging exponentially", FAIL);

	VectorDestroy(vector3);


	printf("----------------------\n\n");
	

	printf("TESTS OF VECTOR RESERVE:\n\n");
	
	vector1 = VectorCreate(2,8);
	VectorReserve(vector1, 5);
	VectorPushBack(vector1, string1);
	VectorPushBack(vector1, string2);
	VectorPushBack(vector1, string3);
	5 == VectorCapacity(vector1) && 3 == VectorSize(vector1) ?
	TestResults ("capacity enlarged with reserve func, more elements pushed", 
																	SUCCESS) :
	TestResults ("capacity enlarged with reserve func, more elements pushed", 
																		FAIL);

	VectorReserve(vector1, 2);
	2 == VectorCapacity(vector1) && 2 == VectorSize(vector1) ?
	TestResults ("capacity decreased with reserve func, vector size adjusted", 
																	SUCCESS) :
	TestResults ("capacity decreased with reserve func, vector size adjusted", 
																		FAIL);

	VectorDestroy(vector1);


	vector2 = VectorCreate(3,1);
	VectorPushBack(vector2, &char1);
	VectorPushBack(vector2, &char2);
	VectorReserve(vector2, 2);
	2 == VectorCapacity(vector2) && 2 == VectorSize(vector2) ?
	TestResults ("capacity decreased with reserve func, no vector size change", 
																	SUCCESS) :
	TestResults ("capacity decreased with reserve func, no vector size change", 
																		FAIL);

	VectorDestroy(vector2);

	printf("----------------------\n\n");
}



static void TestResults(char string[], int status)
{
	if (status)
	{
		printf(GREEN "SUCCESSFUL\n" RESET "test: %s\n\n" , string);
	}
	else
	{
		printf(RED "FAILED\n" RESET "test: %s\n\n", string);
	}
}