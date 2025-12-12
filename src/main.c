#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorting.h"

#define MAX_SIZE 30000000

int sizes[] = {1000,2000,4000,8000,16000,32000,64000,128000,256000,512000,1000000,10000000,20000000};
int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
}

void copy_array(int src[], int dest[], int n) {
    memcpy(dest, src, n * sizeof(int));
}

int main() {
    srand(time(NULL));

    system("mkdir -p results");

    FILE *fp = fopen("results/timings.csv", "w");
    if (!fp) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    fprintf(fp, "Taille,Bubble,Insertion,Selection,Quick,Merge,Heap,Shell,Comb,Counting,Radix,Intro\n");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *original = malloc(n * sizeof(int));
        int *arr = malloc(n * sizeof(int));

        if (!original || !arr) {
            printf("Memory allocation failed for size %d\n", n);
            continue;
        }

        generate_random_array(original, n);
        fprintf(fp, "%d", n);

        clock_t start, end;

        // --- Bubble Sort ---
        if (n <= 10000) {
            copy_array(original, arr, n);
            start = clock();
            bubble_sort(arr, n);
            end = clock();
            fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);
        } else fprintf(fp, ",");

        // --- Insertion Sort ---
        if (n <= 10000) {
            copy_array(original, arr, n);
            start = clock();
            insertion_sort(arr, n);
            end = clock();
            fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);
        } else fprintf(fp, ",");

        // --- Selection Sort ---
        if (n <= 10000) {
            copy_array(original, arr, n);
            start = clock();
            selection_sort(arr, n);
            end = clock();
            fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);
        } else fprintf(fp, ",");

        // --- Quick Sort ---
        copy_array(original, arr, n);
        start = clock();
        quick_sort(arr, 0, n - 1);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- Merge Sort ---
        copy_array(original, arr, n);
        start = clock();
        merge_sort(arr, 0, n - 1);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- Heap Sort ---
        copy_array(original, arr, n);
        start = clock();
        heap_sort(arr, n);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- Shell Sort ---
        copy_array(original, arr, n);
        start = clock();
        shell_sort(arr, n);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- Comb Sort ---
        copy_array(original, arr, n);
        start = clock();
        comb_sort(arr, n);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- Counting Sort ---
        if (n <= 1000000) {
            copy_array(original, arr, n);
            start = clock();
            counting_sort(arr, n);
            end = clock();
            fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);
        } else fprintf(fp, ",");

        // --- Radix Sort ---
        copy_array(original, arr, n);
        start = clock();
        radix_sort(arr, n);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        // --- IntroSort ---
        copy_array(original, arr, n);
        start = clock();
        intro_sort(arr, n);
        end = clock();
        fprintf(fp, ",%f", ((double)(end - start)) / CLOCKS_PER_SEC);

        fprintf(fp, "\n");
        free(original);
        free(arr);

        printf("Finished size %d\n", n);
    }

    fclose(fp);
    printf("All results saved in results/timings.csv\n");
    return 0;
}