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
    int helper(TreeNode* root,int& maxSum){
        if(!root)   return 0;
        int leftSum=helper(root->left,maxSum);
        int rightSum=helper(root->right,maxSum);
        // int curSum=root->val+leftSum+rightSum;
        // maxSum=max(maxSum,curSum);
        // return root->val+max(leftSum,rightSum);
        int temp=root->val+max(leftSum,rightSum);
        int ans=root->val+leftSum+rightSum;
        maxSum=max(ans,maxSum);
        return (temp<0)?0: temp;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};