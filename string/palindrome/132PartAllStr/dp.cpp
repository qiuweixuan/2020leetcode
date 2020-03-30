#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

//abc1234321ab
class Solution
{
public:
    int minCut(string s)
    {

        auto suffixArray = getSuffixStrArray(s);
        //需要切割多少次才能到达id
        vector<int> cuts(s.size(),INT32_MAX);

        for (int end = 0; end < s.size(); end++)
        {
            for(auto start : suffixArray[end]){
                if(start == 0){
                    cuts[end] = 0;
                }
                else if(cuts[start - 1] != INT32_MAX){
                    cuts[end] = min(cuts[end],cuts[start - 1] + 1);
                }
            }
        }
        
        
        return cuts[s.size() - 1];
    }

    vector<vector<bool>> getAllPalindSubStr(const string &s)
    {
        int size = s.size();
        vector<vector<bool>> ans(size, vector<bool>(size, false));
        for (int i = 0; i < size; i++)
        {
            ans[i][i] = true;
        }
        for (int i = 0; i + 1 < size; i++)
        {
            ans[i][i + 1] = s[i] == s[i + 1];
        }
        for (int len = 2; len < size; len++)
        {
            for (int i = 0; i + len < size; i++)
            {
                int j = i + len;
                ans[i][j] = (s[i] == s[j]) && ans[i + 1][j - 1];
            }
        }
        return ans;
    }

    vector<vector<int>> getSuffixStrArray(const string &s)
    {
        int size = s.size();
        vector<vector<bool>> palind(size, vector<bool>(size, false));

        vector<vector<int>> suffixArray(size);
        for (int i = 0; i < size; i++)
        {
            palind[i][i] = true;
            suffixArray[i].push_back(i);
        }
        for (int i = 0; i + 1 < size; i++)
        {
            palind[i][i + 1] = s[i] == s[i + 1];
            if (palind[i][i + 1])
            {
                suffixArray[i + 1].push_back(i);
            }
        }
        for (int len = 2; len < size; len++)
        {
            for (int i = 0; i + len < size; i++)
            {
                int j = i + len;
                palind[i][j] = (s[i] == s[j]) && palind[i + 1][j - 1];
                if (palind[i][j])
                {
                    suffixArray[j].push_back(i);
                }
            }
        }
        return suffixArray;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().minCut(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}