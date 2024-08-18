class Solution {
public:
    void construct(TreeNode* root, string temp, vector<string> &ans )
    {
        temp = temp + to_string(root->val);
        if( root->left == NULL && root->right == NULL )
        {
            ans.push_back(temp);
            return;
        }
        if( root->left )
        {
            if( temp.back() != '>')
            temp = temp + "->";
            construct(root->left,temp,ans);
        }
        if( root->right )
        {
            if( temp.back() != '>')
            temp = temp + "->";
            construct(root->right,temp,ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        construct(root,temp,ans);
        return ans;
    }
};
