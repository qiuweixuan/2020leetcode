#include<iostream>
#include<stdint.h>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> land_vec;
        vector<pair<int,int>> sea_vec;

        int size = grid.size();
        for (int  i = 0; i < size; i++)
        {
           for (int j = 0; j < size; j++)
           {
               auto p = make_pair(i,j);
               grid[i][j] == 0? sea_vec.push_back(p):land_vec.push_back(p);
           }
        }
        if(sea_vec.empty() || land_vec.empty())
        {
            return -1;
        }
        
        int max_dist = 0;
        for(auto&& sea_p : sea_vec){
            int sea_x = sea_p.first;
            int sea_y = sea_p.second;
            int cur_dist = INT32_MAX;
            for (auto&& land_p : land_vec)
            {
                int dist = abs(land_p.first - sea_x) + abs(land_p.second - sea_y);
                cur_dist = min(cur_dist,dist);
            }
            max_dist = max(max_dist,cur_dist);
        }
        return max_dist;
    }
};