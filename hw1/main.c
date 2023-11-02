#include<stdio.h>

int gcd()
{
    int num1, num2, result=1, temp, i=1;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    if(num1<num2)  temp=num1;
    else  temp=num2;
    while(i<=temp){
        if(num1%i == 0 && num2%i == 0) result=i;
        i++;
    }
    printf("GCD of %d and %d is %d\n", num1, num2, result);
}
int sum_function()
{
    int num1, num2, result=1, temp, i=1;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    temp=num1+num2;
    printf("Result:\n");
    printf("%7d\n",num1);
    printf("%7d\n",num2);
    printf("+_________\n");
    printf("%7d\n",temp);

}
int multip()
{
    int a, b;
    printf("Enter first number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    int row1 = a * (b % 10);
    int row2 = a * (b / 10 % 10);
    int row3 = a * (b / 100);
    int result = a * b;
    printf("Result:\n");
    printf("%7d\n", a);
    printf("%7d\n", b);
    printf("*-------\n");
    printf("%7d\n", row1);
    printf("%6d\n", row2);
    if(row3 != 0)   printf("%5d\n", row3);
    printf("+-----\n");
    printf("%7d\n", result);

}
int function()
{
    int a,b;
    printf("Enter an integer number between 1 and 10:");
    scanf("%d",&a);
    if(1 <= a && a <= 5)   printf("Entered number is less than or equal to 5\n");
    else if(a > 5 && a <= 10)   printf("Entered number greater than 5\n");
    else  printf("Invalid input\n");
}
int main(){

    int a;
    printf("Part 1\n");
    printf("Part 2\n");
    printf("Part 3\n");
    printf("Part 4\n");
    printf("Exit 0\n");
    printf("Choose a Part:\n");
    scanf("%d",&a);
    while(a != 0)
    {
      if( a == 1 )   gcd();
      else if( a == 2 )  sum_function();
      else if( a == 3 )  multip();
      else if( a == 4 )  function();
      printf("Part 1\n");
      printf("Part 2\n");
      printf("Part 3\n");
      printf("Part 4\n");
      printf("Exit 0\n");
      printf("Choose a Part:\n");
      scanf("%d",&a);
    }
  return 0;
}
