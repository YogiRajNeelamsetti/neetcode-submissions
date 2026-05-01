class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};
    void dfs(int row, int col, vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis) {
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if(grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    dfs(nrow, ncol, grid, n, m, vis);
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, n, m, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
