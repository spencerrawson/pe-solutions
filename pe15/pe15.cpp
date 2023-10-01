#include <iostream>
#include <string>

/**
 * Author: Spencer Rawson
 * Date: 10/1/23
 * Purpose: Finds the # of lattice paths through an n by n matrix
 * using a formula found mostly through testing by hand
 * and the rest through double checking why my formula was
 * slightly wrong
*/
int main()
{
    //formula is (2n)!/(n!)^2
    int n = 0;
    std::cout << "Input the size for your _ by _ matrix: " << std::endl;
    std::cin >> n;
    long long paths = 1;
    //formula is done per number to keep within long long max value at any given step
    for(int i = 1; i <= n; i++)
    {
        paths *= n+i;
        paths /= i;
    }
    std::cout << "The number of lattice paths for a " << n << " by " << n << " matrix is " << paths << std::endl;
    return 0;
}