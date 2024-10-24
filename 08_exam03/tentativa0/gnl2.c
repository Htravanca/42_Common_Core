#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char *ft_strdup(char *str)
{
    int i;
    char *str2;

    i = 0;
    while (str[i])
        i++;
    str2 = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (str[i])
    {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

char *get_next_line(int fd)
{
    static char *buffer[BUFFER_SIZE];
    char *line[70000];
    int i;
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
        i++;
        buffer_pos++;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}
