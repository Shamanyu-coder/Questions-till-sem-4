#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    top++;
    stack[top] = value;
}

int pop() {
    int value = stack[top];
    top--;
    return value;
}

int evaluatePostfix(char exp[]) {  // Use array instead of pointer for exp
    int i;

    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit, push it onto the stack
        if (exp[i] >= '0' && exp[i] <= '9') {
            int num = exp[i] - '0';  // Convert char to int
            push(num);
        } 
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val2 = pop();
            int val1 = pop();
            
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    // The result will be the only element left in the stack
    return pop();
}

int main() {
    char exp[MAX];

    // Ask the user for input
    printf("Enter a postfix expression: ");
    fgets(exp, MAX, stdin);

    // Remove newline character if present
    int len = strlen(exp);
    if (exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    int result = evaluatePostfix(exp);
    printf("Postfix Evaluation: %d\n", result);

    return 0;
}
