#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int x_contain;
int y_contain;
int target;

class Solution
{

public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        {
            return false;
        }
        if (x + y == z)
        {
            return true;
        }
        
        
        return z % gcd(x,y) == 0; 
    }
    int gcd(int n1,int n2){
        if(n1 < n2){
            swap(n1,n2);
        }

        while(n2 > 0){
            int t = n1 % n2;
            n1 = n2;
            n2 = t;
        }
        return n1;
    }

};


int stringToInteger(string input)
{
    return stoi(input);
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        getline(cin, line);
        int z = stringToInteger(line);

        bool ret = Solution().canMeasureWater(x, y, z);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}