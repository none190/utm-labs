#include <stdio.h>
#include <stdlib.h> // for dynamic memory allocation
#include <math.h>
#include <stdbool.h>

// QUICK SORT
int partition(int arr[], int start, int end);
void swap(int *a, int *b);
void quickSort(int arr[], int start, int end);

int* sortQuick(int inputArray[], int start, int end) {
    int* sortedArr = (int*)malloc(sizeof(int) * end);
    for (int i = 0; i < end; i++) {
        sortedArr[i] = inputArray[i];
    }
    
    quickSort(sortedArr, start, end-1);
    return sortedArr;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // find the pivot element such that elements smaller than pivot are on left of pivot elements greater than pivot are on right of pivot
        int p = partition(arr, start, end);

        // recursive call on the left of pivot
        quickSort(arr, start, p - 1);
        // recursive call on the left of pivot
        quickSort(arr, p + 1, end);
    }
    //return arr;
}

// use the last element as the pivot
int partition(int arr[], int start, int end) {
        int pivot = arr[end];
        int i = (start - 1); // index of the smaller element

        for (int j = start; j <= end - 1; j++) {

            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[end]);
        return (i + 1);
    }
// swap 2 elements:
void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }


int** mountainSort(int oldArr[], int n, int m) {
    int** newArr = (int**)malloc(n * sizeof(int*)); // Allocate memory for rows

    for (int i = 0; i < n; i++) {
        newArr[i] = (int*)malloc(m * sizeof(int)); // Allocate memory for columns
    }
    
    int indexOfOldArr = 0;
    int xStart = 0;
    int yStart = 0;
    int xEnd = m-1;
    int yEnd = n-1;
    int length = n*m;
    
    while (indexOfOldArr < length) {
            // move right
            if (indexOfOldArr < length) {
            for (int i = xStart; i <= xEnd; i++) {
                newArr[yStart][i] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            yStart++;
            } else break;

        // move down
        if (indexOfOldArr < length) {
            for (int i = yStart; i <= yEnd; i++) {
                newArr[i][xEnd] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            xEnd--;
        } else break;
        
        // move left
                if (indexOfOldArr < length) {
                for (int i = xEnd; i >= xStart; i--) {
                    newArr[yEnd][i] = oldArr[indexOfOldArr];
                    indexOfOldArr++;
                }
                yEnd--;
                } else break;

        // move up
            if (indexOfOldArr < length) {
            for (int i = yEnd; i >= yStart; i--) {
                newArr[i][xStart] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            xStart++;
            } else break;
    }
    return newArr;
}


int main() {
    int n, m; // lengths of array
    printf("n (row) = ");
    scanf("%d", &n);
    printf("m (column) = ");
    scanf("%d", &m);
    
    // input 2D array
    // int arr[n][m];
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int)); // Allocate memory for columns
    }
    printf("\nArray:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input. Please enter numeric values.\n");
                return 1; // Exit with an error code
            }
        }
    }
    printf("\n");
    
    // for(int i = 1; i <= n; i++) {
    //     printf("Row %d\n", i);
    //     for(int j = 1; j <= m; j++) {
    //         printf("Element %d = ", j);
    //         scanf("%d", &arr[i-1][j-1]);
    //     }
    // }

    int length = n*m;
    int arr1D[length];
    int index = 0;
    // push all elements from arr to arr1D
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr1D[index] = arr[i][j];
            index++;
        }
    }
    
    int* sorted1D = sortQuick(arr1D, 0, length);
    int** mountain2D = mountainSort(sorted1D, n, m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (j == m-1) {
                printf("%d\n", mountain2D[i][j]);
            } else {
                printf("%d ", mountain2D[i][j]);
            }
        }
    }
    
    // for (int i = 0; i < length; i++) {
    //     printf("%d ", sorted1D[i]);
    // }
    
    printf("\n");

    free(sorted1D);
    return 0;
}
