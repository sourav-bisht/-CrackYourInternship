
class Solution {
public:
    vector<int> num1;
    vector<int> num2;
    void insert(TreeNode* root )
    {
        if( root == NULL )
        {
            num1.push_back(-1000);
            return;
        }
        num1.push_back(root->val);
        insert(root->left);
        insert(root->right);
    return;
    }
    void check(TreeNode *root )
    {
        if( root == NULL )
        {
            num2.push_back(-1000);
            return;
        }
        num2.push_back(root->val);
        check(root->right);
        check(root->left);
    return;
    }
    bool isSymmetric(TreeNode* root) {
        insert(root);
        check(root);
        return num1==num2;
    }
};
