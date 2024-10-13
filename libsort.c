#include <stdlib.h>
#include <unistd.h>
#include "libsort.h"

void merge(int lstart, int rstart, int stop, void **data, void **temp,
           int (*cmp)(void*,void*))
{
    int lp = lstart;
    int rp = rstart;
    int pos;

    for (pos=0; lp<rstart && rp<stop;)
        if (cmp(data[lp], data[rp])<0)
        {
            temp[pos++] = data[lp++];
        } else {
            temp[pos++] = data[rp++];
        }

    while (lp < rstart)
        temp[pos++] = data[lp++];

    while (rp < stop)
        temp[pos++] = data[rp++];

    memcpy(data + lstart, temp, sizeof(void **) * pos);
}

void split(int start, int stop, void **data, void **temp,
           int (*cmp)(void*,void*))
{
    int middle = (stop - start) / 2;
    /* recursion step */
    if (middle-start>1)
        split(start, middle, data, temp, cmp);
    if (middle > start && stop-middle>1)
        split(middle, stop, data, temp, cmp);
    /* merge the two halfes */
    merge(start, middle, stop, data, temp, cmp);
}

void mergesort(void** data, int size,
               int (*compare)(void *a, void *b))
{
    /* setup of configuration */
    void **temp = (void **)malloc( sizeof(void *) * size );
    /* start mergesorting */
    split(0, size, data, temp, compare);
    /* clear configuration */
    free(temp);
}
