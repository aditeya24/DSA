void push(int* a, int item, int* top) { a[++*top] = item; }

void pop(int* top) { (*top)--; }

int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int* top = (int*)malloc(sizeof(int));
    int sum = 0;
    *top = -1;
    for (int i = 0; i < operationsSize; i++) {
        if (*operations[i] == '+') {
            push(stack, stack[*top] + stack[*top - 1], top);
        } else if (*operations[i] == 'D') {
            push(stack, stack[*top] * 2, top);
        } else if (*operations[i] == 'C') {
            pop(top);
        } else {
            push(stack, atoi(operations[i]), top);
        }
    }
    for (int i = 0; i <= *top; i++) {
        sum += stack[i];
    }
    return sum;
}
