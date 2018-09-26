#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int
reverce_num(unsigned int number)
{
    unsigned int result = 0;

    for (int i = 0; i < 3; i++) {
        result += number & 0xFF;

        number >>= 8;
        result <<= 8;
    }
    result += number & 0xFF;

    return result;
}

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }
    int fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0600);

    if (fd < 0) {
        return 1;
    }

    unsigned int now;

    while (scanf("%u", &now) == 1) {
        unsigned int rev_num = reverce_num(now);

        write(fd, &rev_num, sizeof(rev_num));
    }

    close(fd);
    
    return 0;
}
