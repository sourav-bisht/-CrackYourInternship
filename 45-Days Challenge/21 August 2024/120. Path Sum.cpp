class Solution {
public:
    bool check(TreeNode *root, int &targetSum, int sum )
    {
        if( root == NULL )
        {
            return false;
        }

        sum = sum + root->val;
        if( sum == targetSum && root->left == NULL && root->right == NULL )
        {
            return true;
        }
        return (check(root->left,targetSum,sum) || check(root->right,targetSum,sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return check(root,targetSum,sum);
    }
};
