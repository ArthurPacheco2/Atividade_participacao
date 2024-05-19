#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
        mergeSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%.4f\t", n, time_taken);

        // Ascending
        generateArray(arr, n, 1);
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.4f\t", time_taken);

        // Descending
        generateArray(arr, n, 2);
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%.4f\n", time_taken);

        free(arr);
    }

    return 0;
}
