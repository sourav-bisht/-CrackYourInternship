class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int firstRow = -1;
        int firstColumn = -1;
        if( m == 0 ) return;
        if( matrix[0][0] == 0 )
        {
            firstColumn = 0;
            firstRow = 0;
        }
        for( int i = 1; i<m; i++ )
        {
            if( matrix[i][0] == 0 )
            {
                firstColumn = 0;
                break;
            }
        }
        for( int i = 1; i<n; i++ )
        {
            if( matrix[0][i] == 0 )
            {
                firstRow = 0;
                break;
            }
        }

        for( int i = 0; i<m; i++ )
        {
            for( int j = 0; j<n; j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for( int i = 0; i<m; i++ )
        {
            for( int j = 0; j<n; j++ )
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<firstRow<<" "<<firstColumn<<endl;
        
        for( int i = 1; i<n; i++ )
        {
            if( matrix[0][i] == 0 )
            {
                for( int j = 1; j<m; j++ )
                {
                    matrix[j][i] = 0;
                }
            }
        }

        for( int i = 1; i<m; i++ )
        {
            if( matrix[i][0] == 0 )
            {
                for( int j = 1; j<n; j++ )
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if( firstRow == 0 )
        {
            for( int i = 0; i<n; i++ )
            {
                matrix[0][i] = 0;
            }
        }
        if( firstColumn == 0 )
        {
            for( int i = 0; i<m; i++ )
            {
                matrix[i][0] = 0;
            }
        } 
    }
};
