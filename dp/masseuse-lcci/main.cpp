#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

/**
 * 理论：最多跳过两个元素
 *  a b c d e f g
 *  如果一定要选d,可从a 或 b 这两个节点跳过来
 *  
 * 实现：利用末尾元素DP，上楼梯问题变种
 */

class Solution {
public:
    int massage(vector<int>& nums) {
        int customer_size = nums.size();
        //tails_i 选择i作为最后一个元素
        vector<int> tails(customer_size,0);

        
        for(int i = 0 ;i < customer_size;i++){
            if(i < 2){
                //dp初始化
                tails[i] = nums[i];
            }
            else if(i == 2){
                //dp递推式
                tails[i] = tails[i-2] + nums[i];
            }
            else{
                //dp递推式
                tails[i] = max(tails[i-2],tails[i-3])
                    + nums[i];
            }
        }

        //找出以tails_i元素结尾的最大值
        int max_value = 0;
        for (auto&& val : tails)
        {
            max_value = max(max_value,val);
        }
        
        return max_value;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().massage(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}