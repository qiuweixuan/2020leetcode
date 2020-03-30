#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int width = right;

        int ansArea = 0;
        int top = 0;
        //水桶最低木板效应
        while (left < right)
        {
            int area = min(height[left],height[right]) * width;
            ansArea = max(ansArea,area);
            height[left] <= height[right]?left++:right--;
            width--;
            
        }
        return ansArea;
    }
};