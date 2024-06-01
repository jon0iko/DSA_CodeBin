#include <stdio.h>
#include <string.h>

int isAlphanumeric(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

int toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a'; // Convert to lowercase
    }
    return c; // Return unchanged for non-uppercase characters
}

int isPalindrome(char *str, int start, int end) {
    if (start >= end) {
        return 1; // Base case: if start >= end, it's a palindrome
    }

    if (!isAlphanumeric(str[start])) {
        // Skip non-alphanumeric characters at the start
        return isPalindrome(str, start + 1, end);
    }

    if (!isAlphanumeric(str[end])) {
        // Skip non-alphanumeric characters at the end
        return isPalindrome(str, start, end - 1);
    }

    if (toLower(str[start]) != toLower(str[end])) {
        return 0; // Characters at start and end positions don't match (case-insensitive)
    }

    // Recursively check the next characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[1000];

    //printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int length = strlen(str);

    if (isPalindrome(str, 0, length - 1)) {
        printf("palindromic\n");
    } else {
        printf("not palindromic\n");
    }

    return 0;
}
