#include <iostream>
#include <vector>
using namespace std;

void drawSpiral(int n)
{
    int len = (n-1)/2;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            v[i][j] = 0;
        }
    }
    cout << "initialized!\n";
    v[len][len] = 1;
    for(int i = 1; i <= len; i++)
    {
        int r = len-i;
        int c = len+i;
        int num = (2*i+1)*(2*i+1);
        v[r][c] = num;
        c--;
        while(r!=(len-i) || c!=(len+i))
        {
            num--;
            v[r][c] = num;
            if(r == len-i && c > len-i)
            {
                c--;
            }
            else if(c == len-i && r < len+i)
            {
                r++;
            }
            else if(r == len+i && c < len+i)
            {
                c++;
            }
            else
            {
                r--;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(v[i][j] < 100)
            {
                cout << " ";
            }
            if(v[i][j] < 10)
            {
                cout << " ";
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    //drawSpiral(n);
    int tr = 9; //top right
    int tl = 7; //top left
    int bl = 5; //bottom left
    int br = 3; //bottom right
    int sum = 1;
    int last_add = 8;
    for(int i = 0; i < (n-1)/2; i++)
    {
        sum += (tr + tl + bl + br);
        last_add += 2;
        br += last_add;
        last_add += 2;
        bl += last_add;
        last_add += 2;
        tl += last_add;
        last_add += 2;
        tr += last_add;
    }
    cout << sum;
}