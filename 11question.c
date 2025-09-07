#include <stdio.h>
#include <stdlib.h>

int *ht, key[20], n, m;
int count = 0;

// Insert a key into the hash table
void insert(int key) {
    int index = key % m;  // Find the initial position using key % m

    // If that position is full, keep moving to the next one (linear probing)
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }

    ht[index] = key;  // Place the key in the found empty position
    count++;  // Increase the count of keys inserted
}

// Display the hash table contents
void display() {
    if (count == 0) {  // If no keys are added, show that the table is empty
        printf("\nHash Table is empty\n");
        return;
    }

    printf("\nHash Table contents:\n");
    for (int i = 0; i < m; i++) {
        printf(" T[%d] --> %d\n", i, ht[i]);
    }
}

int main() {
    // Get the number of records (n) and the hash table size (m) from the user
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter the hash table size (m): ");
    scanf("%d", &m);

    // Allocate memory for the hash table and set all positions to -1 (empty)
    ht = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht[i] = -1;
    }

    // Get the keys from the user
    printf("Enter the four-digit key values for %d employee records:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    // Insert each key into the hash table
    for (int i = 0; i < n; i++) {
        if (count == m) {  // If the table is full, stop inserting
            printf("~~~ Hash table is full. Cannot insert record %d ~~~\n", i + 1);
            break;
        }
        insert(key[i]);
    }

    // Show the final hash table contents
    display();

    free(ht);  // Free up the memory used by the hash table
    return 0;
}
