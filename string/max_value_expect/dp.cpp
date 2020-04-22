#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n);
    double all_value = 0;
    double seq_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        dp[i] = nums[i];
        all_value += nums[i];
        seq_cnt++;
    }
    for (int len = 1; len < n; len++)
    {
        for(int i = 0;i + len < n;i++){
            int j = i + len;
            dp[i] = max(dp[i],nums[j]);
            all_value += dp[i];
            seq_cnt++;
        }
    }
    double ans = all_value / seq_cnt;
    printf("%.6f\n",ans);
    return 0;
}