#include "sorting.h"

void comb_sort(int arr[], int n) {
    if (n <= 1) return;
    int gap = n;
    int swapped = 1;
    const double shrink = 1.3;

    while (gap != 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1) gap = 1;

        swapped = 0;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int tmp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = tmp;
                swapped = 1;
            }
        }
    }
}