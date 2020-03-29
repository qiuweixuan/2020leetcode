#include<algorithm>
#include<vector>
#include<queue>
#include<stdint.h>

using namespace std;

class Solution {
public:

    struct Point
    {
        int x,y,step;
    };
    
    void wallsAndGates(vector<vector<int>>& rooms) {

        queue<Point> q;
        int row_size = rooms.size();
        if(row_size == 0){
            return;
        }
        int col_size = rooms[0].size();

        for(int i = 0; i < row_size; i++)
        {
            for(int j = 0;j < col_size;j++)
            {
                if(rooms[i][j] == 0){
                    q.push(Point{i,j,0});
                }
            }
        }


        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                int nstep = p.step + 1;
                if(nx >= 0 && nx < row_size && ny >= 0 && ny < col_size){
                    if(rooms[nx][ny] == INT32_MAX){
                        rooms[nx][ny] = nstep;
                        q.push(Point{nx,ny,nstep});
                    }
                }
            }
        }
    }
};