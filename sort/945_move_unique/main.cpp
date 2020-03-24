#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        const int SIZE = 40000; 
        vector<int> cnt(SIZE,0);
        for(auto&& elem : A){
            cnt[elem]++;
        }

        int start = -1;
        int move = 0;
        for (int i = 0; i < SIZE; i++)
        {
            int n = cnt[i];
            if( n == 0){
                continue;
            }
            start = max(start,i);
            int increment = (start - i) * n + 
                        (n - 1) * n / 2;
            move += increment;
            start += n;
        }
        return move;
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
        vector<int> A = stringToIntegerVector(line);
        
        int ret = Solution().minIncrementForUnique(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}