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
        if (!sea_cnt || !land_cnt)
        {
            return -1;
        }

        int dist = 0;
        vector<vector<int>> is_visit(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (grid[i][j] == 0)
                {
                    int val = bfs(grid,is_visit,i,j);
                    dist = max(val,dist);
                }
            }
        }
        return dist;
    }

    int bfs(vector<vector<int>> &grid, vector<vector<int>> &is_visit, int x, int y)
    {
        int size = grid.size();
        for (int i = 0; i < size; i++)
        {
            fill(is_visit[i].begin(), is_visit[i].begin() + size, 0);
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        queue<PointStep> level;
        level.push(PointStep(x,y,0));
        is_visit[x][y] = 1;

        int dist = 0;
        int cur_level = 0;
        while (!level.empty())
        {
            auto p = level.front();
            level.pop();
            for(int i = 0; i < 4;i++){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if(check_bound(nx,ny,size,is_visit)){
                    if(grid[nx][ny]){
                        return p.step + 1;
                    }
                    level.push(PointStep{nx,ny,p.step + 1});
                }
            }

        }
        return dist;
    }
    bool check_bound(int x, int y, int size, vector<vector<int>> &is_visit)
    {
        bool ans = x >= 0 && x < size && y >= 0 && y < size;
        return ans == false ? false : !is_visit[x][y];
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