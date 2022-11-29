#include<stdio.h>
#include<stdlib.h>
int has_loop(int *arr, int n, int looplen, int *ls, int *le){  // in this function controlled is there a loop or not

  int i, j = 0;
   for(i=0;i<n-looplen;i++) // in this loop from start of the sequence to mid of the sequence controlled loop
   {
       if(arr[i+looplen] == arr[i]) // here controlled first numbers equal or not
         while(i+looplen+j<n && arr[i+j] == arr[i+looplen+j]) j++; // here controlled other numbers equal ot not
       if(j>=looplen)
       {
           *ls = n-(2*looplen); // this first numbers of loop
           *le = n-looplen-1;; // this last number of loop
           return 1;
       }
   }
   return 0;
}
void hist_of_firstdigits(void f(int,int,int,int*), int xs, int seqlen, int *h, int digit){ // in this function found histogram
  int *arr;
  arr=(int*) malloc(sizeof(int) * seqlen);
  int currentlen=0,i,k=0,j=0;
  arr[currentlen]=xs;
  f(xs,currentlen,seqlen,arr);  //called genereate function here
  for(i=0; i<seqlen; i++){ // in this loop found first numbers of numbers
    j=0;
    while(j<1){
      if(arr[i]>9){
        arr[i]=arr[i]/10;
      }
      else{ j=2; }
    }
  }
  for(i=0; i<seqlen; i++){ // here we controlled numbers and give the values of h array
    if(arr[i]==digit){
      k++;
      h[digit-1]=k;
    }
  }
  if(digit==9) return;
  (digit)++;
  hist_of_firstdigits(f,xs,seqlen,h,digit); // recursive function this
}
void check_loop_iterative(void f(int,int,int,int*), int xs, int seqlen, int *loop, int *looplen){ // here checked loop
  int *seq,ls,le,i;
  seq=(int*) malloc(sizeof(int) * seqlen);
  int currentlen=0;
  seq[currentlen]=xs;
  f(xs,currentlen,seqlen,seq); // called generate function
  loop[0]=*looplen;
  int func=has_loop(seq,seqlen,*looplen,&ls,&le);
    if(func == 0){  // here controlled output of has loop function
      (*looplen)--;
      if(*looplen == 1 )return;
      check_loop_iterative(f,xs,seqlen,loop,looplen); // here called again check function
    }
    else{
      loop[1]=1;
      loop[2]=ls; // here we give first number of loop
      loop[3]=le; // here we give start number of loop
      return;
    }
}
void generate_sequence (int xs, int currentlen, int seqlen, int *seq){ // in this function found sequence

  int i,j;
  currentlen++;
  if(xs%2==0 && currentlen<seqlen){ // if number even
    xs=xs/2;
    seq[currentlen]=xs;
    generate_sequence(xs,currentlen,seqlen,seq);  // called itself
  }
  else if(xs%2==1 && currentlen<seqlen){ // if number odd
    xs=3*xs+1;
    seq[currentlen]=xs;
    generate_sequence(xs,currentlen,seqlen,seq); // called itself
  }
}
