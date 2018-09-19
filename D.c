#include <stdio.h>

enum
{
    NUM_OF_BYTES = 8,
    NUM_OF_BITS = 8,
    MASK_ILON = 0x80
};


void
print_array(unsigned char *array, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%hhx ", array[i]);
    }
}


void
full_array_zeros(unsigned char *array, int n)
{
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }
}

int
main(void)
{
    unsigned char now;

    unsigned char out_array[NUM_OF_BYTES];
    
    full_array_zeros(out_array, NUM_OF_BYTES);

    for (int j = 0; scanf("%hhx", &now) == 1; j++, j %= NUM_OF_BYTES) {
        for (int i = 0; i < NUM_OF_BITS; i++) {
            out_array[i] += (now % 2) * MASK_ILON;
            
            now >>= 1;
        }

        if (j != NUM_OF_BYTES - 1) {
            for (int i = 0; i < NUM_OF_BYTES; i++) {
                out_array[i] >>= 1;
            }
        }
        if (j == NUM_OF_BYTES - 1) {
            print_array(out_array, NUM_OF_BYTES);
            
            full_array_zeros(out_array, NUM_OF_BYTES);
        }
    }

    printf("\n");

    return 0;
}
