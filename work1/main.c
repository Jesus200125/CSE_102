#include"stdio.h"
#include <string.h>
#include"util.h"

int main() {
    
    // here calculated first divisor after min number
    
   int number1,number2,divisor,nextnum,b2,c2;

   int value,max;

   printf("Enter the first integer:");

   scanf("%d",&number1);

   printf("Enter the second integer:");

   scanf("%d",&number2);

   printf("Enter the divisor:");

   scanf("%d",&divisor);

   if ( number1 > number2 ) {

     max=number1;

    }

   else {

   max=number2;

    }
   
   // here called function
   
   value = find_divisible(number1, number2, divisor);

   if( value == -1 ) {

    printf("there is no value");
    
    return 0;

    }

   else {

    printf("The first integer between %d and %d divided by %d is     %d\n",number1,number2,divisor,value);

    }

   printf("Enter the number how many next:");
   scanf("%d",&nextnum);

   // here fount next number

   b2 = find_nth_divisible(nextnum,value,divisor);

   if ( b2 > max ) {

    printf("you have entered big number\n");

    }

   else {

    printf("%d\n",b2);

    }

   //identity number //

   char identitynum[11];

   printf("Enter your identity number:");

   scanf("%s",identitynum);

   int temp = validate_identity_number(identitynum);

   if ( validate_identity_number(identitynum) == -1 ) {

   printf("wrong identity number");

    return 0;

    }


   int password;

   printf("Creat your pasword with four numbers:");
   scanf("%d",&password);

   int a=creat_customer(identitynum, password);

   // check identity number and password

   char tcnumber[11];
   int cardpassword;

   printf("Welcome please write identity number:");

   scanf("%s",tcnumber);

   printf("Enter your password:");

   scanf("%d",&cardpassword);

   if ( check_login(tcnumber, cardpassword) == -1 ) {

   printf("Identity number or password wrong!!!");

   return -1;

    }

   printf("Login succeed...\n");

   // withdraw money

   float money;
   int ammount;

   printf("How much do you wanna withdraw:");

   scanf("%f",&money);

   ammount = withdrawable_ammount(money);

   printf("Withdrawable amoount:%d",ammount);

    return 0;
}
