#include <stdio.h>
#include <stdlib.h> 
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack[++top] = x;
    }
}
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack[top--];
    }
}

int precedence(char c) {   // operator ka precedence return karne ke liye yah use kiya gya hai
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return 0;
    }
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');// character operator hai kya isko check karne ke liye yah use kiya gya hai
}
void infixToPostfix(char infix[], char postfix[]) {// infix to postfix convert karne ke liye yah function hai
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') { //(  yah hai to isko stack me push kardo
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') { // jab tak pop karo jab tak ) yah na mil jaye
                postfix[j++] = pop();
            }
            pop(); 
        }
    
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {// jab charater operator ho
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();// pure operator ko pop  kardo
    }

    postfix[j] = '\0'; // null ke liye hai
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
