class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        string temp = strs[0];
        int n = strs.size();
        for(int i = 1; i<n; i++ )
        {
            ans = "";
            int j = 0;
            int k = 0;
            int n1 = temp.size();
            int n2 = strs[i].size();
            string temp2 = strs[i];
            while( j<n1 && k<n2 )
            {
                if( temp[j] == temp2[k] )
                {
                    ans = ans + temp[j];
                    j++;
                    k++;
                }
                else if( temp[j] != temp2[k] )
                {
                    break;
                }
            }
            temp = ans;
        }
    return ans;
    }
};
