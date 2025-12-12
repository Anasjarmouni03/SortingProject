#include "sorting.h"
#include <math.h>
#include <stdlib.h>

static void insertion_range(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static void heapify_intro(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapify_intro(arr, n, largest);
    }
}

static void heap_sort_intro(int arr[], int n) {
    if (n <= 1) return;
    for (int i = n / 2 - 1; i >= 0; i--) heapify_intro(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify_intro(arr, i, 0);
    }
}

static int partition_intro(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

static void introsort_util(int arr[], int begin, int end, int depth) {
    if (begin >= end) return;
    int size = end - begin + 1;

    if (size <= 16) {
        insertion_range(arr, begin, end);
        return;
    }

    if (depth == 0) {
        heap_sort_intro(arr + begin, size);
        return;
    }

    int pivot = partition_intro(arr, begin, end);
    introsort_util(arr, begin, pivot - 1, depth - 1);
    introsort_util(arr, pivot + 1, end, depth - 1);
}

void intro_sort(int arr[], int n) {
    if (n <= 1) return;
    int depth = 2 * (int)log2((double)n);
    introsort_util(arr, 0, n - 1, depth);
}