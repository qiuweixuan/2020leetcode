#include <iostream>
#include <stdint.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:

    class PointStep{
        public:
            int x, y,step;
            PointStep(int x,int y,int step):x{x},y{y},step{step} {}
    };

    int maxDistance(vector<vector<int>> &grid)
    {
        int size = grid.size();
        // 从左上两个方向来
        // 从右下两个方向来
        // 四个方向顺序回旋踢
        vector<vector<int>> dp(size,vector<int>(size,0));

        //sea:INF，land:0
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(grid[i][j] == 0){
                    dp[i][j] = INT32_MAX;
                }
            }
        }

        //左上方向dp
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(grid[i][j]){
                    continue;
                }
                if(i - 1 >= 0 && dp[i - 1][j] != INT32_MAX){
                    dp[i][j] = min(dp[i][j],dp[i - 1][j] + 1) ;
                }
                if(j - 1 >= 0 && dp[i][j - 1] != INT32_MAX){
                    dp[i][j] = min(dp[i][j],dp[i][j - 1] + 1) ;
                }
            }
        }

         //右下方向dp
        for (int i = size - 1; i >= 0 ; i--)
        {
            for (int j = size - 1; j >= 0; j--)
            {
                if(grid[i][j]){
                    continue;
                }
                if(i + 1 < size && dp[i + 1][j] != INT32_MAX){
                    dp[i][j] = min(dp[i][j],dp[i + 1][j] + 1) ;
                }
                if(j + 1 < size && dp[i][j + 1] != INT32_MAX){
                    dp[i][j] = min(dp[i][j],dp[i][j + 1] + 1) ;
                }
            }
        }
        
        int max_dist = -1;
        //汇总
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if(grid[i][j]){
                    continue;
                }
                max_dist = max(max_dist,dp[i][j]);
            }
        }
        return max_dist == INT32_MAX? -1 : max_dist;
    }
};



int main(){
    vector<vector<int>> grid;
    grid.push_back({1,0,1});
    grid.push_back({0,0,0});
    grid.push_back({1,0,1});

    int ans = Solution().maxDistance(grid);
    cout<<ans<<endl;
    return 0;
}