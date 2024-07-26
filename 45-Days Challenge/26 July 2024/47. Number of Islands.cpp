class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &visited )
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        int up = i-1;
        int down = i+1;
        int right = j+1;
        int left = j-1;
        if( up >= 0 && grid[up][j] == '1' && !visited[up][j]) dfs(up,j,grid,visited);
        if( down < n && grid[down][j] == '1' && !visited[down][j] ) dfs(down,j,grid,visited);
        if( right < m && grid[i][right] == '1' && !visited[i][right]) dfs(i,right,grid,visited);
        if( left >= 0 && grid[i][left] == '1' && !visited[i][left] ) dfs(i,left,grid,visited); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if( n == 0 )
            return 0;

        int count = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for( int row = 0; row<n; row++ )
        {
            for( int col = 0; col<m; col++ )
            {
                if( grid[row][col] == '1' && !visited[row][col] )
                {
                    dfs(row,col,grid,visited);
                    count += 1;
                }
            }
        }
    return count;
    }
};
