#include"stdio.h"
void print_file(int n, int m, int d){

   printf("Coefficients has been read from the Coefficients file.\n");
   printf("The graph of x=%d*(y*y)+%d*y+%d has been written to graph.txt file\n",n,m,d);
   int loop1,loop2,x,y,z;
   FILE *fp=fopen("graph.txt","w+");
   for(loop1=16; loop1>=-15; loop1--){
     for(loop2=-55; loop2<=55; loop2++){
      if(loop1 == 0 && loop2 == -55)
        fprintf(fp,"<");
      else if(loop1 == 0 && loop2 == 55)
        fprintf(fp,">");
      else if(loop2 == 0 && loop1 == 16)
        fprintf(fp,"^");
      else if(loop2 == (n*loop1*loop1)+(m*loop1)+d)
        fprintf(fp,"#");
      else if(loop2 == 0)
        fprintf(fp,"|");
      else if(loop1 == 0)
        fprintf(fp,"-");
      else
        fprintf(fp," ");
      }
      fprintf(fp,"\n");
    }
   fclose(fp);
  }
int main(){

   int loop1,loop2,loop3,i,a,b,c,choise,x,y,z;
   FILE *file=fopen("a.txt","a+");
   for(i=1; i>0; i++){

      printf("Select an operation...:\n");
      printf("0 -> Enter the coefficients.\n");
      printf("1 -> Draw the graph.\n");
      printf("2 -> Print the graph into a.txt file.\n");
      printf("3 -> Exit.\n");
      printf("Choise:");
      scanf("%d",&choise);
      switch(choise){

        case 0:
          printf("Please enter the coefficient for the following equation: x=a(y*y)+b*y+c\n");
          printf("a:");
          scanf("%d",&a);
          printf("b:");
          scanf("%d",&b);
          printf("c:");
          scanf("%d",&c);
          printf("Coefficients.txt file has been created.\n");
          fprintf(file,"%d\n",a);
          fprintf(file,"%d\n",b);
          fprintf(file,"%d",c);
          fclose(file);
          break;
        case 1:
          printf("Coefficients has been read from the Coefficients.txt file.\n");
          file=fopen("a.txt","r");
          fscanf(file,"%d",&x);
          fscanf(file,"%d",&y);
          fscanf(file,"%d",&z);
          fclose(file);
          printf("Printing the graph of x=%d*(y*y)+%d*y+%d\n",x,y,z);
          for(loop1=16; loop1>=-15; loop1--){
            for(loop2=-55; loop2<=55; loop2++){
               if(loop1 == 0 && loop2 == -55)
                 printf("<");
               else if(loop1 == 0 && loop2 == 55)
                 printf(">");
               else if(loop2 == 0 && loop1 == 16)
                 printf("^");
               else if(loop2 == (x*loop1*loop1)+(y*loop1)+z){
                 printf("\033[0;34m");
                 printf("#");
                 printf("\033[0m"); }
               else if(loop2 == 0)
                 printf("|");
               else if(loop1 == 0)
                 printf("-");
               else if(loop1 == 15 && loop2 == 3){
                 printf("\033[0;33m");
                 printf("\b15");
                 printf("\033[0m"); }
               else if(loop1 == 10 && loop2 == 3){
                 printf("\033[0;33m");
                 printf("\b10");
                 printf("\033[0m"); }
               else if(loop1 == 5 && loop2 == 3){
                 printf("\033[0;33m");
                 printf("5");
                 printf("\033[0m"); }
               else if(loop1 == -15 && loop2 == 4){
                 printf("\033[0;33m");
                 printf("\b\b-15");
                 printf("\033[0m"); }
               else if(loop1 == -10 && loop2 == 4){
                 printf("\033[0;33m");
                 printf("\b\b-10");
                 printf("\033[0m"); }
               else if(loop1 == -5 && loop2 == 4){
                 printf("\033[0;33m");
                 printf("\b-5");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -50){
                 printf("\033[0;33m");
                 printf("\b\b-50");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -40){
                 printf("\033[0;33m");
                 printf("\b\b-40");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -30){
                 printf("\033[0;33m");
                 printf("\b\b-30");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -20){
                 printf("\033[0;33m");
                 printf("\b\b-20");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -10){
                 printf("\033[0;33m");
                 printf("\b\b-10");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == 50){
                 printf("\033[0;33m");
                 printf("\b50");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == 40){
                 printf("\033[0;33m");
                 printf("\b40");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == 30){
                 printf("\033[0;33m");
                 printf("\b30");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == 20){
                 printf("\033[0;33m");
                 printf("\b20");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == 10){
                 printf("\033[0;33m");
                 printf("\b10");
                 printf("\033[0m"); }
               else if(loop1 == -1 && loop2 == -2){
                 printf("\033[0;33m");
                 printf("0");
                 printf("\033[0m"); }
               else
                 printf(" ");
              }
            printf("\n");
          } break;
        case 2:
           print_file(a,b,c);
           break;
        case 3:
           return 0;
        default :
           printf("Wrong Choise !!!\n"); break;
        }
      }
    }
