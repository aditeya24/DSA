#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char designation[50];
    int priority;
    int insertionOrder;
} Customer;

int getPriority(char d[]) {
    if (!strcmp(d, "DifferentlyAbled")) return 1;
    if (!strcmp(d, "SeniorCitizen")) return 2;
    if (!strcmp(d, "Defence")) return 3;
    return 4;
}

void swap(Customer *a, Customer *b) {
    Customer t = *a; *a = *b; *b = t;
}

void heapify(Customer h[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && (h[l].priority < h[smallest].priority || 
                 (h[l].priority == h[smallest].priority && h[l].insertionOrder < h[smallest].insertionOrder))) {
        smallest = l;
    }

    if (r < n && (h[r].priority < h[smallest].priority || 
                 (h[r].priority == h[smallest].priority && h[r].insertionOrder < h[smallest].insertionOrder))) {
        smallest = r;
    }

    if (smallest != i) { 
        swap(&h[i], &h[smallest]); 
        heapify(h, n, smallest); 
    }
}

void insert(Customer h[], int *n, Customer c) {
    int i = (*n)++;
    h[i] = c;

    while (i > 0 && (h[(i-1)/2].priority > h[i].priority || 
                   (h[(i-1)/2].priority == h[i].priority && h[(i-1)/2].insertionOrder > h[i].priority))) {
        
        swap(&h[i], &h[(i-1)/2]);
        i = (i-1)/2;
    }
}

Customer extractMin(Customer h[], int *n) {
    Customer root = h[0];
    h[0] = h[--(*n)];
    heapify(h, *n, 0);
    return root;
}

int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);

    Customer heap[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        Customer c;
        printf("\nEnter name of customer %d: ", i+1);
        scanf(" %49[^\n]", c.name);
        printf("Enter designation (DifferentlyAbled / SeniorCitizen / Defence / Ordinary): ");
        scanf(" %49[^\n]", c.designation);
        
        c.priority = getPriority(c.designation);
        c.insertionOrder = i;
        
        insert(heap, &size, c);
    }

    printf("\nCustomers in order of priority:\n");
    for (int i = 0; i < n; i++) {
        Customer c = extractMin(heap, &size);
        printf("%d. %s (%s)\n", i+1, c.name, c.designation);
    }

    return 0;
}
