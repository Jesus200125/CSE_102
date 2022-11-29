#include"stdio.h"
#include"stdlib.h"
#include"util.h"  // this library call util.h
int main(){
  int sequence_len,first_element,cur_len=0; // these are used to take input from user
  int i,j; // these are used for loops
  int digit=1; // // these used for histogram
  printf("Enter the sequence length:");
  scanf("%d",&sequence_len);
  printf("Enter the first element:");
  scanf("%d",&first_element);
  int *mal_len,*h;
  int *loop;
  int looplen=sequence_len/2;
  mal_len=(int*) malloc(sizeof(int) * sequence_len); // here we give size of mal_len
  loop=(int*) malloc(sizeof(int) * sequence_len); // here we give size of loop
  mal_len[cur_len]=first_element;  // here we give first value of mal_len
  h=(int*) calloc(9,sizeof(int)); // here we give size of h
  generate_sequence(first_element,cur_len,sequence_len,mal_len); //called generate function
  printf("Sequence {"); // here written sequence numbers
  for(i=0; i<sequence_len; i++){
    printf("%d",mal_len[i]);
    if(i<sequence_len-1){ printf(", ");   }
  }
  printf("}\n");
  printf("\n");
  check_loop_iterative(generate_sequence,first_element,sequence_len,loop,&looplen); // called check loop function
  for(j=(sequence_len/2); j>=loop[0]; j--){
    printf("Checking if there is a loop of length %d...\n",j); // here written checking
  }
  if(loop[1]==1){
    printf("\nLoop detected with a length of %d\n",loop[0]);
    printf("The indexes of the loop's first occurance:%d (first digit),%d (last digit)\n",loop[2],loop[3]);
    printf("Loop: {");  // here written first loop
    for(i=loop[2]; i<=loop[3]; i++){
      printf("%d",mal_len[i]);
      if(i<loop[3])  printf(",");
    }
    printf("}\n");
    printf("\n");
  }
  else{
    printf("No loop found.\n");
      printf("\n");
  }
  hist_of_firstdigits(generate_sequence,first_element,sequence_len,h,digit); // here called histogram function
  printf("Histogram of the sequence: {"); // here written histogram numbers
  for(i=0; i<9; i++){
    printf("%d",h[i]);
    if(i<8) { printf(", "); }
  }
  printf("}\n");
  free(loop);
  return 0;
}
