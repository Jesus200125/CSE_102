#include<stdio.h>
int main(){
  FILE *fp; // this is file pointer
  int intnum=0,number=0,a=0,b=0,i=0,x=0,y=0,z=0,j=1;
  fp=fopen("input.txt","r"); // here open input file
  while(!feof(fp)){ // in this while count all elements in input file
    fscanf(fp,"%d",&b);
    a++;
  }
  int numbers[100];
  int numbers1[100];
  for(i=0; i<100; i++){ // in this for do zero inside of two arrays
    numbers[i]=0;
    numbers1[i]=0;
  }
  rewind(fp); // here we bring file pointer start of file
  fscanf(fp,"%d",&numbers[intnum]); // here taken first element of  input file
  numbers1[intnum]++;
  intnum++;
  while(j<a-1){ // in this while we take all elements of input file
    fscanf(fp,"%d",&number);
    i=0; x=0;
    for(i; i<intnum; i++){
      if(number==numbers[i]){  //this if statement used for same elements
        numbers1[i]++;
        x=1;
      }
      if(i==intnum-1 && x==0){  //this if statement used for different elements
          numbers[intnum]=number;
          numbers1[intnum]++;
          intnum++;
          i=intnum;
      }
    }
    j++;
    number=0;
  }
  fclose(fp);
  int output[intnum];  // these two arrays  used for sort taken elements
  int output1[intnum];
  for(i=0; i<intnum; i++){
     output[i]=numbers[i];
     output1[i]=numbers1[i];
  }
  for(i=0; i<intnum; i++){  // in these loops sorted elements
    for(j=i+1; j<intnum; j++){
      if(output1[i]>=output1[j]){
        y=output[i];
        output[i]=output[j];
        output[j]=y;
        z=output1[i];
        output1[i]=output1[j];
        output1[j]=z;
      }
    }
  }
  fp=fopen("output.txt","w");
  for(i=0; i<intnum; i++){ // in this for written to output file all  elements
    fprintf(fp,"%d : %d\n",output[i],output1[i]);
  }
  fclose(fp);
  for(i=0; i<intnum; i++){
     printf("%d : %d\n",output[i],output1[i]);
  }
  return 0;
}
