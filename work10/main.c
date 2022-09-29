// C Program for Iterative Tower of Hanoi
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define STACK_BLOCK_SIZE 10
// A structure to represent a stack
typedef struct{
int *array;
int currentsize;
int maxsize;
}Stack;

// function to create a stack of given capacity.
Stack *init_return(){
  Stack *stack =calloc(STACK_BLOCK_SIZE,sizeof(Stack));
  return stack;
}
int init(Stack *s){
    if( !(init_return()) )
      return 0;
    else{
      s=init_return();
      return 1;
    }
}
// Stack is full when top is equal to the last index
int Full(Stack* stack){
return (stack->currentsize == stack->maxsize - 1);
}
// Stack is empty when top is equal to -1
int Empty(Stack* stack){
return (stack->currentsize == -1);
}
// Function to add an item to stack. It increases
// top by 1
void push(Stack* stack, int n){
    if (Full(stack))
        return;
    stack -> array[++stack -> currentsize] = n;
}
// Function to remove an item from stack. It
// decreases top by 1
int pop(Stack* stack){
    if (Empty(stack))
        return 0;
    return stack -> array[stack -> currentsize--];
}
// Function to implement legal movement between
// two poles
void moveDisks(Stack *X,Stack *Y, char s, char d){
    int pole1 = pop(X);
    int pole2 = pop(Y);
    // When pole 1 is empty
    if (pole1 == 0){
        push(X, pole2);
        //moveDisk(d, s, pole2TopDisk);
        printf("Move the disk %d from \'%d\' to \'%d\'\n",pole2,d,s);
    }
    // When pole2 pole is empty
    else if (pole2 == 0){
        push(Y, pole1);
        //moveDisk(s, d, pole1TopDisk);
        printf("Move the disk %d from \'%d\' to \'%d\'\n",pole1,s,d);
    }
    // When top disk of pole1 > top disk of pole2
    else if (pole1 > pole2){
        push(X, pole1);
        push(X, pole2);
        //moveDisk(d, s, pole2TopDisk);
        printf("Move the disk %d from \'%d\' to \'%d\'\n",pole2,d,s);
    }
    // When top disk of pole1 < top disk of pole2
    else{
        push(Y, pole2);
        push(Y, pole1);
        //moveDisk(s, d, pole1TopDisk);
        printf("Move the disk %d from \'%d\' to \'%d\'\n",pole1,s,d);
    }
}
int main(){

    Stack *A,*B,*C,*temp;
    int i, total_moves;
    int s =1,d=3,a=2;
    // Input: number of disks
    int disks;
    printf("Enter Tower Size:"),
    scanf("%d",&disks);
    // Create three stacks of size 'num_of_disks'
    // to hold the disks
    if(STACK_BLOCK_SIZE<disks){

    }
    temp=init_return();
    A=temp;
    temp=init_return();
    B=temp;
    temp=init_return();
    C=temp;
    if(init(A) && init(B) && init(C)) {
      A->currentsize=-1;
      A->maxsize=STACK_BLOCK_SIZE;
      A->array=calloc(STACK_BLOCK_SIZE,sizeof(int));
      B->currentsize=-1;
      B->maxsize=STACK_BLOCK_SIZE;
      B->array=calloc(STACK_BLOCK_SIZE,sizeof(int));
      C->currentsize=-1;
      C->maxsize=STACK_BLOCK_SIZE;
      C->array=calloc(STACK_BLOCK_SIZE,sizeof(int));
      if(STACK_BLOCK_SIZE<disks){
        A->maxsize=STACK_BLOCK_SIZE*2;
        A->array=calloc(STACK_BLOCK_SIZE*2,sizeof(int));
        B->maxsize=STACK_BLOCK_SIZE*2;
        B->array=calloc(STACK_BLOCK_SIZE*2,sizeof(int));
        C->maxsize=STACK_BLOCK_SIZE*2;
        C->array=calloc(STACK_BLOCK_SIZE*2,sizeof(int));
      }
      if (disks % 2 == 0){
          char temp = d;
          d = a;
          a = temp;
      }
      total_moves = pow(2,disks)-1;
      //Larger disks will be pushed first
      for (i=disks; i>=1; i--)
          push(A,i);

      for (i = 1; i <= total_moves; i++){
          if (i % 3 == 1)
          moveDisks(A,B,s,d);

          else if (i % 3 == 2)
          moveDisks(A,C,s,a);

          else if (i % 3 == 0)
          moveDisks(C,B,a,d);
      }
    }
    free(A);
    free(B);
    free(C);
    return 0;
}
