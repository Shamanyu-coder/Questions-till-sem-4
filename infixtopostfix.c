#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // Return null character if stack is empty
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') { 
        return 3;
    }
    return 0;  // Lowest precedence for other characters
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    push('(');
    strcat(infix, ")");

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[k++] = ch;  // Directly add operands to postfix
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop();  // Remove '(' from stack
        } else {  // If the character is an operator
            while (precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[MAX] = "(c-d)*(e*f+g)+(h)";
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}