class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> directions = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        int n = board.size();
        int m = board[0].size();
        int live, dead;
        for(int i = 0; i<n; ++i )
        {
            for( int j = 0; j<m; ++j )
            {
                live = 0;
                dead = 0;
                for( auto it : directions )
                {
                    int x = i + it.first;
                    int y = j + it.second;
                    if( x>=0 && x<n && y>=0 && y<m )
                    {
                        if( abs(board[x][y]) == 1)
                        {
                            live++;
                        }
                        if( board[x][y] == 0 || board[x][y] == 2 )
                        {
                            dead++;
                        }
                    }
                }
                if( board[i][j] == 0 && live == 3 )
                {
                    board[i][j] = 2;
                }
                else if( board[i][j] == 1 )
                {
                    if( live < 2 || live > 3 )
                    {
                        board[i][j] = -1;
                    }
                }
            }
        }

        for(int i = 0; i<n; ++i )
        {
            for( int j = 0; j<m; ++j )
            {
                if( board[i][j] == 2 )
                {
                    board[i][j] = 1;
                }
                else if( board[i][j] == -1 )
                {
                    board[i][j] = 0;
                }
            }
        }
    }
};
