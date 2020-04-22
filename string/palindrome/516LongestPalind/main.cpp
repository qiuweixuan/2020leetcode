#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++)
        {
            dp[i][i] = 1;
        }
        for (int i = 0; i + 1 < size; i++)
        {
            dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
        }

        for (int len = 2; len < size; len++)
        {
            for (int i = 0; i + len < size; i++)
            {
                int j = i + len;
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
                
            }
        }

        return dp[0][size - 1];
    }
};