class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1') {
                    count++;
                    traveseid(grid, i, j, m, n);
                }
            }
        }

        return count;
    }

    void traveseid(vector<vector<char>>& grid, int i, int j, int m, int n) {

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        traveseid(grid, i, j + 1, m, n);
        traveseid(grid, i + 1, j, m, n);
        traveseid(grid, i, j - 1, m, n);
        traveseid(grid, i - 1, j, m, n);
    }
};