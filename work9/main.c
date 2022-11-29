#include<stdio.h>
#include<stdlib.h>
#include <string.h>
FILE *fp; // here we definy our txt file
float power=1.0; // this value used to calculate loan
int counter=0,ID=1; //these are used to count customer
int Period[50][3]; // this is used to getReport
union Person{
  char name[50];
  char address[50];
  int phone;
};
union Loan{
  float amount;
  float interestRate;
  int period;
};
struct BankAccount{
  union Person Customer;
  union Loan Loans[3];
};
struct BankAccount *Customer1;

struct listcustomer{
  char adress[50];
  int phone;
};
struct listcustomer *listall;
float calculateLoan(float amount, int period, float interestRate){  // in this function calculated loan
   counter++;
   float loan=0;
   if(counter<=period){
     power=power*(1+interestRate);
     calculateLoan(amount,period,interestRate);
   }
   else{
     loan=power*amount;
     counter=0;
     power=1;
     return loan;
   }
}
void ListCustomers(){
  int i;
  fp=fopen("customers.txt","a");
  for(i=1; i<=ID-1; i++){  // in this loop written datas to customer txt file
    fprintf(fp,"Customer ID: %d\n",i);
    fprintf(fp,"Customer name: %s\n",Customer1[i].Customer.name);
    fprintf(fp,"Customer phone: %d\n",listall[i].phone);
    fprintf(fp,"Customer adress: %s\n",listall[i].adress);
    if(Customer1[i].Loans[0].amount != 0.0 && Customer1[i].Loans[1].amount == 0.0){ // in this condition  written first loan
      fprintf(fp,"Loans = [%.2f] => %.2f\n",Customer1[i].Loans[0].amount,Customer1[i].Loans[0].amount);
    }
    else if(Customer1[i].Loans[1].amount != 0.0 && Customer1[i].Loans[0].amount != 0.0 && Customer1[i].Loans[2].amount == 0.0){ // in this condition  written second loan
      fprintf(fp,"Loans = [%.2f+%.2f] => %.2f\n",Customer1[i].Loans[0].amount,Customer1[i].Loans[1].amount,Customer1[i].Loans[0].amount+Customer1[i].Loans[1].amount);
    }
    else if(Customer1[i].Loans[2].amount != 0.0){  // in this condition  written third loan
      fprintf(fp,"Loans = [%.2f+%.2f+%.2f] => %.2f\n",Customer1[i].Loans[0].amount,Customer1[i].Loans[1].amount,Customer1[i].Loans[2].amount,Customer1[i].Loans[0].amount+Customer1[i].Loans[1].amount+Customer1[i].Loans[2].amount);
    }
  }
  fclose(fp);
  fp=fopen("customers.txt","r");
  char c = fgetc(fp);
  printf("%c",c);
  while(c != EOF){ // here written all lists to terminal
     c = fgetc(fp);
     printf("%c",c);
   }
 fclose(fp);
}
void AddCustomer(){ // here saved customers to struct
  union Person Person1;
  printf("Enter the name:");
  scanf(" %[^\n]%*c",Person1.name);
  strcpy(Customer1[ID].Customer.name,Person1.name);
  printf("Enter the adrress:");
  scanf(" %[^\n]%*c",Person1.address);
  strcpy(listall[ID].adress,Person1.address);
  printf("Enter the phone number:");
  scanf("%d",&Person1.phone);
  listall[ID].phone=Person1.phone;
  ID++;
}
void NewLoan(){
  union Loan Loan1;
  float loan;
  int id=0;
  float amount,interestRate,period;
  printf("Enter customer ID:");
  scanf("%d",&id);
  if(id>0 && id<=ID-1){ // here calculated loans
    if(Customer1[id].Loans[0].amount == 0.0 || Customer1[id].Loans[1].amount == 0.0 || Customer1[id].Loans[2].amount == 0.0){ // in this condition controlled are there how many loan
      printf("Enter the loan ammount:");
      scanf("%f",&Loan1.amount);
      amount=Loan1.amount;
      printf("Enter the interest rate:");
      scanf("%f",&Loan1.interestRate);
      interestRate=Loan1.interestRate;
      printf("Enter the period:");
      scanf("%d",&Loan1.period);
      period=Loan1.period;
      loan=calculateLoan(amount,period,interestRate); // here called calculateloan function
      if(Customer1[id].Loans[0].amount == 0.0){ // here saved first loan
        Customer1[id].Loans[0].amount = loan;
        Period[id-1][0]=period;
      }
      else if(Customer1[id].Loans[1].amount == 0.0){ // here saved second loan
        Customer1[id].Loans[1].amount = loan;
        Period[id-1][1]=period;
      }
      else{ // here saved third loan
        Customer1[id].Loans[2].amount = loan;
        Period[id-1][2]=period;
      }
    }
    else{
      printf("You cannot take loan more 3 loans\n");
    }
  }
  else printf("Customer Not Found\n");
}
void getReport(){
  int input,i;
  float value;
  printf("Enter the customer ID for get report:");
  scanf("%d",&input);
  if(input>0 && input<=ID-1){
    printf("Total Credit Value:%.2f\n",Customer1[input].Loans[0].amount+Customer1[input].Loans[1].amount+Customer1[input].Loans[2].amount); // here written total credits
    if(Customer1[input].Loans[0].amount != 0.0){ // here written first loan
      value=Customer1[input].Loans[0].amount/(float)Period[input-1][0];
      for(i=1; i<=Period[input-1][0]; i++){
        printf("%d.Month Installment:%.2f\n",i,value);
      }
    }
    if(Customer1[input].Loans[1].amount != 0.0){ // here written second loan
      printf("Second Credit\n");
      value=Customer1[input].Loans[1].amount/(float)Period[input-1][1];
      for(i=1; i<=Period[input-1][1]; i++){
        printf("%d.Month Installment:%.2f\n",i,value);
      }
    }
    if(Customer1[input].Loans[2].amount != 0.0){ // here written third loan
      printf("Third Credit\n");
      value=Customer1[input].Loans[2].amount/(float)Period[input-1][2];
      for(i=1; i<=Period[input-1][2]; i++){
        printf("%d.Month Installment:%.2f\n",i,value);
      }
    }
    if(Customer1[input].Loans[0].amount == 0.0 && Customer1[input].Loans[1].amount == 0.0 && Customer1[input].Loans[2].amount == 0.0) printf("Report Not Found\n");
  }
  else printf("Customer not found\n");
}
int main(){

  int input,i,j;
  Customer1=(struct BankAccount *)calloc(50,sizeof(Customer1));
  listall=(struct listcustomer *)calloc(50,sizeof(listall));
  for(i=0; i<50; i++){
    for(j=0; j<3; j++){
      Period[i][j]=0;
    }
  }
  while(input != 5){
      printf("===================================\n");
      printf("Welcome to Bank management system\n");
      printf("===================================\n");
      printf("\t1.List All Customers\n");
      printf("\t2.Add New Customer\n");
      printf("\t3.New Loan Application\n");
      printf("\t4.Report Menu\n");
      printf("\t5.Exit System\n");
      scanf("%d",&input);
      switch(input){
        case 1:
          ListCustomers();
          break;
        case 2:
          AddCustomer();
          break;
        case 3:
          NewLoan();
          break;
        case 4:
          getReport();
          break;
        case 5:
          break;
      }
  }
  return 0;
}
