#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


enum 
{
    BUFF_SIZE = 16
};

int
main(void)
{

    int fd = 1;

    char buff[BUFF_SIZE];

    unsigned long long sum = 0;

    while (1) {
        ssize_t r = read(fd, &buff, sizeof(buff));

        if (r < 0) {
            return 1;
        }
        if (!r) {
            break;
        }

        char *some;

        sum += strtoll(buff, &some, 10);
    }


    printf("%lld\n", sum);
    return 0;
}
