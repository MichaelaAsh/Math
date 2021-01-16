
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL -1

// This program calculates the gcd of two numbers.
// Doesn't use Euclid's Algorithm, check LCM.c for that
// to run the program -> ./gcd_simple <first number> <second number>

/////////////////////////////////////////////////////////////////////////////
// must be postive number to be valid
int validate(int x, int y)
{

    if (x > 0 && y > 0)
    {
        return SUCCESS;
    }
    return FAIL;
}
/////////////////////////////////////////////////////////////////////////////
//find the smallest number of two numbers
int smallestVal(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
/////////////////////////////////////////////////////////////////////////////
//find the remainder
int rem(int x, int y)
{

    return x % y;
}
/////////////////////////////////////////////////////////////////////////////
//Computer the gcd
int gcd(int m, int n)
{
    int gcd;

    //gcd cannot be greater than the smallest of these number ( m and n)
    for (gcd = smallestVal(m, n);; gcd--)
    {
        if (rem(m, gcd) == 0) // Divise m by "gcd", which is not the true gcd , if it is 0
        {
            if (rem(n, gcd) == 0) //Divise n by "gcd", which is not the true gcd, if it is 0
            {
                return gcd; //gcd is found and must return gcd
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

    int m = 0;
    int n = 0;

    if (argc < 3)
    {
        printf("Usage: ./gcd_simple <first number> <second number>\n");
        exit(FAIL);
    }
    else
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    if (validate(m, n) == FAIL)
    {
        fprintf(stderr, "Error: Algorithm does not work if m or n is 0");
        exit(FAIL); // if number are not valid to perform gcd calculation, exit program
    }

    printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));

    return (SUCCESS);
}