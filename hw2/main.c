#include<stdio.h>
#include<math.h>

void leap_year() // leap year calculator function
{
  int a=2000,b,temp=0;
  printf("Please enter a year:");
  scanf("%d",&b);
  temp=a-b;
  if(temp % 4 == 0)  printf("%d is a leap year\n",b);
  else printf("%d is not a leap year\n",b);
}
void Science()
{
  float a,b,c;
  int m,n,i,temp=1,counter=0;
  float result = 0;
  char op;
  printf("Enter m and n values:");
  scanf("%d",&m);
  scanf("%d",&n);
  if(n>m)
  {
    printf("n can not be bigger than m!!!\n");
    return;
  }
  printf("Enter the operation(+,-,/,*,%%,!,^):");
  scanf(" %c",&op);
  if(op == '+' || op == '-' || op == '/' || op == '*' || op == '%' || op == '^')
  {
    printf("Enter the first operand:");
    scanf("%f",&a);
    printf("Enter the second operand:");
    scanf("%f",&b);
  }
  else if(op == '!')
  {
    printf("Enter the operand:");
    scanf("%f",&c);
  }
  else
  {
    printf("Invalid operation!\n");
    return;
  }
  switch (op){
    case '+' : result = a + b; break;
    case '-' : result = a - b;   break;
    case '/' : result = (float)a / b;   break;
    case '*' : result = a * b;   break;
    case '%' : result = fmod(a,b);   break;
    case '!' :
              for(i=1; i<=c; i++)
              {
                temp=temp*i;
                result=temp;
              }                  break;
    case '^' : result = pow(a,b); break;
  }
  i=0;
  int result1=(int)result;
  float temp1 = result - result1, temp2 = 10;
  if(temp1 != 0.0)  //if result equal to floating point number work this statement
  {
    result *= pow(10,n+1);
    counter -= (n+1);
  }
  if(fmod(result,10.0) == 0.0)  // if result mod of 10 divided here
  {
    while(fmod(result,10.0) == 0.0)
    {
      result /= 10;
      counter++;
    }
  }
  i=0;
  while(i<n) // here according to n divided
  {
    result /= 10;
    i++;
    counter++;
  }
  printf("%0*.*fe%d\n",m+1,n,result,counter); // counter write power of 10
}
void Easy_calculator() // this function if input I
{
  char op;
  int i,temp=1;
  float a,b,c;
  float result=0;
  printf("Enter the operation(+,-,/,*,%%,!,^):");
  scanf(" %c",&op);
  if(op == '+' || op == '-' || op == '/' || op == '*' || op == '%' || op == '^')
  {
    printf("Enter the first operand:");
    scanf("%f",&a);
    printf("Enter the second operand:");
    scanf("%f",&b);
  }
  else if(op == '!')
  {
    printf("Enter the operand:");
    scanf("%f",&c);
  }
  else
  {
    printf("Invalid operation!\n");
    return;
  }
  switch (op){
    case '+' : result = (float)(a + b);   break;
    case '-' : result = (float)(a - b);   break;
    case '/' : result = (float)(a / b);   break;
    case '*' : result = (float)(a * b);   break;
    case '%' : result = (float)(fmod(a,b));   break;
    case '!' :
              for(i=1; i<=c; i++)
              {
                temp=temp*i;
                result=temp;
              }                   break;
    case '^' : result = (float)(pow(a,b)); break;
  }
  if(op != '!')printf("%.2f%c%.2f=%.2f\n",a,op,b,result);
  else printf("%.2f%c=%.2f\n",c,op,result);
}
void enhanced_calculator()  // enhanced calculator function
{
  char format;
  printf("Enter the format of output(S or I):");
  scanf(" %c",&format);
  if(format == 'S' || format == 's')  // if input equalt S
  {
    Science();
  }
  else if(format == 'I') // if input equalt I
  {
    Easy_calculator();
  }
  else printf("Invalid format\n");

}
void Grade_calculator(){  // grade calculator function

  int a,b,c;
  int as1,as2;
  float final=0;
  printf("Enter 3 exam grades of student:");
  scanf("%d%d%d",&a,&b,&c);
  printf("Enter 2 assignment grades of student:");
  scanf("%d%d",&as1,&as2);
  final = (float)((float)((a+b+c)/3*0.6) + (float)((as1+as2)/2*0.4)); // final grade calculated
  if(final<60)  printf("Final Grade : %.2f Failed!\n",final);
  else  printf("Final Grade : %.2f Passed\n",final);
}
int main(){  // main function
   int a=0;
   printf("PART 1\nPart 2\nPart 3\nExit 4\nChoose a part:");
   while(a != 4)
   {
     scanf("%d",&a);
     if(a == 1)  leap_year();
     else if(a == 2) enhanced_calculator();
     else if(a == 3) Grade_calculator();
     else if(a == 4) a=4;
     if(a != 4)printf("PART 1\nPart 2\nPart 3\nExit 4\nChoose a part:");
   }
   return 0;
}
