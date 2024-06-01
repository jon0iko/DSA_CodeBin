#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return; // Base case: if start >= end, the string is reversed
    }

    // Swap the characters at the start and end positions
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively reverse the substring between start and end
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

   // printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    reverseString(str, 0, length - 1);

    printf("Reversed string: %s\n", str);

    return 0;
}
