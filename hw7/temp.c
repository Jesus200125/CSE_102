#include<stdio.h>
#include<string.h>

#define MAX_WORD_SIZE 12
int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE])
{
  FILE *fp=fopen(file_name,"r");
  int i=0,j=0,temp=0;
  float vector;
  char line[150];
  if (fp == NULL)  // file doesnot exist
  {
      printf("File doesnt open!\n");
      return -1; // return -1 if file doesnot exist
  }
  fgets(line,150,fp);
  while(fscanf(fp,"%s",dict[i]) != EOF)  // read words from dictionary file
  {
    while(j<200)  // read vectors and pass
    {
      fscanf(fp,"%f",&vector) != EOF;
      j++;
    }
    j=0;
    i++;
  }
  i--;
  dict[i][0]='-';   // make - end of array
  dict[i][1] = '\0';  // make null end of array
  fclose(fp);
  return i;
}

int read_text(const char * text_file, const char * ignore_file, char words[][MAX_WORD_SIZE])
{
    FILE *fp,*fb;
    fp = fopen(text_file,"r");
    fb = fopen(ignore_file,"r");
    if (fp == NULL || fb == NULL)
    {
        printf("File doesn't open!\n");
        return -1;
    }

    char word_input[MAX_WORD_SIZE];
    char ignore[10][MAX_WORD_SIZE];
    int i = 0;
    int j = 0;
    int k = 0;
    int a = 0;
    int b = 0;
    int len;
    char c;

    while (fscanf(fb,"%s",ignore[i]) != EOF) i++;  // read ignore file

    while ((c = fgetc(fp)) != EOF)  // read from şnput file
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  //  ignore punctuation characters
        {
            word_input[j] = c;
            j++;
        }
        else
        {
            if (j > 0)
            {
                word_input[j] = '\0';
                for (k = 0; k < i; k++)  // control ignore file
                {
                    if (strcmp(word_input, ignore[k]) == 0) break;
                }
                if (k == i)  // copy word
                {
                    strcpy(words[a], word_input);
                    a++;
                }
                j = 0;
            }
        }
    }
    words[a][0]='-';  // make - end of array
    words[a][1]='\0';  // make null end of array
    a++;
    fclose(fp);
    fclose(fb);
    return a;
}

double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold )
{
  FILE *fp=fopen("dictionary.txt","r");
  char a[12],j,k;
  float v1[200],v2[200],sum=0.0;
  while (fscanf(fp,"%s",a) != EOF)  // read vectors
  {
    if(strcmp(a,w1) == 0)
    {
      for(j=0; j<200; j++)
      {
        fscanf(fp,"%f",&v1[j]);
      }
    }
  }

  rewind(fp);

  while (fscanf(fp,"%s",a) != EOF)  // read vectors
  {
    if(strcmp(a,w2) == 0)
    {
      for(j=0; j<200; j++)
      {
        fscanf(fp,"%f",&v2[j]);
      }
    }
  }

  for(j=0; j<200; j++) // calculate threshold
  {
    sum = sum + ((v1[j]-v2[j]) * (v1[j]-v2[j]));
  }
  fclose(fp);
  return sum;
}

int histogram(const char words[][MAX_WORD_SIZE], const int occurrences[], const char hist[][2], char closest_words[][12], int len)
{
   int a=0,i,k=0;
   while(a<len)
   {
     if(occurrences[a]>20)
     {
       printf("Scale : %d\n",occurrences[a]/20);
       if( hist[a][0] != '+' )  printf("%s ",words[a]);
       else   { printf("%s -> %s ",words[a],closest_words[k]);  k++;  }
       for(i=0; i<occurrences[a]%20; i++)
       {
         printf("%c",hist[a][0]);
       }
       printf("\n");
     }
     else
     {
       if( hist[a][0] != '+' )  printf("%s ",words[a]);
       else   { printf("%s -> %s ",words[a],closest_words[k]);  k++;  }
       for(i=0; i<occurrences[a]%20; i++)
       {
         printf("%c",hist[a][0]);
       }
       printf("\n");
     }
     a++;
   }
   return 0;
}

int main()
{
  char words[100][MAX_WORD_SIZE],words_input[300000][MAX_WORD_SIZE],dict[20000][MAX_WORD_SIZE];
  int w=0,words_similar[100][20],i,j,k,temp1=0,counter=1;
  FILE *fp;
  printf("Enter word(s)(for stop, enter 0 ): ");
  while(1)  // take words from user
  {
    scanf("%s",words[w]);
    if(strcmp(words[w],"0") == 0)  break;
    w++;
  }
  words[w][0]='-';
  words[w][1]='\0';  w++;
  int dictionary_words=read_dict("dictionary.txt",dict);
  int input_words=read_text("input.txt","ignore.txt",words_input);
  /*int c=0,c1=0,c2=0;
  if(w == 1)
  {
    c=0;
    c1=0; 
    while(words_input[c][0] != '-')
    {
      if(strcmp(words[0],words_input[c]) == 0)
      {
        c1++;  c2=1;
        printf("%d\n",c1);
      }
      c++;
    }
  }  */
  if( w == 1 && c2 == 0) { printf("%s is not appear input\n",words[0]);   return 0; }
  else { printf("%s appear %d times input file\n",words[0],c1);  return 0;  }
  int occr[w],a,b,count_dictionary=0,closest=0,cls1=0;
  float dis=0,dis1,temp=0.0;
  char hist[w][2],cls[w][12];
  double threshold=0.0;
  for(i=0; i<w; i++)
  {
    //printf("123\n");
    counter=1; j=0; temp1=0;
    while(j<input_words)
    {
      if(strcmp(words[i],words_input[j]) == 0)  // fins word from input words
      {
        occr[i]=counter;
        counter++;
        hist[i][0]='*';
        temp1=1;
      }
      else if(j == (input_words - 1) && temp1 == 0 )  // find closest words
      {
        for(a=0; a<dictionary_words; a++) // control most closest word
        {
          temp=dissimilarity(words[i],words_input[a],dict,threshold);
          dis1=temp;
          if(dis>dis1)  { dis=dis1;  closest=a;  }  // calculate min threshold
        }
        k=0; counter=1;
        while(k<input_words)
        {
          if(strcmp(dict[closest],words_input[j]) == 0)
          {
            occr[i]=counter;
            counter++;
            hist[i][0]='+';
            strcpy(cls[cls1],dict[closest]);
            cls1++;
          }
          k++;
        }
      }
      j++;
    }
  }

  //printf("123\n");
  histogram(words,occr,hist,cls,w);
}
