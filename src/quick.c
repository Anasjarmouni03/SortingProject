#include "sorting.h"

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quick_sort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}