class Solution {
public:
    pair<int,bool> solve(TreeNode* root) {
        if(root == NULL) 
        {
            return {0, true};
        }
        
        pair<int,bool> l = solve(root->left);
        pair<int,bool> r = solve(root->right);

        int height = 1 + max(l.first, r.first);
        bool balanced = l.second && r.second && abs(l.first - r.first) <= 1;
        
        return {height, balanced};
    }

    bool isBalanced(TreeNode* root) 
    {
        return solve(root).second;
    }
};
