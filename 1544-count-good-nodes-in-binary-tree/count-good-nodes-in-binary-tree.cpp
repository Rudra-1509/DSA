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
    int helper(TreeNode* root,int maxi){
        if(!root)   return 0;
        int good=(root->val >= maxi);
        maxi=max(maxi,root->val);
        int lhs=helper(root->left,maxi);
        int rhs=helper(root->right,maxi);
        return good+lhs+rhs;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};