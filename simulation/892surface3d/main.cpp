#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        return getAllBaseArea(grid) + getAllHeightArea(grid);
    }
    
    int getAllBaseArea(vector<vector<int>>& grid){
        int area = 0;
        int size = grid.size();
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                if(grid[i][j]){
                    area += 2;
                }
            }
        }
        return area;
    }

    int getAllHeightArea(vector<vector<int>>& grid){
        int area = 0;
        int size = grid.size();
        vector<pair<int,int>> step;
        step.push_back(make_pair(-1,0));
        step.push_back(make_pair(0,1));
        step.push_back(make_pair(1,0));
        step.push_back(make_pair(0,-1));


        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                if(grid[i][j] == 0){
                    continue;
                }
                for (auto&& p : step)
                {
                    area+= getNodeHeightArea(grid,grid[i][j], 
                        i + p.first, j + p.second );
                }
                
            }
        }
        return area;
    }

    int getNodeHeightArea(vector<vector<int>>& grid, int height,int x,int y){
        int size = grid.size();
        int adjHeight;
        if(x < 0 || x >= size || y < 0 || y >= size){
            adjHeight =  0;
        }
        else{
            adjHeight = grid[x][y];
        }
        return adjHeight >= height? 0 : height - adjHeight;
    }


};