#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
  struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;
Node *curr = NULL;

Node *createNode () {
	Node *newNode = (Node*)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->next = NULL;
    newNode->prev = NULL;
  }
	return newNode;
}

void deleteRear() {
        Node *toDelete;
        if (head == NULL) {
            printf("List is already empty\n");
            return;
        }
        toDelete = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
        free(toDelete);	
}

const char* pageName(int index) {
    switch (index) {
        case 1:
            return "Home";
        case 2:
            return "About";
        case 3:
            return "Events";
        case 4:
            return "Team";
        case 5:
            return "Contact";
        default:
            return "";
    }
}

void display() {
	Node *ptr = head;
	printf("History: ");
	while (ptr != NULL) {
    if (ptr == curr) {
        printf("[%s]", pageName(ptr->data));
    } else {
        printf("%s", pageName(ptr->data));
    }
    printf("->");
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void displayCurrentPage() {
    printf("Current Page: %s\n", pageName(curr->data));
}

void deleteHistory() {
    while (curr->next != NULL) {
        deleteRear();
    }
}

void addHistory(int data) {
    Node *newNode = createNode();
    if (newNode == NULL) {
        printf("ERROR: Memory insufficient\n");
        return;
    }
    newNode->data = data;
    if (curr != NULL) {
        if (curr->next != NULL) {
            deleteHistory();
        }
    }
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    curr = newNode;
    displayCurrentPage();
    display();
}

void previousPage() {
    if (curr == NULL) {
        return;
    }
    if (curr != NULL) {
        if (curr->prev == NULL) {
            printf("Already at oldest page.\n");
            return;
        }
    }
    curr = curr->prev;
    displayCurrentPage();
    display();
}

void nextPage() {
    if (curr == NULL) {
        return;
    }
    if (curr != NULL) {
        if (curr->next == NULL) {
            printf("Already at latest page.\n");
            return;
        }
    }
    curr = curr->next;
    displayCurrentPage();
    display();
}



int main() {
	int choice, item, position;
	while (1) {
		printf("\n1: Home\n2: About\n3: Events\n4: Team\n5: Contact\n6: Display History\n");
        if (curr != NULL) {
            if (curr->prev != NULL) {
                printf("7: Previous page\n");
            }
            if (curr->next != NULL) {
                printf("8: Next page\n");
            }
        }
        printf("0: Exit\nEnter choice: ");
        scanf("%d", &choice);
		switch (choice) {
			case 0:
				return 0;
			case 1:
                addHistory(1);
                break;
			case 2:
                addHistory(2);
				break;
			case 3:
                addHistory(3);
				break;
			case 4:
                addHistory(4);
				break;
			case 5:
                addHistory(5);
				break;
            case 6:
                display();
                break;
			case 7:
                previousPage();
				break;
			case 8:
                nextPage();
				break;
			default:
				printf("ERROR: Invalid choice\n");
		}
	}
}
