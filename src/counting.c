#include "sorting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void counting_sort(int arr[], int n) {
    if (n <= 0) return;

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    if (max < 0) return; 

    size_t counts_size = (size_t)max + 1;
    int *count = (int *)calloc(counts_size, sizeof(int));
    if (!count) {
        fprintf(stderr, "counting_sort: calloc failed for size %zu\n", counts_size);
        return;
    }

    for (int i = 0; i < n; i++) {
        count[(size_t)arr[i]]++;
    }

    int *output = (int *)malloc((size_t)n * sizeof(int));
    if (!output) {
        fprintf(stderr, "counting_sort: malloc failed for output\n");
        free(count);
        return;
    }

    size_t idx = 0;
    for (size_t v = 0; v < counts_size; v++) {
        while (count[v]-- > 0) {
            output[idx++] = (int)v;
        }
    }

    memcpy(arr, output, (size_t)n * sizeof(int));

    free(count);
    free(output);
}