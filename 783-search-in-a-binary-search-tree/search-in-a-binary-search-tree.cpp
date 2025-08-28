/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        if(root==NULL)return NULL;
        if(root->val==value)
            return root;

        TreeNode* left=searchBST(root->left,value);
        TreeNode* right=searchBST(root->right,value);
        if(left==NULL && right==NULL) return NULL;
        return left!=NULL?left:right;
    }
};