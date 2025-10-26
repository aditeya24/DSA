#include <stdio.h>


void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n,m;

    printf("Enter number of events: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter activity points for each event:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter maximum events you can participate in : ");
    scanf("%d", &m);

    sortDescending(A, n);

    int maxPoints = 0;
    for (int i = 0; i < m && i < n; i++) {
        maxPoints += A[i];
    }

    printf("Maximum Activity Points: %d\n", maxPoints);

    return 0;
}
