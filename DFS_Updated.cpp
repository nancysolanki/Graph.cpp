  void computeArea(vector<vector<int>>& grid, int i, int j, int& a) {
        int m = grid.size(), n = grid[0].size();
        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j]) {
            a++;
            grid[i][j] = 0;            
            computeArea(grid, i - 1, j, a);
            computeArea(grid, i + 1, j, a);
            computeArea(grid, i, j - 1, a);
            computeArea(grid, i, j + 1, a);
        }
    }
