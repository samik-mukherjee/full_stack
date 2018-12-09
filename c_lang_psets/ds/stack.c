#include <stdio.h>             /*  main                */
#include <stdlib.h>            /*  memory allocation   */
#include <assert.h>            /*  assert()            */
#include <string.h>            /*  memcpy()            */
#include "stack.h"             /*  stack functions     */

struct stack {
	size_t size_of_member;
	void * end;
	void * top;
	void * base;
};

stack_t *StackCreate(size_t num_of_members, size_t size_of_member)
{
	/* assigning the size of the structure itself 
	   into a variable */
	size_t size_of_stack = sizeof(stack_t);

	/* assigning the full size (with data, which will be 
	   calculated at run time) of stack and storing 
	   it into he variable total_sizeof_stack */  
	size_t total_sizeof_stack = size_of_stack +
								(num_of_members * size_of_member);

	/* creating a type stack_t pointer and allocating 
	   memory for it */
	stack_t * ptr_to_stack = malloc(total_sizeof_stack);

	/* malloc check */
	if(NULL == *ptr_to_stack)
	{
		return NULL;
	}
    
    /*assigning what address each opinter should point */
	ptr_to_stack->size_of_member = size_of_member;

	/* casting needed for pointer erithmetics */
	ptr_to_stack->end = (char*)ptr_to_stack + total_sizeof_stack;
	ptr_to_stack->base = (char*)ptr_to_stack + size_of_stack;
	ptr_to_stack->top = ptr_to_stack->base;

	return ptr_to_stack;
}

int StackPush(stack_t* stack, const void* value)
{	
	if(stack->top == stack->end)
	{
		return 1;
	}

	memcpy(stack->top, value, stack->size_of_member);
	stack->top = (char*)stack->top + stack->size_of_member;
	
	return 0;
}

void StackPop(stack_t* stack)
{
	if(stack->top != stack->base)
	{
		stack->top = (char*)stack->top - stack->size_of_member;
	}
}

void *StackPeek(const stack_t* stack)
{
	if(stack->top != stack->base)
	{
		return ((char*)stack->top - stack->size_of_member);
	}
	return NULL;
}

void StackDestroy(stack_t* stack)
{
	free(stack);
	stack = NULL;

}

size_t StackSize(const stack_t* stack)
{
	return (((char*)stack->top - (char*)stack->base)/stack->size_of_member); 
}

int StackIsEmpty(const stack_t * stack)
{
	return ((stack->top == stack->base) ? 1 : 0 );
}