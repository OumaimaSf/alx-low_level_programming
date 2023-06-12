#include <fcntl.h>
#include <unistd.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    char buffer[1024];
    ssize_t t_b_r = 0;
    ssize_t b_r;
    ssize_t b_w;
    ssize_t b_t_w;

    if (filename == NULL)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    while (letters > 0)
    {
        b_r = read(fd, buffer, sizeof(buffer));
        if (b_r <= 0)
            break;

        b_t_w = (b_r < (ssize_t)letters) ? b_r : (ssize_t)letters;

        b_w = write(STDOUT_FILENO, buffer, (size_t)b_t_w);
        if (b_w != b_t_w)
            break;

        t_b_r += b_w;
        letters -= b_w;
    }

    close(fd);

    return (t_b_r);
}
