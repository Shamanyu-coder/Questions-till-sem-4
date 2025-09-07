#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int leftDiagonalSum = 0;
    int rightDiagonalSum = 0;

    for (int i = 0; i < n; i++) {
        leftDiagonalSum += matrix[i][i];
        rightDiagonalSum += matrix[i][n - i - 1];
    }

    int difference = leftDiagonalSum - rightDiagonalSum;
    int absoluteDifference;

    if (difference < 0) {
        absoluteDifference = -difference;
    } else {
        absoluteDifference = difference;
    }

    printf("Absolute difference = %d\n", absoluteDifference);

    return 0;
}
