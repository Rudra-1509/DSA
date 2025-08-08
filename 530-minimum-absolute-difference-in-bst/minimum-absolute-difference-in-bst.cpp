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
    void helper(TreeNode* root,TreeNode*& prev,int& mini){
        if(!root)   return;
        helper(root->left,prev,mini);
        if(prev)    mini =min(root->val-prev->val,mini);
        prev=root;
        helper(root->right,prev,mini);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        TreeNode* prev=nullptr;
        helper(root,prev,mini);
        return mini;
    }
};