#include <stdio.h>

// Function to move disks from source to destination using auxiliary
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Move the only disk directly
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move top n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Call the Tower of Hanoi function
    towerOfHanoi(n, 'A', 'C', 'B'); // A is source, C is destination, B is auxiliary
    
    return 0;
}
