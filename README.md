# Conversao De Notacao

# Introdução
Este projeto implementa um conversor de expressões matemáticas em linguagem C. Ele pega uma expressão escrita na notação infixa *(exemplo: A + B * C)* e converte para a notação pós-fixa *(exemplo: A B C * +)*, usando uma pilha para organizar os operadores.

# Objetivo
• Usar a estrutura de dados pilha.

• Respeitar as regras de precedência e associatividade dos operadores.

• Converter expressões infixas para a notação pós-fixa.

# Regras para Conversão
1. Se o caractere é um operando (exemplo: A, B, 1), adiciona diretamente na saída.
2. Se é um operador (exemplo: +, *):
• Empilha se for de maior precedência ou se a pilha estiver vazia.

• Caso contrário, desempilha operadores da pilha para a saída até encontrar um de menor precedência.
4. Se for um parêntese de abertura ((), empilha.

5. Se for um parêntese de fechamento ()), desempilha até encontrar o parêntese de abertura correspondente.
   
6. No final, desempilha todos os operadores restantes para a saída.

# Exemplo

# Entrada:
 A + B * C

Conversão:
1.  A : Vai para a saída.
2.  + : Empilha.
3.  B : Vai para a saída.
4.  * : Empilha (maior precedência que +).
5.  C: Vai para a saída.
6.  Desempilha os operadores restantes (* e depois +).

# Saída:
 A B C * +

Testes
Exemplo 1:
• Entrada: A + B

• Saída: A B +
Exemplo 2:
• Entrada: (A + B) * C

• Saída: A B + C *

# Conclusão
Este projeto demonstra como a estrutura de dados pilha pode ser utilizada para manipular expressões matemáticas complexas, facilitando a conversão para notações computacionalmente mais eficientes. A implementação em C exemplifica conceitos de precedência de operadores, uso de memória dinâmica e organização algorítmica.

*Possíveis Expansões
• Suporte para múltiplas variáveis e valores numéricos.
• Implementação da conversão para notação prefixa.
• Manipulação de erros para entradas inválidas.
