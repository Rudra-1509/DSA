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
    // int ans=0;
    // void helper(TreeNode* root,int depth){
    //     if(!root)   return;
    //     if(!root->left && !root->right){
    //         ans=max(ans,depth);
    //         return;
    //     }
    //     helper(root->left,depth+1);
    //     helper(root->right,depth+1);
    // }
    // int maxDepth(TreeNode* root) {
    //     if(!root)   return 0;
    //     ans=0;
    //     helper(root,1);
    //     return ans;
    // }

    int maxDepth(TreeNode* root) {
        if(!root)   return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};