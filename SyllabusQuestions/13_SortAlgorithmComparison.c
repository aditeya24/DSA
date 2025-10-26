#include <stdio.h>
#define MAX 100

int bubbleComps = 0, bubbleAssigns = 0;
int insertionComps = 0, insertionAssigns = 0;
int radixAssigns = 0;
int quickComps = 0, quickAssigns = 0;
int mergeComps = 0, mergeAssigns = 0;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void readArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bubbleComps++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                bubbleAssigns += 3;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        insertionAssigns++;
        int j = i - 1;
        while (j >= 0) {
            insertionComps++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                insertionAssigns++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        insertionAssigns++;
    }
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n], count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        radixAssigns++;
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        radixAssigns++;
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (1) {
        while (i <= high) {
            quickComps++;
            if (arr[i] <= pivot) {
                i++;
            } else {
                break;
            }
        }
        while (j >= low) {
            quickComps++;
            if (arr[j] > pivot) {
                j--;
            } else {
                break;
            }
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            quickAssigns += 3;
        } else
            break;
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    quickAssigns += 3;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        mergeAssigns++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        mergeAssigns++;
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        mergeComps++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        mergeAssigns++;
    }
    while (i < n1) {
        arr[k++] = L[i++];
        mergeAssigns++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        mergeAssigns++;
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

int main() {
    int original[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    readArray(original, n);

    int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX], arr5[MAX];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = original[i];
    }

    bubbleSort(arr1, n);
    insertionSort(arr2, n);
    radixSort(arr3, n);
    quickSort(arr4, 0, n - 1);
    mergeSort(arr5, 0, n - 1);

    printf("\nSorted Array (Bubble Sort):\n");
    printArray(arr1, n);
    printf("Comparisons: %d, Assignments: %d\n", bubbleComps, bubbleAssigns);

    printf("\nSorted Array (Insertion Sort):\n");
    printArray(arr2, n);
    printf("Comparisons: %d, Assignments: %d\n", insertionComps, insertionAssigns);

    printf("\nSorted Array (Radix Sort):\n");
    printArray(arr3, n);
    printf("Comparisons: N/A, Assignments: %d\n", radixAssigns);

    printf("\nSorted Array (Quick Sort):\n");
    printArray(arr4, n);
    printf("Comparisons: %d, Assignments: %d\n", quickComps, quickAssigns);

    printf("\nSorted Array (Merge Sort):\n");
    printArray(arr5, n);
    printf("Comparisons: %d, Assignments: %d\n", mergeComps, mergeAssigns);

    return 0;
}
