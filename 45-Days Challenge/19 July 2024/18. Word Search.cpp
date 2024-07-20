class Solution {
    private:
    void find( vector<vector<char>>& board, const string &words, int i, int j, int k, vector<vector<int>> &visited, bool &ans)
    {
        if( i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j] == 1 || board[i][j] != words[k] )
        {
            return;
        }
        ++k;
        if( k == words.size() )
        {
            ans = true;
            return;
        }
        visited[i][j] = 1;
        find(board,words,i+1,j,k,visited,ans);
        if( ans ) return;
        find(board,words,i-1,j,k,visited,ans);
        if( ans ) return;
        find(board,words,i,j+1,k,visited,ans);
        if( ans ) return;
        find(board,words,i,j-1,k,visited,ans);
        if( ans ) return;

        visited[i][j] = 0;
        --k;

        return;
    }
public:
    bool exist(vector<vector<char>>& board, string words) {
        int rows = board.size();
        int cols = board[0].size();
        bool ans = false;
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        for( int i = 0; i<board.size(); i++ )
        {
            for( int j = 0; j<board[0].size(); j++ )
            {
                if( board[i][j] == words[0] )
                {
                    int k = 0;
                    find(board,words,i,j,k,visited,ans);
                    if( ans == true ) break;
                }
            }
            if( ans == true ) break;
        }
    return ans;
    }
};
