class Solution {
public:
    void find(TreeNode* root, int &sum )
    {
        if( root == NULL )
        {
            return;
        }

        if( root->left != NULL && root->left->left == NULL && root->left->right == NULL )
        {
            sum += root->left->val;
        }
        find(root->left,sum);
        find(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        find(root,sum);
        return sum;
    }
};
