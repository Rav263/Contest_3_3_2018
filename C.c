#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <endian.h>
#include <stdint.h>

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
        uint32_t rev_num = htobe32(now);

        write(fd, &rev_num, sizeof(rev_num));
    }

    close(fd);
    
    return 0;
}
