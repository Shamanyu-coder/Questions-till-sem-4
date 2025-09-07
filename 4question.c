#include <stdio.h>

#define MAX_SIZE 100 // Define stack size

// Define stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1; // Return a sentinel value for empty stack
    } else {
        return s->items[(s->top)--];
    }
}

// Function to display the elements of the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

// Function to check if the stack is a palindrome
int isPalindrome(Stack *s) {
    if (isEmpty(s)) {
        return 1; // An empty stack is considered a palindrome
    }

    int start = 0;
    int end = s->top;

    while (start < end) {
        if (s->items[start] != s->items[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

int main() {
    Stack stack;
    initializeStack(&stack); // Initialize the stack

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display stack elements
    display(&stack);

    // Check if stack is a palindrome
    if (isPalindrome(&stack)) {
        printf("Stack is a palindrome\n");
    } else {
        printf("Stack is not a palindrome\n");
    }

    // Pop an element from the stack
    int poppedValue = pop(&stack);
    printf("Popped element: %d\n", poppedValue);

    // Display stack elements after pop operation
    display(&stack);

    // Check again if the stack is a palindrome after popping
    if (isPalindrome(&stack)) {
        printf("Stack is a palindrome\n");
    } else {
        printf("Stack is not a palindrome\n");
    }

    return 0;
}
