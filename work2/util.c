#include"stdio.h"
#include"math.h"
#include"util.h"

char dt1a(float a, float b){

  char virginica = 'T',versicolor = 'F',setosa = 'Z';

  if(a<2.45 && !b<1.75)

   return setosa;

  else {

    if(b<1.75 && !a<4.95)

     return virginica;

    else {

     if(a<4.95 && !b<1.65)

      return virginica;

     else{

       if(b<1.65)

        return versicolor;

       else

        return virginica;
    }
   }
  }
 }

char dt1b(float x, float y) {

char virginica = 'T',versicolor = 'F',setosa = 'Z';

  if(x<2.55 && !y<1.69)

   return setosa;

  else {

   if(y<1.69 && !x<4.85)

    return virginica;

   else {

    if(x<4.85)

     return versicolor;

    else

     return virginica;

   }
  }
 }

double dt2a(float a, float b, float c, int d, int e){

  if(a < 31.5) {

    if(b > -2.5)

     return 5;

    else {

     if(a - 0.1 <= c <= a + 0.1)

      return 2.1;

     else

      return -1.1;
     }
   }
   else {

    if(-1 <= c <= 2)

     return 1.4;

     else {

      if(d && e)

       return -2.23;

      else

       return 11;
      }
    }
  }

double dt2b(float a, float b, float c, int d, int e) {

  if(12 < a < 22) {

   if(c > 5/3)

    return -2;

   else {

    if(a - 0.1 <= c <= a + 0.1)

     return 1.01;

    else

     return -8;
      }
    }
  else {

   if(d && e)

    return -1;

   else {

    if(-1 <= b <= 2)

     return -1/7;

    else sqrt(2)/3;
      }
    }
  }

float dt3a(int a, int b, int c, char d[5], char e[5]) {

  if(a < b)

   if(a < 40)

    return 35;

   else {

    if(c && d)

     return 3;

    else

     return 4;

     }

  else {

    if(a > 50)

     return 0;

    else {

     if(d && e)

      return 4;

     else

      return 5;
      }
    }
  }
float dt3b(int a, int b, int c, char d[5], char e[5]) {

  if(30 < a < 60) {

   if(a < 40)

    return 30;

   else {

    if(c || d)

     return 13;

    else

     return 14;
     }
    }

  else {

   if(a < 50)

    return 40;

   else {

    if(d || e)

     return 14;

    else

     return 15;
      }
    }
  }
