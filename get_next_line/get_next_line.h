#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>


/* in case when compiling, we forget to give a size for the buffer,
 * i will have a buffer size already defined, and when compiling
 * it will take the size of the compiler */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif


#endif
