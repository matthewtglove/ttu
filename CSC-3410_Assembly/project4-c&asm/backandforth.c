#include <stdio.h>
#include <unistd.h>

int addstr(char *a, char *b);

int is_palindromeASM(char *a, char *b);

int factstr(char *s);
int fact(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result = result * i;
    }
    return result;
}

void palindrome_check();
int is_palindromeC(char *s);

int main() {
    // --- Menu --- //
    char menuChoice[4];
    printf("Select an option:\n");
    printf("\t1. Add two numbers together\n");
    printf("\t2. Test if a string is a palindrome (C -> ASM)\n");
    printf("\t3. Print the factorial of a number\n");
    printf("\t4. Test if a string is a palindrome (ASM -> C)\n");
    printf("\t0. Exit\n");
    if (!fgets(menuChoice, sizeof menuChoice, stdin)) {
        fprintf(stderr, "Error reading input, exiting program\n");
        return 1;
    }

    switch (menuChoice[0]) {
    case '1':
        // --- Part 1 --- //
        char str1[256];
        char str2[256];
        printf("Enter first number: ");
        if (fgets(str1, sizeof str1, stdin)) {
        }
        printf("Resulting string from adding two together: %s\n", addstr(str1, str2));
        break;
    case '2':
        // --- Part 2 --- //
        // Get string from user
        if (is_palindromeASM(strPal)) {
            printf("✘ %s is NOT a palindrome\n", strPal);
        } else {
            printf("✔ %s is NOT a palindrome\n", strPal);
        }
        break;
    case '3':
        // --- Part 3 --- //
        // Get int from user
        printf("The factorial is: %d\n", fact(factstr(intFact)));
        break;
    case '4':
        // --- Print 4 --- //
        // Get input from user ASM with palindrome_check();
        if (is_palindromeC(strPal2)) {
            printf("✘ %s is NOT a palindrome\n", strPal2);
        } else {
            printf("✔ %s is NOT a palindrome\n", strPal2);
        }
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