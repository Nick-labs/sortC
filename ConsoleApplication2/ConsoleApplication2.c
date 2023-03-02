#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define RFACTOR (1.24733)

void combSort(float* array, int size) {
    int gap = size;
    int swaps = 1;
    int i, j;

    while (gap > 1 || swaps) {
        gap = (int)(gap / RFACTOR);
        if (gap < 1)
            gap = 1;
        swaps = 0;
        for (i = 0; i < size - gap; ++i) {
            j = i + gap;
            if (array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                swaps = 1;
            }
        }
    }
}

void quickSort(float* arr, int first, int last) {
    float x = arr[(first + last) / 2];
    int i = first, j = last;

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            if (arr[i] > arr[j]) {
                float tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            };
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        quickSort(arr, i, last);
    if (first < j)
        quickSort(arr, first, j);
}

void bubbleSort(float* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = (size - 1); j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                float tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void selectionSort(float* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) min_index = j;
        }

        if (min_index != i) {
            float tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}


int main() {
    int i, size;
    printf("n = ");
    scanf_s("%d", &size);
    if (size < 1) return 1;

    float* arr = NULL;
    arr = (float*)malloc(size * sizeof(float));

    srand((unsigned int)time(NULL) / 2);
    printf("\narray:\n");
    for (i = 0; i < size; i++)
        printf("%f\n", arr[i] = rand() / (float)RAND_MAX * 1000);

    printf("\nSelect a sort:\n1. Bubble sort\n2. Selection sort\n3. Comb sort\n4. Quick sort\n\n");
    int sortType;
    scanf_s("%d", &sortType);

    switch (sortType) {
    case 1: bubbleSort(arr, size);
        break;
    case 2: selectionSort(arr, size);
        break;
    case 3: combSort(arr, size);
        break;
    case 4: quickSort(arr, 0, size - 1);
        break;
    default: printf("Error! Incorrect number!\n\nUn");
    }

    printf("sorted array:\n");
    for (i = 0; i < size; i++)
        printf("%f\n", arr[i]);

    free(arr);
    return 0;
}
