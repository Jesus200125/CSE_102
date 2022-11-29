#include<stdio.h>
#define p1 0.5
#define p2 20
int main(){
  FILE *fp;
  int counter=0,i=0,j=0,k,y=1;
  float a=0,b=0,n=0,x=0,temp=0;
  fp=fopen("input.txt","r");
  while (fscanf(fp,"%f",&x) != EOF){ // here counted size of sequence
    counter++;
  }
  x=0;
  rewind(fp);
  float Array[counter][counter]; // this two dimensional array hold on chunks
  int size[counter];
  for (i=0; i<counter; i++){  // in this loops done zero inside of array
    for(j=0; j<counter; j++){
      Array[i][j]=0;
      size[i]=0;
    }
  }
  i=-1; j=0;
  while (fscanf(fp,"%f",&n) != EOF){
    x = x + n;  b = x/y;
    if( !(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2) ){  // in this statement added numbers to past chunk
      Array[i][j]=n;  size[i]++;  j++;   a = b;
    }
    else{
      if(i >= 0){  // in this statement generated new chunk
        a=n; x=n; y=1;
      }
      i++; j=0;
      Array[i][j]=n;  size[i]++;  j++;
      if(i==0){
        a=b;
      }
    }
    y++;
  }
  fclose(fp);
  float Avarage[i+1]; // this array hold avarege of chunks
  for (j=0; j<=i; j++){ // this loop done zero inside of array
    Avarage[j]=0;
  }
  for(j=0; j<=i; j++){ // in this loops calculated avarage of chunks
    for (k=0; k<size[j]; k++){
        temp +=Array[j][k];
    }
    Avarage[j]=temp/size[j];
    temp=0;
  }
  for (j=0; j<=i; j++){ // in this loops sorted avarage of chunks
    for(k=j+1; k<=i; k++){
      if(Avarage[j]>Avarage[k]){
        temp=Avarage[j];
        Avarage[j]=Avarage[k];
        Avarage[k]=temp;
      }
    }
  }
  counter=0; temp=0; j=0;
  fp=fopen("output.txt","w");
  while(j<=i){  // in this loops sorted avarage chunks written to output file
    for (k=0; k<size[j]; k++){
        temp += Array[j][k];
    }
    if(Avarage[counter]==temp/size[j]){
      for(k=0; k<size[j]; k++){
        fprintf(fp,"%.4f   ",Array[j][k]);
      }
      fprintf(fp,"\n");
      size[j]=0;  j=-1;  counter++;
      if(counter==i+1){
        j=i+1;
      }
    }
    temp=0; j++;
  }
  fclose(fp);
  return 0;
}
