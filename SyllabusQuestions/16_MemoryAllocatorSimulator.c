#include <stdio.h>
#include <stdbool.h>

#define BLOCK1_MAX_SIZE 150
#define BLOCK2_MAX_SIZE 100
#define BLOCK3_MAX_SIZE 200

typedef struct Block
{
    int blockID;
    int size;
    struct Block *prev, *next;
} Block;

Block block1, block2, block3;
Block *head, *tail;

void FirstFit()
{
    int itemSize;
    printf("\nEnter the size of your object: ");
    scanf("%d", &itemSize);

    Block *temp = head;

    while (temp)
    {
        if (temp->size >= itemSize)
        {
            printf("Allocated %d to Block %d.\n", itemSize, temp->blockID);
            temp->size -= itemSize;
            return;
        }
        temp = temp->next;
    }
    printf("\nSpace not Found!\n");
}

void WorstFit()
{
    int itemSize;
    printf("\nEnter the size of your object: ");
    scanf("%d", &itemSize);

    Block *temp = head;
    Block *worstBlock = NULL;

    while (temp)
    {
        if (temp->size >= itemSize)
        {
            if (worstBlock == NULL || temp->size > worstBlock->size)
            {
                worstBlock = temp;
            }
        }
        temp = temp->next;
    }

    if (worstBlock == NULL)
    {
        printf("\nSpace not Found!\n");
        return;
    }

    printf("Allocated %d to Block %d.\n", itemSize, worstBlock->blockID);
    worstBlock->size -= itemSize;
}

void BestFit()
{
    int itemSize;
    printf("\nEnter the size of your object: ");
    scanf("%d", &itemSize);

    Block *temp = head;
    Block *bestBlock = NULL;

    while (temp)
    {
        if (temp->size >= itemSize)
        {
            if (bestBlock == NULL || temp->size < bestBlock->size)
            {
                bestBlock = temp;
            }
        }
        temp = temp->next;
    }

    if (bestBlock == NULL)
    {
        printf("\nSpace not Found!\n");
        return;
    }

    printf("Allocated %d to Block %d.\n", itemSize, bestBlock->blockID);
    bestBlock->size -= itemSize;
}

void FreeBlock()
{
    int blocknum;
    printf("Enter the Block number to be freed (reset): ");
    scanf("%d", &blocknum);

    switch (blocknum)
    {
    case 1:
        head->size = BLOCK1_MAX_SIZE;
        break;
    case 2:
        (head->next)->size = BLOCK2_MAX_SIZE;
        break;
    case 3:
        tail->size = BLOCK3_MAX_SIZE;
        break;
    default:
        printf("Invalid Block ID.\n");
    }
}

void PrintBlockVisual()
{
    Block *temp = head;
    const int barWidth = 30;

    printf("\n--- Memory Layout ---\n");
    while (temp)
    {
        int originalSize = 0;
        if (temp->blockID == 1)
            originalSize = BLOCK1_MAX_SIZE;
        else if (temp->blockID == 2)
            originalSize = BLOCK2_MAX_SIZE;
        else if (temp->blockID == 3)
            originalSize = BLOCK3_MAX_SIZE;

        int usedSize = originalSize - temp->size;

        printf("Block %d (%3d/%3d): [", temp->blockID, temp->size, originalSize);

        int usedChars = (int)(((float)usedSize / originalSize) * barWidth);
        int freeChars = barWidth - usedChars;

        for (int i = 0; i < usedChars; i++)
            printf("=");
        for (int i = 0; i < freeChars; i++)
            printf(" ");

        printf("]\n");

        temp = temp->next;
    }
    printf("---------------------\n");
}

int main()
{
    head = &block1;
    tail = &block3;

    block1.blockID = 1;
    block1.size = BLOCK1_MAX_SIZE;
    block1.next = &block2;
    block1.prev = NULL;

    block2.blockID = 2;
    block2.size = BLOCK2_MAX_SIZE;
    block2.next = &block3;
    block2.prev = &block1;

    block3.blockID = 3;
    block3.size = BLOCK3_MAX_SIZE;
    block3.next = NULL;
    block3.prev = &block2;

    bool isEnd = false;

    PrintBlockVisual();

    while (!isEnd)
    {
        int choice;
        printf("\n1: First Fit\n2: Worst Fit\n3: Best Fit\n4: Print Memory\n5: Free Block\n0: Stop\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            FirstFit();
            break;
        case 2:
            WorstFit();
            break;
        case 3:
            BestFit();
            break;
        case 4:
            PrintBlockVisual();
            break;
        case 5:
            FreeBlock();
            break;
        case 0:
            isEnd = true;
            break;
        default:
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
