class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        int ans = -1;
        for(int i = 0; i<= (m-n); ++i )
        {
            int j = 0;
            int temp = i;
            while( j<n )  
            {
                if( haystack[temp] != needle[j]) break;
                else 
                {
                    temp++;
                    j++;
                }
            }
            if( j==n )
            {
                ans = i;
                break;
            }
        }
    return ans;
    }
};

//Above is the naive approach
