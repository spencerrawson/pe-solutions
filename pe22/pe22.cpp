/**
 * Author: Spencer Rawson
 * Date: 10/12/23
 * Purpose: Solve problem 22 of project euler,
 * which is to take an unsorted text file of over 5000 names, 
 * sorting them, and then finding the sum of all their "number scores"
 * (which is the index * their alphabetic sum of characters)
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void quickSort(std::vector<std::string> & a, int low, int high);
int partition(std::vector<std::string> & a, int low, int high);
int alphabetValue(std::string s);

int main()
{
    //take in the data as a single (very long) string
    std::ifstream input("0022_names.txt");
    std::string nameLine;
    if(getline(input, nameLine))
    {
        ;
    }
    //vector of the names that removes the quotes and commas
    std::vector<std::string> names;
    //x is to make it not skip the first letter of the first word
    int x = 0;
    while(nameLine != "")
    {
        std::string temp = nameLine.substr(x);
        int end = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            end = (temp.at(i) == '"') ? i : 0;
            if(end != 0) { break; }
        }
        names.emplace_back(temp.substr(1,end-1));
        nameLine = nameLine.substr(end+1+x);
        x=1;
    }
    quickSort(names, 0, names.size()-1);
    //for each sorted name find and add the name value
    long finalSum = 0;
    for(int i = 0; i < names.size(); i++)
    {
        std::cout << alphabetValue(names[i])  << " " << names[i] << std::endl;
        finalSum += (i+1)*alphabetValue(names[i]);
    }
    std::cout << "Total Sum = " << finalSum << std::endl;
}

/**
 * quicksort starting method for recursion and calling partition
*/
void quickSort(std::vector<std::string> & a, int low, int high)
{
    //start recursion
    if(low < high)
    {
        int pivotIndex = partition(a,low,high);
        quickSort(a,low,pivotIndex-1);
        quickSort(a,pivotIndex+1,high);
    }
}

/**
 * quicksort partition method
*/
int partition(std::vector<std::string> & a, int low, int high)
{
    int li = low-1;
    for(int ri = li+1; ri <= high; ri++)
    {
        if(a[ri].compare(a[high]) < 0)
        {
            li++;
            std::string temp = a[li];
            a[li] = a[ri];
            a[ri] = temp;
        }
    }
    li++;
    std::string temp = a[li];
    a[li] = a[high];
    a[high] = temp;
    return li;
}

int alphabetValue(std::string s)
{
    int sum = 0;
    for(char c : s)
    {
        sum += (c-'A'+1);
    }
    return sum;
}

