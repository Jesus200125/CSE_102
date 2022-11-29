#include"stdio.h"
#include"math.h"
#define PI 3.14
enum shapes{Triangle,Quadrilateral,Circle,Pyramid,Cylinder};
enum calculators{Area,Perimeter,Volume};

int select_shape( ){ // in this function shapes selected

  int input1;// this used to take input from user for shapes
  int temp1;
  printf("\nWelcome to the geometric calculator!\n");
  printf("\nSelect a shape to calculate:\n");
  printf("-------------------------------\n");
  printf("1. Triangle\n");
  printf("2. Quadrilateral\n");
  printf("3. Circle\n");
  printf("4. Pyramid\n");
  printf("5. Cylinder\n");
  printf("0. Exit\n");
  printf("-------------------------------\n");
  printf("Input:");
  if(scanf("%d",&input1)){
    while(getchar() != '\n');
    return input1;
  }
  else{
    printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
    while(getchar() != '\n'); // this is used to clean buffer
  }
}
int select_calc( ){ // in this function selected area,perimeter or volume
  int input2;
  int temp2;
  printf("\nSelect a calculator:\n");
  printf("-------------------------------\n");
  printf("1. Area\n");
  printf("2. Perimeter\n");
  printf("3. Volume\n");
  printf("0. Exit\n");
  printf("-------------------------------\n");
  printf("Input:");
  if(scanf("%d",&input2)) //here we took string value and we change it to integer value below
  return input2;
  else{
    printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
    while(getchar() != '\n'); // this is used to clean buffer
  }
}
// this function calculate triangle area perimeter and volume
int calc_triangle(int selectcalc){  // THIS FUNCTION CALCULATE TRIANGLE
  float a,b,c; // this variables used for area
  float s=0,heronfor=0; // these variables used for area formula
  float x,y,z; // this variables used for perimetre
  int loop,i,j;
  switch(selectcalc){
    case Area+1: // here we calculate area
      printf("Please enter three sides of triangle:\n");
      do{
        if(scanf("%f %f %f",&a,&b,&c)){ // here for calculating area of triangle taken value of sides from user
          if(a>0 && b>0 && c>0){ // here controlled variables smaller than zero or not
            s=(a+b+c)/2;
            heronfor=sqrt(s*(s-a)*(s-b)*(s-c)); //here herons formula used for area
            if(a+b > c && a+c > b && b+c  > a){
              printf("Area of triangle:%.2f\n\n",heronfor);// here printed area of triangle
              i=2;
            }
            else{
              printf("ERROR! Please enter a valid triangle\n");// if sides of triangle are not suitable for triangle this will work
              i=0;
            }
          }
          else{
            printf("Error! Please enter a valid entry\n"); // one of sides are smaller than zero this will work
            while(getchar() != '\n');
            i=0;
          }
        }
        else{
          printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
          while(getchar() != '\n'); // this is used to clean buffer
          i=0;
        }
       }while(i<1); break;
    case Perimeter+1: // here calculated perimet of triangle
      printf("Please enter three sides of triangle:\n");
      do{
        if(scanf("%f %f %f",&x,&y,&z)){// here inputs taken for Perimeter
          if(x>0 && y>0 && z>0){ // here controlled variables smaller than zero or not
            if(x+y > z && x+z > y && y+z  > x){ // here controlled variables true or not for triangle
            printf("Perimetre of Triangle:%.2f\n",(x+y+z));
            j=2;
            }
            else{
            printf("ERROR! Please enter a valid triangle\n"); // if variables are not suitable for triangle this will work
            j=0;
            }
          }
          else{
            printf("Error! Please enter a valid entry\n"); // one of sides are smaller than zero this will work
            while(getchar() != '\n');
            j=0;
          }
         }
         else{
            printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
            while(getchar() != '\n'); // this is used to clean buffer
            j=0;
         }
      }while(j<1); break;
    case Volume+1:
      printf("ERROR! You cannot calculate the volume of a triangle.Please try again!\n\n");
      break;
  }
}
int calc_pyramid(int selectcalc){  // THIS FUNCTION CALCULATE PYRAMID
  float height,side; // these are used to calculate area of pyrmid
  float height1,side1,volume; // these are used to calculte volume of pyramid
  float side2,perimeter; // these are used to calculate perimeter of pyramid
  int i,j,k; // these used to loops
  float base_surface_area,lateral_surface_area,surface_area; // these are used to base,lateral and surface area
  switch(selectcalc){
    case Area+1:
      printf("Please enter the base side and slant height of the pyramid:\n");
      do{
        if(scanf("%f %f",&side,&height)){
          if(side > 0 && height > 0){ // here controlled variables smaller than zero or not
            base_surface_area=(side*side); // here used base surface formula for area of pyramid
            lateral_surface_area=2*side*height; // here lateral surface formula used for area of pyramid
            surface_area=base_surface_area+lateral_surface_area; // here add base and lateral surfaces
            printf("Base surface area of a pyramid:%.2f\n",base_surface_area);
            printf("Lateral surface area of a pyramid:%.2f\n",lateral_surface_area);
            printf("Surface area of a pyramid:%.2f\n",surface_area);
            i=2;
          }
          else{
            printf("Error! Please enter a valid entry\n"); // height or side equal to zero this will work
            while(getchar() != '\n');
            i=0;
          }
        }
        else{
          printf("Error! Please enter a valid entry\n"); // if values are not equal to integer value this will work
          while(getchar() != '\n'); // this is used to clean buffer
          i=0;
        }
      }while(i<1);  break;
    case Perimeter+1:
      printf("Please enter base side of pyramid:\n");
      do{
        if(scanf("%f",&side2)){
          if(side2 > 0){
            perimeter=4*side2;
            printf("Perimeter of pyramid:%.2f\n",perimeter);
            k=2;
          }
          else{
            printf("Error! Please enter a valid entry\n"); // height or side equal to zero this will work
            while(getchar() != '\n');
            k=0;
          }
        }
        else{
          printf("Error! Please enter a valid entry\n"); // if values are not equal to integer value this will work
          while(getchar() != '\n'); // this is used to clean buffer
          k=0;
        }
      }while(k<1); break;
    case Volume+1:
      printf("Please enter the base side and slant height of the pyramid:\n");
      do{
        if(scanf("%f %f",&side1,&height1)){ // side and height of pyramid is taken here for calculate volume
          if(side1>0 && height1>0){ // here controlled variables smaller than zero or not
            volume=(float)1/3*side1*side1*height1;
            printf("Volume of the pyramid:%.2f\n",volume);
            j=2;
          }
          else{
            printf("Error! Please enter a valid entry\n");
            j=0;
            while(getchar() != '\n');

          }
        }
        else{
          printf("Error! Please enter a valid entry\n");
          j=0;
          while(getchar() != '\n');

        }
      }while(j<1);
  }
}
int calc_quadrilateral(int selectcalc){ // THIS FUNCTION CALCULATE QUADRILATERAL
  float a,b,c,d; // this variables used for area
  float s=0,brahmafor=0;
  float x,y,z,k; // this variables used for perimetre
  int i,j;
  switch(selectcalc){
    case Area+1:
      printf("Please enter four sides of quadrilateral:\n");
      do{ // THIS LOOP WORK TILL FIND AREA OF QUADRILATERAL
        if(scanf("%f %f %f %f",&a,&b,&c,&d)){// here for calculating area of quadrilateral taken value of sides from user
          if(a>0 && b>0 && c>0 && d>0){ // HERE CONTROLLED VALUES BIGGER THAN ZERO OR NOT
            s=(a+b+c+d)/2;
            brahmafor=sqrt((s-a)*(s-b)*(s-c)*(s-d)); //here brahmagupta's formula used for area
            printf("Area of quadrilateral:%.2f\n",brahmafor); // here printed area
            i=2;
          }
          else{
            printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT BIGGER THAN ZERO THIS WILL WORK
            while(getchar() != '\n');
            i=0;
          }
        }
        else{
          printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
          while(getchar() != '\n'); // THIS IS FOR THAT CLEAN BUFFER
          i=0;
        }
      }while(i<1); break;
    case Perimeter+1:
      printf("Please enter four sides of quadrilateral:\n");
      do{
        if(scanf("%f %f %f %f",&x,&y,&z,&k)) // here inputs taken for Perimeter
          if(x>0 && y>0 && z>0 && k>0){ // HERE CONTROLLED VALUES BIGGER THAN ZERO OR NOT
            printf("Perimetre of Triangle:%.2f\n",(x+y+z+k));
            j=2;
          }
          else{
            printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT BIGGER THAN ZERO THIS WILL WORK
            while(getchar() != '\n');
            j=0;
          }
        else{
          printf("Error! Please enter a valid entry\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
          while(getchar() != '\n'); // THIS IS USED TO CLEAN BUFFER
          j=0;
        }
      }while(j<1); break;
      case Volume+1:
        printf("ERROR! You cannot calculate the volume of a quadrilateral.Please try again!\n");
        break;
  }
}
int calc_circle(int selectcalc){
  int i,j;
  float radius,perimeter;
  float area_circle,perimeter_circle;
  switch(selectcalc){
    case Area+1:
      printf("Please enter radius of the circle:\n");
      do{
        if(scanf("%f",&radius)){
          if(radius>0){
            area_circle=(float)PI * radius * radius; // this area formula for circle
            printf("Area of circle:%.2f\n\n",area_circle);
            i=2;
          }
          else{
            printf("Error! Please enter a valid entry\n\n"); // IF VALUES ARE NOT BIGGER THAN ZERO THIS WILL WORK
            while(getchar() != '\n');
            i=0;
          }
        }
        else{
          printf("Error! Please enter a valid entry\n\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
          while(getchar() != '\n'); // THIS IS USED TO CLEAN BUFFER
          i=0;
        }
      }while(i<1); break;
    case Perimeter+1:
      printf("Please enter perimeter of the circle:\n\n");
      do{
        if(scanf("%f",&perimeter)){
          if(perimeter>0){
            perimeter_circle=(float)2*PI*perimeter;
            printf("Perimeter of the circle:%.2f\n\n",perimeter_circle);
            j=2;
          }
          else{
            printf("Error! Please enter a valid entry\n\n"); // IF VALUES ARE NOT BIGGER THAN ZERO THIS WILL WORK
            while(getchar() != '\n');
            j=0;
          }
        }
        else {
          printf("Error! Please enter a valid entry\n\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
          while(getchar() != '\n'); // THIS IS USED TO CLEAN BUFFER
          j=0;
        }
      }while(j<1); break;
    case Volume+1:
      printf("ERROR! You cannot calculate the volume of a circle.Please try again!\n\n");
      break;
  }
}
int calc_cylinder(int selectcalc){
   float base_surface_area,lateral_surface_area,surface_area,volume,perimeter; // these variables used for area,volume and perimeter
   int i,j,k; // these used for loops
   float radius,height; // these are used to calculate area
   float radius2,height2; // these are used to calculate perimeter
   float radius3,height3; // these are used to calculate volume
   switch(selectcalc){
     case Area+1:
       printf("Please enter the radius and height of a Cylinder:\n");
       do{
         if(scanf("%f",&radius)){
           if(scanf("%f",&height)){
             if(radius>0 && height>0){
               base_surface_area=PI*radius*radius; // base surface formula used here
               lateral_surface_area=2*PI*radius*height; // lateral surface formula used here
               surface_area=2*PI*radius*(radius+height); // surface area formula used here
               printf("Base surface area of a pyramid:%.2f\n",base_surface_area);
               printf("Lateral surface area of a pyramid:%.2f\n",lateral_surface_area);
               printf("Surface area of a pyramid:%.2f\n\n",surface_area);
               i=2;
               while(getchar() != '\n'); // this is used to clean buffer
             }
             else{
               printf("Error! Please enter a valid entry\n"); // height or side equal to zero this will work
               while(getchar() != '\n');
               i=0;
             }
           }
           else{
             printf("Error! Please enter a valid entry\n"); // if values are not equal to integer value this will work
             while(getchar() != '\n'); // this is used to clean buffer
               i=0;
             }
          }
         else{
           printf("Error! Please enter a valid entry\n\n"); // if values are not equal to integer value this will work
           while(getchar() != '\n'); // this is used to clean buffer
           i=0;
         }
       }while(i<1); break;
     case Perimeter+1:
       printf("Please enter the radius and height of a Cylinder:\n");
       do{
         if(scanf("%f",&radius2)){
           if(scanf("%f",&height2)){
             if(radius2 > 0 && height2 > 0){
              perimeter=2*PI*radius2;
              printf("Perimeter of Cylinder:%.2f\n",perimeter);
              j=2;
             }
             else{
               printf("Error! Please enter a valid entry\n\n"); // height or side equal to zero this will work
               while(getchar() != '\n');
               j=0;
             }
           }
           else{
             printf("Error! Please enter a valid entry\n\n"); // if values are not equal to integer value this will work
             while(getchar() != '\n'); // this is used to clean buffer
             j=0;
           }
         }
         else{
           printf("Error! Please enter a valid entry\n\n"); // if values are not equal to integer value this will work
           while(getchar() != '\n'); // this is used to clean buffer
           j=0;
         }
       }while(j<1); break;
     case Volume+1:
       printf("Please enter the radius and height of a Cylinder:\n");
       do{
         if(scanf("%f %f",&radius3,&height3)){
           if(radius3>0 && height3>0){
             volume=PI*radius3*radius3*height3;
             printf("Volume of a cylinder:%.2f\n\n",volume);
             k=2;
           }
           else{
             printf("Error! Please enter a valid entry\n\n"); // height or side equal to zero this will work
             k=0;
           }
         }
         else{
           printf("Error! Please enter a valid entry\n\n"); // IF VALUES ARE NOT INTEGER THIS WILL WORK
           while(getchar() != '\n'); // THIS IS USED TO CLEAN BUFFER
           k=0;
         }
       }while(k<1); break;
   }
}
int calculate(int (*shape)( ), int (*calc)( )){

  int a,i=1,b=0; // these are used to loops
  int selectshape=0,selectcalc=0; // these used to call shape and calc functions
  do{
   do{
    i=3;
    selectshape=shape();
    if(selectshape == 0)  return 0;
    if( selectshape != 1 && selectshape != 2 && selectshape != 3 && selectshape != 4 && selectshape != 5 ){
      printf("\nError entered wrong number\n\n");
      i=1;
    }
    }while(i<2);
   do{
    a=3;
    selectcalc=calc();
    if(selectcalc == 0)  return 0;
    if(selectcalc != 1 && selectcalc != 2 && selectcalc != 3){
      printf("\nError entered wrong number\n\n");
      a=1;
    }
   }while(a<2); //printf("%d",calc_triangle(selectcalc));
    switch(selectshape){
     case 0:
       return 0;
     case Triangle+1: // here used enums but enum starts zero so we add 1 for all enums
       calc_triangle(selectcalc);
       break;
     case Quadrilateral+1:
       calc_quadrilateral(selectcalc);
       break;
     case Circle+1:
       calc_circle(selectcalc);
       break;
     case Pyramid+1:
       calc_pyramid(selectcalc);
       break;
     case Cylinder+1:
       calc_cylinder(selectcalc);
       break;
    }
  }while(b<1);
}

int main() {

  calculate(select_shape, select_calc);

}
