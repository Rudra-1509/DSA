/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return nullptr;
        if(root==p || root==q)  return root;
        TreeNode* lhs=lowestCommonAncestor(root->left,p,q);
        TreeNode* rhs=lowestCommonAncestor(root->right,p,q);
        if(!lhs && !rhs)    return nullptr;
        if(lhs && rhs)      return root;
        if(lhs)             return lhs;
        return rhs;
    }
};