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
        int pval=p->val,qval=q->val;      
        if(root->val > max(pval,qval))  //both in left
            return lowestCommonAncestor(root->left,p,q);
        if(root->val < min(pval,qval))  //both in right
            return lowestCommonAncestor(root->right,p,q);
        //one in left one in right
        return root;
    }
};