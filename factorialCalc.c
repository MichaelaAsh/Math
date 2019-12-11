#include <stdio.h>
#include <stdlib.h>

/* Functions that calculates the factorial of a number */
int factorial (int num) {

   unsigned long int i;
   unsigned long int answer = 1;

   for (i = num; i > 1; i--) {
      answer *= i;
   }

  return (answer);

}
/*=========================================================*/

int main (int argc, char *argv[]) {

  unsigned long int num;

  if ( argc != 2){
    printf("Usage ./factorial number\n");
    return (-1);
  } else {
    num = atoi (argv [1]);
  }

  unsigned long int ret = factorial(num);
  printf("The factorial of %lu is %lu\n", num, ret);

  return (0);

}
