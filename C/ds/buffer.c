#include <string.h>            /*  memcpy               */
#include <assert.h>            /*  assert               */
#include <stdlib.h>            /*  malloc(), free()     */
#include <errno.h>             /*  errno                */
#include <unistd.h>            /*  size_t and ssize_t    */
#include "buffer.h"            /*  buffer functions     */

static int BufferIsFULL(const Buffer_t* buffer);

struct buffer
{
	void * start;  		/* data starting point  */
	void * end;         /* end of buffer        */
	size_t size;        /* bytes filled         */
	size_t capacity;    /* total bytes capacity */
};

Buffer_t* BufferCreate(size_t capacity)
{
	Buffer_t *buffer = NULL;

	buffer = malloc(sizeof(*buffer));
	if(NULL != buffer && capacity > 0) /* in case of malloc fail & 0 input) */
	{
		buffer->start = malloc(capacity);
		if(buffer->start)
		{
			buffer->end = (char*)buffer->start + capacity;
			buffer->capacity = capacity;
			buffer->size = 0;

			return buffer;	
		}

		free(buffer);
		buffer = NULL;
		return NULL;
	}

	return NULL;
}


void BufferDestroy(Buffer_t* buffer)
{
	assert(buffer);
	free(buffer);
	buffer = NULL;
}

ssize_t BufferWrite(Buffer_t* buffer, const void* input, size_t bytes)
{
	return 0;
}


size_t BufferFreeSpace(const Buffer_t* buffer)
{
	return (buffer->capacity - buffer->size);
}

size_t BufferCapacity(const Buffer_t* buffer)
{	
	assert(buffer);
	return (buffer->capacity);
}

int BufferIsEmpty(const Buffer_t* buffer)
{
	assert(buffer);
	return (buffer->size ? 0 : 1);
}

static int BufferIsFULL(const Buffer_t* buffer)
{	
	assert(buffer);
	return (buffer-> size == buffer->capacity ? 1 : 0);
}
