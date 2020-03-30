#include<vector>
#include<iostream>
using namespace std;

//三路快排，划分为小于，等于，大于三部分
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //左开右开
        int p0 = -1;
        int p2 = nums.size();

        int p1 = 0;
        while(p1 > p0 && p1 < p2){
            while(nums[p1] != 1 && p1 > p0 && p1 < p2){
                switch (nums[p1])
                {
                case 0:
                    p0++;
                    swap(nums[p1],nums[p0]);
                    break;
                case 2:
                    p2--;
                    swap(nums[p1],nums[p2]);
                    break;
                default:
                    break;
                }
            }
            p1++;
        }
    }
};