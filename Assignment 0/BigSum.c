#include <stdio.h>

int main() {
    char s1[1001] = "", s2[1001] = "";
    int len1 = 0,len2 = 0;
    int carry = 0;
    int diff = 0;
    int resLength = 0, n, resIndex = 0;

    scanf("%s\n%s", s1, s2);

    for(int i = 0; s1[i] != '\0'; i++) {
        len1++;
    }

    for(int i = 0; s2[i] != '\0'; i++) {
        len2++;
    }

    // set the resLength, to max(len1,len2) + 1
    resLength = len1 > len2 ? len1 + 1 : len2 + 1;
    // set one place more due to a possible carry
    char res[resLength];

    // set everything to zero
    for(int i = 0; i <= resLength - 1; i++) {
        res[i] = '0';
    }

    /*
        We start from the end of the strings adding number by number
    */
    for(int i = len1 - 1, j = len2 - 1; (i >= 0) || (j >= 0) || carry ; i--, j--) {
        // n is the sum of the current digits at index + the carry over
        // s1[i] - '0' actually converts from char to int
        int n1 = i >= 0 ? (s1[i] - '0') : 0;
        int n2 = j >= 0 ? (s2[j] - '0') : 0;
        n = n1 + n2 + carry;

        resIndex = len1 > len2 ? resLength - (len1 - i) : resLength - (len2 - j);
        // the digit at 1's place is copied but the rest is sent over to carry
        int r = n % 10;
        // '0' + r converts integer r to char
        res[resIndex] = '0' + r;
        carry = n / 10;
    }

    int isPrinted = 0;

    for(int i = 0; i < resLength; i++) {
        // we ignore zeros until the number is printed
        if(!isPrinted && res[i] == '0')
            continue;

        // if a number is not zero, we set isPrinted to 1. and print the characters from now on whether 0 or non zero.
        isPrinted = 1;
        printf("%c", res[i]);
    }
}