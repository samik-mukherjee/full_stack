#ifndef __STACK__
#define __STACK__

#include <stddef.h> /* size_t */

typedef struct stack stack_t;

/*
 * NAME:	Stack
 * AUTHORS:	RD-59
 * VERSION:	1.0
 */



/* DESCRIPTION:
 * Creates a stuck for specified number of members.
 * The stack should be destroyed with StackDestroy() function after usage. 
 *
 *		PARAMETERS:
 *		num_of_members: 	The number of elements to store on the stack.
 *		size_of_members: 	The size in bytes of the elements to be stored.
 *   	 
 * RETURN:
 * Returns a pointer of type stack_t which points to the new stack created. 
 * Returns NULL in case of stack not being created. 
 */
stack_t *StackCreate(size_t num_of_members, size_t size_of_member);



/* DESCRIPTION:
 * Adds a data to the top of the stack.
 * Pushing to full stack causes undefined behavior.   
 *
 *		 PARAMETERS:
 *		 value: 	A data to be added to the top of the stack.
 *    	 stack:		Pointer to the needed stack.
 *
 * RETURN:
 * Returns 0 in case of successful push, and 1 in case of failure.
 */
int StackPush(stack_t* stack, const void* value);



/* DESCRIPTION:
 * Pop top element from the stack’s.
 * Empty stack causes no action.
 * 
 *    	 PARAMETERS:
 *    	 stack:		Pointer to the needed stack.
 *
 * RETURN:
 * No return.
 */
void StackPop(stack_t* stack);



/* DESCRIPTION:
 * Returns pointer to the top element in the stack, without popping it. 
 * Empty stack causes no action. Does not modify any data. 
 *
 *    	 PARAMETERS:
 *    	 stack:		Pointer to the needed stack. 
 *  	
 * RETURN:
 * Returns pointer to the peeked element. 
 * or NULL if the stack in empty. 
 */ 
void *StackPeek(const stack_t* stack);



/* DESCRIPTION:
 * Free memory of stack. 
 * Must be executed before the end of the program. 
 *
 *    	 PARAMETERS:
 *    	 stack:		Pointer to the needed stack.
 *
 * RETURN:
 * No return.
 */
void StackDestroy(stack_t* stack);



/* DESCRIPTION:
 * Returns number of elements in the stack.
 *
 *    	 PARAMETERS:
 *    	 stack:		Pointer to the needed stack.
 *
 * RETURN:
 * Number of elements in the stack.
 */
size_t StackSize(const stack_t* stack);



#endif 	/* __STACK__ */
