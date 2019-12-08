#include <stdio.h>
/*=================================================================================*/
/* Compute GCD using Euclid's Algorithm */
/*=================================================================================*/
int GCD ( int a, int b) {

   if (a == 0) {
     return (b);
   }

   return GCD (b%a, a);

}
/*==================================================================================*/
/* Compute the LCM using the GCD */
/*==================================================================================*/
int LCM (int a, int b, int g) {
  return((a*b)/ g);
}
/*==================================================================================*/
int main  () {

  int min_lcm;
  int MIN;
  int MAX;

  int allLCM[10000];
  int numLCM = 0;

/* Find LCM between any pair of disinct numbers in rang e 9100 and 9199 and storing it */
  for (MIN = 9100; MIN <= 9199; ++MIN) {
      for (MAX = MIN+1; MAX <= 9199; ++MAX)  {
          int greatestCom = GCD(MIN,MAX);
          int lowestCom = LCM(MIN,MAX,greatestCom);
          allLCM[numLCM] = lowestCom; /* storing the each LCM in an array */
          numLCM++;

      }
   }
   int smallestLCM = allLCM[0];
   int maxNumLCM = numLCM;
   numLCM = 0;

   while (numLCM < maxNumLCM) {
       if (allLCM[numLCM] < smallestLCM) {
         smallestLCM = allLCM[numLCM];
         numLCM = 0;  /* this starts back from the beginning of the loop again to test the elements again */
       }
       numLCM++;
   }

   printf("Smallest LCM between two distinct numbers in range 9100 and 9199 is %d \n", smallestLCM);

} /* end of main */
