/**
 * Author: Spencer Rawson
 * Date: 10/15/23
 * Purpose: Solve problem 23, which wants the sum
 * of all positive integers that cannot be written 
 * as the sum of two abundant numbers (abundant means
 * a # which is less than the sum of its divisors)
 * given that it is proven that every number above 28123 
 * is able to be put as the sum of two abundants.
*/
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

int canBeSum(int n);
bool isAbundant(int n);
std::vector<int> abundants;
/**
 * Find the final answer sum, and the time it took
 * in order to compare to the python program I wrote
 * with almost the exact same function
*/
int main()
{
    //find the time at the start
    auto start = std::chrono::system_clock::now();
    //sum each positive int below 28123 that can't be written w/ 2 abundants
    int sum = 0;
    for(int i = 1; i < 28123; i++)
    {
        //for checking progress of program
        std::cout << i << std::endl;
        //if i is abundant, add it to the list of abundants
        if(isAbundant(i))
        {
            abundants.emplace_back(i);
        }
        sum += canBeSum(i);
    }
    //find the time difference, print it, and then print the sum
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end-start;
    std::cout << "Time = " << time.count() << std::endl;
    std::cout << "Sum = " << sum << std::endl;
}

/**
 * Takes a positive number n and checks if it is
 * possible to be written as the sum of two abundant
 * #'s using loops to find each possible sum and checking
 * if they = n
*/
int canBeSum(int n)
{
    //size variable to minimize calls to size
    int size = abundants.size();
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size; j++)
        {
            //if it is writable as a sum of 2 abundants then return 0
            if(n == abundants[i] + abundants[j]) 
            {
                return 0;
            }
        }
    }
    //if n goes through every abundant sum without finding a match return n
    return n;
}

/**
 * For a positive integer n, find the sum
 * of every divisor and return true if it is
 * abundant and false if not
*/
bool isAbundant(int n)
{
    int divSum = 0;
    //find the sum of all divisors
    for(int i = 1; i < n; i++)
    {
        if(n%i == 0)
        {
            divSum += i;
        }
    }
    //return if n is abundant
    return (divSum > n);
}