class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int sum = 0;
        int j,l;
        for( int i = 0; i<k; i++ )
        {
            leftSum += cardPoints[i];
        }
        sum = leftSum;

        j = k-1;
        l = cardPoints.size()-1;
        while( j >= 0 )
        {
            leftSum -= cardPoints[j];
            rightSum += cardPoints[l];
            if( leftSum+rightSum > sum )
            {
                sum = leftSum + rightSum;
            }
        --j;
        --l;
        }
    return sum;
    }
};
