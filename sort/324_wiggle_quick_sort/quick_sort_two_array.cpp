#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<iostream>

using namespace std;

/* class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int k = (nums.size() + 1) / 2;

        kthQSort(nums,0,nums.size(),k);

        vector<int> small_set(nums.begin() , nums.begin() + k);
        vector<int> big_set(nums.begin() + k,nums.end());
        int small_id = 0;
        int big_id = 0;
        for(int i = 0; i < nums.size();i++){
            if(i % 2 == 0){
                nums[i] = small_set[small_id++];
            }
            else{
                nums[i] = big_set[big_id++];
            }
        }
    }

    void kthQSort(vector<int>& nums,int begin,int end,int k){
        int size = end - begin;
        if(size < 2){
            return;
        }

        int pivot = nums[begin];
        int left = begin;
        int right = end;
        while(left < right){
            while (++left < end && nums[left] <= pivot);
            while (--right > begin && nums[right] >= pivot);
            if(left < right){
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[right],nums[begin]);

        //k在左侧
        if(k < right + 1){
            kthQSort(nums,begin,right,k);
        }
        //k在左侧
        if(k > right + 1){
            kthQSort(nums,right + 1,end,k);
        }
    }
};
 */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        quickSelect(nums, 0, len, len / 2);
        auto midptr = nums.begin() + len / 2;
        int mid = *midptr;
        
        // 3-way-partition
        int i = 0, j = 0, k = nums.size() - 1;
        while(j < k){
            if(nums[j] > mid){
                swap(nums[j], nums[k]);
                --k;
            }
            else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        
        if(nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }
    
private:
    void quickSelect(vector<int> &nums, int begin, int end, int n){
        int t = nums[end - 1];
        int i = begin, j = begin;
        while(j < end){
            if(nums[j] <= t){
                swap(nums[i++], nums[j++]);
            }
            else{
                ++j;
            }
        }
        if(i - 1 > n){
            quickSelect(nums, begin, i - 1, n);
        }
        else if(i <= n){
            quickSelect(nums, i, end, n);
        }
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().wiggleSort(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}