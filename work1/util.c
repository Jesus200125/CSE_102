#include"stdio.h"
#include"stdlib.h"
#include <string.h>

// this function used to find first divisible number

int find_divisible(int x, int y, int z){

   int min,max,i;
   
   //here compared to find big number
   
   if ( x > y ) {

    min=y;

    max=x;

    }

   else {

    min=x;

    max=y;

    }

    // here found first divisible number 

   for( i = min+1; i < max; i++) {

    if ( i % z == 0) {

     return i;

     }

     }

     return -1;

     }

// here found next number

int find_nth_divisible(int a, int b, int c) {

   a*=c;

   b+=a;

   return b;

    }

// this function used to validate identity number

int validate_identity_number(char tcno[11]) {

  int a=0;
  int x=0;
  int y,z,temp;

  // first rule first number cannot be zero

  if ( tcno[a]-48 == 0 )

   return -1;

  // second rule calculate 10th number like this

  while( a < 10 ) {

  x += tcno[a]-48;

  a++;

   }

  x = x%10;
  y = tcno[10]-48;

  if ( x != y )

   return -1;

  int oddnumbers=0;

  a=0;

  while(a<9){

  oddnumbers += tcno[a]-48;

  a += 2;

   }

  int valueodd = oddnumbers;

  oddnumbers *= 7;

  int couplenumbers=0;

  a=1;

  while(a<8) {

  couplenumbers += tcno[a]-48;

  a += 2;

   }

  couplenumbers *= 9;

  z = (oddnumbers + couplenumbers) % 10;

  temp = tcno[9]-48;

  if ( z != temp )

   return -1;
   
  // third rule found 11th number

  int b = ( valueodd*8 ) % 10;

  if( b != y )

   return -1;

  return 1;

  }

// here password and identity number written to a file

int creat_customer(char a[11], int b){

    FILE *temp;

    temp=fopen ("customeraccount.txt","w");

    fprintf(temp,"%s",a);

    fprintf(temp,"%d",b);

    fclose(temp);
 }

// in this function controlled login and identity number

int check_login(char x[11], int y){

    char a[11];
    int b=0;
    

    FILE *filep=fopen("customeraccount.txt","r+");
    
    char temp;
    int i=0, hundred=1000;
    
    while (i<11) {
      
     fscanf(filep,"%c",&a[i]);
     
     i++;
      
     }
     
     while (i<15) {
      
     fscanf(filep,"%c",&temp);
      
     b=b+((temp-48)*hundred);
     
     hundred/=10;
     
     i++;
      
     }

    if ( strcmp( a, x ) == 0 && b == y) {
     
     return 1;
      
     }
    
    else {
     
     return -1;
      
     }
 }
 
 // here controlled witdrawable money
 
int withdrawable_ammount(float ammount) {
  
    int temp = (int)ammount;
    temp -= (temp%10);
    
    return temp;
    
   }
