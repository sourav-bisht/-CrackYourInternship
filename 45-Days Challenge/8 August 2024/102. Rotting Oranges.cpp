class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir = { {-1,0}, {0,-1}, {1,0}, {0,1} };
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        for( int i = 0; i<rows; i++ )
        {
            for( int j = 0; j<cols; j++ )
            {
                if( grid[i][j] == 2 )
                {
                    q.push({{i,j},0});
                }
            }
        }

        int count = 0;
        while( !q.empty() )
        {
            auto it = q.front();
            q.pop();
            for( auto jt : dir )
            {
                int x = it.first.first + jt.first;
                int y = it.first.second + jt.second;
                if( x>=0 && x<rows && y>=0 && y<cols && grid[x][y] == 1 )
                {
                    count = it.second + 1;
                    grid[x][y] = 2;
                    q.push({{x,y},count});
                }
            }
        }


        for( int i = 0; i<rows; i++ )
        {
            for( int j = 0; j<cols; j++ )
            {
                if( grid[i][j] == 1 )
                {
                    count = -1;
                    break;
                }
            }
        }
    return count;
    }
};
