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

void display(opstack* stack) {  //Exibe os elementos da pilha
    if (isEmpty(stack)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("\n Elementos na pilha: ");
    Node* current = stack->top;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(opstack* stack) {   //Libera a memória alocada para a pilha
    while (!isEmpty(stack)) {
        pop(stack); // Remove cada elemento
    }
    free(stack); // Libera a estrutura da pilha
}

int main() {        //Teste da pilha
    opstack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    printf("Elemento removido: %d\n", pop(stack));
    display(stack);

    freeStack(stack);
    return 0;
}
