#include<stdio.h>
#include <time.h>
#include<stdlib.h>

void menu_print()  // this function just print menu read from menu txt file
{
  FILE *fp;
  fp=fopen("menu.txt","r");
  int i=0;
  char A;
  float price;
  printf("Product\n\n");
  while(i<10)
  {
    printf("%d.  ",i+1);
    while(fscanf(fp,"%c",&A) == 1 && A != ' ') // here read characters one to one
    {
      printf("%c",A);
    }
    while(fscanf(fp,"%f",&price) == 1 && price != '\n') { }  // here read price

    printf("\n" );
    i++;
  }
  fclose(fp);
}
void print_order() // this function just print order when user enter 0
{
  FILE *fp;
  char A;
  fp=fopen("order.txt","r");
  while(fscanf(fp,"%c",&A) != EOF)
  {
    if(A != '\n')  printf("%c",A);
    else  printf("\n");
  }
}
void take_meal()  // this function take order from user and write it other txt file
{
  menu_print();  // here called menu function
  FILE *fp;
  FILE *fb;
  fp=fopen("menu.txt","r");
  fb=fopen("order.txt","w+");
  if (fb == NULL) {  // if file doesnt open
  printf("Error opening order.txt file for writing\n");
}
  int i=9,j=-1,k=0,meal=-1,service;
  float total=0.0,price,student_discount=0.0,discount=0.0,vat=0.0;
  char A,student;
  time_t now = time(NULL);
  struct tm *t = localtime(&now); // show curretn time
  fprintf(fb,"20180000001\t\t%02d.%02d.%04d/%02d:%02d\n\n", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min); // printed current time to txt file
  fprintf(fb,"--------------------------------------\n\n");
  fprintf(fb,"Product\t\t\tPrice(TL)\n\n");
  fprintf(fb,"--------------------------------------\n\n");
  while(meal != 0)
  {
    printf("Please choose a product:(1-10):"); // user choose product
    scanf("%d",&meal);
    if(meal == 0)  break;
    printf("How many servings do you want:"); // user choose service
    scanf("%d",&service);
    i=0;
    rewind(fp);
    while(i<meal)
    {
      if(i != meal-1) // this statment work till fin right product
      {
        while(fscanf(fp,"%c",&A) == 1 && A != ' '){ }
        while(fscanf(fp,"%f",&price) == 1 && price != '\n'){ }
        i++;
      }
      else //  right product found here
      {
        if(service>1) fprintf(fb,"%d* ",service);
        while(fscanf(fp,"%c",&A) == 1 && A != ' ')
        {
          fprintf(fb,"%c",A); // here printed to txt file choosen product
        }
        fprintf(fb,"\t\t");
        fscanf(fp,"%f",&price);
        fprintf(fb,"%.2f\n\n",(float)(service*price));
        total=total+(float)(service*price); // calculated totol price
        i++;
      }
    }
  }
  fprintf(fb,"Total:\t\t%.2f\n\n",total);
  printf("Are you student(N\\Y):\n");
  while(k<1)  // student discount
  {
    scanf(" %c",&student);
    if(student != 'Y' && student != 'N')
    {
      printf("Enter a valid input!!!\n");
    }
    else if(student == 'Y')
    {
      student_discount=total*12.5/100;
      fprintf(fb,"Student discount:\t-%.2f\n\n",student_discount);
      k=1;
    }
    else if(student == 'N')  k=1;
  }
  if(total>150.0)  // for total more than 150TL discount
  {
    discount=total*10/100;
    fprintf(fb,"Extra discount for 150TL:\t-%.2f\n\n",discount);
  }
  fprintf(fb,"--------------------------------------\n\n");
  total=total-student_discount-discount; // substrackt stduent discount
  fprintf(fb,"Price:\t\t%.2f\n\n",total);
  vat=total*18.0/100.0; // calculate vat price
  total=total+vat;
  fprintf(fb,"Price + VAT:\t\t%.2f\n\n",total);
  fclose(fp);
  fclose(fb);
  print_order(); // print order function
}
void game_play()  // this part two function
{
  int a=0,b,i,k=0;
  char A;
  while(a<1)
  {
    printf("Please make a choice!\n");
    printf("1: Stone, 2: Paper, 3: Scissors\n");
    scanf("%d",&b);
    i=rand()%3;
    i=i+1;
    if(b == 1 && i == 1){         printf("You choose Stone. I choose Stone. It is a tie!\n");         }
    else if(b == 1 && i == 2){    printf("You choose Stone. I choose Paper. I win!\n");               }
    else if(b == 1 && i == 3){    printf("You choose Stone. I choose Scissors. You win!\n");          }
    else if(b == 2 && i == 1){    printf("You choose Paper. I choose Stone. You win!\n");             }
    else if(b == 2 && i == 2){    printf("You choose Paper. I choose Paper. It is a tie!\n");         }
    else if(b == 2 && i == 3){    printf("You choose Paper. I choose Scissors. I win!\n");            }
    else if(b == 3 && i == 1){    printf("You choose Scissors. I choose Stone. I win!\n");            }
    else if(b == 3 && i == 2){    printf("You choose Scissors. I choose Paper. You win!\n");          }
    else if(b == 3 && i == 3){    printf("You choose Scissors. I choose Scissors. It is a tie!\n");   }
    printf("Do you want to play again? (Y/N):");  k=0;
    while(k<1)
    {
      scanf(" %c",&A);  // here controlled yes or no
      if(A != 'Y' && A != 'N')
      {
        printf("Invalid input try again!\n");
      }
      else k=1;
    }
    if(A == 'N')  a=1;
  }
}
int main()
{
  int a=-1;
  while(a != 0) // here called two parts
  {
    printf("Part 1\nPart 2\nExit 0\nChoose a part:");
    scanf("%d",&a);
    fflush(stdin);
    switch(a){
      case 1: take_meal(); break;
      case 2: game_play(); break;
      case 3: return 0;    break;
    }
  }
}
