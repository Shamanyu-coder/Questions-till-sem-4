#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for the polynomial node
typedef struct Node {
    int coef;           // Coefficient
    int xexp, yexp, zexp; // Exponents for x, y, z
    struct Node *link;  // Link to the next node
} *NODE;

// Create a new node (for polynomial term)
NODE getNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return newNode;
}

// Attach a new term to the polynomial linked list
NODE attach(int coef, int xexp, int yexp, int zexp, NODE head) {
    NODE temp = getNode();
    temp->coef = coef;
    temp->xexp = xexp;
    temp->yexp = yexp;
    temp->zexp = zexp;
    temp->link = head->link;  // Insert the new node at the start
    head->link = temp;        // Adjust the head link
    return head;
}

// Read polynomial from the user
NODE readPoly(NODE head) {
    int n, coef, xexp, yexp, zexp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponents (x, y, z) for term %d: ", i + 1);
        scanf("%d %d %d %d", &coef, &xexp, &yexp, &zexp);
        head = attach(coef, xexp, yexp, zexp, head);  // Attach term to the polynomial
    }
    return head;
}

// Display the polynomial
void display(NODE head) {
    if (head->link == head) {
        printf("No polynomial terms.\n");
        return;
    }
    
    NODE temp = head->link;
    while (temp != head) {
        printf("%dx^%dy^%dz^%d", temp->coef, temp->xexp, temp->yexp, temp->zexp);
        temp = temp->link;
        if (temp != head) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Evaluate the polynomial for given values of x, y, and z
int polyEvaluate(NODE head) {
    int x, y, z, sum = 0;
    printf("Enter values for x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    
    NODE temp = head->link;
    while (temp != head) {
        sum += temp->coef * pow(x, temp->xexp) * pow(y, temp->yexp) * pow(z, temp->zexp);
        temp = temp->link;
    }
    return sum;
}

// Add two polynomials and store the result in a new list
NODE polySum(NODE head1, NODE head2, NODE head3) {
    NODE a = head1->link;
    NODE b = head2->link;

    // Traverse through both polynomials
    while (a != head1 && b != head2) {
        if (a->xexp == b->xexp && a->yexp == b->yexp && a->zexp == b->zexp) {
            head3 = attach(a->coef + b->coef, a->xexp, a->yexp, a->zexp, head3);  // Add coefficients of matching terms
            a = a->link;
            b = b->link;
        } else if (a->xexp > b->xexp) {
            head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
            a = a->link;
        } else {
            head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
            b = b->link;
        }
    }

    // Add any remaining terms
    while (a != head1) {
        head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
        a = a->link;
    }
    while (b != head2) {
        head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
        b = b->link;
    }

    return head3;
}

int main() {
    // Initialize the circular linked lists
    NODE head = getNode(); head->link = head;   // For polynomial evaluation
    NODE head1 = getNode(); head1->link = head1; // For POLY1
    NODE head2 = getNode(); head2->link = head2; // For POLY2
    NODE head3 = getNode(); head3->link = head3; // For POLY_SUM

    int choice;
    while (1) {
        printf("\n1. Represent and Evaluate a Polynomial\n2. Add Two Polynomials\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Polynomial evaluation
                head = readPoly(head);
                printf("Polynomial representation: ");
                display(head);
                printf("Polynomial evaluated result: %d\n", polyEvaluate(head));
                break;

            case 2:
                // Polynomial addition
                printf("Enter POLY1:\n");
                head1 = readPoly(head1);
                printf("Enter POLY2:\n");
                head2 = readPoly(head2);
                
                printf("Polynomial 1: ");
                display(head1);
                printf("Polynomial 2: ");
                display(head2);
                
                head3 = polySum(head1, head2, head3);
                printf("Sum of the polynomials: ");
                display(head3);
                break;

            case 3:
                exit(0);  // Exit program
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
