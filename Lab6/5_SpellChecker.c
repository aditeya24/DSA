#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define WORD_LEN 50


typedef struct Node {
    char word[WORD_LEN];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];


unsigned int hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = hash*33 + c;
    return hash % TABLE_SIZE;
}


void insert(const char* word) {
    unsigned int index = hash(word);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(const char* word) {
    unsigned int index = hash(word);
    Node* curr = hashTable[index];
    while (curr) {
        if (strcmp(curr->word, word) == 0)
            return 1;
        curr = curr->next;
    }
    return 0;
}


void suggest(const char* word) {
    char temp[WORD_LEN];
    int len = strlen(word);

    printf("Did you mean:\n");

    for (int i = 0; i < len; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            strcpy(temp, word);
            temp[i] = c;
            if (search(temp) && strcmp(temp, word) != 0)
                printf("  %s\n", temp);
        }
    }

    for (int i = 0; i <= len; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            strcpy(temp, word);
            memmove(temp + i + 1, temp + i, len - i + 1);
            temp[i] = c;
            if (search(temp))
                printf("  %s\n", temp);
        }
    }

    
    for (int i = 0; i < len; i++) {
        strcpy(temp, word);
        memmove(temp + i, temp + i + 1, len - i);
        if (search(temp))
            printf("  %s\n", temp);
    }
}

int main() {
    char* dictionary[] = { "apple", "banana", "car", "cart", "card", "cat", "dog", "elephant", "friend", "from", "hello", "house", "language", "learn", "list", "more", "other", "people", "program", "spell", "stack", "that", "the", "there", "think", "tree", "word", "work", "world", "write" };
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < dictSize; i++) {
        insert(dictionary[i]);
    }

    char word[WORD_LEN];
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (search(word)) {
        printf("'%s' is spelled correctly.\n", word);
    } else {
        printf("'%s' is NOT in dictionary.\n", word);
        suggest(word);
    }

    return 0;
}
