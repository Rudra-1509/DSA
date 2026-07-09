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
    int helper(TreeNode* root,int& k){
        if(!root)   return -1;
        int lhs=helper(root->left,k);
        if(lhs!=-1)     return lhs;
        if(--k==0)  return root->val;
        return helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root,k);
    }
};