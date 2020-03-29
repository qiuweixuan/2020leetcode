#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;


class Solution {
public:

    struct Point{
        int x,y,dist;
    };
    int shortestDistance(vector<vector<int>>& grid) {
        
        int buildCnt = 0;
        vector<vector<int>> visit;
        for(auto&& row :grid){
            visit.push_back(row);
            for(auto&& val:row){
                if(val==1){
                    buildCnt++;
                }
            }
        }

        int minPathSum = INT32_MAX;
        int row_size = grid.size();
        int col_size =  grid[0].size();
        for(int i = 0;i < row_size;i++){
            for(int j = 0; j < col_size;j++){
                if(grid[i][j] == 0){
                    int res = bfs(grid,visit,i,j,buildCnt);
                    minPathSum = (res == -1? minPathSum : min(minPathSum,res) );
                }
            }
        }
        
        return minPathSum == INT32_MAX? -1: minPathSum;
    }
    
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visit,int x,int y,int buildCnt){
        //初始化
        int row_size = grid.size();
        int col_size =  grid[0].size();
        for(int i = 0;i < row_size;i++){
            for(int j = 0; j < col_size;j++){
                visit[i][j] = grid[i][j];
            }
        }
        
        queue<Point> q;
        q.push(Point{x,y,0});
        visit[x][y] = 2;
        int pathSum = 0;

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while (!q.empty()&&buildCnt > 0)
        {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                int ndist = p.dist + 1;
                if(nx >= 0 && nx < row_size && ny >= 0 && ny < col_size && visit[nx][ny] != 2){
                    if(visit[nx][ny] == 1){
                        pathSum += ndist;
                        
                        buildCnt--;
                    }
                    else{
                        
                        q.push(Point{nx,ny,ndist});
                    }
                    visit[nx][ny] = 2;
                }
            }
        }
       
        return buildCnt == 0?pathSum:-1;
    }
};


int main(){
    //[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
    vector<vector<int>> grid;
    grid.push_back({1,0,2,0,1});
    grid.push_back({0,0,0,0,0});
    grid.push_back({0,0,1,0,0});

    int ans = Solution().shortestDistance(grid);
    cout<<ans<<endl;
    return 0;
}