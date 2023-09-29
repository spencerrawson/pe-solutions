#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("pe13input.txt");
    std::vector<std::string> input;
    std::string a;
    //copy all strings into vector
    while(getline(infile, input.emplace_back()))
    {
        ;
    }
    //create sums array and set to 0
    int sums[50];
    for(int k = 0; k < 50; k++) { sums[k] = 0; }
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            sums[j] = sums[j] + input.at(i).at(j) - '0';
        }
    }
    std::cout << sums[0] << std::endl;
    for(int x = 49; x >=0; x--)
    {
        if(x != 0 && sums[x] >= 10)
        {
            sums[x-1] += sums[x]/10;
            sums[x] = sums[x]%10;
        }
    }
    std::cout << sums[0] << std::endl;
    std::cout << sums[0] << sums[1] << sums[2] << sums[3] << sums[4] << sums[5] << sums[6] << sums[7];
    return 0;
}