#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct opstack {
    Node* top;
} opstack;

opstack* createStack() {
    opstack* stack = (opstack*)malloc(sizeof(opstack));
    if (!stack) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(opstack* stack) {
    return stack->top == NULL;
}

void push(opstack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Elemento %d inserido com sucesso.\n", value);
}

int pop(opstack* stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia! Não é possível remover elementos.\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}