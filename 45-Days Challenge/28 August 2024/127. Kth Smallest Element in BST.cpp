class Solution {
public:
    void inorderTraversal(TreeNode* root, int &k, int &mini )
    {
        if( root == NULL )
        {
            return;
        }

        inorderTraversal(root->left,k,mini);
        if( k == 0 )
        {
            return;
        }
        mini = root->val;
        k = k-1;
        inorderTraversal(root->right,k,mini);
    return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if( k == 0 )
        {
            return root->val;
        }
        int mini = 0;
        inorderTraversal(root,k,mini);
    return mini;
    }
};
