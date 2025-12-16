#include <stdio.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char elem) {
    if (top == SIZE - 1) return;
    stack[++top] = elem;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int pr(char symbol) {
    if (symbol == '^') return 3;
    else if (symbol == '*' || symbol == '/') return 2;
    else if (symbol == '+' || symbol == '-') return 1;
    else return 0;
}

int main() {
    char infix[SIZE], postfix[SIZE];
    char ch;
    int i = 0, k = 0;

    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (ch == ' ') continue;
        if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while ((pr(stack[top]) > pr(ch)) || (pr(stack[top]) == pr(ch) && ch != '^'))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s\n", postfix);

    return 0;
}
