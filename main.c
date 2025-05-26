#include <fcntl.h>      // open
#include <stdio.h>      // printf
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
