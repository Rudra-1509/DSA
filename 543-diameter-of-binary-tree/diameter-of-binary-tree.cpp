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
    int helper(TreeNode* root,int& ans){
        if(!root)   return 0;
        int lhs=helper(root->left,ans);
        int rhs=helper(root->right,ans);
        ans=max(ans,lhs+rhs);
        return 1+max(lhs,rhs);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        int ans=0;
        helper(root,ans);
        return ans;
    }
};