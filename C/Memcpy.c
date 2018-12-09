#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define WORD (sizeof(size_t))               /*     Word size         */ 


void *OptimaMemcpy(void *dest, const void *src, size_t n)
{	
    size_t offset_by = 0;
    char * dest_ptr = dest;
    char * src_ptr = (char *)src;
    
    assert(NULL != src);
    assert(NULL != dest);
    assert(0 <= n);

    offset_by = WORD - ((size_t)src_ptr % WORD);
    while ((offset_by) && (n > 0))
    {
        *dest_ptr++ = *src_ptr++;
        --offset_by;
        --n;
    }

    while (n >= WORD)
    {
        *(size_t *)dest_ptr = *(size_t *)src_ptr;
        dest_ptr += WORD;
        src_ptr += WORD;
        n -= WORD;
    }

    while (n > 0)
    {
        *dest_ptr++ = *src_ptr++;
        --n;
    }

    return dest;
}

int UnitTestMemcpy()
{
    char src[] = "Hello great new world";
    char *dest = malloc(sizeof(*dest) * (strlen(src) + 1));
    if(NULL == dest)
    {
        printf("malloc failed\n");

        return  -1;
    }
    
    OptimaMemcpy(dest, src, (strlen(src) + 1));
    printf("src = %s.\n dest = %s.\n", src, dest);

    free(dest);

    return 0;
}

int main()
{
    UnitTestMemcpy();

    return 0;
}
