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
    int helper(TreeNode* root, int& maxi){
        if(!root)   return 0;
        int leftSide=helper(root->left,maxi);
        int rightSide=helper(root->right,maxi);
        int leftPath=0,rightPath=0;
        if(root->left && root->left->val==root->val)
            leftPath=leftSide+1;
        if(root->right && root->right->val==root->val)
            rightPath=rightSide+1;
        maxi =max(maxi,leftPath+rightPath);
        return max(leftPath,rightPath);
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxi=0;
        helper(root,maxi);
        return maxi;
    }
};