

/**
 * 1. 第一个单词的前i位变成第二个单词的前j-1位，然后在第二个单词插入最后一个字符（d[i][j-1]+1）
 * 2. 第一个单词的前i-1位变成第二个单词的前j位，然后在第一个再删去最后一个字符（d[i-1][j]+1）
 * 3. 第一个单词的前i-1位变成第二个单词的前j-1位，然后替换最后一个字符，
 * 如果最后一个字符相同，即第一个单词的第i位和第二个单词的第j位相同的话，就不用替换了（d[i-1][j-1]），
 * 反之，如果不同就替换最后一位（d[i-1][j-1]+1）
 */

#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size() + 1,vector<int>(word2.size() + 1,INT32_MAX));
        for (int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }
        
        for(int i = 1;i <= word1.size(); i++){
            for (int j = 1; j <= word2.size(); j++)
            {
                
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1] + 1);
                }
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string word1 = stringToString(line);
        getline(cin, line);
        string word2 = stringToString(line);
        
        int ret = Solution().minDistance(word1, word2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}