#ifndef __VECTOR__
#define __VECTOR__

#include <stddef.h> /* size_t */

typedef struct vector Vector_t;


/*
 * NAME:	Vector
 * AUTHORS:	RD-59
 * VERSION:	3.0
 */



/* DESCRIPTION:
 * Creates a Vector for the specified number of members and for their respective size.
 * size_of_elem cannot be zero.
 * The received Vector should be destroyed with VectorDestroy() function after usage. 
 *
 *		PARAMETERS:
 *		num_of_elems: 	The number of elements to store on the Vector.
 *		size_of_elem: 	The size in bytes of the elements to be stored.
 *   	 
 * RETURN:
 * Returns a pointer of type Vector_t which points to the new Vector created. 
 * Returns NULL in case of an error creating the Vector. 
 */
Vector_t *VectorCreate(size_t num_of_elem, size_t size_of_elem);

/* DESCRIPTION:
 * Destroy the vector. 
 * Must be executed for each vector was created. 
 *
 *    	 PARAMETERS:
 *    	 vector:		Pointer to the needed vector.
 *
 * RETURN:
 * No return.
 */
void VectorDestroy(Vector_t* vector);

/* DESCRIPTION: 
 * Adds specified value to the end of the vector. If the size of the vector
 * is not enough, the size will be increased exponentially.
 *
 *		PARAMETERS:
 *		vector:		Pointer to the vector	
 *		value:		Data to be added to the end of the vector.
 *		
 * RETURN:
 * Returns 0 if push is successful, and 1 if it fails.
*/
int VectorPushBack(Vector_t* vector, const void* elem);

/* DESCRIPTION:
 * PopBack pops element from the vector's end.
 * In the case of empty vector PopBack does nothing. 
 * 
 *    	 PARAMETERS:
 *    	 vector:		Pointer to the needed vector.
 *
 * RETURN:
 * No return.
 */
void VectorPopBack(Vector_t* vector);

/* DESCRIPTION:
  * Returns pointer to the indexed element in the vector.
  * The pointer is temporary and might be lost with next vector function call.
  *  
  *
  *    	 PARAMETERS:
  *    	 vector:		Pointer to the needed vector.
  *		 index:			Index of the element in the vector
  *
  * RETURN:
  * Returns temporary pointer to the indexed element.
  * Returns NULL in case vector is empty.
  */
void* VectorGetItem(const Vector_t* vector, size_t index);

/* DESCRIPTION:
 * Returns number of elements in the vector.
 *
 *    	 PARAMETERS:
 *    	 vector:		Pointer to the needed vector.
 *
 * RETURN:
 * Number of elements in the vector.
 */
size_t VectorSize(const Vector_t* vector);

/* DESCRIPTION:
 * Function returns max possible number 
 * of elements in vector.
 *
 *		PARAMETERS:
 *		vector: pointer to vector to check.
 *   	 
 * RETURN:
 * Max possible number of elements in vector.
 */
size_t VectorCapacity(const Vector_t* vector);

/* DESCRIPTION:
 * Resizes vector to the num_of_elements. 
 * If num_of_elements is smaller than current size of vector, 
 * only num_of_elements remain.
 *
 *		PARAMETERS:
 *		vector:             pointer to vector.
 *		num_of_elements:    number of elements in vector.
 *
 * RETURN:
 * Returns 1 if number of elements cannot be reserved.
 * Returns 0 in case of success.
 */
int VectorReserve(Vector_t* vector, size_t num_of_elements);

#endif 	/* __VECTOR__ */
