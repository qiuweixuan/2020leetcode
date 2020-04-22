#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.size() < second.size()){
            swap(first,second);
        }
        if(first.size() - second.size() > 1){
            return false;
        }
        int left_len = 0;
        for(int i = 0;i < second.size() && first[i] == second[i];i++){
            left_len++;
        }
        int right_len = 0;
        for(int i = 0 ;left_len + i < second.size() && first[first.size() - 1 - i] == second[ second.size() - 1 - i];i++){
            right_len++;
        }
        return left_len + right_len + 1 >= first.size();
    }
};