#include<stdio.h>

int main(){
  int a,b,z=1;
  float a1=0,a2=0,b1=0,b2=0;
  float x1=0,x2=0,y1=0,y2=0;
  float class1_avx=0,class2_avx=0,class1_avy=0,class2_avy=0;
  float midx=0,midy=0,m1=0,m2;
  float inputx=0,inputy=0;
  printf("Enter the cordinates for class 1:\n"); // here taken cordinates for class 1
  for(a=0; a<10; a++){
    scanf("%f  %f",&a1,&b1);
    x1=x1+a1; // here calculated sum of x
    y1=y1+b1; // here calculated sum of y
    a1=0;
    b1=0;
  }
  class1_avx=x1/(a+1); // here calculated avarage of x for class1
  class1_avy=y1/(a+1);  // here calculated avarage of y for class1
  printf("Enter the cordinates for class 2:\n"); // here taken cordinates for class 2
  for(a=0; a<10; a++){
    scanf("%f  %f",&a2,&b2);
    x2=x2+a2; // here calculated sum of x2
    y2=y2+b2; // here calculated sum of x2
    a2=0;
    b2=0;
  }
  class2_avx=x2/(a+1); // here calculated avarage of x for class2
  class2_avy=y2/(a+1); // here calculated avarage of y for class2
  midx=(class1_avx+class2_avx)/2; // here found midpoint x
  midy=(class1_avy+class2_avy)/2; // here found midpoint y
  m1=(y1-y2)/(x1-x2); // here found slope 1
  m2=(-1)/m1; //here found slope 2
  printf("Enter test point:\n");
  while( scanf("%f",&inputx) == 1 && scanf("%f",&inputy) == 1){
    if(inputy>(m2*(inputx-midx)+midy) && class1_avy>(m2*(class1_avx-midx)+midy)){
      printf("CLASS 1\n");
    }
    else if(inputy<(m2*(inputx-midx)+midy) && class1_avy<(m2*(class1_avx-midx)+midy)){
      printf("CLASS 1\n");
    }
    else
      printf("CLASS 2\n");
    printf("Enter test point:\n");
  }
}
