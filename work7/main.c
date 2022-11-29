#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"time.h" // this is for srand function

int main(){

 char BOARD[15][15];
 int word_size=10,text_long=50;
 char table[50][10] = {};
 char TEMP_BOARD[10][10]= {};
 char word[6],END[10]=":q";
 int cordinate1,cordinate2,temp_cordinate1=0,temp_cordinate2=0,len_word=0,point=0,mistakes=3,true_words=0; // these are for take coordinates from user
 int TEMP1[7],TEMP2[7],TEMP3[7],TEMP4[7],TEMP5[7];
 int k,x,y,z,i,j,a=0,b,direction_type=0,back1,back2=0; // these are for loops
 int loop,loop1=0,loop2,loop3,loop4,loop5,loop6,compare_word=0;
 int rand1,rand2,rand3,rand4,temp=0,counter=0,counter1=0,counter2=0; // these are for taken random numbers
 srand(time(0));
 FILE *file=fopen("wordlist.txt","r");
 for(y=0; y<15; y++){  // here we do empty inside of BOARD string
   for(j=0; j<15; j++){
     BOARD[y][j]=' ';
   }
 }
 for(k=0; k<50; k++){  // here  we read all words from wordlist.txt file
   fscanf(file,"%s",table[k]);
 }
 fclose(file);
 for(k=0; k<7; k++){  TEMP4[k] = ' '; } // here we make empty inside of temp4 array
 for(x=0; x<7; x++){  // in this loop  we read 7 random words from all words
   for(k=0; k<7; k++){  TEMP1[k] = ' '; } // here we make empty inside of temp1
   rand3=rand()%50;
   TEMP4[x]=rand3;
   TEMP1[x]=rand3;
   counter1=0;
   for(loop6=0; loop6<=x; loop6++){ // in this loop we control words equal each other or not
     if(TEMP1[x] == TEMP4[loop6]){
       counter1=counter1+1;
     }
   }
   if(counter1 == 1){ // in this if we find cordinate of words and directions
     rand1=rand()%15;
     rand2=rand()%15;
     rand4=(1+rand()%8);
     a=strlen(table[rand3]);
     TEMP2[x]=rand1;
     TEMP3[x]=rand2;
     TEMP5[x]=a;
     counter=0;
     switch(rand4){  // this rand4  be direction of words
       case 1:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             rand2++;
             counter++;
           }
           else{
             rand2--;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand2--;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
             }
           } break;
       case 2:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand2--;
           }
           else{
             rand2++;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand2++;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         } break;
       case 3:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand1++;
           }
           else{
             rand1--;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1--;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       case 4:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand1--;
           }
           else{
             rand1++;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1++;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       case 5:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand2++;
             rand1++;
           }
           else  {
             rand1--;
             rand2--;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1--;
               rand2--;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       case 6:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand2++;
             rand1--;
           }
           else  {
             rand1++;
             rand2--;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1++;
               rand2--;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       case 7:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand2--;
             rand1++;
           }
           else {
             rand1--;
             rand2++;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1--;
               rand2++;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       case 8:
         for(y=0; y<a; y++){
           if(BOARD[rand1][rand2] == ' ' && rand1<15 && rand2<15 && rand1>=0 && rand2>=0){
             BOARD[rand1][rand2]=table[rand3][y];
             TEMP_BOARD[x][y]=table[rand3][y];
             counter++;
             rand2--;
             rand1--;
           }
           else  {
             rand1++;
             rand2++;
             back2=x;
             for(back1=0; back1<counter; back1++){
               BOARD[rand1][rand2]='\0';
               rand1++;
               rand2++;
             }
             for(loop5=0; loop5<a; loop5++) { TEMP_BOARD[back2][loop5]='\0'; }
             y=a;
             x--;
           }
         }break;
       }
     }
 else { x--; }
 }
 for(loop1=0; loop1<7; loop1++){ // here written  random words and cordinates
   printf("%s  %d   %d\n",TEMP_BOARD[loop1],TEMP2[loop1],TEMP3[loop1]);
 }
 for(y=0; y<15; y++){ // in this loop we write letters to empty spaces
   for(j=0; j<15; j++){
     if(BOARD[y][j]=='\0' || BOARD[y][j]==' '){
       BOARD[y][j]=97+rand()%26;
     }
   }
 }
for(z=0; z<15; z++){ // here written letters to terminal
  for(i=0; i<15; i++){
    printf("%c ",BOARD[z][i]);
  }
  printf("\n");
}
loop1=0;
while(loop1<3){ // in this loop we take cordinates and word from user  and control it whether there are words or not
   if(true_words==7){ printf("You found all words.Total point %d\n",point);  return 0;}
   printf("Enter the coordinates and the words: ");
   scanf("%d",&cordinate1);
   scanf("%d",&cordinate2);
   scanf("%s",word);
   compare_word=0;
   temp_cordinate1=cordinate1;
   temp_cordinate2=cordinate2;
   len_word=(int)strlen(word);
   if(strcmp(END,word)==0) { printf("Game finished! Total point %d\n",point); return 0; }

   int testFlag = 0;
   for (loop3 = 0; loop3 < 7; ++loop3) {
     if (strcmp(TEMP_BOARD[loop3], word) == 0) {
       testFlag = 1;
     }
   }
    if (testFlag == 1){
     if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1][temp_cordinate2+1]==word[1] && BOARD[temp_cordinate1][temp_cordinate2+2]==word[2] ){
       direction_type=1;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1][temp_cordinate2-1]==word[1] && BOARD[temp_cordinate1][temp_cordinate2-2]==word[2] ){
       direction_type=2;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1+1][temp_cordinate2]==word[1] && BOARD[temp_cordinate1+2][temp_cordinate2]==word[2] ){
       direction_type=3;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1-1][temp_cordinate2]==word[1] && BOARD[temp_cordinate1-2][temp_cordinate2]==word[2] ){
       direction_type=4;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1+1][temp_cordinate2+1]==word[1] && BOARD[temp_cordinate1+2][temp_cordinate2+2]==word[2] ){
       direction_type=5;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1-1][temp_cordinate2+1]==word[1] && BOARD[temp_cordinate1-2][temp_cordinate2+2]==word[2] ){
       direction_type=6;
       point=point+2;
       true_words++;
     }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1+1][temp_cordinate2-1]==word[1] && BOARD[temp_cordinate1+2][temp_cordinate2-2]==word[2]){
       direction_type=7;
       point=point+2;
       true_words++;
         }
     else if(BOARD[temp_cordinate1][temp_cordinate2]==word[0] && BOARD[temp_cordinate1-1][temp_cordinate2-1]==word[1] && BOARD[temp_cordinate1-2][temp_cordinate2-2]==word[2] ){
       direction_type=8;
       point=point+2;
       true_words++;
     }
     else{
       direction_type=9;
     }
   }
   else{
     direction_type=9;
   }
   switch(direction_type){
     case 1:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2++;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 2:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2--;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 3:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate1++;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 4:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate1--;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 5:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2++;
         cordinate1++;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 6:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2++;
         cordinate1--;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 7:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2--;
         cordinate1++;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 8:
       for(loop2=0; loop2<len_word; loop2++){
         BOARD[cordinate1][cordinate2]='X';
         cordinate2--;
         cordinate1--;
       }
       for(z=0; z<15; z++){
         for(i=0; i<15; i++){
           printf("%c ",BOARD[z][i]);
         }
         printf("\n");
       }
       printf("Founded! You got 2 points.Total point:%d\n",point);
       break;
     case 9:
       mistakes--;
       loop1++;
       if(mistakes != 0)
         printf("Wrong choice! You have only %d lefts.\n",mistakes);
       else
         printf("Game over. You made 3 mistakes. Total point %d\n",point);
   }
}
  return 0;
}
