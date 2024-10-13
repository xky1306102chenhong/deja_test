#ifndef LIBSORT_H__
#define LIBSORT_H__

void mergesort(void** data, int size,
               int (*compare)(void *a, void *b));

/* internal function */
void merge(int lstart, int rstart, int stop, void **data, void **temp,
           int (*cmp)(void*,void*));

void split(int start, int stop, void **data, void **temp,
           int (*cmp)(void*,void*));

#endif
