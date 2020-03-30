#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row_size = matrix.size();
        if(row_size == 0) return 0;
        int col_size = matrix[0].size();

        //左闭右开，until是开区间
        vector<vector<int>> untilX(row_size,vector<int>(col_size,-1));
        vector<vector<int>> untilY(row_size,vector<int>(col_size,-1));

        for (int i = 0; i < row_size; i++)
        {
            for(int j = 0;j < col_size;j++){
                if(matrix[i][j] == '0') continue;
                //左闭右开
                int start = j;
                while(j < col_size && matrix[i][j] == '1'){
                    j++;
                }
                while(start < j){
                    untilY[i][start] = j;
                    start++;
                }
            }
        }
        for(int j = 0;j < col_size;j++){
            for(int i = 0;i < row_size;i++){
                 if(matrix[i][j] == '0') continue;
                //左闭右开
                int start = i;
                while(i < row_size && matrix[i][j] == '1'){
                    i++;
                }
                while(start < i){
                    untilX[start][j] = i;
                    start++;
                }
            }
        }


        int maxArea = 0;
        for (int i = 0; i < row_size; i++)
        {
            for(int j = 0;j < col_size;j++){
                if(matrix[i][j] == '0') continue;
                int area = getMaxArea(untilX,untilY,maxArea,i,j);
                // printf(" %d %d | %d %d %d\n \n",untilX[i][j],untilY[i][j],i,j,area);
                maxArea = max(maxArea,area);

            }
        }

        return maxArea;
    }

    int getMaxArea(vector<vector<int>>& untilX,vector<vector<int>>& untilY,int globalMaxArea,int x,int y){
        
        int mayMaxArea = (untilX[x][y] - x) * (untilY[x][y] - y);
        // cout<<"mayMaxArea:"<<mayMaxArea<<endl;
        if(mayMaxArea <= globalMaxArea){
            return 0;
        }

        
        int heigth = 1;
        int width = untilY[x][y] - y;
        int ansArea = heigth * width;
        for(int i = x + 1;i < untilX[x][y];i++){
            heigth++;
            width = min(width,untilY[i][y] - y);
            // cout<<heigth<<" "<<width<<endl;
            ansArea = max(ansArea,heigth * width);
        }
        return ansArea;
    }
};


int main(){
    // [['1','0','1','0','0'],['1','0','1','1','1'],['1','1','1','1','1'],['1','0','0','1','0']]
    vector<vector<char>> grid;
    grid.push_back({'1','0','1','0','0'});
    grid.push_back({'1','0','1','1','1'});
    grid.push_back({'1','1','1','1','1'});
    grid.push_back({'1','0','0','1','0'});

    int ans = Solution().maximalRectangle(grid);
    cout<<ans<<endl;
    return 0;
}