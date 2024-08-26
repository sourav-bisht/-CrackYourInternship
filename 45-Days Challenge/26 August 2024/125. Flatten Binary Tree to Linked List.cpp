class Solution {
public:
    TreeNode* helper(TreeNode *root)
    {
        if( root == NULL )
        {
            return NULL;
        }

        TreeNode *head = new TreeNode(root->val);
        head->right = helper(root->left);

        TreeNode *temp = head;
        while( temp->right != NULL )
        {
            temp = temp->right;
        }
        temp->right = helper(root->right);
    return head;
    }

    void flatten(TreeNode* root) {
         if( root == NULL )
        {
            return;
        }
        TreeNode *flattenedLeft = helper(root->left);
        TreeNode *flattenedRight = helper(root->right);
        root->left = NULL;
        root->right = flattenedLeft;
        TreeNode *temp = root;
        while( temp->right != NULL )
        {
            temp = temp->right;
        }
        temp->right = flattenedRight;
    }
};
