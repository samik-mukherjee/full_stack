#ifndef __BUFFER__
#define __BUFFER__

#include <unistd.h> /* size_t and ssize_t */

typedef struct buffer Buffer_t;


/*
 * NAME:	Buffer
 * AUTHORS:	RD-59
 * VERSION:	5.0
 */


/* DESCRIPTION:
 * Creates a circular buffer for the specified size.
 * The created buffer should be destroyed with BufferDestroy() function
 * after usage.
 *
 *		PARAMETERS:
 *		capacity: Size of buffer in bytes to be created.
 *
 * RETURN:
 * Returns a pointer to Buffer_t.
 * Returns NULL in case of an error creating the buffer.
 */
Buffer_t* BufferCreate(size_t capacity);


/* DESCRIPTION:
 * Destroy the buffer. If pointer given does not point to a valid buffer,
 * the result is undefined.
 * Must be executed for each buffer that was created.
 *
 *    	 PARAMETERS:
 *    	 buffer:		Pointer to the buffer.
 *
 * RETURN:
 * No return.
 */
void BufferDestroy(Buffer_t* buffer);

/* DESCRIPTION:
 * Write specified number of bytes from input to the buffer.
 *
 *		PARAMETERS:
 *		buffer:		Pointer to the buffer
 *		input:		Point to beginning of input.
 * 		bytes: 		Maximum number of bytes from data to be added to the buffer.
 *
 * RETURN:
 * Returns number of bytes written, or -1 in case of error.
 * If buffer is full and not all bytes are written, errno is set to EOVERFLOW.
 */
ssize_t BufferWrite(Buffer_t* buffer, const void* input, size_t bytes);

/* DESCRIPTION:
 * Reads specified number of bytes from buffer to output.
 *
 *    	PARAMETERS:
 *    	buffer:		Pointer to the buffer.
 *		output:		Pointer to beginning of output.
 * 		bytes: 		Maximum number of bytes from buffer to be read to output.
 *
 * RETURN:
 * Returns number of bytes read, or -1 in case of error.
 * If buffer is empty and not all bytes are read, errno is set to ENODATA.
 */
ssize_t BufferRead(Buffer_t* buffer, void* output, size_t bytes);

/* DESCRIPTION:
 * Gives the number of bytes available in buffer to write to.
 *
 *    	 PARAMETERS:
 *    	 buffer:		Pointer to the buffer.
 *
 * RETURN:
 * Number of empty bytes in the buffer.
 */
size_t BufferFreeSpace(const Buffer_t* buffer);

/* DESCRIPTION:
 * Gives the total amount of bytes in the buffer.
 *
 *		PARAMETERS:
 *		buffer: 		Pointer to the buffer.
 *
 * RETURN:
 * Number of bytes in buffer.
 */
size_t BufferCapacity(const Buffer_t* buffer);

/* DESCRIPTION:
 * Function checks if buffer is empty.
 *
 *		PARAMETERS:
 *		buffer: 		Pointer to the buffer.
 *
 * RETURN:
 * 0 if not empty, 1 if empty.
 */
int BufferIsEmpty(const Buffer_t* buffer);

#endif /*__BUFFER__*/
