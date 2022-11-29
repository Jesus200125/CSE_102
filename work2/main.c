#include"stdio.h"
#include"math.h"
#include"util.h"
#include"stdlib.h"

int main() {

  int problem;
  float PL,PW,SL,SW;
  float x1,x2,x3;
  int x4,x5;
  int all,capa,boy;
  char girl[5],teac[5];

// ask to user choose a problem

  printf("Select 1th, 2th or 3th problem: ");
  scanf("%d",&problem);

// this is for first function

  if(problem == 1) {

    printf("Enter PL:");
    scanf("%f",&PL);
    printf("Enter PW:");
    scanf("%f",&PW);

// here compared output of first function and write it

    if(dt1a(PL,PW) == 'T')

     printf("Answer of dt1a is Virginica\n");

    else if(dt1a(PL,PW) == 'F')

     printf("Answer of dt1a is Versicolor\n");

    else

     printf("Answer of dt1a is Setosa\n");

    if(dt1b(PL,PW) == 'T')

     printf("Answer of dt1b is Virginica\n");

    else if(dt1b(PL,PW) == 'F')

     printf("Answer of dt1b is Versicolor\n");

    else

     printf("Answer of dt1b is Setosa\n");

    if(dt1a(PL,PW) == dt1b(PL,PW))

     printf("Answer of dt1a and dt1b are same");

    else

     printf("Answer of dt1a and dt1b are different");

   }

// this for second problem

  else if(problem == 2) {

    printf("Enter a real number:");
    scanf("%f",&x1);
    printf("Enter a real number:");
    scanf("%f",&x2);
    printf("Enter a real number:");
    scanf("%f",&x3);
    printf("Enter a binary number no longer 5 numbers:");
    scanf("%d",&x4);
    printf("Enter a binary number no longer 5 numbers:");
    scanf("%d",&x5);

    float temp3 = dt2a(x1, x2, x3, x4, x5);
    float temp4 = dt2b(x1, x2, x3, x4, x5);

// here controlled output of 3 and 4 functions close to 0.001

    if(abs(temp3-temp4) != 0.001 && abs(temp3-temp4) != 0.011) {

     if(temp3 == temp4) {

      printf("Answer of dt2a and dt2b are same\n");
      printf("Answer of dt2a:%.2f\n",temp3);
      printf("Answer of dt2b:%.2f\n",temp4);

       }

    else {

      printf("Answer of dt2a and dt2b are different\n");
      printf("Answer of dt2a:%.2f\n",temp3);
      printf("Answer of dt2b:%.2f\n",temp4);

       }
     }

     else {

       if(temp3 == temp4) {

        printf("Answer of dt2a and dt2b are same\n");
        printf("Answer of dt2a and dt2b:%f\n",(float)abs(temp3-temp4)/2);

         }

      else {

        printf("Answer of dt2a and dt2b are different\n");
        printf("Answer of dt2a and dt2b:%f\n",(float)abs(temp3-temp4)/2);

         }
       }
     }

// here 5th and 6th function's inputs taken

  else {

    printf("Enter all people:");
    scanf("%d",&all);
    printf("Enter all capacity:");
    scanf("%d",&capa);
    printf("Enter all boys:");
    scanf("%d",&boy);
    printf("Enter all girls:");
    scanf("%s",girl);
    printf("Enter all teachers:");
    scanf("%s",teac);

    float temp5=dt3a(all, capa, boy, girl, teac);
    float temp6=dt3b(all, capa, boy, girl, teac);

    if(temp5 == temp6) {

      printf("Answer of dt3a and dt3b are same\n");
      printf("Answer of dt3a:%.2f\n",temp5);
      printf("Answer of dt3b:%.2f\n",temp6);

      }

    else {

      printf("Answer of dt3a and dt3b are different\n");
      printf("Answer of dt3a:%.2f\n",temp5);
      printf("Answer of dt3b:%.2f\n",temp6);

     }
   }
  return 0;
  }
