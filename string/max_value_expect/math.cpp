#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

double all_value = 0;
double seq_cnt = 0;

void search(vector<int>& nums,int start,int end){
    if(start >= end){
        return;
    }
    int mid = start;
    int max_value = nums[start];
    for (int i = start; i < end; i++)
    {
       if(nums[i] > max_value){
           max_value = nums[i];
       }
    }

    double seq = (mid - start + 1) * (end - mid);
    seq_cnt += seq;
    all_value +=seq * max_value;
    search(nums,start,mid);
    search(nums,mid + 1,mid);
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n);

    int mid = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    search(nums,0,nums.size());
    cout<<all_value<<" "<<seq_cnt<<endl;
    double ans = all_value / seq_cnt;
    printf("%.6f\n",ans);
    return 0;
}