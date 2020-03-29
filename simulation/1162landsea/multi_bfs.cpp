#include <iostream>
#include <stdint.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:

    class PointStep{
        public:
            int x, y,step;
            PointStep(int x,int y,int step):x{x},y{y},step{step} {}
    };

    int maxDistance(vector<vector<int>> &grid)
    {
        int size = grid.size();
        int land_cnt = 0, sea_cnt = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                grid[i][j] == 0 ? sea_cnt++ : land_cnt++;
            }
        }
        if (sea_cnt == 0 || land_cnt == 0)
        {
            return -1;
        }

        int dist = multiBfs(grid);
        return dist;
    }

    int multiBfs(vector<vector<int>> &grid)
    {
        int size = grid.size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        queue<PointStep> level;
        for(int i = 0;i < size;i++){
            for (int j = 0; j < size; j++)
            {
                if(grid[i][j]){
                    level.push(PointStep{i,j,0});
                }
            }
        }
        int maxDist = 0;
        while(!level.empty()){
            auto p = level.front();
            level.pop();
            for(int i = 0;i < 4;i++){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                int nstep = p.step + 1;
                if( nx >= 0 && nx < size && ny >= 0 && ny < size){
                    if(grid[nx][ny]== 0){
                        grid[nx][ny] = 1;
                        level.push(PointStep{nx,ny,nstep});
                        maxDist = max(maxDist,nstep);
                    }
                }
            }
        }
        return maxDist;
    }
};



int main(){
    vector<vector<int>> grid;
    grid.push_back({1,0,1});
    grid.push_back({0,0,0});
    grid.push_back({1,0,1});

    int ans = Solution().maxDistance(grid);
    cout<<ans<<endl;
    return 0;
}