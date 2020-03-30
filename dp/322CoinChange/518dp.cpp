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
    int change(int amount,vector<int>& coins) {
        if(amount == 0){
            return 0;
        }

        vector<int> dp(amount + 1,0);
        dp[0] = 1;

        for(int i = 0;i < coins.size();i++){
            int coin_val = coins[i];
            for(int j = coin_val;j <= amount;j++){
                if(dp[j - coin_val] != 0){
                    dp[j] += dp[j - coin_val];
                }
            }
        }
        return dp[amount];
    }
};


