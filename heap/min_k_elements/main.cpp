#include<iostream>
#include<queue>
#include<algorithm>
#include<list>
#include<sstream> 

using namespace std;


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> ans;
        if(k <= 0){
            return ans;
        }

        //默认最大堆,找最小k个数用最大堆，堆顶是看门员
        priority_queue<int> heap;
        int cnt = 0;

        for(auto&& val: arr){
            if(cnt < k){
                heap.push(val);
                cnt++;
            }
            else if(val < heap.top()){
                heap.pop();
                heap.push(val);
            }
        }

        
        while(!heap.empty())
        {
            ans.emplace_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};



class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> ans;
        if(k <= 0){
            return ans;
        }

        //默认最大堆,找最小k个数用最大堆，堆顶是看门员
        list<int> heap_list;
        
        for (size_t i = 0; i < k; i++)
        {
            heap_list.push_back(arr[i]);
        }

        heap_list.sort(greater<int>());
       
        for (size_t i = k; i < arr.size(); i++)
        {
            
            int val = arr[i];
            if(val < heap_list.front()){
                auto&&  it = find_if(heap_list.begin(),heap_list.end(),[val](int elem){return elem <= val;});
                heap_list.insert(it,val);
                heap_list.pop_front();
            }
        }
        
        for(auto&& val:heap_list)
        {
            ans.emplace_back(val);
        }
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
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
        vector<int> arr = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution2().getLeastNumbers(arr, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}