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
    int helper(TreeNode* root,int& maxsum){
        if(!root)   return 0;
        int lhs=max(helper(root->left,maxsum),0);
        int rhs=max(helper(root->right,maxsum),0);
        int cursum=root->val+lhs+rhs;
        maxsum=max(maxsum,cursum);
        return root->val+max(lhs,rhs);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        helper(root,maxsum);
        return maxsum;
    }
};