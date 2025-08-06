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
    int helper(TreeNode* root,int num){
        if(!root)   return 0;
        num=num*10+root->val;
        if(!root->left && !root->right)
            return num;
        int leftSide=helper(root->left,num);
        int rightSide=helper(root->right,num);
        return leftSide+rightSide;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};