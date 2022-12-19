#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*get_next_line(int fd);
char	*left_str(char *left_str);
char	*get_line(char *str);
void	ft_bzero(void *s, size_t n);

#endif
