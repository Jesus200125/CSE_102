#include<stdio.h>
#include<stdlib.h>
#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

int control_status(int a, int a1, int b, int b1)  // here controlled location of D and C
{
  if(a == b && a1 == b1)   return 1;
  else return 0;
}
int draw_room(int x)
{
  int i,j,k,a=0,b=0,a1,b1,counter=0,temp=0;
  char move;
  while(a == b) // here found location of C and D
  {
    a=rand()%x;
    b=rand()%x;
  }
  a1=a;   b1=b;
  while(temp != 1) //  this loop continue until game finish
  {
    for(i=0; i<x*2+1; i++)   printf("-");  // this loop draw -
    printf("\n");
    for(i=0; i<x; i++)  // in this loops draw rooms
    {
      for(j=0; j<=x; j++)
      {
        if(a1 == j && a == i)        printf("|D");
        else if(b == i && b1 == j)   printf("|C");
        else                         printf("| ");
      }
      printf("\n");
    }
    for(i=0; i<x*2+1; i++)   printf("-");   // this loop draw -
    printf("\n");
    printf("Enter the move(a-left,d-right,w-up,s-down):");
    scanf(" %c",&move);
    switch(move){   // here controlled direciton of C
      case LEFT: if(b1 == 0)     printf("You reached the wall!!!\n");
                else {  b1--;    counter++;  }
                break;
      case RIGHT: if(b1 == (x-1))         printf("You reached the wall!!!\n");
                else {  b1++;    counter++;  }
                break;
      case UP: if(b == 0)          printf("You reached the wall!!!\n");
                else {  b--;     counter++;  }
                break;
      case DOWN: if(b == (x-1))      printf("You reached the wall!!!\n");
                else {  b++;     counter++;  }
                break;
      default : printf("Entered wrong character\n");  break;
    }

    if(1 == control_status(a,a1,b,b1)) // called control_status function
    {
      printf("\nYou have reached to the door.Congratulation\nTotal move:%d\n\n",counter);
      temp=1;
    }
  }
}
int main()
{
  int x,y,control=1,z=0;
  while(z != 3)
  {
    printf("Welcome to the 2D puzzle game!\n");
    printf("1. New Game\n2. Help\n3. Exit\n");
    scanf("%d",&z);
    switch(z)  // controlled menu
    {
      case 1 : while(control != 0)
               {
                printf("Enter size of room:");
                scanf("%d",&x);
                if(x >= 5 && x <= 10)   control=0;
                else  printf("Size of room can not be smaller than 5 or bigger than 10\n");
               }
               control=1;
               draw_room(x);  // called draw function
               break;
      case 2 : printf("\nThis is a 2D puzzle game.You have to reach to the door(D)\nFor moving:a-left,d-right,w-up,s-down\n\n");break;
      case 3 : return 0;
      default:  printf("Wrong input\n");
    }
  }
}
