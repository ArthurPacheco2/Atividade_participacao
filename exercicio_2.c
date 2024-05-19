#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void generateArray(int arr[], int n, int type) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        if (type == 0) {
            arr[i] = rand() % 10000; // Random values
        } else if (type == 1) {
            arr[i] = i; // Sorted in ascending order
        } else if (type == 2) {
            arr[i] = n - i; // Sorted in descending order
        }
    }
}

int main() {
    int sizes[] = {1000, 2000, 10000, 20000, 100000, 200000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Size\tRandom\tAscending\tDescending\n");
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        clock_t start, end;
        double time_taken;

        // Random
        generateArray(arr, n, 0);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%.4f\t", n, time_taken);

        // Ascending
        generateArray(arr, n, 1);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.4f\t", time_taken);

        // Descending
        generateArray(arr, n, 2);
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.4f\n", time_taken);

        free(arr);
    }

    return 0;
}
