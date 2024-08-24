class Solution {
public:
    int helper(TreeNode *root )
    {
        if( root == NULL )
        {
            return 0;
        }

        return 1 + max(helper(root->left), helper(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if( root == NULL ) return true;

        int leftheight = helper(root->left);
        int rightheight = helper(root->right);

        return (abs(leftheight - rightheight ) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
