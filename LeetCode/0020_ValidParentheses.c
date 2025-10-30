typedef struct Node {
    char val;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void push(char val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

char pop() {
    Node* temp = head;
    char val = temp->val;
    head = head->next;
    free(temp);
    return val;
}

bool isValid(char* s) {
    head = NULL;
    char val;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '(':
                push(s[i]);
                break;
            case '{':
                push(s[i]);
                break;
            case '[':
                push(s[i]);
                break;
            case ')':
                if (head == NULL) return false;
                val = pop();
                if (val != '(') return false;
                break;
            case '}':
                if (head == NULL) return false;
                val = pop();
                if (val != '{') return false;
                break;
            case ']':
                if (head == NULL) return false;
                val = pop();
                if (val != '[') return false;
                break;
        }
    }
    bool result;
    if (head != NULL) {
        result = false;
    } else {
        result = true;
    }
    while (head != NULL) {
        val = pop();
    }
    return result;
}
