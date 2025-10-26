#include <stdio.h>

int binarySearch(int n, int array[n], int x) {
    int start = 0, end = n - 1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if(x == array[middle])
            return middle;
        else if(x > array[middle])
            start = middle + 1;
        else if(x < array[middle])
            end = middle - 1;
    }
    return -1;
}

int main() {
    int n, k, index;
    printf("Enter number of terms in array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter terms in array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the search term: ");
    scanf("%d", &k);

    index = binarySearch(n, a, k);
    if (index == -1)
        printf("The search term was not found\n");
    else
        printf("The search term was found at index %d \n", index);
    return 0;
}
