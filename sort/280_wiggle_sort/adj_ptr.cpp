#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        for (int i = 0; i + 1< nums.size(); i++)
        {
            int j = i + 1;
            if(i % 2 == 0 && nums[i] > nums[j]){
                swap(nums[i],nums[j]);
            }
            if(i % 2 == 1 && nums[i] < nums[j]){
                swap(nums[i],nums[j]);
            }
        }
        
    }
};