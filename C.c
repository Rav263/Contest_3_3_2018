#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <limits.h>

enum 
{
    BYTE_MASK = 256
};


uint32_t
reverse_num(uint32_t number)
{
    uint32_t result = 0;

    for (int i = 0; i < sizeof(result); i++) {
        result += number % BYTE_MASK;
        number /= BYTE_MASK;
        if (i != 3) {
            result <<= CHAR_BIT;
        }
    }

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

    uint32_t now;

    while (scanf("%u", &now) == 1) {
        uint32_t rev_num = reverse_num(now);

        write(fd, &rev_num, sizeof(rev_num));
    }

    close(fd);
    
    return 0;
}
