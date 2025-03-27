#include <iostream>
using namespace std;
int maxA = 0;
int maxB = 0;
int maxPrimes = 0;


bool isPrime(int n) //all primes past the elementary ones are in the form 6k+1 or 6k-1
{
    if(n<=1) return false;
    if(n<4) return true;

    if(n%2 == 0 || n%3 == 0)
    {
        return false;
    }

    for(int i = 5; i*i <= n; i=i+6)
    {
        if(n%i == 0 || n % (i+2) == 0)
        {
            return false;
        }
    }
    return true;
}

void testQuadratic(int a, int b) //quadratic in the form n^2 + an + b
{
    int i = 0;
    while(1)
    {
        int sum = i*i + a*i + b;
        if(i > maxPrimes)
        {
            maxPrimes = i;
            maxA = a;
            maxB = b;
        }
        if(!isPrime(sum)) { return; }
        i++;
    }
}

int main()
{
    int a;
    int b;
    for(a = -999; a < 1000; a++)
    {
        for(b = -1000; b <= 1000; b++)
        {
            testQuadratic(a,b);
        }
    }
    cout << "a = " << maxA <<", b = " << maxB << ", max primes in a row = " << maxPrimes;
}