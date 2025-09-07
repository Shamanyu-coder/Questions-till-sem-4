#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;               // Data part of the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;  // Set the data
    newNode->left = NULL;  // Initialize left child as NULL
    newNode->right = NULL; // Initialize right child as NULL
    return newNode;        // Return the new node
}

// Function to insert a node in the binary tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recursively insert the data
    if (data < root->data) {
        root->left = insert(root->left, data); // Insert in the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insert in the right subtree
    }

    return root; // Return the unchanged root pointer
}

// Function to search for a value in the binary tree
int search(struct Node* root, int data) {
    // Base Cases: root is null or data is present at root
    if (root == NULL || root->data == data) {
        return root != NULL; // Return true if found, false otherwise
    }

    // Data is greater than root's data
    if (root->data < data) {
        return search(root->right, data); // Search in the right subtree
    }

    // Data is smaller than root's data
    return search(root->left, data); // Search in the left subtree
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);          // Traverse the left subtree
        printf("%d ", root->data);    // Visit the root
        inorder(root->right);         // Traverse the right subtree
    }
}

// Function to perform preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);    // Visit the root
        preorder(root->left);         // Traverse the left subtree
        preorder(root->right);        // Traverse the right subtree
    }
}

// Function to perform postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);        // Traverse the left subtree
        postorder(root->right);       // Traverse the right subtree
        printf("%d ", root->data);    // Visit the root
    }
}

// Main function with menu
int main() {
    struct Node* root = NULL;    // Initial tree is empty
    int choice, data;            // Variables for user input

    while (1) {
        printf("\n--- Binary Tree Operations ---\n");
        printf("1. Insert\n2. Search\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert a node
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted!\n");
                break;
            case 2: // Search for a node
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Data found in the tree!\n");
                } else {
                    printf("Data not found in the tree!\n");
                }
                break;
            case 3: // Inorder traversal
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4: // Preorder traversal
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5: // Postorder traversal
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6: // Exit the program
                exit(0);
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0; // End of the program
}
