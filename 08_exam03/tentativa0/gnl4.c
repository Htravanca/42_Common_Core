#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char *ft_strdup(char *src)
{
    int i;
    char *dest;

    i = 0;
    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));    
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char	  *get_next_line(int fd)
{
    char line[70000];
    int i;
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_read;

    i = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break ;
        }
        if (line[i] == '\n')
            break ;
        line[i] = buffer[buffer_pos];
        buffer_pos++;
        i++;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));    
}

int main()
{
    int fd;
    char *line;

    fd = open("file1.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line)
            printf("%s", line);
        else
            break ;
    }
    close(fd);
}