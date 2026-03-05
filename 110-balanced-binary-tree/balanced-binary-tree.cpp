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
    int helper(TreeNode* root){
        if(!root)   return 0;
        int lhs=helper(root->left);
        if(lhs==-1) return -1;
        int rhs=helper(root->right);
        if(rhs==-1) return -1;
        if(abs(lhs-rhs)>1)  return -1;
        return 1+max(lhs,rhs);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};