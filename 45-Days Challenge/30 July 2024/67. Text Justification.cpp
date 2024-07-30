class Solution {
public:
    int maxW;
    string find(int i, int j, vector<string> &words, int &eachSpaceValue, int &extraSpaces)
    {
        string line = "";
        while( i<j )
        {
            line += words[i];
            if( i == j-1 )
            {
                break;
            }
            for( int k = 1; k<=eachSpaceValue; k++ )
            {
                line += " ";
            }

            if( extraSpaces > 0 )
            {
                line += " ";
                extraSpaces--;
            }

            i++; 
        }
        while( line.length() < maxW )
        {
                line += " ";
        }
    return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i = 0;
        maxW = maxWidth;
        vector<string> result;
        while( i<n )
        {
            int lettersCount = words[i].length();
            int spaceCount = 0;
            int j = i+1;
            while( j < n && (words[j].length()+1+lettersCount+spaceCount) <= maxWidth )
            {
                lettersCount += words[j].length();
                spaceCount += 1;
                j++;
            }

            int remainingSpace = maxWidth - lettersCount;
            int eachSpaceValue = spaceCount == 0 ? 0 : remainingSpace/spaceCount;
            int extraSpaces = spaceCount == 0 ? 0 : remainingSpace%spaceCount;

            if( j==n )
            {
                eachSpaceValue = 1;
                extraSpaces = 0;
            }

            result.push_back(find(i,j,words,eachSpaceValue,extraSpaces));
            i = j;
        }
    return result; 
    }
};
