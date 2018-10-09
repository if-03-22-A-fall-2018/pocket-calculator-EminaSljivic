/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 02
 * Title:			Pocket Calculator
 * Author:			Emina Sljivic
 * ----------------------------------------------------------
 * Description:
 * First the user can choose between some operations then
 * that operation will be performed and the result will
 * be printed. This is reapiting until the user enter -1.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <float.h>

int print_menu_and_get_operation()
{
  int operation;

  do {

    printf("Choose one of the following operations: \n   Add (1) \n   Subtract (2) \n   Multiply (3) \n   Divide (4) \n   Power (5)\n   Arithmetic_Series (7)\n   Stop program (-1) \nEnter your choice: ");
    scanf("%d",&operation );
    if(operation != 1 && operation != 2 && operation != 3 && operation !=4 && operation !=5 && operation !=7 && operation !=-1){
      printf("Input not allowed, please try again!\n");
    }
  } while(operation != 1 && operation != 2 && operation != 3 && operation !=4 && operation !=5 && operation !=7 && operation !=-1);

  return operation;
}

void get_opernads(double* opernad_one, double* opernad_two)
{
  do {
    printf("Please enter the first operand: ");
    scanf("%lf",opernad_one);
    if(*opernad_one > DBL_MAX)
    {
      printf("Number overflow!\n");
    }
    else if(*opernad_one < DBL_MIN)
    {
      printf("Number underflow!\n");
    }
  } while(*opernad_one > DBL_MAX || *opernad_one < DBL_MIN);

  do {
    printf("Please enter the second operand: ");
    scanf("%lf",opernad_two);
    if(*opernad_two > DBL_MAX)
    {
      printf("Number overflow!\n");
    }
    else if(*opernad_two < DBL_MIN)
    {
      printf("Number underflow!\n");
    }
  } while(*opernad_two > DBL_MAX || *opernad_two < DBL_MIN);

}

double perform_operation(int operation,double num1, double num2)
{
  double result=0;

  if(operation==1)
  {
      result=num1+num2;
  }

  else if(operation==2)
  {
    result=num1-num2;
  }

  else if(operation==3)
  {
    result=num1*num2;
  }

  else if(operation==5)
  {
      result=num1;
      for (int i = 1; i < num2; i++)
      {
          result=result*num1;
      }
  }

  else if(num2!=0)
  {
      result=num1/num2;
  }

  else
  {
    printf("Division by zero!\n");
  }

  return result;
}

double read_one_operand()
{
  double operand;
  do {
    printf("Please enter the operand: ");
    scanf("%lf",&operand);
    if(operand > DBL_MAX)
    {
      printf("Number overflow!\n");
    }
    else if(operand < 1)
    {
      printf("Number too small!\n");
    }
  } while(operand > DBL_MAX || operand < 1);

  return operand;
}

double Arithmetic_Series(double operand)
{
  int result=0;
  for (int i = 1; i <= operand; i++) {
    result =result + i;
  }

  return result;
}

int main(int argc, char const *argv[])
{
  int operation=0;
    do {
      double opernad_one;
      double opernad_two;
      double result;

      operation=print_menu_and_get_operation();

      if(operation==7)
      {
        opernad_one=read_one_operand();

        result=Arithmetic_Series(opernad_one);

        printf("The result is: %lf\n",result);
      }

      else if(operation!=-1)
      {
        get_opernads(&opernad_one, &opernad_two);
        result=perform_operation(operation,opernad_one,opernad_two);

        if(opernad_two!=0)
        {
          printf("The result is: %lf\n",result);
        }

      }
    } while(operation!=-1);
  return 0;
}
