# CSE_102
cse projects
#include <stdio.h>

int main() {
    int num1, num2, tempNum2, digit, multiplier = 1, product, carry = 0, sum = 0;

    printf("1. sayiyi girin: ");
    scanf("%d", &num1);
    printf("2. sayiyi girin: ");
    scanf("%d", &num2);

    tempNum2 = num2;

    printf("%*d\n", 3, num1);
    printf("%*d\n", 3, num2);
    printf("  ---\n");

    while (tempNum2 > 0) {
        digit = tempNum2 % 10;
        tempNum2 /= 10;

        product = num1 * digit + carry;

        if (product > 9) {
            carry = product / 10;
            product %= 10;
        } else {
            carry = 0;
        }

        sum += product * multiplier;
        printf("%*d\n", 3+multiplier, num1 * digit);

        multiplier *= 10;
    }

    if (carry > 0) {
        sum += carry * multiplier;
        printf("%*d\n", 3+multiplier, carry * multiplier);
    }

    printf("  ---\n");
    printf("%*d", 3+multiplier, sum);

    return 0;
}
