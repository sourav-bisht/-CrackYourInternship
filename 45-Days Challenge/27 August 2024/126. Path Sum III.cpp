class Solution {
public:
    void dfs(TreeNode* root, int &targetSum, int &count, long long int sum )
    {
        if( root == NULL )
        {
            return;
        }
        sum += root->val;
        if( sum == targetSum )
        {
            count += 1;
        }
        dfs(root->left,targetSum,count,sum);
        dfs(root->right,targetSum,count,sum);
    }
    void helper(TreeNode *root, int &targetSum, int &count )
    {
        if( root == NULL )
        {
            return;
        }
        long long int sum = 0;
        dfs(root,targetSum,count,sum);
        helper(root->left, targetSum,count);
        helper(root->right,targetSum,count);
    return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        helper(root,targetSum,count);
        return count;
    }
};
