#include<iostream>
#include<vector>
#include<algorithm>
#include<stdint.h>
#include<queue>
using namespace std;



/**
 * 1. presum[i] <= presum[j] - k
 * 2. i as large as possible , deque store i 
 * 3. ans = min(ans, j - deque.first) , if presum[j] - presum[deque.first] >= k 
 * 4. pop(deque.last) if( presum[deque.first] < presum[i]) -> mono ascend deque
 */
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int aSize = A.size();
        if(aSize == 0){
            return -1;
        }

        vector<int> presum(aSize + 1,0);
        for (int i = 1; i <= aSize; i++)
        {
            presum[i] = presum[i - 1] + A[i - 1];
        }

        // mono ascend deque
        deque<int> startQue;
        startQue.push_back(0);
        
        int minLen = INT32_MAX;

        for (int j = 1; j <= aSize; j++)
        {
            int i;
            int presumEnd = presum[j];

            //move start ptr -> ascend
            while(!startQue.empty() && presum[startQue.front()] <= presumEnd - K ){
                i = startQue.front();
                startQue.pop_front();
                minLen = min(minLen,j - i);
            }
            i = j;
            //move end ptr -> ascend
            while(!startQue.empty() && presum[startQue.back()] >= presumEnd){
                startQue.pop_back();
            }
            //add new star
            startQue.push_back(i);
        }
        
        return minLen == INT32_MAX ? -1 : minLen;
    }
};