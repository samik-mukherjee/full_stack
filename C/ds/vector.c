#include <stdio.h>                 /* perror           */
#include <stdlib.h>                /* malloc           */
#include <string.h>                /* memcpy           */
#include <assert.h>                /* assert           */
#include <stddef.h>                /* size_t           */
#include "vector.h"                /* vector functions */



/* creaing Vector_t type structure */
struct vector
{
	void * start; 
	void * top;
	void * end;
	size_t element_size;
};

typedef Vector_t vector_t;


Vector_t * VectorCreate(size_t num_of_elem, size_t element_size)
{
	vector_t * vector = NULL;

	assert(0 < element_size);

	/* metadata allocation */
	vector = malloc(sizeof(*vector));
	if(NULL == vector)
	{
		return NULL;
	}

	vector->start = malloc(num_of_elem * element_size);
	if(NULL == vector->start)
	{
		/* if malloc fails at total datasize allocation */
		free(vector);
		return NULL;
	}
	
    vector->top = vector->start;	
    vector->end = (char *)vector->start + num_of_elem * element_size; 
    vector->element_size = element_size;

    return vector;
}

void VectorDestroy(Vector_t* vector)
{
	if (NULL != vector)
	{
		free(vector->start);
		memset(vector, 0, sizeof(*vector));
	}

	free(vector);
}

	int VectorPushBack(Vector_t* vector, const void* elem)
{
	void * new_start = NULL;

	assert(vector);
	assert(elem);

	if ((size_t)vector->top + (size_t)vector->element_size > (size_t)vector->end)
	{
		/* Create a new buffer. */
		new_start = malloc(2 * ((char*)vector->end - (char*)vector->start));
		if (NULL == new_start)
		{
			return 1;
		}

		memcpy(new_start, vector->start, (char*)vector->top - (char*)vector->start);
		vector->top = (char *)new_start + ((char *)vector->top - (char *)vector->start);
		vector->end = (char*)new_start + 2 * ((char*)vector->end -(char*) vector->start);
		free(vector->start);
		vector->start = new_start;
	}

	memcpy(vector->top, elem, vector->element_size);
	vector->top = (char *)vector->top + vector->element_size;

	return 0;
}

  size_t VectorCapacity(const Vector_t* vector)
{
    assert(vector->element_size);

    return (((size_t)((char*)vector->end - (char*)vector->start))
                / vector->element_size);
}

size_t VectorSize(const Vector_t* vector)
{
    assert(vector);

	return (((char*)vector->top - 
			(char*)vector->start)/vector->element_size); 
}

void VectorPopBack(Vector_t* vector)
{
    assert(vector);

	if(0 != VectorSize(vector))
	{
		vector->top = (char*)vector->top -
					  vector->element_size;
	}
}

void* VectorGetItem(const Vector_t* vector, size_t index)
{
	assert(vector);

	return ((char*)vector->start + (vector->element_size * index)); 
}



int VectorReserve(Vector_t* vector, size_t num_of_elements)
{	
	assert(vector);

	if (0 != num_of_elements)
	{
		size_t new_size = num_of_elements * vector->element_size;
		
		Vector_t *new_vector = malloc(new_size);
		assert(new_vector);

		if (NULL != new_vector)
		{
			size_t old_size = (size_t)vector->top - (size_t)vector->start;
			if (old_size > new_size)
			{
				old_size = new_size;
			}
			memcpy(new_vector, vector->start, old_size);
			free(vector->start);
			vector->start = new_vector; 

			vector->top = (char*)vector->start + old_size;
			vector->end = (char*)vector->start + new_size;

			return 0;
		}
	}

	return 1;
}










