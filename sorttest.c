#include <stdio.h>
#include <string.h>
#include "libsort.h"

int compare(int *a, int *b)
{
    return *a - *b;
}

int main(int argc, char *argv[])
{
    int size = argc - 2;
    int **data = (int **)malloc(sizeof(int *) * size);
    void **temp = (void **)malloc(sizeof(void *) * size);
    int **realdata;
    int i;

    /* reading the data */
    for (i = 0; i < size; i++) {
        data[i] = (int *)malloc(sizeof(int));
        *data[i] = atoi(argv[i + 2]);
    }

    /* run the test */
    switch (atoi(argv[1]))
    {
        case 0: /* merge */
            realdata = data + 3;
            size -= 3;
            merge(*data[0], *data[1], *data[2], realdata, temp, compare);
            break;
        case 1: /* split */
            realdata = data + 2;
            size -= 2;
            split(*data[0], *data[1], realdata, temp, compare);
            break;
        case 2: /* mergesort */
            realdata = data + 1;
            size -= 1;
            mergesort(realdata, *data[0], compare);
            break;
        default:
            printf("unknown function!\n");
    }

    /* generate output */
    for (i = 0; i < size; i++) 
        printf("%i ", *realdata[i]);
    printf("\n");

    return 0;
}
