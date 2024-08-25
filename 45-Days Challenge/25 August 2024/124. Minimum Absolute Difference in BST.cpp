class Solution {
public:
    void helper(TreeNode* root, vector<int> &nums )
    {
        if( root == NULL )
        {
            return;
        }

        nums.push_back(abs(root->val-0));
        helper(root->left,nums);
        helper(root->right,nums);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        if( root == NULL )
        {
            return 0;
        }
        vector<int> nums;

        helper(root,nums);
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;

        for( int i = 1; i<nums.size(); i++ )
        {
            mini = min(mini,nums[i]-nums[i-1]);
        }
    return mini;
    }
};
