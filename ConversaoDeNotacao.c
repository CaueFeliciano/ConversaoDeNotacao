#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    char data; // Alterado para char
    struct Node *next;
} Node;

typedef struct opstack
{ // Pilha de operadores
    Node *top;
} opstack;

opstack *createStack()
{ // Cria uma pilha vazia
    opstack *stack = (opstack *)malloc(sizeof(opstack));
    if (!stack)
    {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

int isEmpty(opstack *stack)
{ // Verifica se a pilha está vazia
    return stack->top == NULL;
}

void push(opstack *stack, char value)
{ // Insere elemento no topo
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(opstack *stack)
{ // Remove e retorna o elemento do topo
    if (isEmpty(stack))
    {
        printf("Pilha vazia! Não é possível remover elementos.\n");
        return '\0';
    }
    Node *temp = stack->top;
    char poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

void freeStack(opstack *stack)
{ // Libera memória alocada para a pilha
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

int isOperator(char ch)
{ // Verifica se é operador
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op)
{ // Retorna a precedência do operador
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

char *reverseString(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    // Alocar memória para a string invertida
    char *reversed = (char *)malloc((len + 1) * sizeof(char));
    // Inverter a string
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1];
    }
    // Finalizar a string invertida
    reversed[len] = '\0';
    return reversed;
}

char *convertToPostfix(char *infix)
{ // Converte expressão infixa para pós-fixa
    opstack *stack = createStack();
    char *postfix = (char *)malloc(100 * sizeof(char)); // Saída
    int k = 0;                                          // Índice para postfix

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        { // Se for operando (letra ou número)
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(stack) && stack->top->data != '(')
            {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Remove '('
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(stack) && precedence(stack->top->data) >= precedence(ch))
            {
                postfix[k++] = pop(stack);
            }
            push(stack, ch);
        }
    }

    while (!isEmpty(stack))
    { // Adiciona operadores restantes
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0'; // Finaliza string
    freeStack(stack);
    return postfix;
}

char *convertToPreFix(char *infix)
{
    opstack *stack = createStack();
    char *prefix = (char *)malloc(100 * sizeof(char)); // Saída
    int k = 0;                                         // Índice para prefix
    char *reversedInfix = reverseString(infix);        // Inverte a expressão infixa
    for (int i = 0; reversedInfix[i] != '\0'; i++)     // Percorre a expressão infixa invertida
    {
        char ch = reversedInfix[i];
        if (isalnum(ch))
        {
            prefix[k++] = ch;
        }
        else if (ch == ')')
        {
            push(stack, ch);
        }
        else if (ch == '(')
        {
            while (!isEmpty(stack) && stack->top->data != ')')
            {
                prefix[k++] = pop(stack);
            }
            pop(stack);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(stack) && precedence(stack->top->data) > precedence(ch))
            {
                prefix[k++] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while (!isEmpty(stack))
    {
        prefix[k++] = pop(stack);
    }
    prefix[k] = '\0';
    free(reversedInfix);                       // Libera memória alocada para a string invertida
    char *finalPrefix = reverseString(prefix); // Inverte a string prefix
    freeStack(stack);
    return finalPrefix;
}

int main()
{
    char infix[] = "A+B*(C-D)"; // Exemplo de expressão infixa
    printf("Expressão Infixa: %s\n", infix);

    char *postfix = convertToPostfix(infix);
    printf("Expressão Pós-fixa: %s\n", postfix);

    char *prefix = convertToPreFix(infix);
    printf("Expressão Pré-fixa: %s\n", prefix);

    free(postfix); // Libera memória alocada para a string pós-fixa
    return 0;
}
