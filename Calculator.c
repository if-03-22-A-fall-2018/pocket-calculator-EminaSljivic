#include <stdio.h>

int print_menu_and_get_operation(){
  int operation;

do {

  printf("Choose one of the following operations: \n   Add (1) \n   Subtract (2) \n   Multiply (3) \n   Divide (4 ) \n   Stop program (-1) \nEnter your choice: ");
  scanf("%d",&operation );
} while(operation != 1 || operation != 2 || operation != 3|| operation !=4|| operation !=-1);

return operation;
}

int main(int argc, char const *argv[]) {
  print_menu_and_get_operation();
  return 0;
}
