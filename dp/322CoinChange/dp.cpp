#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <assert.h>
#include <stdint.h>
#include <stdexcept>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }

        vector<int> dp(amount + 1,INT32_MAX);
        dp[0] = 0;

        for(int i = 0;i < coins.size();i++){
            int coin_val = coins[i];
            for(int j = coin_val;j <= amount;j++){
                if(dp[j - coin_val] != INT32_MAX){
                    dp[j] = min(dp[j] ,dp[j - coin_val] + 1);
                }
            }
        }
        return dp[amount] == INT32_MAX? -1: dp[amount];
    }
};


