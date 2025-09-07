#include <stdio.h>
#include <string.h>

void replacePattern(char *str, char *pat, char *rep, char *ans) {
    int i = 0, j = 0, k;
    int strLen = strlen(str);
    int patLen = strlen(pat);
    int repLen = strlen(rep);
    int flag = 0;

    while (i < strLen) {
        // Check if pattern matches at current position manually
        int match = 1;
        for (k = 0; k < patLen; k++) {
            if (str[i + k] != pat[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // Copy replacement string to answer string
            for (k = 0; k < repLen; k++) {
                ans[j++] = rep[k];
            }
            i += patLen; // Move past the pattern in the input string
            flag = 1; // Pattern found
        } else {
            // Copy current character from input string to answer string
            ans[j++] = str[i++];
        }
    }

    ans[j] = '\0'; // Null-terminate the resultant string

    if (flag)
        printf("The resultant string is: %s\n", ans);
    else
        printf("Pattern string NOT found\n");
}

void getInput(char *str, int size, const char *prompt) {
    printf("%s", prompt);
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF && i < size - 1) {
        str[i++] = c;
    }
    str[i] = '\0'; // Null-terminate the string
}int main() {
    char str[100], pat[50], rep[50], ans[200];

    getInput(str, sizeof(str), "Enter the main string: ");
    getInput(pat, sizeof(pat), "Enter the pattern string: ");
    getInput(rep, sizeof(rep), "Enter the replacement string: ");

    replacePattern(str, pat, rep, ans);

    return 0;
}
