#include <iostream>
#include <string>
#include <array>
//maxRun is the longest run (what the program solves for)
int maxRun = 0;
//counter to make the recursion work in collatz
bool counter = 0;
//nums is an array of booleans to check if a number has been reached before
const long SIZE = 200000000;
int nums[SIZE];
std::array<int, 2> collatz(long long n);
/**
 * run the program and print final value of maxRun and its starting number
*/
int main()
{
    for(int i = 0; i < SIZE; i++)
    {
        nums[i] = 0;
    }
    //For every number from 2 to 1 million run the collatz() and if run is longest then change maxRun and print start #
    for(long n = 2; n <= 1000000; n++)
    {
        std::array<int, 2> temp = collatz(n);
        if(temp[0] > maxRun) { 
            maxRun = temp[0]; 
            std::cout << "Max run start num = " << temp[1] << "\n";
        }
    }
    //print final maxRun
    std::cout << "Max run = " << maxRun;
    return 0;
}

/**
 * while n != 1 run the collatz conjecture problem and count run length
 * if have seen num before, break loop, else set nums[n] to true
*/
std::array<int, 2> collatz(long long n)
{
    //return array with index 1 of the run length and index 2 of run starting #
    std::array<int,2> run = {0, n};
    while(n != 1) {
        run[0]++;
        //check if have already seen number before, if so skip and add length, if no make number seen and update nums[n]
        if(n < SIZE) {
            if(nums[n] > 0) { 
                run[0] += nums[n];
                break; 
            }
            else if(counter == 0) { 
                counter = 1;
                nums[n] = collatz(n)[0]-1;
                counter = 0;
            }
        }
        //collatz part
        if(n%2==0) {
            n/=2;
        }
        else {
            run[0]++;
            n=(3*n+1)/2;
        }
    }
    return run;
}