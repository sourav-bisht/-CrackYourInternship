class Solution{
public:
    vector<pair<int,int>> directions = { {-1,0}, {0,-1}, {1,0}, {0,1} };
    void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<bool>> &visited)
    {
        int n = mat.size();
        int m = mat[0].size();
        visited[i][j] = true;
        

        for( auto it : directions )
        {
            int new_i = i + it.first;
            int new_j = j + it.second;
            if( new_i >=0 && new_i < n && new_j >= 0 && new_j < m && !visited[new_i][new_j] && mat[new_i][new_j] != 'X')
            {
                dfs(new_i,new_j,mat,visited);
            }
        }
        
    return;
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j<m; j++ )
            {
                if( i == 0 || j == 0 || i == (n-1) || j == (m-1) )
                {
                    if( mat[i][j] == 'O' && !visited[i][j] )
                    {
                        dfs(i,j,mat,visited);
                    }
                }
            }
        }
           
        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j<m; j++ )
            {
                if( mat[i][j] == 'O' && !visited[i][j] )
                {
                    mat[i][j] = 'X';
                }
            }
        }
    return mat;
    }
};
