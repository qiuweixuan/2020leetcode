#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    struct Point
    {
        int x, y;
    };

    void solve(vector<vector<char>> &board)
    {
        int row_size = board.size();
        if (row_size == 0)
            return;
        int col_size = board[0].size();

        queue<Point> q;
        char save_char = 'S';
        for (int i = 0; i < row_size; i++)
        {
            if (board[i][0] == 'O')
            {
                q.push({i, 0});
            }
            if (board[i][col_size - 1] == 'O')
            {
                q.push({i, col_size - 1});
            }
        }
        for (int i = 1; i < col_size - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                q.push({0, i});
            }
            if (board[row_size - 1][i] == 'O')
            {
                q.push({row_size - 1, i});
            }
        }

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            board[p.x][p.y] = save_char;
            for (int i = 0; i < 4; i++)
            {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                if (nx >= 0 && nx < row_size && ny >= 0 && ny < col_size && board[nx][ny] == 'O')
                {
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < row_size; i++)
        {
            for (int j = 0; j < col_size; j++)
            {
                if (board[i][j] == save_char)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};