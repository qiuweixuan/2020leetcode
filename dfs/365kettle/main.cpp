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
        // int contain = max(x, y) + 1;
        // vector<vector<bool>>  isVisit(contain,vector<bool>(contain,false));
        vector< vector<bool> > isVisit;
        for (size_t i = 0; i < x + 1; i++)
        {
           isVisit.emplace_back(vector<bool>(y + 1,false));
        }
        

        x_contain = x;
        y_contain = y;
        target = z;
        
        return dfs(0,0,isVisit);
    }

    int dfs(int x, int y, vector<vector<bool>>& isVisit)
    {
        if (isVisit[x][y])
        {
            return 0;
        }
        isVisit[x][y] = true;
        
        if (x + y == target)
        {
            return 1;
        }
        
        int state = 0;

        // 1.1 清空x水壶
        state |= dfs(0, y, isVisit);

        // 1.2 装满x水壶
        state |= dfs(x_contain, y, isVisit);

        // 1.3 x水壶倒水给y水壶
        if (x + y <= y_contain)
        {
            state |= dfs(0, x + y, isVisit);
        }
        else
        {
            state |= dfs(x + y - y_contain, y_contain, isVisit);
        }

         // 2.1 清空y水壶
        state |= dfs(x, 0, isVisit);

        // 2.2 装满y水壶
        state |= dfs(x, y_contain, isVisit);

        // 2.3 y水壶倒水给x水壶
        if (x + y <= x_contain)
        {
            state |= dfs(x + y, 0 , isVisit);
        }
        else
        {
            state |= dfs(x_contain,x + y - x_contain, isVisit);
        }
        return state;
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