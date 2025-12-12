#include "sorting.h"
#include <stdlib.h>
#include <string.h>

static void counting_sort_radix(int arr[], int n, int exp) {
    if (n <= 0) return;

    int *output = (int *)malloc((size_t)n * sizeof(int));
    if (!output) return;

    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        int pos = --count[digit];
        output[pos] = arr[i];
    }

    memcpy(arr, output, (size_t)n * sizeof(int));
    free(output);
}

void radix_sort(int arr[], int n) {
    if (n <= 0) return;

    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];

    if (max == 0) return;

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_radix(arr, n, exp);
        if (exp > max / 10) break;
    }
}