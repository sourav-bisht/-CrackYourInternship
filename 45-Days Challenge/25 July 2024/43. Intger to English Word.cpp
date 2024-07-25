class Solution {
public:
    vector<int> range = {1000000000, 1000000, 1000, 100};
    vector<string> rangeEnglish = { "Billion", "Million", "Thousand", "Hundred"};
    unordered_map<int,string> constants;
    
    string helper(int num )
    {
        if( constants.find(num) != constants.end() )
        {
            return constants[num];
        }
        string str = "";
        if( num < 100 )
        {
            str += helper(num/10*10);
            str += " ";
            str += helper(num%10);
        }

        for( int i = 0; i<range.size(); i++ )
        {
            if( num < range[i] ) continue;
            str += helper(num/range[i]);
            str += " ";
            str += rangeEnglish[i];
            str += " ";
            str += helper(num%range[i]);
            break;
        }
        if( str.back() == ' ') str.pop_back();
    return str;
    }
    string numberToWords(int num) {
    constants[0] = "";
    constants[1] = "One";
    constants[2] = "Two";
    constants[3] = "Three";
    constants[4] = "Four";
    constants[5] = "Five";
    constants[6] = "Six";
    constants[7] = "Seven";
    constants[8] = "Eight";
    constants[9] = "Nine";
    constants[10] = "Ten";
    constants[11] = "Eleven";
    constants[12] = "Twelve";
    constants[13] = "Thirteen";
    constants[14] = "Fourteen";
    constants[15] = "Fifteen";
    constants[16] = "Sixteen";
    constants[17] = "Seventeen";
    constants[18] = "Eighteen";
    constants[19] = "Nineteen";
    constants[20] = "Twenty";
    constants[30] = "Thirty";
    constants[40] = "Forty";
    constants[50] = "Fifty";
    constants[60] = "Sixty";
    constants[70] = "Seventy";
    constants[80] = "Eighty";
    constants[90] = "Ninety";

    if(num == 0 ) return "Zero";
    string ans = helper(num);
    return ans;
    }
};
