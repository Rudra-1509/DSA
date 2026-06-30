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
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
    bool helper(TreeNode* root,long long minLim,long long maxLim){
        if(!root)   return true;
        if(root->val<=minLim || root->val>=maxLim)    return false;
        bool lhs=helper(root->left,minLim,root->val);
        bool rhs=helper(root->right,root->val,maxLim);
        return lhs && rhs;
    }
};