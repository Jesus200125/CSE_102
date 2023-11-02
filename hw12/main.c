#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    char type[20];
    int ivals[1];
    double svals[1];
} Asset1;

typedef struct {
    char type[20];
    double svals[2];
    int ivals[2];
} Asset2;

typedef struct {
    char type[20];
    char string1[50];
    char string2[50];
} Asset3;

typedef struct {
    char type[20];
    double value1;
    float value2;
    double value3;
} Asset4;

void fillLinkedList(Node** head) {
    srand(time(NULL));
    int numAssets = rand() % 11 + 10;
    
    for (int i = 0; i < numAssets; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next = NULL;
        
        int assetType = rand() % 4 + 1;
        switch (assetType) {
            case 1:
                newNode->data = (Asset1*)malloc(sizeof(Asset1));
                strcpy(((Asset1*)newNode->data)->type, "Asset1");
                ((Asset1*)newNode->data)->ivals[0] = rand() % 100;
                ((Asset1*)newNode->data)->svals[0] = (double)(rand() % 10000) / 100;
                break;
            case 2:
                newNode->data = (Asset2*)malloc(sizeof(Asset2));
                strcpy(((Asset2*)newNode->data)->type, "Asset2");
                ((Asset2*)newNode->data)->ivals[0] = rand() % 100;
                ((Asset2*)newNode->data)->ivals[1] = rand() % 100;
                ((Asset2*)newNode->data)->svals[0] = (double)(rand() % 10000) / 100;
                ((Asset2*)newNode->data)->svals[1] = (double)(rand() % 10000) / 100;
                break;
            case 3:
                newNode->data = (Asset3*)malloc(sizeof(Asset3));
                strcpy(((Asset3*)newNode->data)->type, "Asset3");
                sprintf(((Asset3*)newNode->data)->string1, "String1: %d", rand() % 100);
                sprintf(((Asset3*)newNode->data)->string2, "String2: %d", rand() % 100);
                break;
            case 4:
                newNode->data = (Asset4*)malloc(sizeof(Asset4));
                strcpy(((Asset4*)newNode->data)->type, "Asset4");
                ((Asset4*)newNode->data)->value1 = (double)(rand() % 10000) / 100;
                ((Asset4*)newNode->data)->value2 = (float)(rand() % 10000) / 100;
                ((Asset4*)newNode->data)->value3 = (double)(rand() % 10000) / 100;
                break;
        }
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void serializeLinkedList(Node* head) {
    FILE* file = fopen("linkedlist.bin", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(((Asset1*)temp->data)->type, "Asset1") == 0) {
            fwrite(((Asset1*)temp->data)->type, sizeof(char), 20, file);
            fwrite(((Asset1*)temp->data)->ivals, sizeof(int), 1, file);
            fwrite(((Asset1*)temp->data)->svals, sizeof(double), 1, file);
        } else if (strcmp(((Asset2*)temp->data)->type, "Asset2") == 0) {
            fwrite(((Asset2*)temp->data)->type, sizeof(char), 20, file);
            fwrite(((Asset2*)temp->data)->svals, sizeof(double), 2, file);
            fwrite(((Asset2*)temp->data)->ivals, sizeof(int), 2, file);
        } else if (strcmp(((Asset3*)temp->data)->type, "Asset3") == 0) {
            fwrite(((Asset3*)temp->data)->type, sizeof(char), 20, file);
            fwrite(((Asset3*)temp->data)->string1, sizeof(char), 50, file);
            fwrite(((Asset3*)temp->data)->string2, sizeof(char), 50, file);
        } else if (strcmp(((Asset4*)temp->data)->type, "Asset4") == 0) {
            fwrite(((Asset4*)temp->data)->type, sizeof(char), 20, file);
            fwrite(&((Asset4*)temp->data)->value1, sizeof(double), 1, file);
            fwrite(&((Asset4*)temp->data)->value2, sizeof(float), 1, file);
            fwrite(&((Asset4*)temp->data)->value3, sizeof(double), 1, file);
        }
        
        temp = temp->next;
    }
    
    fclose(file);
}

void deserializeLinkedList(Node** head) {
    FILE* file = fopen("linkedlist.bin", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    char type[20];
    while (fread(type, sizeof(char), 20, file) == 20) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->next = NULL;
        
        if (strcmp(type, "Asset1") == 0) {
            newNode->data = (Asset1*)malloc(sizeof(Asset1));
            strcpy(((Asset1*)newNode->data)->type, type);
            fread(((Asset1*)newNode->data)->ivals, sizeof(int), 1, file);
            fread(((Asset1*)newNode->data)->svals, sizeof(double), 1, file);
        } else if (strcmp(type, "Asset2") == 0) {
            newNode->data = (Asset2*)malloc(sizeof(Asset2));
            strcpy(((Asset2*)newNode->data)->type, type);
            fread(((Asset2*)newNode->data)->svals, sizeof(double), 2, file);
            fread(((Asset2*)newNode->data)->ivals, sizeof(int), 2, file);
        } else if (strcmp(type, "Asset3") == 0) {
            newNode->data = (Asset3*)malloc(sizeof(Asset3));
            strcpy(((Asset3*)newNode->data)->type, type);
            fread(((Asset3*)newNode->data)->string1, sizeof(char), 50, file);
            fread(((Asset3*)newNode->data)->string2, sizeof(char), 50, file);
        } else if (strcmp(type, "Asset4") == 0) {
            newNode->data = (Asset4*)malloc(sizeof(Asset4));
            strcpy(((Asset4*)newNode->data)->type, type);
            fread(&((Asset4*)newNode->data)->value1, sizeof(double), 1, file);
            fread(&((Asset4*)newNode->data)->value2, sizeof(float), 1, file);
            fread(&((Asset4*)newNode->data)->value3, sizeof(double), 1, file);
        }
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    fclose(file);
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(((Asset1*)temp->data)->type, "Asset1") == 0) {
            printf("Type: %s\n", ((Asset1*)temp->data)->type);
            printf("Int value: %d\n", ((Asset1*)temp->data)->ivals[0]);
            printf("Double value: %.2f\n", ((Asset1*)temp->data)->svals[0]);
        } else if (strcmp(((Asset2*)temp->data)->type, "Asset2") == 0) {
            printf("Type: %s\n", ((Asset2*)temp->data)->type);
            printf("Int values: %d, %d\n", ((Asset2*)temp->data)->ivals[0], ((Asset2*)temp->data)->ivals[1]);
            printf("Double values: %.2f, %.2f\n", ((Asset2*)temp->data)->svals[0], ((Asset2*)temp->data)->svals[1]);
        } else if (strcmp(((Asset3*)temp->data)->type, "Asset3") == 0) {
            printf("Type: %s\n", ((Asset3*)temp->data)->type);
            printf("Strings: %s, %s\n", ((Asset3*)temp->data)->string1, ((Asset3*)temp->data)->string2);
        } else if (strcmp(((Asset4*)temp->data)->type, "Asset4") == 0) {
            printf("Type: %s\n", ((Asset4*)temp->data)->type);
            printf("Values: %.2f, %.2f, %.2f\n", ((Asset4*)temp->data)->value1, ((Asset4*)temp->data)->value2, ((Asset4*)temp->data)->value3);
        }
        
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    fillLinkedList(&head);
    serializeLinkedList(head);

    Node* newHead = NULL;
    deserializeLinkedList(&newHead);

    printLinkedList(newHead);

    return 0;
}

