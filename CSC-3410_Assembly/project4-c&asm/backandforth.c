#include <stdio.h>
#include <unistd.h>

extern int addstr(char *a, char *b);

extern int is_palindromeASM(char *s);

extern int factstr(char *s);
int fact(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result = result * i;
    }
    return result;
}

extern void palindrome_check();
int is_palindromeC(char *s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // is NOT a palindrome
            return 0;
        }
        left++;
        right--;
    }
    // is a palindrome
    return 1;
}

int main() {
    // --- Menu --- //
    char menuChoice[4];
    printf("Select an option:\n");
    printf("\t1. Add two numbers together\n");
    printf("\t2. Test if a string is a palindrome (C -> ASM)\n");
    printf("\t3. Print the factorial of a number\n");
    printf("\t4. Test if a string is a palindrome (ASM -> C)\n");
    printf("\t0. Exit\n");
    // Note: Learned this form of safe input from research (Copilot suggested it)
    if (!fgets(menuChoice, sizeof menuChoice, stdin)) {
        fprintf(stderr, "Error reading input, exiting program\n");
        return 1;
    }

    switch (menuChoice[0]) {
    case '1':
        // --- Part 1 --- //
        char intStr1[4];
        char intStr2[4];
        printf("Enter first number: ");
        if (!fgets(intStr1, sizeof intStr1, stdin)) {
            fprintf(stderr, "Error reading input, exiting program\n");
            return 1;
        }
        printf("Enter second number: ");
        if (!fgets(intStr2, sizeof intStr2, stdin)) {
            fprintf(stderr, "Error reading input, exiting program\n");
            return 1;
        }

        printf("Result: %d\n", addstr(intStr1, intStr2));
        break;

    case '2':
        // --- Part 2 --- //
        char strPal[256];
        printf("Enter some text: ");
        if (!fgets(strPal, sizeof strPal, stdin)) {
            fprintf(stderr, "Error reading input, exiting program\n");
            return 1;
        }

        if (is_palindromeASM(strPal)) {
            printf("✔ %s is a palindrome\n", strPal);
        } else {
            printf("✘ %s is NOT a palindrome\n", strPal);
        }
        break;

    case '3':
        // --- Part 3 --- //
        char intFact[64];
        printf("Enter a number to calculate factorial: ");
        if (!fgets(strPal, sizeof strPal, stdin)) {
            fprintf(stderr, "Error reading input, exiting program\n");
            return 1;
        }
        printf("The factorial is: %d\n", factstr(intFact));
        break;

    case '4':
        // --- Print 4 --- //
        palindrome_check();
        break;

    case '0':
        printf("Exiting program\n");
        return 0;

    default:
        printf("Invalid option selected, exiting program\n");
        return 1;
    }

    return 0;
}