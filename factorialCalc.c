#include <stdio.h>
#include <stdlib.h>

/* Functions that calculates the factorial of a number */
int factorial (int num) {

   int i;
   int answer = 1;

   for (i = num; i > 1; i--) {
      answer *= i;
   }

  return (answer);

}
/*=========================================================*/

int main (int argc, char *argv[]) {

  int num;

  if ( argc < 2 || argc > 2){
    printf("Usage ./factorial number\n");
    return (-1);
  } else {
    num = atoi (argv [1]);
  }


  printf("The factorial of %d is %d\n", num, factorial(num));

  return (0);

}
