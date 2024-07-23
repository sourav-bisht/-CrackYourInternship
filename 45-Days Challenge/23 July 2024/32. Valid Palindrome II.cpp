class Solution {
public:
    bool validPalindrome(string s) {
        bool ans;
        int i = 0;
        int j = s.length() - 1;
        int count = 0;
        while( i<j )
        {
            if( s[i] != s[j] )
            {
                break;             //Indices found where the character are not same.
            }
            i++;
            j--;
        }
        int k = i+1;
        int l = j;
        bool ans1 = true;
        while( k<l )
        {
            if( s[k] != s[l] )
            {
                ans1 = false;
                break;
            }
            k++;
            l--;
        }
        k = i;
        l = j-1;
        bool ans2 = true;
        while( k<l )
        {
            if( s[k] != s[l] )
            {
                ans2 = false;
            }
            k++;
            l--;
        }
    ans = ans1 || ans2;
    return ans;
    }
};
