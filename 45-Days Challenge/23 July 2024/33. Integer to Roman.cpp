class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int i = 10;
        int temp = 0;
        while( num/i != 0 )
        {
            int ans = num % i;
            ans = ans - temp;
            temp = ans + temp;
            if( ans == 1 ) result = 'I' + result;
            else if( ans == 2 ) result = "II" + result;
            else if( ans == 3 ) result = "III" + result;
            else if( ans == 4 ) result = "IV" + result;
            else if( ans == 5 ) result = 'V' + result;
            else if( ans == 6 ) result = "VI" + result;
            else if( ans == 7 ) result = "VII" + result;
            else if( ans == 8 ) result = "VIII" + result;
            else if( ans == 9 ) result = "IX" + result;
            else if( ans == 10 ) result = "X" + result;
            else if( ans == 20 ) result = "XX" + result;
            else if( ans == 30 ) result = "XXX" + result;
            else if( ans == 40 ) result = "XL" + result;
            else if( ans == 50 ) result = "L" + result;
            else if( ans == 60 ) result = "LX" + result;
            else if( ans == 70 ) result = "LXX" + result;
            else if( ans == 80 ) result = "LXXX" + result;
            else if( ans == 90 ) result = "XC" + result;
            else if( ans == 100 ) result = "C" + result;
            else if( ans == 200 ) result = "CC" + result;
            else if( ans == 300 ) result = "CCC" + result;
            else if( ans == 400 ) result = "CD" + result;
            else if( ans == 500 ) result = 'D' + result;
            else if( ans == 600 ) result = "DC" + result;
            else if( ans == 700 ) result = "DCC" + result;
            else if( ans == 800 ) result = "DCCC" + result;
            else if( ans == 900 ) result = "CM" + result;
        i = i*10;            
        }
        i = i / 10;
        temp = num / i;
        if( i == 1 )
        {
            if( temp == 1 ) result = 'I' + result;
            else if( temp == 2 ) result = "II" + result;
            else if( temp == 3 ) result = "III" + result;
            else if( temp == 4 ) result = "IV" + result;
            else if( temp == 5 ) result = 'V' + result;
            else if( temp == 6 ) result = "VI" + result;
            else if( temp == 7 ) result = "VII" + result;
            else if( temp == 8 ) result = "VIII" + result;
            else if( temp == 9 ) result = "IX" + result;
        }
        else if ( i == 10 )
        {
            if( temp == 1 ) result = 'X' + result;
            else if( temp == 2 ) result = "XX" + result;
            else if( temp == 3 ) result = "XXX" + result;
            else if( temp == 4 ) result = "XL" + result;
            else if( temp == 5 ) result = 'L' + result;
            else if( temp == 6 ) result = "LX" + result;
            else if( temp == 7 ) result = "LXX" + result;
            else if( temp == 8 ) result = "LXXX" + result;
            else if( temp == 9 ) result = "XC" + result;
        }
        else if( i == 100 )
        {
            if( temp == 1 ) result = 'C' + result;
            else if( temp == 2 ) result = "CC" + result;
            else if( temp == 3 ) result = "CCC" + result;
            else if( temp == 4 ) result = "CD" + result;
            else if( temp == 5 ) result = 'D' + result;
            else if( temp == 6 ) result = "DC" + result;
            else if( temp == 7 ) result = "DCC" + result;
            else if( temp == 8 ) result = "DCCC" + result;
            else if( temp == 9 ) result = "CM" + result;
        }
        else if( i == 1000 )
        {
            if( temp == 1 ) result = 'M' + result;
            else if( temp == 2 ) result = "MM" + result;
            else if( temp == 3 ) result = "MMM" + result;
        }
    return result;
    }
};
