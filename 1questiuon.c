#include <stdio.h>

// Function to create an array
void createArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int pos, int value) {
    if (*size >= pos) {
        for (int i = *size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        (*size)++;
        printf("Element inserted successfully!\n");
    } else {
        printf("Invalid position for insertion.\n");
    }
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size, int pos) {
    if (*size > 0 && pos >= 0 && pos < *size) {
        for (int i = pos; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted successfully!\n");
    } else {
        printf("Invalid position for deletion.\n");
    }
}

int main() {
    int arr[100];
    int size = 0;
    int choice, pos, value;

    do {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                createArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &value);
                insertElement(arr, &size, pos, value);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
