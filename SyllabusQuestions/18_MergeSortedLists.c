#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct HeapNode {
    int value;
    int listIndex;
    int nextIndex;
};

void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void mergeKSortedLists(int **lists, int *sizes, int K) {
    int totalElements = 0;
    for (int i = 0; i < K; i++)
        totalElements += sizes[i];

    struct HeapNode *heap = (struct HeapNode *)malloc(K * sizeof(struct HeapNode));
    int heapSize = 0;

    for (int i = 0; i < K; i++) {
        if (sizes[i] > 0) {
            heap[heapSize].value = lists[i][0];
            heap[heapSize].listIndex = i;
            heap[heapSize].nextIndex = 1;
            heapSize++;
        }
    }

    for (int i = (heapSize - 1) / 2; i >= 0; i--)
        heapify(heap, heapSize, i);

    printf("\nMerged Sorted List:\n");

    int mergedCount = 0;
    while (heapSize > 0) {
        struct HeapNode root = heap[0];
        printf("%d ", root.value);
        mergedCount++;

        if (root.nextIndex < sizes[root.listIndex]) {
            heap[0].value = lists[root.listIndex][root.nextIndex];
            heap[0].nextIndex++;
        } else {
            heap[0] = heap[heapSize - 1];
            heapSize--;
        }

        heapify(heap, heapSize, 0);
    }

    printf("\n");
    free(heap);
}

int main() {
    int K;
    printf("Enter number of sorted lists (K): ");
    scanf("%d", &K);

    int **lists = (int **)malloc(K * sizeof(int *));
    int *sizes = (int *)malloc(K * sizeof(int));

    for (int i = 0; i < K; i++) {
        printf("\nEnter number of elements in list %d: ", i + 1);
        scanf("%d", &sizes[i]);

        lists[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter %d sorted elements: ", sizes[i]);
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &lists[i][j]);
    }

    mergeKSortedLists(lists, sizes, K);

    for (int i = 0; i < K; i++)
        free(lists[i]);
    free(lists);
    free(sizes);

    return 0;
}
